#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

template<class T>
struct Item {
    T value;
    Item<T> *prev = nullptr;
    Item<T> *next = nullptr;

    Item(T value1, Item<T> *prev1, Item<T> *next1) : value(value1), prev(prev1), next(next1) {}

    ~Item() = default;
};

template<class T>
class LinkedList {
    Item<T> *first = nullptr;
    Item<T> *last = nullptr;
    int list_size;

public:
    LinkedList() : first(nullptr), last(nullptr), list_size(0) {}

    LinkedList(T *list, int size) {
        list_size = 0;
        for (int i = 0; i < size; i++)
            Append(list[i]);
    }

    LinkedList(const LinkedList<T> &list) {
        list_size = list.GetSize();
        for (Item<T> *i = list.first; i != nullptr; i = i->next) {
            auto *item = new Item<T>(i->value, last, nullptr);
            if (first == nullptr)
                first = item;
            if (last != nullptr)
                last->next = item;
            last = item;
        }
    }

    T GetFirst() const {
        if (first == nullptr)
            throw out_of_range("Index out of range");
        return first->value;
    }

    T GetLast() const {
        if (last == nullptr)
            throw out_of_range("Index out of range");
        return last->value;
    }

    [[nodiscard]] int GetSize() const {
        return list_size;
    }

    void Resize(int size) {
        if (size < 0)
            throw bad_array_new_length();
        int old_size = GetSize();
        if (size <= old_size) {
            while (old_size != size) {
                Item<T> *item = last;
                last = last->prev;
                delete item;
                old_size--;
            }
            last->next = nullptr;
        } else {
            while (old_size != size) {
                auto *item = new Item<T>(0, last, nullptr);
                last->next = item;
                last = item;
                old_size++;
            }
        }
        list_size = size;
    }

    T &Get(int index) const {
        if (index < 0 || index >= GetSize())
            throw out_of_range("Index out of range");
        int j = 0;
        for (Item<T> *i = first; i != nullptr; i = i->next) {
            if (j == index)
                return i->value;
            j++;
        }
    }

    T operator[](int index) const {
        return Get(index);
    }

    T &operator[](int index) {
        return Get(index);
    }

    void Append(T &item) {
        auto *elem = new Item<T>(item, last, nullptr);
        if (first == nullptr)
            first = elem;
        if (last != nullptr)
            last->next = elem;
        last = elem;
        list_size++;
    }

    void Prepend(T &item) {
        auto *elem = new Item<T>(item, nullptr, first);
        if (first != nullptr)
            first->prev = elem;
        first = elem;
        if (last == nullptr)
            last = elem;
        list_size++;
    }

    void InsertAt(T &item, int index) {
        if (index < 0 || index > GetSize())
            throw out_of_range("Index out of range");
        if (GetSize() == 0) {
            first = new Item<T>(item, nullptr, nullptr);
            last = new Item<T>(item, nullptr, nullptr);
        } else {
            if (index == 0) {
                auto *elem = new Item<T>(item, nullptr, first);
                first->prev = elem;
                first = elem;
            } else {
                Item<T> *i = first;
                for (int j = 0; j < index - 1; j++)
                    i = i->next;
                auto *elem = new Item<T>(item, i, i->next);
                i->next = elem;
                if (elem->next == nullptr) {
                    last = elem;
                } else {
                    elem->next->prev = elem;
                }
            }
        }
        list_size++;
    }

    void Print() const {
        cout << "{";
        for (Item<T> *i = first; i != nullptr; i = i->next) {
            T value = i->value;
            cout << value;
            if (i->next != nullptr) cout << ", ";
        }
        cout << "}";
        cout << endl;
    }

    ~LinkedList() {
        while (first != nullptr) {
            Item<T> *item = first;
            first = first->next;
            delete item;
        }
        first = nullptr;
        last = nullptr;
    }

};