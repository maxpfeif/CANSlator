/* 	Testbench for the modules in the CANSlator. Comment out specific tests
*	if you wish to run them in isolation. This should only be used to run 
*	hardware validation. USE ON HARDWARE ONLY with U2/TEENSY B only!
*/ 

// #include <"serial.h"> // don't need if compiling through Arduino IDE

// INPUT PIN DEFINITIONS 

// OUTPUT PIN DEFINITIONS
#define SPORT_MODE_SW	14
#define TRACTION_CTRL	17
#define CRUISE_ON_OFF	23
#define CRUISE_RES_PL	22
#define CRUISE_SET_PL	21
#define CRUISE_CANCEL 	20
#define COOLANT_PUMP 	15	
#define INTERIOR_LAMP	16
#define ADAPTIVE_CRUS	28

void setup() {
	pinMode(SPORT_MODE_SW, OUTPUT);
	pinMode(TRACTION_CTRL, OUTPUT);
	pinMode(CRUISE_ON_OFF, OUTPUT);
	pinMode(CRUISE_RES_PL, OUTPUT);
	pinMode(CRUISE_SET_PL, OUTPUT);
	pinMode(CRUISE_CANCEL, OUTPUT);
	pinMode(COOLANT_PUMP, OUTPUT);
	pinMode(INTERIOR_LAMP, OUTPUT);
	pinMode(ADAPTIVE_CRUS, OUTPUT);
}

void main() {
	test_sport_mode();
	test_traction_control();
	test_cruise_control();
	test_coolant_pump();
	test_interior_lamp();
	test_adapative_cruise();
}

void test_sport_mode() {
	Serial.println();
	Serial.println("--TESTING SPORT MODE--");
	Serial.println();
	digitalWrite(SPORT_MODE_SW, HIGH);	// note that this is a LSD, so inverse measured on C100
	Serial.println("Sport mode pin driven low for 10 seconds...");
	delay(10000);
	digitalWrite(SPORT_MODE_SW, LOW);
	Serial.println("Sport mode pin driven high for 10 seconds...");
	delay(10000);
	Serial.println("Sport mode pin left high...");
	Serial.println();
}

void test_traction_control() {
	Serial.println();
	Serial.println("--TESTING TRACTION CONTROL--");
	Serial.println();
	digitalWrite(TRACTION_CTRL, HIGH);	// note that this is a LSD, so inverse measured on C100
	Serial.println("Traction control pin driven low for 10 seconds...");
	delay(10000);
	digitalWrite(TRACTION_CTRL, LOW);
	Serial.println("Traction control pin driven high for 10 seconds...");
	delay(10000);
	Serial.println("Traction control pin left high...");
	Serial.println();
}

void test_cruise_control() {
	Serial.println();
	Serial.println("--TESTING CRUISE CONTROL--");
	Serial.println();
	digitalWrite(CRUISE_ON_OFF, HIGH);	// note that this is a LSD, so inverse measured on C100
	Serial.println("Cruise On/Off driven for 10 seconds...");
	delay(10000);
	digitalWrite(CRUISE_ON_OFF, LOW); 
	digitalWrite(CRUISE_RES_PL, HIGH);
	Serial.println("Cruise Res/+ driven for 10 seconds...");
	delay(10000);
	digitalWrite(CRUISE_RES_PL, LOW);
	digitalWrite(CRUISE_SET_PL, HIGH);
	Serial.println("Cruise Set/- driven for 10 seconds...");
	delay(10000);
	digitalWrite(CRUISE_SET_PL, LOW);
	digitalWrite(CRUISE_CANCEL, HIGH);
	Serial.println("Cruise Cancel driven for 10 seconds...");
	delay(10000);
	digitalWrite(CRUISE_CANCEL, LOW);
	Serial.println();
}

void test_coolant_pump() {
	Serial.println();
	Serial.println("--TESTING COOLANT PUMP--");
	Serial.println();
	digitalWrite(COOLANT_PUMP, HIGH);	// note that this is a LSD, so inverse measured on C100
	Serial.println("Coolant pump pin driven low for 10 seconds...");
	delay(10000);
	digitalWrite(COOLANT_PUMP, LOW);
	Serial.println("Coolant pump pin driven high for 10 seconds...");
	delay(10000);
	Serial.println("Coolant pump pin left high...");
	Serial.println();
}

void test_interior_lamp() {
	Serial.println();
	Serial.println("--TESTING INTERIOR LAMP--");
	Serial.println();
	digitalWrite(INTERIOR_LAMP, HIGH);	// note that this is a LSD, so inverse measured on C100
	Serial.println("Interior lamp pin driven low for 10 seconds...");
	delay(10000);
	digitalWrite(INTERIOR_LAMP, LOW);
	Serial.println("Interior lamp pin driven high for 10 seconds...");
	delay(10000);
	Serial.println("Interior lamp pin left high...");
	Serial.println();
}

void test_adapative_cruise() {
	Serial.println();
	Serial.println("--TESTING ADAPTIVE CRUISE--");
	Serial.println();
	digitalWrite(ADAPTIVE_CRUS, HIGH);	// note that this is a LSD, so inverse measured on C100
	Serial.println("Adaptive cruise pin driven low for 10 seconds...");
	delay(10000);
	digitalWrite(ADAPTIVE_CRUS, LOW);
	Serial.println("Adaptive cruise pin driven high for 10 seconds...");
	delay(10000);
	Serial.println("Adaptive cruise pin left high...");
	Serial.println();
}

