#pragma once

#include "DynamicArray.hpp"

template<class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> items;

public:
    //Constructors
    ArraySequence() : items() {}

    ArraySequence(T *list, int size) : items(list, size) {}

    ArraySequence(const ArraySequence<T> &list) : items() {
        for (int i = 0; i < list.GetSize(); i++)
            Append(list.Get(i));
    }

    //Operations
    [[nodiscard]] int GetSize() const override {
        return items.GetSize();
    }

    void Resize(int size) override {
        items.Resize(size);
    }

    T &Get(int index) const override {
        return items.Get(index);
    }

    T GetFirst() const override {
        return items[0];
    }

    T GetLast() const override {
        return items[items.GetSize() - 1];
    }

    T operator[](int index) const override {
        return items[index];
    }

    T &operator[](int index) override {
        return items[index];
    }

    void Append(T &item) override {
        int size = items.GetSize();
        items.Resize(size + 1);
        items[size] = item;
    }

    void Prepend(T &item) override {
        int size = items.GetSize();
        items.Resize(size + 1);
        for (int i = size; i > 0; i--)
            items[i] = items[i - 1];
        items[0] = item;
    }

    void InsertAt(T &item, int index) override {
        int size = items.GetSize();
        if (index < 0 || index > size)
            throw out_of_range("Index out of range");
        items.Resize(size + 1);
        for (int i = size; i > index; i--)
            items[i] = items[i - 1];
        items[index] = item;
    }

    void Print() const override {
        items.Print();
    }

    Sequence<T> *Concat(Sequence<T> &list) override {
        auto *concatenated = new ArraySequence<T>;
        concatenated->items.Resize(GetSize() + list.GetSize());
        for (int i = 0; i < items.GetSize(); i++)
            concatenated->items[i] = items[i];
        for (int i = 0; i < list.GetSize(); i++)
            concatenated->items[i + items.GetSize()] = list[i];
        return concatenated;
    }

    Sequence<T> *GetSubsequence(int startIndex, int endIndex) override {
        auto *sub = new ArraySequence<T>;
        sub->items.Resize(endIndex - startIndex);
        for (int i = startIndex; i < endIndex; i++)
            sub->items[i - startIndex] = items[i];
        return sub;
    }

    Sequence<T> *Clone() const override {
        auto *new_items = new ArraySequence<T>();
        new_items->Resize(GetSize());
        for (int i = 0; i < GetSize(); i++)
            (*new_items)[i] = items.Get(i);
        return new_items;
    }

    //Destructor
    virtual ~ArraySequence<T>() = default;

};