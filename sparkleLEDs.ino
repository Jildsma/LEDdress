//make it easier to reference the output pins
int led1 = 5; //linksboven top & linksachter - fade
int led2 = 6; //middenvoor - fade
int led3 = 7; //rechterzij - aan/uit
int led4 = 8; //rechterheup - aan/uit
int led5 = 9; //linkerzijde - fade
int led6 = 10; //sterrenbeeld - fade
int led7 = 11; //linkerheup - fade
int led8 = 12; //links ondderin - aan/uit
int led9 = 13; //midden rug & rechts bovenin - aan/uit

int staticLedsValue = 130;

int fadePins[] = {led1,led2,led5,led6, led7};

int waitTimeDown = 1000; // The time the LEDs stays off
int waitTime = 40; // The time the LEDs stays on
int minBrightness = 30; // Lowest brightness of the LED
int maxBrightness = 255; // Max brightness of the LED
int fadeAmount = 5; // the value of which the LED increases or decreases the brightness

void setup() {   
  Serial.begin(9600);   
  pinMode(led1, OUTPUT);     
  pinMode(led2, OUTPUT);  
  pinMode(led3, OUTPUT);  
  pinMode(led4, OUTPUT);   
  pinMode(led5, OUTPUT); 
  pinMode(led6, OUTPUT); 
  pinMode(led7, OUTPUT); 
  pinMode(led8, OUTPUT); 
  randomSeed(analogRead(0));
}

void loop() {
  analogWrite(led3, staticLedsValue);  
  analogWrite(led4, staticLedsValue);  
  analogWrite(led8, staticLedsValue);  
  analogWrite(led9, staticLedsValue); 
  
  analogWrite(led1, minBrightness);
  analogWrite(led2, minBrightness);  
  analogWrite(led5, minBrightness);  
  analogWrite(led6, minBrightness);  
  analogWrite(led7, minBrightness);  
  
  int randomLED = random(5);  
  int chosenLED = fadePins[randomLED];
  sparkleLED(chosenLED); 
}

void sparkleLED(int chosenLED){ 
  for (int i=minBrightness; i <= maxBrightness; i+=fadeAmount){ 
  analogWrite(chosenLED, i);
  delay(waitTime);
  }
    
  for (int i=maxBrightness; i >= minBrightness; i-=fadeAmount){
  analogWrite(chosenLED, i);;
  delay(waitTime);
  }

  delay(waitTimeDown); 
}
