#include "PriorityQueue.hpp"
#include "TestWorkQueue.hpp"
#include "TimeTestQueue.hpp"


int main() {
    int choice = 0;
    int n = 1000;
    while (choice != 3) {
        cout << "Choose:" << endl;
        cout << "1. Test work" << endl;
        cout << "2. Time test" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;

        switch(choice) {
            case 1: {
                TestWorkQueue();
                break;
            }
            case 2: {
                TimeTestQueue(n);
                break;
            }
            case 3: {
                break;
            }
            default: {
                cout << "Enter a number from the list!" << endl;
            }
        }
    }

    return 0;
}