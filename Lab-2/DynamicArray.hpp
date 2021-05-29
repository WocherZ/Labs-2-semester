#pragma once

#include <iostream>
#include <stdexcept>
#include <cstring>

using namespace std;

template<class T>
class DynamicArray {
private:
    int list_size;
    T *items;

public:
    //Constructors
    DynamicArray() : list_size(0) {}

    DynamicArray(T *list, int size) {
        if (size < 0)
            throw bad_alloc();
        items = new T[size];
        list_size = size;
        for (int i = 0; i < size; i++)
            items[i] = list[i];
    }

    DynamicArray(const DynamicArray<T> &list) : list_size(list.list_size), items(list.items) {}

    //Operations
    [[nodiscard]] int GetSize() const {
        return list_size;
    }

    void Resize(int size) {
        if (size < 0)
            throw bad_array_new_length();
        if (size > list_size) {
            T *new_items = new T[size];
            for (int i = 0; i < list_size; ++i)
                new_items[i] = items[i];
            items = new_items;
        }
        list_size = size;
    }

    T &Get(int index) const {
        if (index < 0 || index >= list_size)
            throw out_of_range("Index out of range");
        return items[index];
    }

    T operator[](int index) const {
        if (index < 0 || index >= list_size)
            throw out_of_range("Index out of range");
        return items[index];
    }

    T &operator[](int index) {
        if (index < 0 || index >= list_size)
            throw out_of_range("Index out of range");
        return items[index];
    }

    void Print() const {
        cout << "{";
        for (int i = 0; i < GetSize(); ++i) {
            T value = items[i];
            cout << value;
            if (i != GetSize() - 1) cout << ", ";
        }
        cout << "}";
        cout << endl;
    }

    //Destructor
    ~DynamicArray<T>() = default;
};