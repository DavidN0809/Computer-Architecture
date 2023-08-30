#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

// EventManager class to manage events and related operations
class EventManager {
private:
    // Constants for the number of events and maximum events
    static const int NUM_EVENTS = 20;
    static const int MAX_EVENTS = 100;

    // Vector to store events as pairs
    vector<pair<int, int>> events;

    // Private method to generate a random number using the system clock as a seed
    int RNG() {
        srand((unsigned) clock());
        return rand();
    }

    // Private method to generate a random number using a passed integer as a seed
    int seedRNG(int n) {
        srand((unsigned) n);
        return rand();
    }

    // Private method to get the current system time
    int getTime() {
        return clock();
    }

    // Private method to sort the events vector using insertion sort
    vector<pair<int, int>> insertionSort() {
        int n = events.size();
        for (int j = 1; j < n; j++) {
            pair<int, int> temp = events[j];
            int i = j - 1;
            while (i >= 0 && events[i].second > temp.second) {
                events[i + 1] = events[i];
                i = i - 1;
            }
            events[i + 1] = temp;
        }
        return events;
    }

    // Private method to print the Master Event Queue (MEQ)
    void printMEQ() {
        int n = events.size();
        for (int i = 0; i < n; i++) {
            cout << "event " << i << ": " << events[i].second << "\n";
        }
    }

public:
    // Public constructor to initialize events
    EventManager() {
        int t, v;
        for (int i = 0; i < NUM_EVENTS; ++i) {
            t = getTime();
            v = RNG();
            events.push_back(make_pair(t, v));
        }
    }

    // Public method to run the main event management logic
    void run() {
        cout << "\nUnsorted list:\n";
        printMEQ();

        // Sort and print events
        insertionSort();
        cout << "\nSorted list:\n";
        printMEQ();

        // Add and sort events until reaching the maximum number of events
        while(events.size() < MAX_EVENTS) {
            addNewEvent();
            insertionSort();
        }

        cout << "\nSorted list:\n";
        printMEQ();
    }

    // Public method to add a new event to the MEQ
    void addNewEvent() {
        int temp = events[0].second;
        int t = getTime() + seedRNG(temp);
        events.push_back(make_pair(t, temp));
    }
};

// Main function to initialize and run the EventManager
int main() {
    EventManager em;
    em.run();
    return 0;
}

