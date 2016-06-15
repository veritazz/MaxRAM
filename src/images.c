#include <Arduino.h>
#include <stdint.h>

const uint8_t l1_table[12] = {
	0x00, 0x01, 0x40, 0xff, 0x10, 0x08, 0x80, 0x04, 0x20, 0xc0, 0x07, 0x03,
};

const uint8_t arduboy_logo_img[146] PROGMEM = {
	0x58, /* width */
	0x10, /* height */
	0x04, 0x80,
/* [0]
 * ____***_______*******______*******_____**_______**___*******________*****_____**______**
 * ___*****_____*********____*********____**_______**__*********______*******____**______**
 * __***_***____**_____***___**_____***___**_______**__**_____***____***___***___**______**
 * _***___***___**______***__**______***__**_______**__**______***__***_____***__**______**
 * ***_____***__**_______**__**_______**__**_______**__**_______**__**_______**__**______**
 * **_______**__**_______**__**_______**__**_______**__**______***__**_______**__***____***
 * **_______**__**_______**__**_______**__**_______**__**_____***___**_______**___***__***_
 * ***********__**_______**__**_______**__**_______**__*********____**_______**____******__
 * ***********__**______***__**_______**__**_______**__*********____**_______**_____****___
 * **_______**__**_____***___**_______**__**_______**__**_____***___**_______**______**____
 * **_______**__*********____**_______**__**_______**__**______***__**_______**______**____
 * **_______**__********_____**_______**__**_______**__**_______**__**_______**______**____
 * **_______**__**____***____**______***__***_____***__**______***__***_____***______**____
 * **_______**__**_____***___**_____***____***___***___**_____***____***___***_______**____
 * **_______**__**______***__*********______*******____*********______*******________**____
 * **_______**__**_______**___*******________*****______*******________*****_________**____
 */
	0xc0, 0xbf, 0x0f, 0x89, 0xc8, 0xe8, 0x78, 0x38, 0x78, 0xe9, 0xcf, 0x8f,
	0x00, 0x0f, 0xfe, 0x3d, 0x05, 0xba, 0xc0, 0x30, 0xef, 0xcf, 0x80, 0x0f,
	0xfe, 0x3d, 0x05, 0xba, 0xc0, 0x30, 0xef, 0xcf, 0x80, 0x03, 0x3d, 0x07,
	0x03, 0x30, 0x0f, 0xfe, 0x3e, 0x05, 0x83, 0xc0, 0x4c, 0x7e, 0xe7, 0xc3,
	0x80, 0x0c, 0x03, 0xf8, 0xfc, 0x0e, 0xab, 0xbb, 0xac, 0x03, 0x0e, 0xfc,
	0xf8, 0x00, 0xc0, 0x33, 0xf7, 0xfe, 0x09, 0x66, 0x9c, 0x03, 0xe0, 0x7f,
	0x3f, 0x33, 0xd0, 0x71, 0x33, 0x00, 0x33, 0xe0, 0x40, 0xcc, 0x05, 0x1c,
	0x3e, 0x77, 0xe3, 0xc1, 0x00, 0xf7, 0xf3, 0xd0, 0x59, 0xc0, 0x4e, 0x07,
	0x03, 0xf1, 0xf0, 0x0c, 0x04, 0x1f, 0x3f, 0x70, 0xe0, 0x99, 0x9c, 0x04,
	0xe0, 0x70, 0x3f, 0x1f, 0x00, 0xf7, 0xf3, 0xe0, 0x5c, 0x1c, 0x04, 0xe3,
	0x77, 0x3e, 0x1c, 0x00, 0xc0, 0x41, 0xf3, 0xf7, 0x0e, 0x09, 0x99, 0xc0,
	0x4e, 0x07, 0x03, 0xf1, 0xfd, 0x05, 0x01, 0x33, 0x10, 0x00,
};
