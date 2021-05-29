#pragma once

#include <stdexcept>
#include "BinaryTree.hpp"


template<typename T>
class PriorityQueue {
    BinaryTree<T>* m_queue;
    int size;

public:
    //Constructors
    PriorityQueue() {
        m_queue = new BinaryTree<T>();
        size = 0;
    }

    explicit PriorityQueue(T value) {
        m_queue = new BinaryTree<T>(value);
        size = 1;
    }

    explicit PriorityQueue(BinaryTree<T> tree) {
        m_queue = tree.Clone();
        size = tree.GetSize();
    }

    PriorityQueue(PriorityQueue<T> const &queue) {
        if (this->m_queue != nullptr) {
            this->DeleteQueue();
        }
        this->m_queue = new BinaryTree<T>();
        this->size = queue->size;
        this->m_queue = queue->m_queue->Clone();
    }

    //Operations
    int GetSize() {
        return size;
    }

    void Print() {
        m_queue->Print();
    }

    PriorityQueue<T>& operator=(const PriorityQueue<int>& queue) {
        if (this->m_queue != nullptr) {
            this->DeleteQueue();
        }

        this->m_queue = new BinaryTree<T>();
        this->size = queue.size;
        this->m_queue = queue.m_queue->Clone();
        return *this;
    }


    void Insert(T value) {
        m_queue->Insert(value);
        size++;
    }

    bool Find(T value) {
        return m_queue->Find(value);
    }

    void DeleteElement(T value) {
        m_queue->DeleteElement(value);
        size = m_queue->GetSize();
    }

    void DeleteQueue() {
        m_queue->DeleteTree(m_queue->GetRoot());
    }

    T GetFirst() {
        tree_element<T>* current = m_queue->GetRoot();
        while (current->m_left) current = current->m_left;
        return current->m_value;
    }

    T GetLast() {
        tree_element<T>* current = m_queue->GetRoot();
        while (current->m_right) current = current->m_right;
        return current->m_value;
    }

    void Map(void(*func)(tree_element<T>*)) {
        m_queue->Map(func);
    }

    void Where(bool(*func)(tree_element<T>*)) {
        m_queue->Where(func);
        size = m_queue->GetSize();
    }

    T Reduce(T(*func)(tree_element<T>*,T)) {
        return m_queue->Reduce(func);
    }

    PriorityQueue<T>* SubSequence(int StartIndex, int EndIndex) {
        auto queue = new PriorityQueue<T>();
        if (StartIndex >= 0 && EndIndex < GetSize()) {
            vector<T> array = m_queue->TreeToArray();
            for (int i = StartIndex; i <= EndIndex; i++) {
                queue->Insert(array[i]);
            }
        } else {
            throw out_of_range("Index out of range");
        }
        return queue;
    }


    bool FindSubSequence(PriorityQueue<T>* queue) {
        if (queue->GetSize() <= GetSize()) {
            int k = 0;
            vector<T> array1 = m_queue->TreeToArray(); // sorted
            vector<T> array2 = queue->m_queue->TreeToArray(); // sorted
            for (int i = 0; i < array1.size(); i++) {
                if (array1[i] == array2[0]) {
                    for (int j = 0; j < array2.size(); j++) {
                        if (j < GetSize()) {
                            if (array1[i + j] == array2[j]) {
                                k++;
                            }
                        }
                    }
                    if (k == queue->GetSize()) return true;
                }
                k = 0;
            }

        } else {
            return false;
        }
        return false;
    }

    //Destructor
    ~PriorityQueue() {
        DeleteQueue();
    }
};