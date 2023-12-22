#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define LED_COUNT 200
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

//MAX_X and MAX_Y represent the largest X and Y value from the table of Positions
//This is used to derive where the middle of the tree is in the X and Y direction.
//For example if MAX_X = 20, then LEDs at a position of 10 would be the middle of
//the tree.
#define MAX_X 16
#define MAX_Y 28

//Define the X,Y positions of each pixel.  The first array element is the X 
//coordinate of the first LED in the string, the second array element is the
//Y coordinate of the first LED.   The third array element is the X position of
//the second LED, etc...
byte Positions[LED_COUNT*2] =
{        
11, 12, 10, 24, 13, 24, 13, 23, 15, 21, 14, 22, 13, 22, 15, 23,
16, 22, 15, 24, 13, 26, 12, 26, 9, 24, 9, 27, 6, 25, 7, 27, 5,
27, 3, 26, 2, 26, 2, 24, 2, 24, 1, 24, 1, 22, 1, 23, 3, 22, 3,
22, 1, 22, 3, 23, 2, 23, 5, 23, 3, 23, 5, 25, 6, 22, 8, 24, 8,
25, 10, 24, 12, 23, 13, 22, 13, 21, 13, 23, 14, 22, 16, 22, 15,
22, 16, 23, 16, 23, 15, 23, 16, 22, 15, 23, 14, 24, 13, 24, 13,
24, 13, 23, 14, 22, 12, 22, 11, 22, 11, 22, 9, 22, 7, 22, 7, 21,
6, 20, 4, 20, 4, 21, 3, 19, 3, 20, 3, 19, 3, 19, 1, 20, 4, 21,
5, 20, 6, 19, 7, 19, 8, 20, 10, 18, 11, 20, 12, 18, 12, 18,
14, 19, 13, 16, 13, 17, 15, 18, 14, 18, 14, 20, 14, 19, 13, 18,
13, 17, 12, 19, 11, 20, 10, 19, 8, 21, 8, 21, 7, 20, 5, 20, 5,
20, 4, 18, 6, 17, 5, 17, 5, 17, 5, 17, 5, 17, 5, 18, 7, 14, 7,
15, 8, 14, 8, 16, 9, 15, 12, 16, 11, 15, 12, 16, 13, 16, 13,
16, 13, 16, 14, 15, 13, 14, 13, 16, 13, 14, 11, 15, 11, 15, 
9, 15, 8, 16, 7, 16, 5, 15, 4, 15, 5, 15, 4, 14, 4, 13, 5, 
12, 6, 13, 6, 13, 7, 12, 9, 12, 10, 13, 11, 13, 12, 13, 13, 
12, 12, 13, 13, 13, 13, 13, 11, 12, 13, 12, 10, 13, 11, 11, 
9, 12, 8, 13, 6, 12, 6, 12, 5, 13, 4, 12, 5, 11, 6, 10, 6, 9, 
7, 9, 8, 10, 11, 9, 10, 9, 11, 8, 12, 9, 12, 10, 12, 10, 12, 
10, 12, 8, 10, 9, 9, 8, 9, 9, 8, 9, 6, 8, 6, 9, 6, 7, 7, 8, 8, 6, 
9, 6, 9, 5, 11, 5, 12, 7, 11, 7, 10, 6, 10, 7, 8, 7, 7, 7, 8, 5, 
6, 6, 5, 6, 6, 6, 6, 6, 6, 5, 6, 3, 8, 2, 10, 4, 9, 5, 11, 4, 11, 
5, 10, 5, 9, 4, 8, 3, 7, 4, 7, 4, 7, 3, 7, 2, 8, 1, 9, 2, 9, 2
};

