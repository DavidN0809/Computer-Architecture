#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Enum to represent the stages in the pipeline
enum Stage {
    Fetch,Decode,Execute,Store,NONE
};

// Enum to represent the instructions in the instruction queue
enum InstructionQueue {
    ld,add,sd,addi,bne,halt,NO_OP
};

// Class to represent an event in the pipeline
class Event {
public:
    Stage stage;
    InstructionQueue instruction;
    int data;
    int clock_cycle;

    // Constructor to initialize an event
    Event(Stage s, InstructionQueue i, int d, int c) : stage(s), instruction(i), data(d), clock_cycle(c) {}

    // Function to print the details of an event
    void print() const {
        string stageNames[] = {"Fetch", "Decode", "Execute", "Store", "NONE"};
        string instructionNames[] = {"ld", "add", "sd", "addi", "bne", "halt", "NO_OP"};

        cout << "Clock : " << clock_cycle << " ";
        for (int i = 0; i < 4; i++) {
            if (i == stage) 
                cout << instructionNames[instruction] << " ";
            else 
                cout << "NO_OP ";
        }
        cout << "x=>" << data << endl;
    }
};

// Class to simulate the pipeline
class Simulator {
private:
    queue<Event> events;  // Queue to store the events
    float x1 = 160;  // Register x1 initialized to 160
    float x2 = 0;  // Register x2 initialized to 0
    float f0 = 0.0, f2 = 0.0, f4 = 0.0;  // Registers for floating point operations

public:
    // Function to simulate the pipeline
    void simulatePipeline() {
        int clock_cycle = 1;
        while (x1 != x2) {
            events.push(Event(Fetch, ld, x1, clock_cycle++));
            f0 = x1;  // Fetch the value from the array using x1

            events.push(Event(Decode, add, x1, clock_cycle++));
            f4 = f0 + f2;  // Add scalar in f2

            events.push(Event(Execute, sd, x1, clock_cycle++));
            // Store result (no operation needed in this simulation)

            events.push(Event(Store, addi, x1, clock_cycle++));
            x1 -= 8;  // Decrement pointer

            events.push(Event(Fetch, bne, x1, clock_cycle++));
            // Branch operation (no operation needed in this simulation as the loop condition is handled by the while loop)
        }
        events.push(Event(Fetch, halt, x1, clock_cycle++));  // Halt instruction
    }

    // Function to print the events
    void printEvents() {
        while (!events.empty()) {
            events.front().print();
            events.pop();
        }
    }
};

int main() {
    Simulator test;  // Create a simulator object
    test.simulatePipeline();  // Simulate the pipeline
    test.printEvents();  // Print the events

    return 0;
}
