
// Imports
#include "FastLED.h" // communication with the LED Hexagon
#include <stdlib.h>  // to generate random numbers

// Definitions
#define NUM_LEDS   37 // number of LEDs of the Hexagon
#define BRIGHTNESS 30 // maximal brightness (for development low: 10 - max is 255)
#define DATA_PIN    6

// Variables
CRGB leds[NUM_LEDS];  // define list of LEDs
int rn = 0;           // random number variable

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
  for( int ii = 0; ii < NUM_LEDS; ++ii) {
    leds[ii] = CRGB::Black;
  }
  FastLED.show();
}

// Even LEDs are green, odd LEDs are Red or Yellow or Blue
void xmasTree(){
  for( int ii = 0; ii < NUM_LEDS; ++ii) {
    if (ii % 2 == 0){
      leds[ii] = CRGB::Green;
    } else{
      rn = rand();
      rn = rn % 3;
      if (rn == 0){
        leds[ii] = CRGB::Red;
      }else if (rn == 1){
        leds[ii] = CRGB::Yellow;
      }else{
        leds[ii] = CRGB::Blue;
      }
    }
   }
   FastLED.show();
   delay(300); 
}

// timer 
unsigned long timingInfo;

// Star
int star_a[] = { 0,3,5,7,11,12,15,16,17,18,19,20,21,24,25,29,31,33,36 };
int star_a_len = 19;

// innerHEx
int innerHEx[] = { 5,7,16,18,20,29,31 };
int innerHEx_len = 7;

// tree
//int tree[] = { 14,27,4,9,15,22,28,16,2,6,11,17,24,30,35,12,18,25,0,33,10,23 };
int tree[] = { 14,27,36,31,25,18,12,7,3,19,34,29,23,16,10,5,1,17,9,15,22,11,24,13,26,20,21,8,32 };
int tree_len = 29;

// ak
int ak[] = { 15,9,10,17,23,22,1,2,5,7,11,12,13,14,19,21,26,27,24,25,29,31,34,35 };
int ak_len = 24;

// green
int green[] = { 0,4,3,8,32,36,33,28,18 };
int green_len = 9;

// snowFlake
int snowFlake[] = { 15,16,17,18,19,20,21,0,5,11,12,7,3,33,29,24,25,31,36 };
int snowFlake_len = 19;
int snowFlakeSPikes[]  = { 4,1,14,27,28,34 };
int snowFlakeSPikes2[] = { 2,8,32,35,9,22 };
int snowFlakeSPikes_len = 6;

void star_1(){
  for( int ii = 0; ii < star_a_len; ++ii) {
    leds[star_a[ii]] = CRGB::Yellow;
  }
  FastLED.show();
}

void xmaxballs(){
  for( int ii = 0; ii < NUM_LEDS; ++ii) {
    leds[ii] = CRGB::Green;
  }
  for( int ii = 0; ii < innerHEx_len; ++ii) {
    rn = rand();
      rn = rn % 3;
      if (rn == 0){
        leds[innerHEx[ii]] = CRGB::Red;
      }else if (rn == 1){
        leds[innerHEx[ii]] = CRGB::Yellow;
      }else{
        leds[innerHEx[ii]] = CRGB::Blue;
      }
  }
  FastLED.show();
  delay(300); 
}

void tannenbaum(){
  for( int ii = 0; ii < tree_len; ++ii) {
    leds[tree[ii]] = CRGB::Green;
  }
  leds[15] = CRGB::Yellow;
  FastLED.show();
}

void advendskranz(){
  // red candles and green
  for( int ii = 0; ii < ak_len; ++ii) {
    leds[ak[ii]] = CRGB::Red;
    leds[ak[ii]].fadeToBlackBy(235);
  }
  for( int ii = 0; ii < green_len; ++ii) {
    leds[green[ii]] = CRGB::Green;
    leds[green[ii]].fadeToBlackBy(235);
  }

  // flames
  leds[6] = CRGB::Yellow;
  leds[6].fadeToBlackBy(rand() % 255);
  
  leds[16] = CRGB::Yellow;
  leds[16].fadeToBlackBy(rand() % 255);

  leds[20] = CRGB::Red;
  leds[20].fadeToBlackBy(235);
  leds[30] = CRGB::Red;
  leds[30].fadeToBlackBy(235);

  FastLED.show();

  delay(rand() % 50 + 50);
}

void bigCandle(){
   for( int ii = 0; ii < NUM_LEDS; ++ii) {
    leds[ii] = CRGB::Yellow;
    leds[ii].fadeToBlackBy(rand() % 255);
  }
  FastLED.show();
  delay(rand() % 100 + 50);
}

void showSnowFlake(){
  for( int ii = 0; ii < snowFlake_len; ++ii) {
    leds[snowFlake[ii]] = CRGB::Yellow;
    leds[snowFlake[ii]].fadeToBlackBy(rand() % 128);
  }
  timingInfo = int(millis() / 1000);
  if ((timingInfo % 2) == 0){
    for( int ii = 0; ii < snowFlakeSPikes_len; ++ii) {
      leds[snowFlakeSPikes[ii]] = CRGB::Yellow;
      leds[snowFlakeSPikes[ii]].fadeToBlackBy(rand() % 200);
    }
    for( int ii = 0; ii < snowFlakeSPikes_len; ++ii) {
      leds[snowFlakeSPikes2[ii]] = CRGB::Black;
      leds[snowFlakeSPikes2[ii]].fadeToBlackBy(rand() % 200);
    }
  }else{
    for( int ii = 0; ii < snowFlakeSPikes_len; ++ii) {
      leds[snowFlakeSPikes[ii]] = CRGB::Black;
      leds[snowFlakeSPikes[ii]].fadeToBlackBy(rand() % 200);
    }
    for( int ii = 0; ii < snowFlakeSPikes_len; ++ii) {
      leds[snowFlakeSPikes2[ii]] = CRGB::Yellow;
      leds[snowFlakeSPikes2[ii]].fadeToBlackBy(rand() % 200);
    }
  }
  FastLED.show();
  delay(rand() % 100 + 50);
  
}

// ##################
// LOOP
// ##################
void loop() { 
  //xmasTree();
  //star_1();
  //xmaxballs();
  //tannenbaum();
  //advendskranz();
  //showSnowFlake();
}
