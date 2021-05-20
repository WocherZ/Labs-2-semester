#pragma once

#include <cmath>
#include "ListSequence.hpp"
#include "ArraySequence.hpp"

using namespace std;

template<class T>
class Set {
    Sequence<T> *elements;

public:
    //Constructors
    Set() : elements() {}

    Set(const Set<T> &set) : elements(set.elements->Clone()) {}

    explicit Set(Sequence<T> *sequence) : elements(sequence->Clone()) {}

    //Operations
    [[nodiscard]] int GetSize() const  {
        return elements->GetSize();
    }

    void Resize(int size)  {
        elements->Resize(size);
    }

    T &Get(int index) const {
        return (*elements)[index];
    }

    T GetFirst() const  {
        return elements->GetFirst();
    }

    T GetLast() const {
        return elements->GetLast();
    }

    T operator[](int index) const {
        return (*elements)[index];
    }

    T &operator[](int index) {
        return (*elements)[index];
    }

    void Append(T &item) {
        elements->Append(item);
    }

    void Prepend(T &item) {
        elements->Prepend(item);
    }

    void InsertAt(T &item, int index) {
        elements->InsertAt(item, index);
    }

    void Print() const {
        elements->Print();
    }

    Set<T> *GetSubsequence(int startIndex, int endIndex) {
        return elements->GetSubsequence(startIndex, endIndex);
    }

    Set<T> *Create_empty_set() {
        auto *result = new Set<T>(new ArraySequence<T>());
        return result;
    }

    //Объединение
    Set<T> *Union(Set<T> &set1) {
        auto *result = new Set<T>(elements);
        for (int i = 0; i < set1.GetSize(); i++) {
            if (!(result->InSet(set1[i]))) result->Append(set1[i]);
        }
        return result;
    }

    //Пересечение
    Set<T> *Cross(Set<T> &set1) {
        auto *result = Create_empty_set();
        auto *U = Union(set1);
        for (int i = 0; i < U->GetSize(); i++) {
            T item = U->Get(i);
            if (InSet(item) and set1.InSet(item)) result->Append(item);
        }
        return result;
    }

    //Вычитание
    Set<T> *Subtraction(Set<T> &set1) {
        auto *result = Create_empty_set();
        for (int i = 0; i < GetSize(); i++) {
            if ( !set1.InSet(Get(i)) ) {
                result->Append(Get(i));
            }
        }
        return result;
    }

    //Проверка на вхождение элемента
    bool InSet(T &item) {
        for (int i = 0; i < GetSize(); i++) {
            if (Get(i) == item) return true;
        }
        return false;
    }

    //Проверка на включение подмножества
    bool InSet(Set<T> &set1) {
        auto *subset = new Set<T>();
        for (int i = 0; i < GetSize(); i++) {
            if (Get(i) == set1.GetFirst()) {
                if (GetSize() > i + set1.GetSize()) {
                    subset = GetSubsequence(i, i + set1.GetSize());
                    if (subset == set1) return true;
                }
            }
        }
        return false;
    }

    //Равенство двух множеств
    friend bool operator==(Set<T> &set1, Set<T> &set2) {
        if (set1.GetSize() != set2.GetSize()) {
            return false;
        } else {
            for (int i = 0; i < set1.GetSize(); i++) {
                if (set1.Get(i) != set2.Get(i)) return false;
            }
        }
        return true;
    }

    //Равенство двух множеств
    bool IsEqual(Set<T> &set1) {
        if (set1.GetSize() != GetSize()) {
            return false;
        } else {
            for (int i = 0; i < GetSize(); i++) {
                if (set1.Get(i) != Get(i)) return false;
            }
        }
        return true;
    }

    Set<T> &operator=(Set<T> *set) {
        elements = set->elements->Clone();
        return *this;
    }

    //Map
    Set<T> *Map(T (*function)(T)) {
        auto *result = Create_empty_set();
        for (int i = 0; i < GetSize(); i ++) {
            T item = function(Get(i));
            result->Append(item);
        }
        return result;
    }

    //Where
    Set<T> *Where(bool (*function)(T)) {
        auto *result = Create_empty_set();
        for (int i = 0; i < GetSize(); i++) {
            if ( function(Get(i)) ) {
                result->Append(Get(i));
            }
        }
        return result;
    }

    //Destructor
    ~Set() = default;
};