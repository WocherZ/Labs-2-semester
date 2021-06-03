#pragma once

#include <cmath>
#include "PriorityQueue.hpp"

template<typename T>
void square(tree_element<T>* current) { //(для Map)
    current->m_value = current->m_value * current->m_value;
}

template<typename T>
void fractional_part(tree_element<T>* current) {
    current->m_value = modf(current->m_value, &current->m_value);
}

template<typename T>
bool even_number(tree_element<T>* current) {
    if (current->m_value % 2 == 0) return true;
    else return false;
}

template<typename T>
T sum(tree_element<T>* current,T current_sum) { //(для Reduce)
    return current_sum + current->m_value;
}

string print_bool(bool t) {
    if (t) return "True";
    else return "False";
}

void TestIntQueue() {
    int value = 6;
    auto queue1 = new PriorityQueue<int>(value);
    queue1->Insert(4);
    queue1->Insert(8);
    queue1->Insert(5);
    queue1->Insert(3);
    cout << "First queue: ";
    queue1->Print();

    int StartIndex = 1;
    int EndIndex = 3;
    cout << "Second queue is subsequence first queue from 1 to 3 index" << endl;
    auto queue2 = new PriorityQueue<int>();
    queue2 = queue1->SubSequence(StartIndex, EndIndex);
    cout << "Second queue: ";
    queue2->Print();
    cout << endl;

    cout << "OPERATIONS" << endl;

    cout << "Find elements in queue: " << endl;
    cout << "3 in first queue - " << print_bool(queue1->Find(3)) << endl;
    cout << "3 in second queue - " << print_bool(queue2->Find(3)) << endl;
    cout << "5 in first queue - " << print_bool(queue1->Find(5)) << endl;
    cout << "5 in second queue - " << print_bool(queue2->Find(5)) << endl;

    cout << endl;

    cout << "First element in first queue: " << queue1->GetFirst() << endl;
    cout << "Last element in first queue: " << queue1->GetLast() << endl;
    cout << "First element in second queue: " << queue2->GetFirst() << endl;
    cout << "Last element in second queue: " << queue2->GetLast() << endl;

    cout << endl;

    cout << "Second queue is subsequence first queue - ";
    cout << print_bool(queue1->FindSubSequence(queue2)) << endl;
    cout << "First queue is subsequence second queue - ";
    cout << print_bool(queue2->FindSubSequence(queue1)) << endl;
    cout << "First queue is subsequence first queue - ";
    cout << print_bool(queue1->FindSubSequence(queue1)) << endl;

    cout << endl;
    cout << "For first queue:" << endl;
    cout << "Use square for elements(Map): ";
    queue1->Map(square);
    queue1->Print();

    cout << "Use choose even number(Where): ";
    queue1->Where(even_number);
    queue1->Print();

    cout << "Use sum elements(Reduce): ";
    cout << queue1->Reduce(sum) << endl;


    cout << endl;
    cout << "For second queue:" << endl;
    cout << "Use square for elements(Map): ";
    queue2->Map(square);
    queue2->Print();

    cout << "Use choose even number(Where): ";
    queue2->Where(even_number);
    queue2->Print();

    cout << "Use sum elements(Reduce): ";
    cout << queue2->Reduce(sum) << endl;
}

void TestDoubleQueue() {
    double value = 6.6;
    auto queue1 = new PriorityQueue<double>(value);
    queue1->Insert(4.4);
    queue1->Insert(8.8);
    queue1->Insert(5.5);
    queue1->Insert(3.3);
    cout << "First queue: ";
    queue1->Print();

    int StartIndex = 1;
    int EndIndex = 3;
    cout << "Second queue is subsequence first queue from 1 to 3 index" << endl;
    auto queue2 = new PriorityQueue<double>();
    queue2 = queue1->SubSequence(StartIndex, EndIndex);
    cout << "Second queue: ";
    queue2->Print();
    cout << endl;

    cout << "OPERATIONS" << endl;

    cout << "Find elements in queue: " << endl;
    cout << "3.3 in first queue - " << print_bool(queue1->Find(3.3)) << endl;
    cout << "3.3 in second queue - " << print_bool(queue2->Find(3.3)) << endl;
    cout << "5.5 in first queue - " << print_bool(queue1->Find(5.5)) << endl;
    cout << "5.5 in second queue - " << print_bool(queue2->Find(5.5)) << endl;

    cout << endl;

    cout << "First element in first queue: " << queue1->GetFirst() << endl;
    cout << "Last element in first queue: " << queue1->GetLast() << endl;
    cout << "First element in second queue: " << queue2->GetFirst() << endl;
    cout << "Last element in second queue: " << queue2->GetLast() << endl;

    cout << endl;

    cout << "Second queue is subsequence first queue - ";
    cout << print_bool(queue1->FindSubSequence(queue2)) << endl;
    cout << "First queue is subsequence second queue - ";
    cout << print_bool(queue2->FindSubSequence(queue1)) << endl;
    cout << "First queue is subsequence first queue - ";
    cout << print_bool(queue1->FindSubSequence(queue1)) << endl;

    cout << endl;
    cout << "For first queue:" << endl;
    cout << "Use fractional part for elements(Map): ";
    queue1->Map(fractional_part);
    queue1->Print();

    cout << "Use sum elements(Reduce): ";
    cout << queue1->Reduce(sum) << endl;

    cout << endl;
    cout << "For second queue:" << endl;
    cout << "Use fractional part for elements(Map): ";
    queue2->Map(fractional_part);
    queue2->Print();

    cout << "Use sum elements(Reduce): ";
    cout << queue2->Reduce(sum) << endl;
}


