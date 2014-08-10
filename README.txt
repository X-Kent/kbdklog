Use as root !

To Build:
make

To Install:
make install

To Uninstall:
make uninstall

To run:
modprobe kbdklog mode = ascii
OR
modprobe kbdklog mode = full

To see output:
cat /sys/kernel/kbdklog/logger

To enable on boot run:
echo "kbdklog" >> /etc/modules

