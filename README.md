**CANSlator Firmware Development**

Track, store and manage development of CANSlator firmware modules for the CANSlator board V1.0 to be used in the RHEV0. 

---

## TODO

1. **Method Definitions and System Block Diagram**
2. **State Macine Definitions**
3. **System State Machine Description**
4. **Communiction interfaces definition**
5. **Hierarchy and Priority Definitions**
6. **Module development**
7. **Test Bench Development & Integration**
8. **Debugging and Physical Testing**

---

**Method Definitions and System Block Diagrams** 

 1. Define the inputs, outputs and functional requirements for each of the specific CANSlator functionalities 
 2. Define parametric boundaries 
 3. Make block diagrams for each one of these subsystems 
 4. Determine and notate the structures you intend to use to deploy the functionality described 

---

**State Machine Definitions**

 1. Define specific states, and transition triggers. 
 2. Capture this in state diagrams and in pseudo-code 
 3. Evaluate edge cases and put bounds on transitions 

---

**System State Machine Description**

 1. Using an understanding of the vehicle's state machine, and the sub-state machines, to develope an overall state machine for the CANSlator.
 2. Make sure that this state machine can encompass all of the sub-states without conflict.  
 3. Ensure that the CANSlator can ALWAYS remain in or return to the correct state upon reboot/reset or transition. 

---

**Communiction interfaces definition**

 1. Compile a list of the specific communication channels and their protocol, baudrate, and bandwidth. 
 2. Define interface methodologies between the communication modules and logical blocks
 3. Create a logic-level diagram of how information should flow, be translated, transmitted and saved. 
 4. Include specific communication packet genres that must be covered and their priority 

---

**Hierarchy and Priority Definitions**

 1. Create a hierarchy of operations in the software based on requirements for safe operations of the vehicles 
 2. Create a priority tree for specific operations to balance the operations in a way that allows high-priority processes can take as needed without drowning out sub-tier systems 

---

**Module development**

 1. Generate a list of specific modules necessary to accomplish the scope in the previously deifned TODO items.
 2. Begin writing code for each of the required modules, working from low-level, I/O handlers, upwards towards logic level transfers. 

---

**Test Bench Development & Integration**

 1. Develop test benches at a modular and system level to test each specific module reflecting the state behavior of the vehicle system. 
 2. To do this, vehicle logs will need to be taken and replayed to the CANslator in some instances. 
 3.	Separate test-suites will need to be run at each level of operation. 
 4. Should be run and generate reports each time code is updated 

---

**Debugging and Physical Testing**

 1. After the code has been validated in simulation, test the firmware on the CANSlator device 
 2. Make adjustments, as needed, to the firmware

