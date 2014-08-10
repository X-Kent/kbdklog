#ifndef _KEYMAP_H_
#define _KEYMAP_H_

#define MAP_LEN 128

char* high_map[MAP_LEN + 1   ] = {
    /* 000 */ "<UDF-000>",
    /* 001 */ "<ESC>",
    /* 002 */ "!",
    /* 003 */ "@",
    /* 004 */ "#",
    /* 005 */ "$",
    /* 006 */ "%",
    /* 007 */ "^",
    /* 008 */ "&",
    /* 009 */ "*",
    /* 010 */ "(",
    /* 011 */ ")",
    /* 012 */ "_",
    /* 013 */ "+",
    /* 014 */ "<Backspace>",
    /* 015 */ "	", /* TAB */
    /* 016 */ "Q",
    /* 017 */ "W",
    /* 018 */ "E",
    /* 019 */ "R",
    /* 020 */ "T",
    /* 021 */ "Y",
    /* 022 */ "U",
    /* 023 */ "I",
    /* 024 */ "O",
    /* 025 */ "P",
    /* 026 */ "{",
    /* 027 */ "}",
    /* 028 */ "<Enter>",
    /* 029 */ "<L-Ctrl>",
    /* 030 */ "A",
    /* 031 */ "S",
    /* 032 */ "D",
    /* 033 */ "F",
    /* 034 */ "G",
    /* 035 */ "H",
    /* 036 */ "J",
    /* 037 */ "K",
    /* 038 */ "L",
    /* 039 */ ":",
    /* 040 */ "\"",
    /* 041 */ "~",
    /* 042 */ "<L-Shift>",
    /* 043 */ "\\",
    /* 044 */ "Z",
    /* 045 */ "X",
    /* 046 */ "C",
    /* 047 */ "V",
    /* 048 */ "B",
    /* 049 */ "N",
    /* 050 */ "M",
    /* 051 */ "<",
    /* 052 */ ">",
    /* 053 */ "?",
    /* 054 */ "<R-Shift>",
    /* 055 */ "*",
    /* 056 */ "<L-Alt>",
    /* 057 */ " ", /* Space */
    /* 058 */ "<Caps Lock>",
    /* 059 */ "<F1>",
    /* 060 */ "<F2>",
    /* 061 */ "<F3>",
    /* 062 */ "<F4>",
    /* 063 */ "<F5>",
    /* 064 */ "<F6>",
    /* 065 */ "<F7>",
    /* 066 */ "<F8>",
    /* 067 */ "<F9>",
    /* 068 */ "<F10>",
    /* 069 */ "<Num Lock>",
    /* 070 */ "<Scroll Lock>",
    /* 071 */ "<Home 7>",
    /* 072 */ "<Up 8>",
    /* 073 */ "<Page Up 9>",
    /* 074 */ "-",
    /* 075 */ "<Left 4>",
    /* 076 */ "<5>",
    /* 077 */ "<Right 6>",
    /* 078 */ "+",
    /* 079 */ "<End>",
    /* 080 */ "<Down 2>",
    /* 081 */ "<Page Down 3>",
    /* 082 */ "<Insert>",
    /* 083 */ "<Del>",
    /* 084 */ "<UDF-084>",
    /* 085 */ "<UDF-085>",
    /* 086 */ "<UDF-086>",
    /* 087 */ "<F11>",
    /* 088 */ "<F12>",
    /* 089 */ "<UDF-089>",
    /* 090 */ "<UDF-090>",
    /* 091 */ "<UDF-091>",
    /* 092 */ "<UDF-092>",
    /* 093 */ "<UDF-093>",
    /* 094 */ "<UDF-094>",
    /* 095 */ "<UDF-095>",
    /* 096 */ "<R-Enter>",
    /* 097 */ "<R-Ctrl>",
    /* 098 */ "/",
    /* 099 */ "<Print Screen>",
    /* 100 */ "<R-Alt>",
    /* 101 */ "<UDF-101>",
    /* 102 */ "<Home>",
    /* 103 */ "<Up>",
    /* 104 */ "<Page Up>",
    /* 105 */ "<Left>",
    /* 106 */ "<Right>",
    /* 107 */ "<End>",
    /* 108 */ "<Down>",
    /* 109 */ "<Page Down>",
    /* 110 */ "<Insert>",
    /* 111 */ "<Del>",
    /* 112 */ "<UDF-112>",
    /* 113 */ "<UDF-113>",
    /* 114 */ "<UDF-114>",
    /* 115 */ "<UDF-115>",
    /* 116 */ "<UDF-116>",
    /* 117 */ "<UDF-117>",
    /* 118 */ "<UDF-118>",
    /* 119 */ "<Pause>",
    /* 120 */ "<UDF-120>",
    /* 121 */ "<UDF-121>",
    /* 122 */ "<UDF-122>",
    /* 123 */ "<UDF-123>",
    /* 124 */ "<UDF-124>",
    /* 125 */ "<UDF-125>",
    /* 126 */ "<UDF-126>",
    /* 127 */ "<UDF-127>",
    /* 128 */ "<UDF-128>"
    };


