#pragma once

#include <cassert>
#include <chrono>
#include "sets.hpp"

void print_result(const string &Test, pair<int, int> times) {
    int array_time = times.first;
    int list_time = times.second;
    cout << Test << ":" << endl;
    if (array_time > list_time) cout << "Linked List faster than Dynamic Array" << endl;
    else if (list_time > array_time) cout << "Dynamic array faster than Linked List" << endl;
    else cout << "Linked List as fast as Dynamic Array" << endl;

    cout << "Dynamic Array: " << array_time << " microseconds" << endl;
    cout << "Linked list: " << list_time << " microseconds" << endl;
}

pair<int, int> test_create_int_set(int n) {
    int elements[n];
    for (int i =0; i < n; i++) {
        elements[i] = i + 1;
    }

    auto start_time = chrono::steady_clock::now();
    Set<int> array_set(new ArraySequence<int>(elements, n));
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    Set<int> list_set(new ListSequence<int>(elements, n));
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_create_double_set(int n) {
    double elements[n];
    for (int i =0; i < n; i++) {
        elements[i] = i + 1;
    }

    auto start_time = chrono::steady_clock::now();
    Set<double> array_set(new ArraySequence<double>(elements, n));
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    Set<double> list_set(new ListSequence<double>(elements, n));
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_create_char_set(int n) {
    char elements[n];
    for (int i =0; i < n; i++) {
        elements[i] = 'a';
    }

    auto start_time = chrono::steady_clock::now();
    Set<char> array_set(new ArraySequence<char>(elements, n));
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    Set<char> list_set(new ListSequence<char>(elements, n));
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_create_string_set(int n) {
    string elements[n];
    for (int i =0; i < n; i++) {
        elements[i] = "a";
    }

    auto start_time = chrono::steady_clock::now();
    Set<string> array_set(new ArraySequence<string>(elements, n));
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    Set<string> list_set(new ListSequence<string>(elements, n));
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_get_int(const int n) {
    int elements[n];
    for (int i = 0; i < n; i++) {
        elements[i] = i + 1;
    }

    Set<int> array_set(new ArraySequence<int>(elements, n));
    Set<int> list_set(new ListSequence<int>(elements, n));

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        int item = array_set[i];
    }
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        int item = list_set[i];
    }
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    return {array_time, list_time};
}


pair<int, int> test_get_double(const int n) {
    double elements[n];
    for (int i = 0; i < n; i++) {
        elements[i] = i + 1;
    }

    Set<double> array_set(new ArraySequence<double>(elements, n));
    Set<double> list_set(new ListSequence<double>(elements, n));

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        double item = array_set[i];
    }
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        double item = list_set[i];
    }
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    return {array_time, list_time};
}


pair<int, int> test_get_char(const int n) {
    char elements[n];
    for (int i = 0; i < n; i++) {
        elements[i] = 'a';
    }

    Set<char> array_set(new ArraySequence<char>(elements, n));
    Set<char> list_set(new ListSequence<char>(elements, n));

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        char item = array_set[i];
    }
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        char item = list_set[i];
    }
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    return {array_time, list_time};
}


pair<int, int> test_get_string(const int n) {
    string elements[n];
    for (int i = 0; i < n; i++) {
        elements[i] = 'a';
    }

    Set<string> array_set(new ArraySequence<string>(elements, n));
    Set<string> list_set(new ListSequence<string>(elements, n));

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        string item = array_set[i];
    }
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        string item = list_set[i];
    }
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    return {array_time, list_time};
}


