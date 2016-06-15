#include <Arduino.h>
#include "VeritazzExtra.h"
#include "images.h"

VeritazzExtra arduboy(l1_table);


/*---------------------------------------------------------------------------
 * setup
 *---------------------------------------------------------------------------*/
void
setup(void)
{
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

	arduboy.display();
}