char* low_map[MAP_LEN + 1   ] = {
    /* 000 */ "<UDF-000>",
    /* 001 */ "<ESC>",
    /* 002 */ "1",
    /* 003 */ "2",
    /* 004 */ "3",
    /* 005 */ "4",
    /* 006 */ "5",
    /* 007 */ "6",
    /* 008 */ "7",
    /* 009 */ "8",
    /* 010 */ "9",
    /* 011 */ "0",
    /* 012 */ "-",
    /* 013 */ "=",
    /* 014 */ "<Backspace>",
    /* 015 */ "	", /* TAB */
    /* 016 */ "q",
    /* 017 */ "w",
    /* 018 */ "e",
    /* 019 */ "r",
    /* 020 */ "t",
    /* 021 */ "y",
    /* 022 */ "u",
    /* 023 */ "i",
    /* 024 */ "o",
    /* 025 */ "p",
    /* 026 */ "[",
    /* 027 */ "]",
    /* 028 */ "<Enter>",
    /* 029 */ "<L-Ctrl>",
    /* 030 */ "a",
    /* 031 */ "s",
    /* 032 */ "d",
    /* 033 */ "f",
    /* 034 */ "g",
    /* 035 */ "h",
    /* 036 */ "j",
    /* 037 */ "k",
    /* 038 */ "l",
    /* 039 */ ";",
    /* 040 */ "'",
    /* 041 */ "`",
    /* 042 */ "<L-Shift>",
    /* 043 */ "\\",
    /* 044 */ "z",
    /* 045 */ "x",
    /* 046 */ "c",
    /* 047 */ "v",
    /* 048 */ "b",
    /* 049 */ "n",
    /* 050 */ "m",
    /* 051 */ ",",
    /* 052 */ ".",
    /* 053 */ "/",
    /* 054 */ "<R-Shift>",
    /* 055 */ "*",
    /* 056 */ "<L-Alt>",
    /* 057 */ " ", /* Space */
    /* 058 */ "<Caps Lock>",
    /* 059 */ "<F1>",
    /* 060 */ "<F2>",
    /* 061 */ "<F3>",
    /* 062 */ "<F4>",
    /* 063 */ "<F5>",
    /* 064 */ "<F6>",
    /* 065 */ "<F7>",
    /* 066 */ "<F8>",
    /* 067 */ "<F9>",
    /* 068 */ "<F10>",
    /* 069 */ "<Num Lock>",
    /* 070 */ "<Scroll Lock>",
    /* 071 */ "<Home 7>",
    /* 072 */ "<Up 8>",
    /* 073 */ "<Page Up 9>",
    /* 074 */ "-",
    /* 075 */ "<Left 4>",
    /* 076 */ "<5>",
    /* 077 */ "<Right 6>",
    /* 078 */ "+",
    /* 079 */ "<End>",
    /* 080 */ "<Down 2>",
    /* 081 */ "<Page Down 3>",
    /* 082 */ "<Insert>",
    /* 083 */ "<Del>",
    /* 084 */ "<UDF-084>",
    /* 085 */ "<UDF-085>",
    /* 086 */ "<UDF-086>",
    /* 087 */ "<F11>",
    /* 088 */ "<F12>",
    /* 089 */ "<UDF-089>",
    /* 090 */ "<UDF-090>",
    /* 091 */ "<UDF-091>",
    /* 092 */ "<UDF-092>",
    /* 093 */ "<UDF-093>",
    /* 094 */ "<UDF-094>",
    /* 095 */ "<UDF-095>",
    /* 096 */ "<R-Enter>",
    /* 097 */ "<R-Ctrl>",
    /* 098 */ "/",
    /* 099 */ "<Print Screen>",
    /* 100 */ "<R-Alt>",
    /* 101 */ "<UDF-101>",
    /* 102 */ "<Home>",
    /* 103 */ "<Up>",
    /* 104 */ "<Page Up>",
    /* 105 */ "<Left>",
    /* 106 */ "<Right>",
    /* 107 */ "<End>",
    /* 108 */ "<Down>",
    /* 109 */ "<Page Down>",
    /* 110 */ "<Insert>",
    /* 111 */ "<Del>",
    /* 112 */ "<UDF-112>",
    /* 113 */ "<UDF-113>",
    /* 114 */ "<UDF-114>",
    /* 115 */ "<UDF-115>",
    /* 116 */ "<UDF-116>",
    /* 117 */ "<UDF-117>",
    /* 118 */ "<UDF-118>",
    /* 119 */ "<Pause>",
    /* 120 */ "<UDF-120>",
    /* 121 */ "<UDF-121>",
    /* 122 */ "<UDF-122>",
    /* 123 */ "<UDF-123>",
    /* 124 */ "<UDF-124>",
    /* 125 */ "<UDF-125>",
    /* 126 */ "<UDF-126>",
    /* 127 */ "<UDF-127>",
    /* 128 */ "<UDF-128>"
    };

#endif