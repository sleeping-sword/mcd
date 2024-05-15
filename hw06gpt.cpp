#include <iostream>
#include <deque>
using namespace std;

// Function to check the feasibility of the train rearrangement
bool isFeasibleInRotatedStackville(int carriages, int* order) {
    deque<int> station;
    int index = 0;
    
    // Push each carriage onto the deque, and pop those that can leave directly towards direction B
    for (int i = 1; i <= carriages; i++) {
        station.push_back(i);
        while (!station.empty() && (station.front() == order[index] || station.back() == order[index])) {
            if (station.front() == order[index]) {
                station.pop_front();
            } else {
                station.pop_back();
            }
            index++;
        }
    }
    // If the deque is empty, it means that all carriages have correctly left towards direction B.
    return station.empty();
}
int main() {
    int carriages;
    // The program reads input until it cannot read an integer into carriages
    while (cin >> carriages) {
        // Input the order of carriages leaving towards direction B
        int* order = new int[carriages];
        for (int i = 0; i < carriages; i++) {
            cin >> order[i]; 
        }

        // Check the feasibility and output
        if (isFeasibleInRotatedStackville(carriages, order)) {
            cout << "TAK" << endl;
        } else {
            cout << "NIE" << endl;
        }
        delete[] order;
    }
    return 0;
}