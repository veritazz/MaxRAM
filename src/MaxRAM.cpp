#include <Arduino.h>
#include "VeritazzExtra.h"
#include "images.h"

VeritazzExtra arduboy(l1_table);

static uint8_t huge[1024];

/*---------------------------------------------------------------------------
 * setup
 *---------------------------------------------------------------------------*/
void
setup(void)
{
	memset(huge, 0, sizeof(huge));
	arduboy.initRandomSeed();
	arduboy.begin();
}

/*---------------------------------------------------------------------------
 * loop
 *---------------------------------------------------------------------------*/
void
loop(void)
{
	if (arduboy.nextFrame()) {
		arduboy.poll();
		arduboy.clear();
	} else
		return;

	memset(huge, 0, sizeof(huge));

	arduboy.display();
}
