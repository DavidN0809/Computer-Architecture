#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "event.h"
#include <queue>

// Class to simulate the pipeline
class Simulator {
private:
    std::queue<Event> events;  // Queue to store the events
    std::queue<InstructionSet> instructionQueue; // Instruction queue
    int x1 = 160;  // Register x1 initialized to 160
    int x2 = 0;  // Register x2 initialized to 0
    float f0 = 0.0, f2 = 0.0, f4 = 0.0;  // Registers for floating point operations
    int fetch = NO_OP, decode = NO_OP, execute = NO_OP, store = NO_OP;

public:
   Simulator() {
        // Initial fill of the instruction queue
        loadInstructions();
    }

    void loadInstructions() {
	instructionQueue.push(ld);
	instructionQueue.push(add);
	instructionQueue.push(sd);
	instructionQueue.push(addi);
	instructionQueue.push(bne);

    }
    
    // Function to simulate the pipeline
    void simulatePipeline() {
        int clock_cycle = 1;
       // events.push(Event(fetch, NO_OP,  NO_OP,  NO_OP, x1, clock_cycle++));

        while (x1 != x2) {
        //************************************************************************************************************
        
              
            if(instructionQueue.empty()) {
                loadInstructions();  // Re-load instructions for next iteration
            }
            
                        
        if(execute == add && instructionQueue.front() == sd) {
                instructionQueue.push(STALL);  // Inject a stall after add
            }
            
        // Reposition 'addi' if 'ld' is in 'store' and 'addi' is next in line
        if(store == ld && instructionQueue.front() == addi) {
            instructionQueue.push(addi);  // push 'addi' to the back
            instructionQueue.pop();       // remove the front 'addi'
        }
        
	// Check if 'addi' is available during stall and move it up
        if(fetch == STALL && !instructionQueue.empty() && instructionQueue.front() == addi) {
            fetch = addi;
            instructionQueue.pop();
        } 
        
        else if(fetch == STALL && !instructionQueue.empty()) {
            fetch = instructionQueue.front();
            instructionQueue.pop();
        }
       
            if(decode == NO_OP && execute == NO_OP && store == NO_OP) {
                decode = fetch;
		fetch = instructionQueue.front();
                instructionQueue.pop();
                
           // if (fetch > bne)
           //         fetch = ld;
            }
            
             else if(decode != NO_OP) {
                execute = decode;
                decode = NO_OP;
            } else if(execute != NO_OP) {
                store = execute;
                execute = NO_OP;
            } else if(store != NO_OP) {
                store = NO_OP;
            }
            
            if(store == ld) {
                f0 = x1;
            } else if(store == add) {
                f4 = f0 + f2;
            } else if(store == sd) {
                
            } else if(store == addi) { 
                x1 -= 8;  // Decrement pointer
            } else if(store == bne) {
  
            }

            events.push(Event(fetch, decode, execute, store, x1, clock_cycle++));
        //************************************************************************************************************
        }
        events.push(Event(NO_OP, NO_OP, NO_OP, NO_OP, x1, clock_cycle++));  // Halt instruction
        printEvents();
    }

    // Function to print the events
    void printEvents() {
        std::cout << "Part1 Output\t\t\t\t\t\t\t|Part2 Output\n";
        std::cout << "\t\tFetch\tDecode\tExecute\tStore\t\n";
        while (!events.empty()) {
            events.front().print();
            events.pop();
        }
    }
};

#endif //SIMULATOR_H
