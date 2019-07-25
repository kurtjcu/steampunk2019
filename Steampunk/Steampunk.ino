
#include <Metro.h> // Include the Metro library

// pin maps
// demux (digi select)
// 0-2

#define mux0 2
#define mux1 3
#define mux2 4
#define mux3 5

// led (within digit)
// 23-16

#define led0 16
#define led1 17
#define led2 18
#define led3 19
#define led4 20
#define led5 21
#define led6 22
#define led7 23

// clocks (select row)
// 6-8

#define clk0 6
#define clk1 7
#define clk2 8


// pin arrays

const int muxes[] = {mux0, mux1, mux2, mux3};
const int leds[] = {led0, led1, led2, led3, led4, led5, led6, led7};
const int clocks[] = {clk0, clk1, clk2};

const byte digitLookup[] = {
  B00111111,  //0 
  B00000110,  //1
  B01011011,  //2
  B01001111,  //3
  B01100110,  //4
  B01101101,  //5
  B01111101,  //6
  B00000111,  //7
  B01111111,  //8
  B01101111,  //9
  B01110111,  //A - 10
  B01111100,  //b - 11
  B00111001,  //C - 12
  B01011110,  //d - 13
  B01111001,  //E - 14
  B01110001,  //F - 15
  B00000000   // clear
};

//const int digitLocation[] = {4, 3, 2, 1, 0, 11, 10, 9, 8, 7, 6, 5};
//const int digitLocation[] = {5, 6, 7, 8, 9, 10, 11, 0, 1, 2, 3, 4};
//const int digitLocation[] = {11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const int digitLocation[] = {11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int digitsStorage[3][12] = {
  {16,16,16,16,16,16,16,16,16,16,16,16},
  {16,16,16,16,16,16,16,16,16,16,16,16},
  {16,16,16,16,16,16,16,16,16,16,16,16}
};

const int numberOfRoutines = 10;

int routineNum = 0;
int routineTickerNum = 0;

Metro changeRoutine = Metro(1000);  // Instantiate an instance
Metro routineTicker = Metro(30000);  // Instantiate an instance

Metro killRoutine = Metro(300000);  // Instantiate an instance

Metro seconds = Metro(1000);  // Instantiate an instance

void setup() {
  // put your setup code here, to run once:
  pinMode(mux0, OUTPUT);
  pinMode(mux1, OUTPUT);
  pinMode(mux2, OUTPUT);
  pinMode(mux3, OUTPUT);

  pinMode(clk0, OUTPUT);
  pinMode(clk1, OUTPUT);
  pinMode(clk2, OUTPUT);

  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);

  resetLeds();
  resetMux();
  resetClk();

  resetDisplay();
  delay(10);

  int temp[3][12] = {
//        {16,16,01,09,09,07,02,09,16,00,08,16},
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16}
      };
      
  writeToDigitStorage(temp);
}

void loop() {

  if (changeRoutine.check()){
    
    if(routineNum == numberOfRoutines){
      routineNum = 0;
    } else {
      routineNum++;
    }

    if (routineNum == 0){ // dead beef
      int temp[3][12] = {
        {11,14,14,15,16,16,13,14,10,13,16,16},
        {16,11,14,14,15,16,16,13,14,10,13,16},
        {16,16,11,14,14,15,16,16,13,14,10,13}
      };
      
      writeToDigitStorage(temp);
      
    } else if(routineNum == 1){ // clear
      int temp[3][12] = {
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16}
      };
      
      writeToDigitStorage(temp);
      
    } else if(routineNum == 2){ // delorian time 21 / 10 / 2015
      int temp[3][12] = {
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,02,00,01,05,02,01,16,01,00,16},
        {16,16,16,16,16,16,16,16,16,16,16,16}
      };
      
      writeToDigitStorage(temp);
      
    }  else if(routineNum == 3){ // clear
      int temp[3][12] = {
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16}
      };
      
      writeToDigitStorage(temp);
      
    } else if(routineNum == 4){ // judgement day 29 / 8 / 1997
      int temp[3][12] = {
        {16,16,01,9,9,7,02,9,16,00,8,16},
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16}
      };
      
      writeToDigitStorage(temp);
      
    } else if(routineNum == 5){ // clear
      int temp[3][12] = {
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16}
      };
      
      writeToDigitStorage(temp);
      
    } else if(routineNum == 6){ // weasle hadron collider day
      int temp[3][12] = {
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {2,0,1,6,16,16,2,9,16,0,4,16}
      };
      
      writeToDigitStorage(temp);
      
    } else if(routineNum == 7){ // clear
      int temp[3][12] = {
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16}
      };
      
      writeToDigitStorage(temp);
      
    }else if(routineNum == 8){ // my birthday
      int temp[3][12] = {
        {1,9,7,9,16,16,1,6,16,0,5,16},
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16}
      };
      
      writeToDigitStorage(temp);
      
    }else if(routineNum == 9){ // clear
      int temp[3][12] = {
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16}
      };
      
      writeToDigitStorage(temp);
      
    }else if(routineNum == 10){ // clear
      int temp[3][12] = {
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16},
        {16,16,16,16,16,16,16,16,16,16,16,16}
      };
      
      writeToDigitStorage(temp);
      
    }
    
  }

  //todo add a clear for a while
  
  displayDigitStorage();
}

