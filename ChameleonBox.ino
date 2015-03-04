/*
Chameleon Box

Connections:
  Keypad
  Mode button
  Speaker
  RGB LED

*/
#include <Tone.h> // This library allows the Arduino to generate more than one tone at once
#include <Keypad.h> // This library makes it easy to use a key matrix

Tone notePlayer[2]; // Declaring two tone generators as an array

#define ROWS 4 // Four rows of keys
#define COLS 3  // Three columns 

#define RED 12
#define BLUE 11
#define GREEN 13

#define BLINK_INTERVAL_MS 1000

//define the symbols on the buttons of the keypads,
//makes the code easier to understand down the line.
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setRgbLed(byte red, byte green, byte blue) {
  digitalWrite(RED, red);
  digitalWrite(GREEN, green);
  digitalWrite(BLUE, blue);
}

byte ledState = LOW;
boolean shouldBlink = true;
unsigned long lastBlinkTime = 0;


void blinkLed() {
  if (ledState == LOW) {
    ledState = HIGH;
  } else {
    ledState = LOW;
  }
  setRgbLed(ledState, ledState, ledState);
}


void stopLedBlink() {
  shouldBlink = false;
}


void setup(){
  //Serial.begin(9600); // Pour a bowl of Serial
  notePlayer[0].begin(9); // Initialize our first tone generator
  notePlayer[1].begin(10); // Initialize our second tone generator
  pinMode(GREEN, OUTPUT); // Green LED 
  pinMode(RED, OUTPUT); // Red LED
  pinMode(BLUE, OUTPUT); // Blue LED
  
  setRgbLed(HIGH, HIGH, HIGH);
}


void playTones(int tone1, int tone2) {
  //Serial.print('p');
  if (tone1 != 0) {
    notePlayer[0].play(tone1);
  }
  if (tone2 != 0) {
    notePlayer[1].play(tone2);
  }
  delay(60);
  notePlayer[0].stop();
  notePlayer[1].stop(); 
}

void playNickel(int a, int b) {
  notePlayer[0].play(1700);
  notePlayer[1].play(2200);
  delay(66);
  notePlayer[0].stop();
  notePlayer[1].stop();   
}

void playDime(int a, int b) {
  notePlayer[0].play(1700);
  notePlayer[1].play(2200);
      delay(66);
  notePlayer[0].stop();
  notePlayer[1].stop();  
  delay(66);
  notePlayer[0].play(1700);
  notePlayer[1].play(2200);
      delay(66);
  notePlayer[0].stop();
  notePlayer[1].stop(); 
}

void playQuarter(int a, int b) {
    notePlayer[0].play(1700);
    notePlayer[1].play(2200);
    delay(33);
    notePlayer[0].stop();
    notePlayer[1].stop();  
    delay(33);
    notePlayer[0].play(1700);
    notePlayer[1].play(2200);
    delay(33);
    notePlayer[0].stop();
    notePlayer[1].stop();  
    delay(33);
    notePlayer[0].play(1700);
    notePlayer[1].play(2200);
    delay(33);
    notePlayer[0].stop();
    notePlayer[1].stop();  
    delay(33);
    notePlayer[0].play(1700);
    notePlayer[1].play(2200);
    delay(33);
    notePlayer[0].stop();
    notePlayer[1].stop();  
    delay(33);
    notePlayer[0].play(1700);
    notePlayer[1].play(2200);
    delay(33);
    notePlayer[0].stop();
    notePlayer[1].stop();  
    delay(33);
}

void playCoinCollect(int a, int b) {
  notePlayer[0].play(2600);
  delay(90);
  notePlayer[0].stop();
  delay(60);
  notePlayer[0].play(700);
  notePlayer[1].play(1100);
  delay(900);
  notePlayer[0].stop();
  notePlayer[1].stop();
}

void playCoinReturn(int a, int b) {
  notePlayer[0].play(2600);
  delay(90);
  notePlayer[0].stop();
  delay(60);
  notePlayer[0].play(1700);
  notePlayer[1].play(1100);
  delay(900);
  notePlayer[0].stop();
  notePlayer[1].stop();
}

void playRingback(int a, int b) {
  notePlayer[0].play(2600);
  delay(90);
  notePlayer[0].stop();
  delay(60);
  notePlayer[0].play(700);
  notePlayer[1].play(1700);
  delay(900);
  notePlayer[0].stop();
  notePlayer[1].stop();
}

void play2600(int time, int b) {
  notePlayer[0].play(2600);
  delay(time);
  notePlayer[0].stop();
}

void(*beigeFuncs[ROWS][COLS])(int, int) = {
  { &playTones, &playTones, &playTones },
  { &playTones, &playTones, &playTones },
  { &playTones, &playTones, &playTones },
  { &playTones, &playTones, &playTones }
};

int beigeTone1[ROWS][COLS] = { 
  {1209, 1336, 1477},
  {1209, 1336, 1477}, 
  {1209, 1336, 1477}, 
  {1209, 1336, 1477} 
};
int beigeTone2[ROWS][COLS] = { 
  {697, 697, 697}, 
  {770, 770, 770},
  {852, 852, 852},
  {941, 941, 941} 
};

void(*blueFuncs[ROWS][COLS])(int, int) = {
  { &playTones, &playTones, &playTones },
  { &playTones, &playTones, &playTones },
  { &playTones, &playTones, &playTones },
  { &playTones, &playTones, &playTones }
};

