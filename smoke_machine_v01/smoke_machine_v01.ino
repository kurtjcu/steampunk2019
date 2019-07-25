/*    Max6675 Module  ==>   Arduino
 *    CS              ==>     D10
 *    SO              ==>     D12
 *    SCK             ==>     D13
 *    Vcc             ==>     Vcc (5v)
 *    Gnd             ==>     Gnd      */




#define MAX6675_CS   4
#define MAX6675_SO   12
#define MAX6675_SCK  13

// fets = 6,9,10
#define HEAT 6
#define PUMP 9
#define BUTTON A2


float temperature = -99999;
void setup() {
  Serial.begin(9600);
  pinMode(HEAT, OUTPUT);
  pinMode(PUMP, OUTPUT);
  int sensorValue = analogRead(A0);
  
}

void loop() {
  float temperature_read = readThermocouple(); 
  int sensorValue = analogRead(BUTTON);
  Serial.print("BUTTON: ");
  Serial.println(sensorValue, 1); 

  Serial.print("TEMPERATURE: ");  
  
  Serial.println(temperature_read, 1);    
  delay(300);

//  digitalWrite(HEAT, HIGH);
//  Serial.println("on");
//  delay(1000);
//  digitalWrite(HEAT, LOW);
//  Serial.println("off");
//  delay(1000);

  if(temperature_read < 200) {
    digitalWrite(HEAT, HIGH);
  } else if (temperature_read > 205) {
    digitalWrite(HEAT, LOW);
  }


   if(sensorValue > 120 && temperature_read > 190) {
    digitalWrite(PUMP, HIGH);
    delay(20);
    digitalWrite(PUMP, LOW);
    delay(2000);
    
  } else  {
    digitalWrite(PUMP, LOW);
  }

  
  

  
  
}


double readThermocouple() {

  uint16_t v;
  pinMode(MAX6675_CS, OUTPUT);
  pinMode(MAX6675_SO, INPUT);
  pinMode(MAX6675_SCK, OUTPUT);
  
  digitalWrite(MAX6675_CS, LOW);
  delay(1);

  // Read in 16 bits,
  //  15    = 0 always
  //  14..2 = 0.25 degree counts MSB First
  //  2     = 1 if thermocouple is open circuit  
  //  1..0  = uninteresting status
  
  v = shiftIn(MAX6675_SO, MAX6675_SCK, MSBFIRST);
  v <<= 8;
  v |= shiftIn(MAX6675_SO, MAX6675_SCK, MSBFIRST);
  
  digitalWrite(MAX6675_CS, HIGH);
  if (v & 0x4) 
  {    
    // Bit 2 indicates if the thermocouple is disconnected
    return NAN;     
  }

  // The lower three bits (0,1,2) are discarded status bits
  v >>= 3;

  // The remaining bits are the number of 0.25 degree (C) counts
  return v*0.25;
}
