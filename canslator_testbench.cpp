/* 	Testbench for the modules in the CANSlator. Comment out specific tests
*	if you wish to run them in isolation. This should only be used to run 
*	validation simulations. NOT DESIGNED FOR PHYSICAL HARDWARE TESTING
*
*/ 

#include <"brakeBooster.h">
#include <"serial.h">



void main() {
	test_brake_booster(); 
}


void test_brake_booster() {
	//Test the brake booster, pass it values and print the response.	
	Serial.print("Initializing the brake booster to 400...");
	if(brake_booster(400)) {
		Serial.println("FAIL"); //should be off, returning true is a fail
	} else {
		Serial.println("PASS");
	}
	Serial.print("Initializing the brake booster to 50...");
	if(brake_booster(50)) {
		Serial.println("PASS"); // should be on, returning true is a pass 
	} else {
		Serial.println("FAIL");
	}
	Serial.print("Initializing the brake booster to 600...");
	if(brake_booster(600)) {
		Serial.println("FAIL"); // should be off, returning true is a fail 
	} else {
		Serial.println("PASS");
	}
}