int blueTone1[ROWS][COLS] = {
    { 700,  700,  900},
    { 700,  900, 1100},
    { 700,  900, 1100},
    {1500, 1300, 1100}  
  };
  
int blueTone2[ROWS][COLS] = {
    { 900, 1100, 1100},
    {1300, 1300, 1300},
    {1500, 1500, 1500},
    {1700, 1500, 1700}
};

void(*redFuncs[ROWS][COLS])(int, int) = {
  { &playNickel, &playDime, &playQuarter },
  { &playTones, &playTones, &playTones },
  { &playTones, &playTones, &playTones },
  { &playTones, &playTones, &playTones }
};

int redTone1[ROWS][COLS] = {
  { 0,  0,  0},
  { 0,  0,  0},
  { 0,  0,  0},
  { 0,  0,  0}  
};
  
int redTone2[ROWS][COLS] = {
  { 0,  0,  0},
  { 0,  0,  0},
  { 0,  0,  0},
  { 0,  0,  0}  
};


void(*silverFuncs[ROWS][COLS])(int, int) = {
  { &playCoinCollect, &playCoinReturn, &playRingback },
  { &playTones, &playTones, &playTones },
  { &playTones, &playTones, &playTones },
  { &play2600, &playTones, &playTones }
};

int silverTone1[ROWS][COLS] = {
  { 697,  770,  852},
  { 941,  0,  0},
  { 0,  0,  0},
  { 1000,  0,  0}  
};
  
int silverTone2[ROWS][COLS] = {
  {1633,  1633,  1633},
  { 1633,  0,  0},
  { 0,  0,  0},
  { 0,  0,  0}  
};


void(*greenFuncs[ROWS][COLS])(int, int) = {
  { &playCoinCollect, &playCoinReturn, &playRingback },
  { &playTones, &playTones, &playTones },
  { &playTones, &playTones, &playTones },
  { &playTones, &playTones, &playTones }
};

int greenTone1[ROWS][COLS] = {
  { 0,  0,  0},
  { 0,  0,  0},
  { 0,  0,  0},
  { 0,  0,  0}  
};
  
int greenTone2[ROWS][COLS] = {
  { 0,  0,  0},
  { 0,  0,  0},
  { 0,  0,  0},
  { 0,  0,  0}  
};

/*

void(*curFuncs[ROWS][COLS])(int, int) = {};
int curTone1[ROWS][COLS] = {};
int curTone2[ROWS][COLS] = {};
  
  
void setBox(void(*newFuncs[ROWS][COLS])(int, int), int newTone1[ROWS][COLS], int newTone2[ROWS][COLS]) {
  for (int r = 0; r < ROWS; ++r) {
    for (int c = 0; c < COLS; ++c) {
      curFuncs[r][c] = newFuncs[r][c];
      curTone1[r][c] = newTone1[r][c];
      curTone2[r][c] = newTone2[r][c];
    }
  }
};
*/
void runBox(void(*func[ROWS][COLS])(int, int), int tone1[ROWS][COLS], int tone2[ROWS][COLS]) {
  //Serial.begin(9600);
  //Serial.println('r');
  while(true) { 
    
      char customKey = customKeypad.getKey();
    
      if (customKey){
          
        boolean done = false;
        for (byte r = 0; !done && r < ROWS; ++r) {
          for (byte c = 0; !done && c < COLS; ++c) {
            if (customKey == hexaKeys[r][c]) {
              if (func) {
                func[r][c](tone1[r][c], tone2[r][c]);
              }
              done = true;
            }
          }
        }
        
        
      }
    }
}
  
void loop() { //Main loop is the boot select. Allows the unit to start in one of several modes
  char customKey = customKeypad.getKey();
  
  if (customKey) {
     
    //Serial.println(customKey);
    // Dial DTMF Tones
    
    if(customKey=='1'){
      //Serial.println("beige");
      stopLedBlink();
      setRgbLed(HIGH, HIGH, LOW);
      runBox(beigeFuncs, beigeTone1, beigeTone2);
      //runBox();
    }
    
    // Dial MF Tones
    if(customKey=='2'){
      //Serial.println("blue");
      stopLedBlink();
      setRgbLed(LOW, LOW, HIGH);
      runBox(blueFuncs, blueTone1, blueTone2);
      //runBox();
    } 
    
    // Dial Payphone Coin Tones
    if (customKey=='3') {
      //Serial.println("red");
      stopLedBlink();
      setRgbLed(HIGH, LOW, LOW);
      runBox(redFuncs, redTone1, redTone2);
      //runBox();
    } 
    
    // Dial Payphone Control Tones
    if (customKey=='4') {
      //Serial.println("green");
      stopLedBlink();
      setRgbLed(LOW, HIGH, LOW);
      runBox(greenFuncs, greenTone1, greenTone2);
      //runBox();
    } 
    
    // Dial Autovon Priority Tones & 2600Hz
    if (customKey=='5') { 
      //Serial.println("silver");
      stopLedBlink();
      setRgbLed(HIGH, HIGH, HIGH);
      runBox(silverFuncs, silverTone1, silverTone2);
      //runBox();
    } 
 
  }
  
  if ((millis() - lastBlinkTime) > BLINK_INTERVAL_MS) {
    lastBlinkTime = millis();
    blinkLed();
  }
  
}
