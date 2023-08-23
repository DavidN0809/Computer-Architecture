/*
Generate 20 events randomly. Each event E = (t, v) where t is time the event will be executed
and v is an integer value (randomly generated) for printing. You can get t from the system time.
*/

#include<iostream>
#include<ctime> // used to work with date and time
#include<cstdlib>

// C++ program to generate random number
#include <bits/stdc++.h>
using namespace std;

// Function with return random number from 1 to
// given limit

int randomNoGenerator(){
	// Providing a seed value
	srand((unsigned) clock());

	// Get a random number
	int random = rand();
        return random;
}
int gettime(){
  time_t seconds;

  seconds = clock();
  //printf ("%ld seconds since January 1, 1970", seconds);
  return seconds;
}

int main() {
    vector<pair<int, int>> events;  // Vector to store events

// #1
    for (int i = 0; i < 20; ++i) {
        int t = gettime();
        int v = randomNoGenerator();
        events.push_back(make_pair(t, v));  // Add event to vector
    }

    // Print the generated events
    for (const auto& event : events) {
        cout << "Time: " << event.first << ", Value: " << event.second << endl;
    }

// #2
    for (int k = 1; k < 20; k++) {
        pair<int, int> temp = events[k];
        int j = k - 1;
        while (j >= 0 && temp.second <= events[j].second) {
            events[j + 1] = events[j];
            j = j - 1;
        }
        events[j + 1] = temp;
    }

    cout << "\nSorted list is \n";
    for (int i = 0; i < 20; i++) {
        cout << "(" << events[i].first << ", " << events[i].second << ")\t";
    }

    return 0;
}
