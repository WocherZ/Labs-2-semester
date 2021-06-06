#include <iostream>
#include "test_sets.hpp"
#include "time_test_sets.hpp"
#include "TimeTestStlSet.h"

using namespace std;


int main() {
    int choice = 0, type_test = 0;

    while (choice != 4) {
        cout << endl << "Select an action:" << endl;
        cout << "1. Run tests" << endl << "2. Run time test" << endl << "3. Run time test stl set" << endl << "4. Exit" << endl;
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1: { //Tests
                while (type_test != 5) {
                    cout << "Select type of test:" << endl;
                    cout << "1. Int set" << endl << "2. Double set" << endl << "3. Char set" << endl << "4. String set" << endl << "5. Go back" << endl;
                    cin >> type_test;
                    switch (type_test) {
                        case 1: {
                            test_int_set();
                            break;
                        }
                        case 2: {
                            test_double_set();
                            break;
                        }
                        case 3: {
                            test_char_set();
                            break;
                        }
                        case 4: {
                            test_string_set();
                            break;
                        }
                        case 5: {
                            break;
                        }
                        default: {
                            cout << "Enter a number from the list!" << endl;
                            break;
                        }
                    }
                    cout << endl;
                }
                break;
            }
            case 2: { //Time test
                Test_Time_Set(1000);
                break;
            }
            case 3: {
                Test_Time_Stl_Set(1000);
                break;
            }
            case 4: {
                break;
            }
            default: {
                cout << "Enter a number from the list!" << endl;
                break;
            }
        }
    }
    return 0;
}