void TestCharQueue() {
    char value = 'c';
    auto queue1 = new PriorityQueue<char>(value);
    queue1->Insert('b');
    queue1->Insert('a');
    queue1->Insert('d');
    queue1->Insert('f');
    cout << "First queue: ";
    queue1->Print();

    int StartIndex = 1;
    int EndIndex = 3;
    cout << "Second queue is subsequence first queue from 1 to 3 index" << endl;
    auto queue2 = new PriorityQueue<char>();
    queue2 = queue1->SubSequence(StartIndex, EndIndex);
    cout << "Second queue: ";
    queue2->Print();
    cout << endl;

    cout << "OPERATIONS" << endl;

    cout << "Find elements in queue: " << endl;
    cout << "'a' in first queue - " << print_bool(queue1->Find('a')) << endl;
    cout << "'a' in second queue - " << print_bool(queue2->Find('a')) << endl;
    cout << "'c' in first queue - " << print_bool(queue1->Find('c')) << endl;
    cout << "'c' in second queue - " << print_bool(queue2->Find('c')) << endl;

    cout << endl;

    cout << "First element in first queue: " << queue1->GetFirst() << endl;
    cout << "Last element in first queue: " << queue1->GetLast() << endl;
    cout << "First element in second queue: " << queue2->GetFirst() << endl;
    cout << "Last element in second queue: " << queue2->GetLast() << endl;

    cout << endl;

    cout << "Second queue is subsequence first queue - ";
    cout << print_bool(queue1->FindSubSequence(queue2)) << endl;
    cout << "First queue is subsequence second queue - ";
    cout << print_bool(queue2->FindSubSequence(queue1)) << endl;
    cout << "First queue is subsequence first queue - ";
    cout << print_bool(queue1->FindSubSequence(queue1)) << endl;
}


void TestStringQueue() {
    string value = "c";
    auto queue1 = new PriorityQueue<string>(value);
    queue1->Insert("b");
    queue1->Insert("a");
    queue1->Insert("dg");
    queue1->Insert("f");
    cout << "First queue: ";
    queue1->Print();

    int StartIndex = 1;
    int EndIndex = 3;
    cout << "Second queue is subsequence first queue from 1 to 3 index" << endl;
    auto queue2 = new PriorityQueue<string>();
    queue2 = queue1->SubSequence(StartIndex, EndIndex);
    cout << "Second queue: ";
    queue2->Print();
    cout << endl;

    cout << "OPERATIONS" << endl;

    cout << "Find elements in queue: " << endl;
    cout << "'a' in first queue - " << print_bool(queue1->Find("a")) << endl;
    cout << "'a' in second queue - " << print_bool(queue2->Find("a")) << endl;
    cout << "'c' in first queue - " << print_bool(queue1->Find("c")) << endl;
    cout << "'c' in second queue - " << print_bool(queue2->Find("c")) << endl;

    cout << endl;

    cout << "First element in first queue: " << queue1->GetFirst() << endl;
    cout << "Last element in first queue: " << queue1->GetLast() << endl;
    cout << "First element in second queue: " << queue2->GetFirst() << endl;
    cout << "Last element in second queue: " << queue2->GetLast() << endl;

    cout << endl;

    cout << "Second queue is subsequence first queue - ";
    cout << print_bool(queue1->FindSubSequence(queue2)) << endl;
    cout << "First queue is subsequence second queue - ";
    cout << print_bool(queue2->FindSubSequence(queue1)) << endl;
    cout << "First queue is subsequence first queue - ";
    cout << print_bool(queue1->FindSubSequence(queue1)) << endl;
}


void TestWorkQueue() {
    int choice_type = 0;
    while (choice_type != 5) {
        cout << "Choose type of element for test:" << endl;
        cout << "1. Int" << endl;
        cout << "2. Double" << endl;
        cout << "3. Char" << endl;
        cout << "4. String" << endl;
        cout << "5. Back" << endl;
        cin >> choice_type;

        switch (choice_type) {
            case 1: {
                TestIntQueue();
                cout << endl;
                break;
            }
            case 2: {
                TestDoubleQueue();
                cout << endl;
                break;
            }
            case 3: {
                TestCharQueue();
                break;
            }
            case 4: {
                TestStringQueue();
                break;
            }
            case 5: {
                break;
            }
            default: {
                cout << "Enter a number from the list!" << endl;
            }

        }
        cout << endl;
    }
}