#include <iostream>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;

int randomNoGenerator() {
    srand((unsigned) clock());
    int random = rand();
    
    return random;
}

int getTime() {
    time_t seconds;
    seconds = clock();

    return seconds;
}

void insertionSort(vector<pair<int, int>> arr, int n) {
    for (int j = 1; j < n; j++) {
        pair<int, int> key = arr[j];
        int i = j - 1;
            
        while (i > 0 && arr[i].second >= key.second) {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}


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
    for (const auto& event : events) {
        cout << "Time: " << event.first << ", Value: " << event.second << endl;
    }
    printf("Size of events vector: %zu\n", events.size());


    // Sort generated events
    insertionSort(events, numEvents);


    // Print the sorted generated events
    cout << "\nSorted list is \n";
    for (int i = 0; i < numEvents; i++) {
        cout << "(" << events[i].first << ", " << events[i].second << ")\n";
    }
    
    return 0;
}