void writeToDigitStorage(int myArray[3][12]){
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 12; ++j){
      digitsStorage[i][j] = myArray[i][j];
    }
  }
}

void displayDigitStorage(){

  for(int i = 0; i < 12; ++i) {
//    resetLeds();
    digitalWrite( mux3, ((digitLocation[i] >> 3) % 2) == 1);
    digitalWrite( mux2, ((digitLocation[i] >> 2) % 2) == 1); // See what I did there? Ninja bit magic! 
    digitalWrite( mux1, ((digitLocation[i] >> 1) % 2) == 1); // Got the idea from 
    digitalWrite( mux0, ((digitLocation[i] >> 0) % 2) == 1); // http://forums.adafruit.com/viewtopic.php?f=20&t=12289
    delayMicroseconds(1500);
    
    for(int j = 0; j <3; j++){
      writeDigitToLeds(digitsStorage[j][11 - i]);
      digitalWrite(clk0 + j, 0);
      digitalWrite(clk0 + j, 1);
    }
    
  } 
  
}

void writeDigitToLeds(int digit){
  for (int i=0; i<8; i++){
    if ( bitRead (digitLookup[digit],i) )
      digitalWrite(i + led0, 1);
    else
      digitalWrite(i + led0, 0);
  } 
}


void resetDisplay() {
  resetLeds();
  for(int j = 0; j <3; j++) {
    pulseClk(clk0 + j);
    for(int i = 0; i < 12; ++i) {
      digitalWrite( mux3, ((i >> 3) % 2) == 1);
      digitalWrite( mux2, ((i >> 2) % 2) == 1); // See what I did there? Ninja bit magic! 
      digitalWrite( mux1, ((i >> 1) % 2) == 1); // Got the idea from 
      digitalWrite( mux0, ((i >> 0) % 2) == 1); // http://forums.adafruit.com/viewtopic.php?f=20&t=12289
      delay(1);
    }
  }
}

void pulseClk(int clk)  {
  digitalWrite( clk, 0);
//  delayMicroseconds(100);
  digitalWrite( clk, 1);
}

void resetMux() {
  digitalWrite( mux3, 0);
  digitalWrite( mux2, 0);
  digitalWrite( mux1, 0);
  digitalWrite( mux0, 0);
}

void resetClk() {
  digitalWrite( clk2, 0);
  digitalWrite( clk1, 0);
  digitalWrite( clk0, 0);
}

void resetLeds() {
  for (int i = 0; i <=7; i++) {
    digitalWrite( led0 + i, 0);
  }
}

void testAllLeds(){

  resetLeds();
  resetMux();
  resetClk();

  for (int i = 0; i <=7; i++) {
    digitalWrite( led0 + i, 1);
  }
  
  for(int j = 0; j <3; j++){
    pulseClk(clk0 + j);
    for(int i = 0; i < 12; ++i) 
    {
      digitalWrite( mux3, ((i >> 3) % 2) == 1);
      digitalWrite( mux2, ((i >> 2) % 2) == 1); // See what I did there? Ninja bit magic! 
      digitalWrite( mux1, ((i >> 1) % 2) == 1); // Got the idea from 
      digitalWrite( mux0, ((i >> 0) % 2) == 1); // http://forums.adafruit.com/viewtopic.php?f=20&t=12289
      delay(1);
    }
  }
}


void testSingleDigit(){ 

  for(int i = 0; i < 12; ++i) {
//    resetMux();
    digitalWrite( mux3, ((digitLocation[i] >> 3) % 2) == 1);
    digitalWrite( mux2, ((digitLocation[i] >> 2) % 2) == 1); // See what I did there? Ninja bit magic! 
    digitalWrite( mux1, ((digitLocation[i] >> 1) % 2) == 1); // Got the idea from 
    digitalWrite( mux0, ((digitLocation[i] >> 0) % 2) == 1); // http://forums.adafruit.com/viewtopic.php?f=20&t=12289
//    delay(1);
    delayMicroseconds(1500);
    for(int j = 0; j <3; j++){
      writeDigitToLeds(i);
//      delayMicroseconds(100);
      pulseClk(clk0 + j);
//      delayMicroseconds(100);
    }
  } 
}


