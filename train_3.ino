// Simple train monitoring system 
// By Spencer Organ
// Visit home.uktechreviews.com for more projects and blog


int track1_in = 0;         // variable for reading the pushbutton status for entering section 1
int track1_out = 0;        // variable for reading the pushbutton status for leaving section 1
int track2_in = 0;         // variable for reading the pushbutton status for entering section 2
int track2_out = 0;       // variable for reading the pushbutton status for leaving section 2
int track3_in = 0;         // variable for reading the pushbutton status for entering section 3
int track3_out = 0;       // variable for reading the pushbutton status for leaving section 3

int section1 = 0;         // train in section 1 initally set to false (0)
int section2 = 0;         // train in section 2 initally set to false (0)
int section3 = 0;         // train in section 2 initally set to false (0)

int error =0;

void setup() {
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, OUTPUT);

test_leds();      // Call the function to test all the LEDs and the buzzer
open_track();     // Call the function which resets the track

Serial.begin(9600);  
  Serial.println("--- Start Serial Monitor SEND_RCVE ---");
  Serial.println();

  
}

void loop() {

//  Read the state of all the microswitches on the rail network
 
  track1_in = digitalRead(2);
  track1_out = digitalRead(3);
  track2_in = digitalRead(6);
  track2_out = digitalRead(7);
  track3_in = digitalRead(10);
  track3_out = digitalRead(11);

  if (track1_in != HIGH) {
  section1=1; digitalWrite(A1,HIGH);digitalWrite(A0,LOW);
  Serial.println("Train just came into section1");
    } 
    
    if (track1_out != HIGH){
    section1=0;digitalWrite(A0,HIGH);digitalWrite(A1,LOW);
    Serial.println("Train just left section1");
    if (section2==1){alarm();error=1;}
    else {error=0;}
    }

   
    if (track2_in != HIGH) {
    section2=1; digitalWrite(5,HIGH);digitalWrite(4,LOW);
    Serial.println("Train just came into section2");
    } 
    
  if (track2_out != HIGH){
    section2=0; digitalWrite(4,HIGH);digitalWrite(5,LOW);
    Serial.println("Train just left section2");
    if (section3==1){alarm();error=1;}
    else {error=0;}
    }
    
    if (track3_in != HIGH) {
    section3=1; digitalWrite(9,HIGH);digitalWrite(8,LOW);
    Serial.println("Train just came into section3");
    } 
    
 if (track3_out != HIGH){
    section3=0; digitalWrite(8,HIGH);digitalWrite(9,LOW);
    Serial.println("Train just left section3");
    if (section1==1){alarm();error=1;}
    else {error=0;}
    }

Serial.println("Current status of each section");
Serial.println(section1);
Serial.println(section2);
Serial.println(section3);

check_status();

}

int test_leds(){
digitalWrite(A0, HIGH);
delay(200);
digitalWrite(A0, LOW);
digitalWrite(A1, HIGH);
delay(200);
digitalWrite(A1, LOW);
delay(200);
digitalWrite(4, HIGH);
delay(200);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
delay(200);
digitalWrite(5, LOW);
delay(200);
digitalWrite(8, HIGH);
delay(200);
digitalWrite(8, LOW);
digitalWrite(9, HIGH);
delay(200);
digitalWrite(9, LOW);
delay(200);
digitalWrite(12, HIGH);
delay(200);
digitalWrite(12, LOW);
delay(200);
digitalWrite(12, HIGH);
delay(200);
digitalWrite(12, LOW);
delay(200);
digitalWrite(A5, HIGH);
delay(200);
digitalWrite(A5, LOW);
delay(200);
}

int open_track(){
  digitalWrite(A0, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(12, HIGH);
}

int alarm(){
  digitalWrite(A5, HIGH);delay(200);digitalWrite(A5, LOW);delay(200);
}

int check_status(){
  if (error==1){digitalWrite(12,LOW);}
  else {digitalWrite(12,HIGH);}
}

