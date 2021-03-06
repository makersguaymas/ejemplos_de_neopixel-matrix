#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 6

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_GRBW    Pixels are wired for GRBW bitstream (RGB+W NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
int brightness = 85;
bool maxBright = false;
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8,8, PIN,NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS ,NEO_GRB + NEO_KHZ800);

const uint16_t baseColor = matrix.Color(255,255,255);
const uint16_t morado = matrix.Color(185,34,186);
const uint16_t magenta = matrix.Color(294,0,102);
const uint16_t violeta = matrix.Color(153, 0, 76);

const uint16_t gamaAmarilla[] = {
  matrix.Color(255,134,42), matrix.Color(209,134,42), matrix.Color(165,134,42),matrix.Color(150,134,42), matrix.Color(127,134,42), matrix.Color(113,134,42)    
};

const uint16_t rojo = matrix.Color(231,34,45);
const uint16_t verde = matrix.Color(47,168,40);
const uint16_t lila = matrix.Color(116,115,233);
const uint16_t rosa = matrix.Color(254,74,232);
const uint16_t amarillo = matrix.Color(157,162,29);
const uint16_t aqua = matrix.Color(0,252,191);

const uint16_t colores[] = {
  rojo, verde, aqua, rosa, amarillo, lila
};

//from top
int top = 0;
int left= 0;

//from bottom
int bottom = 7;
int right = 7;

//routines
int routine = 0;

//reverse
bool reverse = false;


void setup() {
  matrix.begin();
  matrix.setBrightness(brightness);
}



void loop() {

  int indexRandom = random(0,6);
  if(!reverse){
    
      //filas
      for(int i = right; i > -1; i--){
        //columnas
      
        
        for(int y = bottom; y > -1; y--){
            matrix.drawPixel(i, y, colores[indexRandom]);
            matrix.show();
            delay(30);
            //centro de neopixel
            /***
            if((i > 0 && i < 4) && (y > 1 && y < 6)){
                matrix.drawPixel(i, y, baseColor);
                matrix.show();
                
            }*/
        }
      }
       
      delay(20);

      brightness= 0;
      matrix.setBrightness(brightness);

      delay(5);
      brightness= 85;
      matrix.setBrightness(brightness);

      reverse = true;
  }else{
    //filas
      
      for(int i = left; i < 8; i++){
        //columnas
       
        for(int y = top; y < 8; y++){
            matrix.drawPixel(i, y, colores[indexRandom]);
            matrix.show();
            delay(30);
            //centro de neopixel
            /**
            if((i > 0 && i < 4) && (y > 1 && y < 6)){
                matrix.drawPixel(i, y, baseColor);
                matrix.show();
                
            }*/
        }
      }
      
      delay(20);

      brightness= 0;
      matrix.setBrightness(brightness);

      delay(5);
      brightness= 85;
      matrix.setBrightness(brightness);

      reverse = false;
  }

      
      
     
}
