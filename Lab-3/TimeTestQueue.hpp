#pragma once

#include <ctime>
#include <random>
#include <cstdlib>
#include <chrono>
#include "PriorityQueue.hpp"

using namespace std;

int randomRange(int low, int high)
{
    return rand() % (high - low + 1) + low;
}


void PrintTimeTestResult(const string &NameTest, int time) {
    cout << "Test " << NameTest << ":" << endl;
    cout << "Time - " << time << " nanoseconds" << endl;
}


int TestInsertIntElement(int n) {
    auto queue1 = new PriorityQueue<int>();

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        queue1->Insert(i);
    }
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestInsertDoubleElement(int n) {
    auto queue1 = new PriorityQueue<double>();

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        queue1->Insert(i * 0.1);
    }
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestInsertCharElement(int n) {
    auto queue1 = new PriorityQueue<char>();

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        queue1->Insert('a');
    }
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}


int TestFindIntElement(int n) {
    auto queue1 = new PriorityQueue<int>();

    for (int i = 0; i < n; i++) {
        queue1->Insert(i);
    }

    auto start_time = chrono::steady_clock::now();
    queue1->Find(n - 1);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestFindDoubleElement(int n) {
    auto queue1 = new PriorityQueue<double>();

    for (int i = 0; i < n; i++) {
        queue1->Insert(i * 0.1);
    }

    auto start_time = chrono::steady_clock::now();
    queue1->Find((n - 1) * 0.1);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestFindCharElement(int n) {
    auto queue1 = new PriorityQueue<char>();
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        const char sim = randomRange('a', 'z');
        queue1->Insert(sim);
    }

    auto start_time = chrono::steady_clock::now();
    queue1->Find('z');
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}


int TestFindIntSubSequence(int n) {
    auto queue1 = new PriorityQueue<int>();

    for (int i = 0; i < n; i++) {
        queue1->Insert(i);
    }

    auto queue2 = new PriorityQueue<int>();

    for (int i = 0; i < n; i++) {
        queue2->Insert(i);
    }

    auto start_time = chrono::steady_clock::now();
    queue1->FindSubSequence(queue2);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestFindDoubleSubSequence(int n) {
    auto queue1 = new PriorityQueue<double>();

    for (int i = 0; i < n; i++) {
        queue1->Insert(i * 0.1);
    }

    auto queue2 = new PriorityQueue<double>();

    for (int i = 0; i < n; i++) {
        queue2->Insert(i * 0.1);
    }

    auto start_time = chrono::steady_clock::now();
    queue1->FindSubSequence(queue2);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestFindCharSubSequence(int n) {
    auto queue1 = new PriorityQueue<char>();

    for (int i = 0; i < n; i++) {
        queue1->Insert('a');
    }

    auto queue2 = new PriorityQueue<char>();

    for (int i = 0; i < n; i++) {
        queue2->Insert('a');
    }

    auto start_time = chrono::steady_clock::now();
    queue1->FindSubSequence(queue2);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}


int TestGiveIntSubSequence(int n) {
    auto queue1 = new PriorityQueue<int>();

    for (int i = 0; i < n; i++) {
        queue1->Insert(i);
    }

    auto start_time = chrono::steady_clock::now();
    queue1->SubSequence(0, queue1->GetSize()-1);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestGiveDoubleSubSequence(int n) {
    auto queue1 = new PriorityQueue<double>();

    for (int i = 0; i < n; i++) {
        queue1->Insert(i * 0.1);
    }

    auto start_time = chrono::steady_clock::now();
    queue1->SubSequence(0, queue1->GetSize()-1);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestGiveCharSubSequence(int n) {
    auto queue1 = new PriorityQueue<char>();

    for (int i = 0; i < n; i++) {
        queue1->Insert('a');
    }

    auto start_time = chrono::steady_clock::now();
    queue1->SubSequence(0, queue1->GetSize()-1);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestDeleteIntElement(int n) {
    auto queue1 = new PriorityQueue<int>();

    for (int i = 0; i < n; i++) {
        queue1->Insert(i);
    }

    auto start_time = chrono::steady_clock::now();
    queue1->DeleteElement(0);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestDeleteDoubleElement(int n) {
    auto queue1 = new PriorityQueue<double>();

    for (int i = 0; i < n; i++) {
        queue1->Insert(i * 0.1);
    }

    auto start_time = chrono::steady_clock::now();
    queue1->DeleteElement(0.0);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestDeleteCharElement(int n) {
    auto queue1 = new PriorityQueue<char>();
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        const char sim = randomRange('a', 'z');
        queue1->Insert(sim);
    }

    auto start_time = chrono::steady_clock::now();
    queue1->DeleteElement('a');
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

void TimeTestQueue(int n) {
    PrintTimeTestResult("Insert int element", TestInsertIntElement(n));
    PrintTimeTestResult("Insert double element", TestInsertDoubleElement(n));
    PrintTimeTestResult("Insert char element", TestInsertCharElement(n));

    PrintTimeTestResult("Find int element", TestFindIntElement(n));
    PrintTimeTestResult("Find double element", TestFindDoubleElement(n));
    PrintTimeTestResult("Find char element", TestFindCharElement(n));

    PrintTimeTestResult("Find int subsequence", TestFindIntSubSequence(n));
    PrintTimeTestResult("Find double subsequence", TestFindDoubleSubSequence(n));
    PrintTimeTestResult("Find char subsequence", TestFindCharSubSequence(n));

    PrintTimeTestResult("Give int subsequence", TestGiveIntSubSequence(n));
    PrintTimeTestResult("Give double subsequence", TestGiveDoubleSubSequence(n));
    PrintTimeTestResult("Give char subsequence", TestGiveCharSubSequence(n));

    PrintTimeTestResult("Delete int element", TestDeleteIntElement(n));
    PrintTimeTestResult("Delete double element", TestDeleteDoubleElement(n));
    PrintTimeTestResult("Delete char element", TestDeleteCharElement(n));

}

