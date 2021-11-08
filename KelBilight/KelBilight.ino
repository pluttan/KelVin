#include <Adafruit_NeoPixel.h>

//constants
#define r1 15 //number of pixels in the first/the third row
#define r2 14 //number of pixels in the second/the fourth row

uint32_t mas[r1*2+r2*2]={(0)*r1*2+r2*2};
int k=0;
uint8_t gap[2]{0,0};
uint8_t mode=0;
bool fl_of_st=false;
int rgb[3];

//pin
#define strip_pin 6

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

Adafruit_NeoPixel strip(r1*2+r2*2, strip_pin, NEO_RGB + NEO_KHZ800);

void setup(){
    strip.begin();
    strip.setBrightness(50);
    digitalWrite(2,HIGH);
    Serial.begin(9600);
};

void loop(){
    stepp(15);
    CL("Yellow");
    EF_blightness(5);
    strip.show();
    delay(100);
};


void step(uint8_t start, uint8_t end){
    gap[0]=start;
    gap[1]=end;
};
void stepp(uint8_t step){
    gap[0]=gap[1];
    gap[1]=step+gap[0];
};
void colorConverter(uint32_t color)
{
    rgb[0]=color/(65536);
  	rgb[1]=(color%(65536)-color%(256))/(256);
  	rgb[2]=color%(256); 
};