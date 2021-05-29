#pragma once

#include <chrono>
#include "PriorityQueue.hpp"


void PrintTimeTestResult(string &NameTest, int time) {
    cout << "Test " << NameTest << ":" << endl;
    cout << "Time - " << time << " microseconds" << endl;
}


int TestInsertIntElement(int n) {
    auto queue1 = new PriorityQueue<int>();

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        queue1->Insert(i);
    }
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    return time;
}


int TestFindIntElement(int n) {
    auto queue1 = new PriorityQueue<int>();

    for (int i = 0; i < n; i++) {
        queue1->Insert(i);
    }

    auto start_time = chrono::steady_clock::now();
    queue1->Find(n -1);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    return time;
}

int TestDeleteIntElement(int n) {
    auto queue1 = new PriorityQueue<int>();

    for (int i = 0; i < n; i++) {
        queue1->Insert(i);
    }

    auto start_time = chrono::steady_clock::now();
    queue1->DeleteElement(n -1);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    return time;
}


int TestFindIntSubSequence(int n) {
    auto queue1 = new PriorityQueue<int>();

    for (int i = 0; i < n; i++) {
        queue1->Insert(i);
    }

    auto queue2 = new PriorityQueue<int>(n - 1);

    auto start_time = chrono::steady_clock::now();
    queue1->FindSubSequence(queue2);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    return time;
}

void TimeTestQueue(int n) {
    string test = "Insert int element";
    PrintTimeTestResult(test, TestInsertIntElement(n));
    test = "Find int element";
    PrintTimeTestResult(test, TestFindIntElement(n));
    test = "Delete int element";
    PrintTimeTestResult(test, TestDeleteIntElement(n));
    test = "Find int subsequence";
    PrintTimeTestResult(test, TestFindIntSubSequence(n));
}

