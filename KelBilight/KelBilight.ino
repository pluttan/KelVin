#include <Adafruit_NeoPixel.h>

//constants
#define r1 300 //number of pixels in the first/the third row
#define r2 300 //number of pixels in the second/the fourth row

uint32_t mas[r1*2+r2*2];

//pin
#define strip_pin 3

// -----plan of your room-----
//             r2 s
//   |-------------------|
//   |                  n|
// r1|                   |r1
//  r|                   |l
//   |                   |
//   |-------------------|
//             r2 f 
//
//  n-the start/end of the tape 

Adafruit_NeoPixel strip(r1*2+r2*2, strip_pin, NEO_GRB + NEO_KHZ800);

void setup(){
    strip.begin();
    strip.setBrightness(1);
    digitalWrite(2,HIGH);
    Serial.begin(9600);
};

void loop(){
    CL_White();
    int gap[2]{0,r1};
    print(gap);
        
};

void print(int *gap){
    int start=gap[0];
    int end=gap[1];
    for (int c = start; c < end; c++)
    {
        strip.setPixelColor(c, mas[c]);
    }
    strip.show();
}