/******************************************************/
void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(100);
  strip.show(); // Initialize all pixels to 'off'
  /*
  BLUE = strip.Color(0,0,200)
  YELLOW = strip.Color(200,200,0)
  RED = strip.Color(0,200,0)
  GREEN = strip.Color(200,0,0)
  ORANGE = strip.Color(100,200,0)
  PURPLE = strip.Color(0,200,200)
  IDK = strip.Color(200,0,200)
  WHITE = strip.Color(200,200,200)
  */
  
}
/******************************************************/
void loop() {
  solid(strip.Color(0,0,0));
  while (true)
  {

    //Serial.println("vertStripes");
    //vertStripes(strip.Color(100,100,100),strip.Color(0,255,0),5000);
    /* UnComment the following block if you are going to calculate
       LED Positions.   Extend and add calls as necessary to match
       your LED count.   
    Serial.println("GetLocation");
    getLocation(0);  //LEDs 0-9
    getLocation(1);  //LEDs 10-19
    getLocation(2);  //LEDs 20-29
    getLocation(3);  //LEDs 30-39
    getLocation(4);  //LEDs 40-49    
    delay(3000);
    */
    /*
    Serial.println("Solid2");
    two_solid(strip.Color(0,255,0),strip.Color(255,255,255)); 
    delay(3000);
    */
    

    Serial.println("WipeShow");
    wipeShow(2);
    
    Serial.println("DissolveShow");
    dissolveShow(1000);
 
   /*
    Serial.println("Fade");
    fade(strip.Color(0,0,0),strip.Color(255,255,0),5000);
    delay(3000);
    
    Serial.println("HorizWipe");
    horizWipe(false,strip.Color(255,0,0),strip.Color(0,0,255),5000);

    
    Serial.println("centerHorizWipe");
    centerHorizWipe(strip.Color(0,0,255),strip.Color(255,0,0),5000);

    Serial.println("vertWipe");
    vertWipe(false,strip.Color(255,0,0),strip.Color(0,0,255),5000);

    Serial.println("vertWipe");
    vertWipe(false,strip.Color(100,100,100),strip.Color(255,0,0),5000);


    Serial.println("vertStripes");
    vertStripes(strip.Color(0,255,0),strip.Color(100,100,100),5000);
    
    Serial.println("vertLine");
    vertLine(false,strip.Color(255,0,0),strip.Color(100,100,100),5000);

    Serial.println("vertLine");
    vertLine(false,strip.Color(0,255,0),strip.Color(100,100,100),5000);

    Serial.println("vertLine");
    vertLine(false,strip.Color(0,0,255),strip.Color(100,100,100),5000);
    
    Serial.println("vertWave");
    vertWave(strip.Color(0,255,0),strip.Color(255,0,0),150,5000);

    */

    /*
    Serial.println("vertCenterWave");
    vertCenterWave(strip.Color(255,255,0),strip.Color(0,255,255),150,5000); 
    delay(3000);
    
    Serial.println("transition");
    transition(strip.Color(255,0,0),strip.Color(0,255,0)); 
    delay(3000);
    
    Serial.println("setBlock");
    setBlock(3,strip.Color(255,255,255));
    delay(3000);
    
    
          */  
          
  }
}
/*******************************************************/
uint32_t colorSlope(uint32_t c1, uint32_t c2, float percent)
{
  uint32_t temp_color, temp_c1_component, temp_c2_component;
  
     temp_color = 0;
     temp_c1_component = (c1 & 0x00ff0000) >> 16;
     temp_c2_component = (c2 & 0x00ff0000) >> 16;
     temp_color = uint32_t(temp_c1_component + (float(temp_c2_component) - float(temp_c1_component)) * percent);
     temp_color = temp_color << 8;

     temp_c1_component = (c1 & 0x0000ff00) >> 8;
     temp_c2_component = (c2 & 0x0000ff00) >> 8;
     temp_color += uint32_t(temp_c1_component + (float(temp_c2_component) - float(temp_c1_component)) * percent);
     temp_color = temp_color << 8;
     
     temp_c1_component = (c1 & 0x000000ff);
     temp_c2_component = (c2 & 0x000000ff);
     temp_color += uint32_t(temp_c1_component + (float(temp_c2_component) - float(temp_c1_component)) * percent);
  
  return temp_color;
}
/*******************************************************/
void solid(uint32_t color)
{
  for(uint16_t i=0; i<strip.numPixels(); i++)
  { strip.setPixelColor(i,color); }
     
  strip.show();    
}
/*******************************************************/
void two_solid(uint32_t color_1, uint32_t color_2)
{
  for(uint16_t i=0; i<strip.numPixels(); i++)
  { if (i % 2 == 0)
      {strip.setPixelColor(i,color_1);}
    else  
      {strip.setPixelColor(i,color_2);}    
  }
     
  strip.show();    
}
/*******************************************************/
void dissolve(uint32_t c_from, uint32_t c_to, uint32_t duration)
{
   uint32_t elapsed_time = 0;
   uint32_t tick = duration/(strip.numPixels()+50);
   bool temp[strip.numPixels()];
   int  rand;
   
   for(uint16_t j=0; j<strip.numPixels(); j++)
   { temp[j] = false;
     strip.setPixelColor(j,c_from);
   }
   
   while (elapsed_time < duration)
   {
     rand = random(strip.numPixels());
     if (temp[rand])
     { rand = random(strip.numPixels());
       if (temp[rand])
       {
         for(uint16_t i=0; i<strip.numPixels(); i++)
         { if (!temp[i]) {rand=i; i = 999;} }
       }
     }
     temp[rand] = true;
     strip.setPixelColor(rand,c_to);
     strip.show();     
     delay(tick); 
     
     elapsed_time += tick+5;     
   }
   
   for(uint16_t j=0; j<strip.numPixels(); j++)
   { strip.setPixelColor(j,c_to);}
   strip.show();
      
} //dissolve
/*******************************************************/
// Transition all lights from color c_from to color c_to
void fade(uint32_t c_from, uint32_t c_to, uint32_t duration)
{
   uint32_t elapsed_time = 0;
   uint32_t temp_color;
   
 
   while (elapsed_time < duration) 
   {
     temp_color = colorSlope(c_from,c_to,float(elapsed_time)/float(duration));

     for(uint16_t i=0; i<strip.numPixels(); i++)
     { strip.setPixelColor(i,temp_color); }
     
     strip.show();     
     delay(50); 
     elapsed_time += 55;
     
   }
   for(uint16_t i=0; i<strip.numPixels(); i++)
     { strip.setPixelColor(i,c_to); }
   strip.show();
      
} //fade
/***********************************************************/
// Transition of colors
void transition(uint32_t c_top, uint32_t c_bottom)
{
   uint32_t elapsed_time = 0;
   uint32_t temp_color;
   
   for(uint16_t i=0; i<strip.numPixels(); i++)
     { temp_color = colorSlope(c_top,c_bottom,float(Positions[i*2+1])/float(MAX_Y));        
       strip.setPixelColor(i,temp_color); }
     
   strip.show();     
   delay(50); 
      
} //Transition of colors
/***********************************************************/
// Horiz Wipe from color c_from to color c_to
void horizWipe(boolean left_to_right, uint32_t c_wipe, uint32_t c_orig, uint32_t duration)
{
   uint32_t elapsed_time = 0;
   uint32_t X_temp;
   
 
   while (elapsed_time < duration) 
   {
     //Locate the wipe X
     X_temp = (uint32_t)(float(elapsed_time)/float(duration)*float(MAX_X));
      
    
     for(uint16_t i=0; i<strip.numPixels(); i++)
     { if (left_to_right) 
          {if (Positions[i*2] < X_temp ) {strip.setPixelColor(i,c_wipe); } else {strip.setPixelColor(i,c_orig);   }}
       else
          {if (Positions[i*2] > MAX_X - X_temp ) {strip.setPixelColor(i,c_wipe); } else {strip.setPixelColor(i,c_orig);   }}       
     }
     strip.show();     
     delay(50); 
     elapsed_time += 55;     
   }
   for(uint16_t i=0; i<strip.numPixels(); i++)
     { strip.setPixelColor(i,c_wipe); }
   strip.show();
   
} //horizWipe
/***********************************************************/
// Horiz Wipe from color c_from to color c_to
void centerHorizWipe(uint32_t c_wipe, uint32_t c_orig, uint32_t duration)
{
   uint32_t elapsed_time = 0;
   uint32_t X_Lower,X_Upper;
   
 
   while (elapsed_time < duration) 
   {
     //Locate the wipe X
     X_Lower = (uint32_t)(float(MAX_X/2) - float(elapsed_time)/float(duration)*float(MAX_X)/2);
     X_Upper = (uint32_t)(float(MAX_X/2) + float(elapsed_time)/float(duration)*float(MAX_X)/2); 
    
     for(uint16_t i=0; i<strip.numPixels(); i++)
     { if (Positions[i*2] >= X_Lower && Positions[i*2] <= X_Upper )
           {strip.setPixelColor(i,c_wipe); } 
       else 
           {strip.setPixelColor(i,c_orig);   }
     }
     strip.show();     
     delay(50); 
     elapsed_time += 55;     
   }
   for(uint16_t i=0; i<strip.numPixels(); i++)
     { strip.setPixelColor(i,c_wipe); }
   strip.show();
} //horizWipe
/***********************************************************/
// Vert Wipe from color c_from to color c_to
void vertWipe(boolean bottom_to_top, uint32_t c_wipe, uint32_t c_orig, uint32_t duration)
{
   uint32_t elapsed_time = 0;
   uint32_t Y_temp;
   
 
   while (elapsed_time < duration) 
   {
     //Locate the wipe Y
     Y_temp = (uint32_t)(float(elapsed_time)/float(duration)*float(MAX_Y));
      
    
     for(uint16_t i=0; i<strip.numPixels(); i++)
     { if (bottom_to_top) 
          {if (Positions[i*2+1] < Y_temp ) {strip.setPixelColor(i,c_wipe); } else {strip.setPixelColor(i,c_orig);   }}
       else
          {if (Positions[i*2+1] > MAX_Y - Y_temp ) {strip.setPixelColor(i,c_wipe); } else {strip.setPixelColor(i,c_orig);   }}       
     }
     strip.show();     
     delay(50); 
     elapsed_time += 55;     
   }
   for(uint16_t i=0; i<strip.numPixels(); i++)
     { strip.setPixelColor(i,c_wipe); }
   strip.show();
      
} //vertWipe
/*******************************************************/
// Vert Line across from color c_from to color c_to
void vertLine(boolean bottom_to_top, uint32_t c_wipe, uint32_t c_orig, uint32_t duration)
{
   uint32_t elapsed_time = 0;
   uint32_t Y_temp;
   
 
   while (elapsed_time < duration) 
   {
     //Locate the wipe Y
     Y_temp = (uint32_t)(float(elapsed_time)/float(duration)*float(MAX_Y));
      
    
     for(uint16_t i=0; i<strip.numPixels(); i++)
     { if (bottom_to_top) 
          {if (Positions[i*2+1] == Y_temp | Positions[i*2+1] == Y_temp+1) {strip.setPixelColor(i,c_wipe); } else {strip.setPixelColor(i,c_orig);   }}
       else
          {if (Positions[i*2+1] == MAX_Y - Y_temp | Positions[i*2+1] == MAX_Y - Y_temp+1 ) {strip.setPixelColor(i,c_wipe); } else {strip.setPixelColor(i,c_orig);   }}       
     }
     strip.show();     
     delay(50); 
     elapsed_time += 55;     
   }
} //vertWipe

