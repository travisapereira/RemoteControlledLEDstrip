#include <Adafruit_NeoPixel.h>

#include <IRremote.h>
#include <IRremoteInt.h>

#define PIN 6
int RECV_PIN = 11;
int x;
IRrecv irrecv(RECV_PIN);
decode_results results;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(240, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600);
  x=0;
  irrecv.enableIRIn(); // Start the receiver
    strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop()
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    irrecv.resume();
  }
  if (irrecv.decode(&results) && x==0)
    {
     for (int i=0; i<240; i++){
       strip.setPixelColor(i,i,20,240-i);
       strip.show();
     }
     x=1;
     irrecv.resume(); // Receive the next value
    }

    
    if (irrecv.decode(&results) && x==1)
    {
     for (int i=0; i<240; i++){
       strip.setPixelColor(i,0,0,0);
       strip.show();
     }
     x=2;
     irrecv.resume(); // Receive the next value
    }

    
    if (irrecv.decode(&results) && x==2)
    {
     for (int i=0; i<240; i++){
       strip.setPixelColor(i,50,50,50);
       strip.show();
     }
     x=3;
     irrecv.resume(); // Receive the next value
    }
    
    
    if (irrecv.decode(&results) && x==3)
    {
     for (int i=0; i<240; i++){
       strip.setPixelColor(i,0,0,0);
       strip.show();
     }
     x=4;
     irrecv.resume(); // Receive the next value
    }
        
    
    if (irrecv.decode(&results) && x==4)
    {
     for (int i=0; i<240; i++){
       strip.setPixelColor(i,100,100,100);
       strip.show();
     }
     x=5;
     irrecv.resume(); // Receive the next value
    }
            
    
    if (irrecv.decode(&results) && x==5)
    {
     for (int i=0; i<240; i++){
       strip.setPixelColor(i,0,0,0);
       strip.show();
     }
     x=6;
     irrecv.resume(); // Receive the next value
    }
        
    
    if (irrecv.decode(&results) && x==6)
    {
     for (int i=0; i<240; i++){
       strip.setPixelColor(i,175,175,150);
       strip.show();
     }
     x=7;
     irrecv.resume(); // Receive the next value
    }
            
    
    if (irrecv.decode(&results) && x==7)
    {
     for (int i=0; i<240; i++){
       strip.setPixelColor(i,0,0,0);
       strip.show();
     }
     x=0;
     irrecv.resume(); // Receive the next value
    }

}
