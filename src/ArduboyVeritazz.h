#ifndef ArduboyVeritazz_h
#define ArduboyVeritazz_h

#include "ArduboyCoreVeritazz.h"
#include <limits.h>

// Library version.
// For a version number in the form of x.y.z the value of the define will be
// ((x * 10000) + (y * 100) + (z)) as a decimal number.
// So, it will read as xxxyyzz, with no leading zeros on x.
#define ARDUBOY_LIB_VER 10200

// EEPROM settings
#define EEPROM_VERSION 0
#define EEPROM_BRIGHTNESS 1
#define EEPROM_AUDIO_ON_OFF 2

// we reserve the first 16 byte of EEPROM for system use
#define EEPROM_STORAGE_SPACE_START 16 // and onward

#define PIXEL_SAFE_MODE

// pixel colors
#define INVERT 2 //< lit/unlit pixel
#define WHITE 1 //< lit pixel
#define BLACK 0 //< unlit pixel

#ifndef HOST_TEST
// compare Vcc to 1.1 bandgap
#define ADC_VOLTAGE (_BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1))
// compare temperature to 2.5 internal reference and _BV(MUX5)
#define ADC_TEMP (_BV(REFS0) | _BV(REFS1) | _BV(MUX2) | _BV(MUX1) | _BV(MUX0))
#endif

class ArduboyVeritazz : public ArduboyCoreVeritazz
{
public:
  ArduboyVeritazz();

  /// Initialize hardware, boot logo, boot utilities, etc.
  void begin();

  /// Init just hardware, no logo, no boot utilities.
  /**
   * Look at the source for `begin()` and just rip out what you do not
   * need and start there.  Calling just `boot()` might work also
   * depending on your requirements.
   *
   * The minimum recommended `begin` replacement:
   *
   *   arduboy.boot()         // raw hardware init
   *   arduboy.audio.begin()  // if you need audio
   */

  /// Flashlight mode
  /**
   * Hold up key when booting to enable, press down key to exit
   * or simply turn off your ArduboyVeritazz.  Your sketches can also
   * call this at any time.  It goes into a tight loop until the
   * down buttn is pressed.
   */
  void doNothing();

  /// Clears display.
  void clear();

  /// Copies the contents of the screen buffer to the screen.
  /**
   * X and Y positions on the display are from the top left corner, thus a Y of 64
   * is the bottom of the screen and an X of 128 is the right side of the screen.
   * "Color" or "value" means choosing whether a pixel is lit or not - if color is
   * 0, the pixel is off (black), if color is 1, the pixel is on (white).
   */
  void display();

  /// Sets a single pixel on the screen buffer to white or black.
  void drawPixel(int x, int y, uint8_t color);

  uint8_t getPixel(uint8_t x, uint8_t y);

  /// Draw a circle of a defined radius.
  /**
   * Draws a circle in white or black. X and Y are the center point of the circle.
   */
  void drawCircle(int16_t x0, int16_t y0, uint8_t r, uint8_t color);

  /// Draws one or more "corners" of a circle.
  void drawCircleHelper(int16_t x0, int16_t y0, uint8_t r, uint8_t cornername, uint8_t color);

  /// Draws a filled-in circle.
  void fillCircle(int16_t x0, int16_t y0, uint8_t r, uint8_t color);

   /// Draws one or both vertical halves of a filled-in circle.
  void fillCircleHelper(int16_t x0, int16_t y0, uint8_t r, uint8_t cornername, int16_t delta, uint8_t color);

  /// Draws a line between two points.
  /**
   * Uses Bresenham's algorithm.
   */
  void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color);

  /// Draws a rectangle of a width and height.
  void drawRect(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t color);

  /// Draws vertical line.
  void drawFastVLine(int16_t x, int16_t y, uint8_t h, uint8_t color);

  /// Draws a horizontal line.
  void drawFastHLine(int16_t x, int16_t y, uint8_t w, uint8_t color);

  /// Draws a filled-in rectangle.
  void fillRect(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t color);

  /// Fills the screen buffer with white or black.
  void fillScreen(uint8_t color);

  /// Draws a rectangle with rounded edges.
  void drawRoundRect(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t r, uint8_t color);

  /// Draws a filled-in rectangle with rounded edges.
  void fillRoundRect(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t r, uint8_t color);

   /// Draws the outline of a triangle.
  void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t color);

  /// Draws a filled-in triangle.
  void fillTriangle (int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t color);

  /// Draws a bitmap from program memory to a specific X/Y
  void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, uint8_t w, uint8_t h, uint8_t color);

  /// Draws images that are bit-oriented horizontally.
  /**
   * This requires a lot of additional CPU power and will draw images slower
   * than drawBitmap, where the images are stored in a format that
   * allows them to be directly written to the screen. It is
   * recommended you use drawBitmap when possible.
   */
  void drawSlowXYBitmap(int16_t x, int16_t y, const uint8_t *bitmap, uint8_t w, uint8_t h, uint8_t color);

  unsigned char* getBuffer();


  /// Seeds the random number generator with entropy from the temperature, voltage reading, and microseconds since boot.
  /**
   * This method is still most effective when called semi-randomly such
   * as after a user hits a button to start a game or other semi-random
   * events
   */
  void initRandomSeed();

  /// Swap the references of two pointers.
  void swap(int16_t& a, int16_t& b);

  void setFrameRate(uint8_t rate);
  uint8_t nextFrame();
  uint8_t everyXFrames(uint8_t frames);

  /// Returns the load on the CPU as a percentage.
  /**
   * This is based on how much of the time your app is spends rendering
   * frames.  This number can be higher than 100 if your app is rendering
   * really slowly.
   */
  int cpuLoad();

  uint8_t frameRate;
  uint16_t frameCount;
  uint8_t eachFrameMillis;
  long lastFrameStart;
  long nextFrameStart;
  uint8_t post_render;
  uint8_t lastFrameDurationMs;

  /// useful for getting raw approximate voltage values
  uint16_t rawADC(uint8_t adc_bits);

	/* simple buttons */
	void poll();
	uint8_t pressed(uint8_t buttons);
	uint8_t notPressed(uint8_t buttons);
	uint8_t justReleased(uint8_t button);
	uint8_t justPressed(uint8_t button);

	// returns true if button is current depressed
	uint8_t up();
	uint8_t down();
	uint8_t right();
	uint8_t left();
	uint8_t a();
	uint8_t b();

	// returns true if button is was just pressed (previously unpressed)
	uint8_t pressedUp();
	uint8_t pressedDown();
	uint8_t pressedRight();
	uint8_t pressedLeft();
	uint8_t pressedA();
	uint8_t pressedB();


private:
	uint8_t currentButtonState = 0;
	uint8_t previousButtonState = 0;

protected:
  unsigned char sBuffer[(HEIGHT*WIDTH)/8];


protected:
  int16_t cursor_x;
  int16_t cursor_y;
  uint8_t textsize;
  uint8_t wrap; // If set, 'wrap' text at right edge of display
};

#endif