void vertStripes(uint32_t c_wipe, uint32_t c_orig, uint32_t duration)
{
   uint32_t elapsed_time = 0;
   while (elapsed_time < duration) 
   {
     for(uint16_t i=0; i<strip.numPixels(); i++)
          {if (Positions[i*2+1] %4 == 0 | Positions[i*2+1] %4 == 1 | Positions[i*2+1] %4 == 2) {strip.setPixelColor(i,c_wipe); } else {strip.setPixelColor(i,c_orig);   }}

     strip.show();     
     delay(50); 
     elapsed_time += 55;     
   }
}
/*******************************************************/
// Lights up each light in the strip one-by-one, used to
// define pixel positions
void getLocation(uint32_t loc) {
  uint32_t signal = loc;
  
  for(uint16_t i=0; i<strip.numPixels();i++) {
    strip.setPixelColor(i,strip.Color(0,0,0)); 
  }
  
  while(signal > 0)
  {
    
    if (signal >= 10)
    { for(uint16_t i=0; i< 10; i++)
      {strip.setPixelColor(loc*10+i,strip.Color(255,0,0));}
      signal -= 10;
    }
    else
    { for(uint16_t i=0; i< 10; i++)
      {strip.setPixelColor(loc*10+i,strip.Color(255,255,255));}
      signal -= 1;
    }
  
    strip.show();
    delay(500);
    for(uint16_t i=0; i<strip.numPixels();i++) {
      strip.setPixelColor(i,strip.Color(0,0,0)); 
    }
    strip.show();
    delay(500); 
  } //while on signal
  
  for(uint16_t i=0; i < 10; i++)
  {
    strip.setPixelColor(loc*10+i,strip.Color(255,255,255));
    strip.show();
    delay(1000);
    strip.setPixelColor(loc*10+i,strip.Color(0,0,0));
    
    
    
  }
  
} //setupWipe()
/********************************************************/
void vertWave(uint32_t c1, uint32_t c2, uint32_t tick, uint32_t duration)
{
   uint32_t elapsed_time = 0;
   uint32_t ticker = 0;
   while (elapsed_time < duration)
   {
     for(uint16_t i=0; i < LED_COUNT; i++)
     {
       if ((Positions[i*2+1] / 4) % 4 == ticker % 4) 
          {strip.setPixelColor(i, c1);}
       else
          {strip.setPixelColor(i, c2);}
     }
     strip.show();     
     delay(tick);
     ticker++;
     elapsed_time += tick + 5;
   }  
} 
/********************************************************/
void vertCenterWave(uint32_t c1, uint32_t c2, uint32_t tick, uint32_t duration)
{
   uint32_t elapsed_time = 0;
   uint32_t ticker = 0;
   while (elapsed_time < duration)
   {
     for(uint16_t i=0; i < LED_COUNT; i++)
     {
       if (((abs(MAX_Y/2 - Positions[i*2+1]) / 3) % 3 == ticker % 3)) 
          {strip.setPixelColor(i, c1);}
       else
          {strip.setPixelColor(i, c2);}
     }
     strip.show();     
     delay(tick);
     ticker++;
     elapsed_time += tick + 5;
   }  
} 
/********************************************************/
void setBlock(uint32_t block, uint32_t c)
{
  uint32_t y_pos;
  
  for(uint16_t i=0; i<strip.numPixels();i++) {
    y_pos = Positions[i*2+1];    
      if (y_pos/(MAX_Y/6) == block)
        { strip.setPixelColor(i,c); } 
    }
    
  strip.show();
  
}
/********************************************************/
void shimmer(uint32_t c_base, uint32_t c_shimmer, uint32_t duration, uint32_t amount)
{
   uint32_t shimmer_pixel_num[amount];
   float    shimmer_pixel_percent[amount];
   uint32_t elapsed_time = 0;

   for(uint16_t i=0; i < amount; i++)
   { shimmer_pixel_num[i] = 0; }

   for(uint16_t i=0; i < strip.numPixels(); i++)
   { strip.setPixelColor(i,c_base);   }  
   
   while (elapsed_time < duration)
   {
     // See if we should start a shimmer
     for(uint16_t i=0; i < amount; i++)
     {
       if (shimmer_pixel_num[i] == 0 & random(10) > 8)
       { shimmer_pixel_num[i] = random(199) + 1;
         shimmer_pixel_percent[i] = 0.0;
       }
       if (shimmer_pixel_num[i] > 0)
       {
         if (i% 2 == 0)
         { shimmer_pixel_percent[i] += 0.02; }
         else
         { shimmer_pixel_percent[i] += 0.04; }
         if (shimmer_pixel_percent[i] >= 2.0)
         {
           strip.setPixelColor(shimmer_pixel_num[i],c_base);           
           shimmer_pixel_num[i] = 0; 
         }
         else
         {           
           strip.setPixelColor(shimmer_pixel_num[i],colorSlope(c_shimmer,c_base,abs(1.0 - shimmer_pixel_percent[i])));           
         }
       } 
     }
     
     strip.show();
     delay(50);
     elapsed_time += 50 + 5 ;
   }  
   
   for(uint16_t i=0; i < strip.numPixels(); i++)
   { strip.setPixelColor(i,c_base);   }  
   strip.show();
}

