/* 	Testbench for the modules in the CANSlator. Comment out specific tests
*	if you wish to run them in isolation. This should only be used to run 
*	hardware validation. USE ON HARDWARE ONLY with U1/TEENSY A only!
*/ 

#include <"brakeBooster.h">
// #include <"serial.h"> // don't need if compiling through Arduino IDE 

// INPUT PIN DEFINITIONS
#define BOOST_SENSE_PIN 17
#define ACSY_WAKE_SENSE 20
#define RUN_CRANK_SENSE 23
#define PARK_LOCK_SENSE 36
#define BRAKE_POS_SENSE 39
#define RAM_IGN_SWITCH	35

// OUTPUT PIN DEFINITIONS 
#define BOOST_DRIVE_PIN 16
#define SHIFT_INTER_PIN 14
#define PARK_POS_DRIVER 15
#define ACSY_WAKE_DRIVE 21
#define RUN_CRANK_DRIVE 22


void setup() {
	// not sure if you have to define digital input pins?
	pinMode(ACSY_WAKE_SENSE, INPUT);
	pinMode(RUN_CRANK_SENSE, INPUT);
	pinMode(PARK_LOCK_SENSE, INPUT);
	pinMode(BRAKE_POS_SENSE, INPUT);

	pinMode(BOOST_DRIVE_PIN, OUTPUT);
	pinMode(SHIFT_INTER_PIN, OUTPUT);
	pinMode(PARK_POS_DRIVER, OUTPUT);
	pinMode(ACSY_WAKE_DRIVE, OUTPUT);
	pinMode(RUN_CRANK_DRIVE, OUTPUT);

	// initialize all of the drive pins to low 
	digitalWrite(BOOST_DRIVE_PIN, LOW);
	digitalWrite(SHIFT_INTER_PIN, LOW);
	digitalWrite(PARK_POS_DRIVER, LOW);
	digitalWrite(ACSY_WAKE_DRIVE, LOW);
	digitalWrite(RUN_CRANK_DRIVE, LOW);
}

// Comment out tests you don't wish to run. 
void main() {
	test_brake_booster(); 
	test_accessory_wakeup();
	test_run_crank();
}

void test_brake_booster() {
	Serial.println();
	Serial.println("--TESTING BRAKE BOOSTER CONTROL--");
	uint8_t boost_pressure = analogRead(BOOST_SENSE_PIN); 
	Serial.print("External Stimulation; Brake boost pump should be ");
	if(brake_booster(boost_pressure)) {
		Serial.println("ON"); 
		digitalWrite(BOOST_DRIVE_PIN, HIGH);
	} else {
		Serial.println("OFF");
		digitalWrite(BOOST_DRIVE_PIN, LOW);
	}
	delay(1000);

	// Test the output regardless of the input... 
	digitalWrite(BOOST_DRIVE_PIN, HIGH);
	Serial.println("Brake boost pump should be on for 10 seconds...");
	delay(10000);
	digitalWrite(BOOST_DRIVE_PIN, LOW);
	Serial.println("Brake boost pump should be off for >10 seconds...");
	delay(10000);
	Serial.println();
}

void test_brake_position() {
	Serial.println();
	Serial.println("--TESTING BRAKE POSITION SENSE--");
	Serial.println();
	float brake_position = 0.0035 * analogRead(BRAKE_POS_SENSE);
	Serial.print("Brake position sensor voltage sensed as ");
	Serial.println(brake_position);
	Serial.println();
}

void test_ram_ignition() {
	Serial.println();
	Serial.println("--TESTING RAM IGNITION SENSE--");
	Serial.println();
	Serial.print("External Stimulation; RAM Ignition Sense is sensed as ");
	if(digitalRead(RAM_IGN_SWITCH)) {
		Serial.println("HIGH"); 
	} else {
		Serial.println("LOW");
	}
	Serial.println();
}

void test_BCM_park_lock() {
	Serial.println();
	Serial.println("--TESTING VOLT BCM DRIVEN PARK LOCK SENSE--");
	Serial.println();
	Serial.print("External Stimulation; Park Lock Sense is sensed as ");
	if(digitalRead(PARK_LOCK_SENSE)) {
		Serial.println("HIGH"); 
	} else {
		Serial.println("LOW");
	}
	Serial.println();
}

void test_accessory_wakeup() {
	Serial.println();
	Serial.println("--TESTING ACCESSORY WAKEUP--");
	Serial.println();
	Serial.print("External Stimulation; Accessory Wakeup Sensed is ");
	if(digitalRead(ACSY_WAKE_SENSE)) {
		Serial.println("HIGH");
	} else {
		Serial.println("LOW");
	}
	delay(1000);
	digitalWrite(ACSY_WAKE_DRIVE, HIGH);
	Serial.println();
	Serial.print("Internal Stimulation; Accessory Wakeup driven high and sensed as ");
	if(digitalRead(ACSY_WAKE_SENSE)) {
		Serial.println("HIGH");
	} else {
		Serial.println("LOW");
	}
	delay(1000);
	digitalWrite(ACSY_WAKE_DRIVE, LOW);
	Serial.print("Internal Stimulation; Accessory Wakeup driven low and sensed as ");
	if(digitalRead(ACSY_WAKE_SENSE)) {
		Serial.println("HIGH");
	} else {
		Serial.println("LOW");
	}
	Serial.println();
}

void test_run_crank() {
	Serial.println();
	Serial.println("--TESTING RUN/CRANK--");
	Serial.println();
	Serial.print("External Stimulation; Run/Crank Sensed is ");
	if(digitalRead(RUN_CRANK_SENSE)) {
		Serial.println("HIGH");
	} else {
		Serial.println("LOW");
	}
	delay(1000);
	digitalWrite(RUN_CRANK_DRIVE, HIGH);
	Serial.println();
	Serial.print("Internal Stimulation; Run/Crank driven high and sensed as ");
	if(digitalRead(RUN_CRANK_SENSE)) {
		Serial.println("HIGH");
	} else {
		Serial.println("LOW");
	}
	delay(1000);
	digitalWrite(RUN_CRANK_DRIVE, LOW);
	Serial.print("Internal Stimulation; Accessory Wakeup driven low and sensed as ");
	if(digitalRead(RUN_CRANK_SENSE)) {
		Serial.println("HIGH");
	} else {
		Serial.println("LOW");
	}
	Serial.println()
}

void test_shift_interlock() {
	Serial.println();
	Serial.println("--TESTING SHIFT INTERLOCK--");
	Serial.println();
	digitalWrite(SHIFT_INTER_PIN, HIGH);	// note that this is a LSD, so inverse measured on C100
	Serial.println("Shift interlock pin driven low for 10 seconds...");
	delay(10000);
	Serial.println("Shift interlock pin driven high for 10 seconds...");
	delay(10000);
	Serial.println("Shift interlock pin left low...");
} 

void test_park_position() {
	Serial.println();
	Serial.println("--TESTING PARK POSITION--");
	Serial.println();
	digitalWrite(PARK_POS_DRIVER, HIGH);// note that this is a LSD, so inverse measured on C100
	Serial.println("Park position pin driven low for 10 seconds...");
	delay(10000);
	Serial.println("Park position pin driven high for 10 seconds...");
	delay(10000);
	Serial.println("Park position pin left high...");
} 
