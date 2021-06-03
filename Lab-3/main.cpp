#include "PriorityQueue.hpp"
#include "TestWorkQueue.hpp"
#include "TimeTestQueue.hpp"
#include "TestWorkBinaryTree.hpp"
#include "TimeTestBinaryTree.hpp"


int main() {
    int choice = 0;
    int n = 1000;
    while (choice != 5) {
        cout << "Choose:" << endl;
        cout << "1. Test work priority queue" << endl;
        cout << "2. Time test priority queue" << endl;
        cout << "3. Test work binary tree" << endl;
        cout << "4. Time test binary tree" << endl;
        cout << "5. Exit" << endl;
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
                TestWorkBinaryTree();
                break;
            }
            case 4: {
                TimeTestBinaryTree(n);
                break;
            }
            case 5: {
                break;
            }
            default: {
                cout << "Enter a number from the list!" << endl;
            }
        }
    }

    return 0;
}