//******************************************************************************
// Libraries
//******************************************************************************
#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;


//******************************************************************************
// Defines
//******************************************************************************
#define NUM_EVENTS 20
#define MAX_EVENTS 100


//******************************************************************************
// Function Prototypes
//******************************************************************************
int RNG(void);
int seedRNG(int n);
int getTime(void);
vector<pair<int, int>> insertionSort(vector<pair<int, int>>);
void printMEQ(vector<pair<int, int>>);
vector<pair<int, int>> addNewEvent(vector<pair<int, int>>);


//***********************************************************************************
// Driver Code
//***********************************************************************************
int main() {
    vector<pair<int, int>> events;  // Vector to store events
    int t,v;

    // Generate random number and add event to vector
    for (int i = 0; i < NUM_EVENTS; ++i) {
        t = getTime();
        v = RNG();
        events.push_back(make_pair(t, v));
    }

    // Print the generated events
    cout << "\nUnsorted list:\n";
    printMEQ(events);
    
    // Sort generated events
    events = insertionSort(events);

    // Print the sorted generated events
    cout << "\nSorted list:\n";
    printMEQ(events);
    
    // Add events and sort MEQ until 100 events have been processed
    while(events.size() < MAX_EVENTS){
       events = addNewEvent(events);
       events = insertionSort(events);
    }
    cout << "\nSorted list:\n";
    printMEQ(events);
    
    return 0;
}

//***********************************************************************************
// Functions
//***********************************************************************************
//******************************************************************************
// RNG - using system clock as seed
//******************************************************************************
int RNG(void) {
    srand((unsigned) clock());
    int random = rand();
    
    return random;
}

//******************************************************************************
// RNG - using passed int as seed
//******************************************************************************
int seedRNG(int n) {
    srand((unsigned) n);
    int random = rand();
    
    return random;
}

//******************************************************************************
// Returns system cycles between instructions
//******************************************************************************
int getTime(void) {
    time_t seconds;
    seconds = clock();

    return seconds;
}

//******************************************************************************
// Insertion Sort
//******************************************************************************
vector<pair<int, int>> insertionSort(vector<pair<int, int>> events) {
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

//******************************************************************************
// Prints out the Master Event Queue(MEQ)
//******************************************************************************
void printMEQ(vector<pair<int, int>> events) {
    int n = events.size();
    for (int i = 0; i < n; i++)
        cout << "(" << events[i].first << ", " << events[i].second << ")\n";

    cout << "Size of events vector: " << events.size() << "\n\n";
}

//******************************************************************************
// Adds new event to MEQ
//******************************************************************************
vector<pair<int, int>> addNewEvent(vector<pair<int, int>> events) {
    int temp = events[0].second;
    cout << "Earliest event: " << temp << "\n";
    
    int t = getTime() + seedRNG(temp);
    int v = RNG();
    events.push_back(make_pair(t, v));
    
    return events;
}