void dissolveShow(uint32_t length){

    Serial.println("Fade");
    fade(strip.Color(0,0,0),strip.Color(255,0,0),3000);
    
    Serial.println("Dissolve");
    dissolve(strip.Color(255,0,0),strip.Color(0,255,0),10000);

    Serial.println("Dissolve");
    dissolve(strip.Color(0,255,0),strip.Color(225,225,225),10000);

    Serial.println("Dissolve");
    dissolve(strip.Color(225,225,225),strip.Color(0,0,255),10000);

    Serial.println("Dissolve");
    dissolve(strip.Color(0,0,255),strip.Color(255,255,0),10000);

    Serial.println("Dissolve");
    dissolve(strip.Color(255,255,0),strip.Color(255,0,0),10000);

    Serial.println("Fade");
    fade(strip.Color(255,0,0),strip.Color(0,0,0),3000);
  
}

void wipeShow(uint32_t length){

    int time = 1000;

    //green to red
    Serial.println("vertWipe");
    vertWipe(false,strip.Color(200,0,0), strip.Color(0,200,0),time);
    //green to red
    Serial.println("vertWipe");
    vertWipe(false,strip.Color(200,200,0),strip.Color(200,0,0),time);
    //green to red
    Serial.println("vertWipe");
    vertWipe(false,strip.Color(0,0,200),strip.Color(200,200,0),time);
    Serial.println("vertWipe");
    vertWipe(false,strip.Color(200,200,200),strip.Color(0,0,200),time);
    Serial.println("vertWipe");
    vertWipe(false,strip.Color(0,200,0),strip.Color(200,200,200),time);
    Serial.println("vertWipe");
    vertWipe(false,strip.Color(0,200,200),strip.Color(0,200,0),time);
    //red to white
    Serial.println("vertWipe");
    vertWipe(false,strip.Color(0,200,0), strip.Color(0,200,200),time);

}

void regularProgram(){

}