pair<int, int> test_append_int(int n) {
    Set<int> array_set(new ArraySequence<int>());
    Set<int> list_set(new ListSequence<int>());

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        int item = i;
        array_set.Append(item);
    }
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        int item = i;
        list_set.Append(item);
    }
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_append_double(int n) {
    Set<double> array_set(new ArraySequence<double>());
    Set<double> list_set(new ListSequence<double>());

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        double item = i;
        array_set.Append(item);
    }
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        double item = i;
        list_set.Append(item);
    }
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_append_char(int n) {
    Set<char> array_set(new ArraySequence<char>());
    Set<char> list_set(new ListSequence<char>());

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        char item = 'a';
        array_set.Append(item);
    }
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        char item = 'a';
        list_set.Append(item);
    }
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_append_string(int n) {
    Set<string> array_set(new ArraySequence<string>());
    Set<string> list_set(new ListSequence<string>());

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        string item = "a";
        array_set.Append(item);
    }
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        string item = "a";
        list_set.Append(item);
    }
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_insert_int(int n) {
    Set<int> array_set(new ArraySequence<int>());
    Set<int> list_set(new ListSequence<int>());

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        int item = i + 1;
        array_set.InsertAt(item, array_set.GetSize() / 2);
    }
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        int item = i + 1;
        list_set.InsertAt(item, list_set.GetSize() / 2);
    }
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_insert_double(int n) {
    Set<double> array_set(new ArraySequence<double>());
    Set<double> list_set(new ListSequence<double>());

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        double item = i + 1;
        array_set.InsertAt(item, array_set.GetSize() / 2);
    }
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        double item = i + 1;
        list_set.InsertAt(item, list_set.GetSize() / 2);
    }
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_insert_char(int n) {
    Set<char> array_set(new ArraySequence<char>());
    Set<char> list_set(new ListSequence<char>());

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        char item = 'a';
        array_set.InsertAt(item, array_set.GetSize() / 2);
    }
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        char item = 'a';
        list_set.InsertAt(item, list_set.GetSize() / 2);
    }
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_insert_string(int n) {
    Set<string> array_set(new ArraySequence<string>());
    Set<string> list_set(new ListSequence<string>());

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        string item = "a";
        array_set.InsertAt(item, array_set.GetSize() / 2);
    }
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        string item = "a";
        list_set.InsertAt(item, list_set.GetSize() / 2);
    }
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_union_int_sets(int n) {
    int elements[n];
    for (int i = 0; i < n; i++) {
        elements[n] = i;
    }

    Set<int> array_set(new ArraySequence<int>(elements, n));
    Set<int> list_set(new ListSequence<int>(elements, n));

    auto start_time = chrono::steady_clock::now();
    array_set = array_set.Union(array_set);
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    list_set = list_set.Union(list_set);
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_union_double_sets(int n) {
    double elements[n];
    for (int i = 0; i < n; i++) {
        elements[n] = i;
    }

    Set<double> array_set(new ArraySequence<double>(elements, n));
    Set<double> list_set(new ListSequence<double>(elements, n));


    auto start_time = chrono::steady_clock::now();
    array_set = array_set.Union(array_set);
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    list_set = list_set.Union(list_set);
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_union_char_sets(int n) {
    char elements[n];
    for (int i = 0; i < n; i++) {
        elements[n] = 'a';
    }

    Set<char> array_set(new ArraySequence<char>(elements, n));
    Set<char> list_set(new ListSequence<char>(elements, n));

    auto start_time = chrono::steady_clock::now();
    array_set = array_set.Union(array_set);
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    list_set = list_set.Union(list_set);
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_union_string_sets(int n) {
    string elements[n];
    for (int i = 0; i < n; i++) {
        elements[n] = "a";
    }

    Set<string> array_set(new ArraySequence<string>(elements, n));
    Set<string> list_set(new ListSequence<string>(elements, n));

    auto start_time = chrono::steady_clock::now();
    array_set = array_set.Union(array_set);
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    list_set = list_set.Union(list_set);
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_cross_int_sets(int n) {
    int elements[n];
    for (int i = 0; i < n; i++) {
        elements[n] = i;
    }

    Set<int> array_set(new ArraySequence<int>(elements, n));
    Set<int> list_set(new ListSequence<int>(elements, n));

    auto start_time = chrono::steady_clock::now();
    array_set = array_set.Cross(array_set);
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    list_set = list_set.Cross(list_set);
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_cross_double_sets(int n) {
    double elements[n];
    for (int i = 0; i < n; i++) {
        elements[n] = i;
    }

    Set<double> array_set(new ArraySequence<double>(elements, n));
    Set<double> list_set(new ListSequence<double>(elements, n));

    auto start_time = chrono::steady_clock::now();
    array_set = array_set.Cross(array_set);
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    list_set = list_set.Cross(list_set);
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_cross_char_sets(int n) {
    char elements[n];
    for (int i = 0; i < n; i++) {
        elements[n] = 'a';
    }

    Set<char> array_set(new ArraySequence<char>(elements, n));
    Set<char> list_set(new ListSequence<char>(elements, n));

    auto start_time = chrono::steady_clock::now();
    array_set = array_set.Cross(array_set);
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    list_set = list_set.Cross(list_set);
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_cross_string_sets(int n) {
    string elements[n];
    for (int i = 0; i < n; i++) {
        elements[n] = "a";
    }

    Set<string> array_set(new ArraySequence<string>(elements, n));
    Set<string> list_set(new ListSequence<string>(elements, n));

    auto start_time = chrono::steady_clock::now();
    array_set = array_set.Cross(array_set);
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    list_set = list_set.Cross(list_set);
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(array_set == list_set);

    return {array_time, list_time};
}


pair<int, int> test_inset_int_element(int n) {
    int elements[n];
    for (int i = 0; i < n; i++) {
        elements[n] = i;
    }
    int item = n;
    elements[n - 1] = item;

    Set<int> array_set(new ArraySequence<int>(elements, n));
    Set<int> list_set(new ListSequence<int>(elements, n));

    auto start_time = chrono::steady_clock::now();
    bool check_array = array_set.InSet(item);
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    bool check_list = list_set.InSet(item);
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(check_array == check_list);

    return {array_time, list_time};
}


pair<int, int> test_inset_double_element(int n) {
    double elements[n];
    for (int i = 0; i < n; i++) {
        elements[n] = i;
    }
    double item = n;
    elements[n - 1] = item;

    Set<double> array_set(new ArraySequence<double>(elements, n));
    Set<double> list_set(new ListSequence<double>(elements, n));

    auto start_time = chrono::steady_clock::now();
    bool check_array = array_set.InSet(item);
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    bool check_list =  list_set.InSet(item);
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(check_array == check_list);

    return {array_time, list_time};
}


pair<int, int> test_inset_char_element(int n) {
    char elements[n];
    for (int i = 0; i < n; i++) {
        elements[n] = 'a';
    }
    char item = 'b';
    elements[n - 1] = item;
    Set<char> array_set(new ArraySequence<char>(elements, n));
    Set<char> list_set(new ListSequence<char>(elements, n));


    auto start_time = chrono::steady_clock::now();
    bool check_array = array_set.InSet(item);
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    bool check_list = list_set.InSet(item);
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(check_array == check_list);

    return {array_time, list_time};
}


pair<int, int> test_inset_string_element(int n) {
    string elements[n];
    for (int i = 0; i < n; i++) {
        elements[n] = "a";
    }
    string item = "b";
    elements[n - 1] = item;
    Set<string> array_set(new ArraySequence<string>(elements, n));
    Set<string> list_set(new ListSequence<string>(elements, n));

    auto start_time = chrono::steady_clock::now();
    bool check_array = array_set.InSet(item);
    auto end_time = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::steady_clock::now();
    bool check_list = list_set.InSet(item);
    end_time = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    assert(check_array == check_list);

    return {array_time, list_time};
}


void Test_Time_Set(int n) {
    cout << "TIME TESTS" << endl;

    print_result("Create INT set", test_create_int_set(n));
    print_result("Create DOUBLE set", test_create_double_set(n));
    print_result("Create CHAR set", test_create_char_set(n));
    print_result("Create STRING set", test_create_string_set(n));

    print_result("Get INT", test_get_int(n));
    print_result("Get DOUBLE", test_get_double(n));
    print_result("Get CHAR", test_get_char(n));
    print_result("Get STRING", test_get_string(n));

    print_result("Append INT", test_append_int(n));
    print_result("Append DOUBLE", test_append_double(n));
    print_result("Append CHAR", test_append_char(n));
    print_result("Append STRING", test_append_string(n));

    print_result("Insert INT", test_insert_int(n));
    print_result("Insert DOUBLE", test_insert_double(n));
    print_result("Insert CHAR", test_insert_char(n));
    print_result("Insert STRING", test_insert_string(n));

    print_result("Union INT sets", test_union_int_sets(n));
    print_result("Union DOUBLE sets", test_union_double_sets(n));
    print_result("Union CHAR sets", test_union_char_sets(n));
    print_result("Union STRING sets", test_union_string_sets(n));

    print_result("Cross INT sets", test_create_int_set(n));
    print_result("Cross DOUBLE sets", test_cross_double_sets(n));
    print_result("Cross CHAR sets", test_cross_char_sets(n));
    print_result("Cross STRING sets", test_cross_string_sets(n));

    print_result("Check entering INT element in set", test_inset_int_element(n));
    print_result("Check entering DOUBLE element in set", test_inset_double_element(n));
    print_result("Check entering CHAR element in set", test_inset_char_element(n));
    print_result("Check entering STRING element in set", test_inset_string_element(n));

}