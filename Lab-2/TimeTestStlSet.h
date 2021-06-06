#pragma once

#include <chrono>
#include <set>
#include <ctime>
#include <random>

int randomRange(int low, int high)
{
    return rand() % (high - low + 1) + low;
}

void print_result_set(const string &Test, int time) {
    cout << "Test " << Test << endl;
    cout << "Time: " << time << " nanoseconds" << endl;
}

int test_insert_int_stlset(int n) {
    multiset<int> set;

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        set.insert(i);
    }
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int test_insert_double_stlset(int n) {
    multiset<double> set;

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        set.insert(i);
    }
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int test_insert_char_stlset(int n) {
    multiset<char> set;

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        set.insert('a');
    }
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int test_insert_string_stlset(int n) {
    multiset<string> set;

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        set.insert("a");
    }
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int test_find_int_stlset(int n) {
    multiset<int> set;

    for (int i = 0; i < n; i++) {
        set.insert(i);
    }

    auto start_time = chrono::steady_clock::now();
    set.find(n);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int test_find_double_stlset(int n) {
    multiset<double> set;

    for (int i = 0; i < n; i++) {
        set.insert(i);
    }

    auto start_time = chrono::steady_clock::now();
    set.find(n);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int test_find_char_stlset(int n) {
    multiset<char> set;

    for (int i = 0; i < n; i++) {
        set.insert('a');
    }

    auto start_time = chrono::steady_clock::now();
    set.find('b');
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int test_find_string_stlset(int n) {
    multiset<string> set;

    for (int i = 0; i < n; i++) {
        set.insert("a");
    }

    auto start_time = chrono::steady_clock::now();
    set.find("b");
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int test_count_int_stlset(int n) {
    multiset<int> set;

    for (int i = 0; i < n; i++) {
        set.insert(1);
    }

    auto start_time = chrono::steady_clock::now();
    set.count(1);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int test_count_double_stlset(int n) {
    multiset<double> set;

    for (int i = 0; i < n; i++) {
        set.insert(1.1);
    }

    auto start_time = chrono::steady_clock::now();
    set.count(1.1);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int test_count_char_stlset(int n) {
    multiset<char> set;

    for (int i = 0; i < n; i++) {
        set.insert('a');
    }

    auto start_time = chrono::steady_clock::now();
    set.count('a');
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int test_count_string_stlset(int n) {
    multiset<string> set;

    for (int i = 0; i < n; i++) {
        set.insert("A");
    }

    auto start_time = chrono::steady_clock::now();
    set.count("A");
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}


void Test_Time_Stl_Set(int n) {
    cout << "TIME TESTS Stl Set" << endl;

    print_result_set("Insert int element", test_insert_int_stlset(n));
    print_result_set("Insert double element", test_insert_double_stlset(n));
    print_result_set("Insert char element", test_insert_char_stlset(n));
    print_result_set("Insert string element", test_insert_string_stlset(n));

    print_result_set("Find int element", test_find_int_stlset(n));
    print_result_set("Find double element", test_find_double_stlset(n));
    print_result_set("Find char element", test_find_char_stlset(n));
    print_result_set("Find string element", test_find_string_stlset(n));

    print_result_set("Count int element", test_count_int_stlset(n));
    print_result_set("Count double element", test_count_double_stlset(n));
    print_result_set("Count char element", test_count_char_stlset(n));
    print_result_set("Count string element", test_count_string_stlset(n));

}