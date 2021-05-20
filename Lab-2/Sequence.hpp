#pragma once

template<class T>
class Sequence {
public:
    //Operations
    [[nodiscard]] virtual int GetSize() const = 0;

    virtual void Resize(int size) = 0;

    virtual T &Get(int index) const = 0;

    virtual T GetFirst() const = 0;

    virtual T GetLast() const = 0;

    virtual T operator[](int index) const = 0;

    virtual T &operator[](int index) = 0;

    virtual void Append(T &item) = 0;

    virtual void Prepend(T &item) = 0;

    virtual void InsertAt(T &item, int index) = 0;

    virtual void Print() const = 0;

    virtual Sequence<T> *Concat(Sequence<T> &list) = 0;

    virtual Sequence<T> *GetSubsequence(int startIndex, int endIndex) = 0;

    virtual Sequence<T> *Clone() const = 0;

    //Destructor
    virtual ~Sequence<T>() = default;
};