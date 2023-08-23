//******************************************************************************
// Libraries
//******************************************************************************
#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

//******************************************************************************
// Function Prototypes
//******************************************************************************
int randomNoGenerator(void);
int getTime(void);
vector<pair<int, int>> insertionSort(vector<pair<int, int>>);
void printMEQ(vector<pair<int, int>>);


//***********************************************************************************
// Driver Code
//***********************************************************************************
int main() {
    vector<pair<int, int>> events;  // Vector to store events
    int t,v;
    int numEvents = 20;

    // Generate random number and add event to vector
    for (int i = 0; i < numEvents; ++i) {
        t = getTime();
        v = randomNoGenerator();
        events.push_back(make_pair(t, v));
    }

    // Print the generated events
    cout << "\nUnsorted list:\n";
    printMEQ(events);
    
    // Sort generated events
    events = insertionSort(events);
    // vector<pair<int, int>> events2 = insertionSort(events);

    // Print the sorted generated events
    cout << "\nSorted list:\n";
    printMEQ(events);
    
    return 0;
}


//***********************************************************************************
// Functions
//***********************************************************************************
//******************************************************************************
// 
//******************************************************************************
int randomNoGenerator(void) {
    srand((unsigned) clock());
    int random = rand();
    
    return random;
}

//******************************************************************************
// 
//******************************************************************************
int getTime(void) {
    time_t seconds;
    seconds = clock();

    return seconds;
}

//******************************************************************************
// 
//******************************************************************************
vector<pair<int, int>> insertionSort(vector<pair<int, int>> events) {
    int n = events.size();
    for (int j = 1; j < n; j++) {
        pair<int, int> temp = events[j];
        int i = j - 1;
        
        while (i >= 0 && events[i].second >= temp.second) {
            events[i + 1] = events[i];
            i = i - 1;
        }
        events[i + 1] = temp;
    }
    return events;
}

//******************************************************************************
// 
//******************************************************************************
void printMEQ(vector<pair<int, int>> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        cout << "(" << arr[i].first << ", " << arr[i].second << ")\n";
        // cout << "Time: " << events[i].first << ", Value: " << events[i].second << endl;
    }
    // cout << "Size of events vector: " << arr.size() << "\n";
}
