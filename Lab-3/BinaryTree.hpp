#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
class tree_element { // Element of binary tree
public:
    T m_value;
    tree_element* m_left;
    tree_element* m_right;

    //Constructors
    tree_element(T value) {
        m_value = value;
        m_left = nullptr;
        m_right = nullptr;
    }

    tree_element(T value, tree_element<T> *left, tree_element<T> *right) {
        m_value = value;
        m_left = left;
        m_right = right;
    }
};


template<typename T>
class BinaryTree { // Binary tree
    tree_element<T>* m_root;

    int size;

public:
    //Constructors
    BinaryTree() {
        m_root = nullptr;
        size = 0;
    }

    explicit BinaryTree(T value) {
        m_root = new tree_element<T>(value);
        size = 1;
    }

    BinaryTree(BinaryTree<T> const &tree) {
        m_root = tree.m_root;
        size = tree.size;
    }

    //Operations
    int GetSize() {
        return size;
    }

    void PrintTree(tree_element<T>* current) {
        if (current) {
            if (current->m_left) PrintTree(current->m_left);
            cout << current->m_value << " ";
            if (current->m_right) PrintTree(current->m_right);
        }
    }

    void Print() {
        PrintTree(m_root);
        cout << endl;
    }

    bool Find(T value) {

        tree_element<T>* current = m_root;
        while(current && current->m_value != value){
            if(current->m_value > value)
                current = current->m_left;
            else
                current = current->m_right;
        }
        return (bool)current;
    }


    void Insert(T value) {
        if (m_root == nullptr) {
            m_root = new tree_element<T>(value);
            size = 1;
        } else {
            tree_element<T>* current = m_root;
            while(current && current->m_value != value) {
                if (current->m_value > value) {
                    if (current->m_left) current = current->m_left;
                    else {
                        current->m_left = new tree_element<T>(value);
                        size++;
                        return;
                    }
                }
                else{
                    if (current->m_right) current = current->m_right;
                    else{
                        current->m_right = new tree_element<T>(value);
                        size++;
                        return;
                    }
                }
            }
        }
    }

    void DeleteElement(T value) {
        tree_element<T>* current = m_root;
        tree_element<T>* prev = nullptr;

        while(current && current->m_value != value) {
            prev = current;
            if (current->m_value > value) current = current->m_left;
            else current = current->m_right;
        }
        if (!current)
            return;


        if(prev->m_right == current) {
            if (current->m_right == nullptr && current->m_left == nullptr){
                prev->m_right = nullptr;
                delete[] current;
                size--;
                return;
            }
            if (current->m_left == nullptr) {
                prev->m_right = current->m_right;
                delete[] current;
                size--;
                return;
            }
            if (current->m_right == nullptr) {
                prev->m_right = current->m_left;
                delete[] current;
                size--;
                return;
            }
        }

        if (prev->m_left == current) {
            if (current->m_right == nullptr && current->m_left == nullptr) {
                prev->m_left = nullptr;
                delete[] current;
                size--;
                return;
            }
            if (current->m_left == nullptr) {
                prev->m_left = current->m_right;
                delete[] current;
                size--;
                return;
            }
            if (current->m_right == nullptr) {
                prev->m_left = current->m_left;
                delete[] current;
                size--;
                return;
            }
        }

        tree_element<T>* tmp = current->m_right;
        while (tmp->m_left) tmp = tmp->m_left;

        T minimum = tmp->m_value;



        if (prev->m_left == current) {
            DeleteElement(tmp->m_value);
            prev->m_left = new tree_element<T>(minimum,current->m_left,current->m_right);
            delete[] current;
            size--;
            return;
        }
        if (prev->m_right == current) {
            DeleteElement(tmp->m_value);
            prev->m_right = new tree_element<T>(minimum,current->m_left,current->m_right);
            delete[] current;
            size--;
            return;
        }
    }


    void DeleteTree(tree_element<T>* current) {
        if(current) {
            DeleteTree(current->m_left);
            DeleteTree(current->m_right);
            delete[] current;
        }
    }

    tree_element<T> *CloneElement(tree_element<T>* element) {
        tree_element<T>* result = new tree_element(element->m_value);
        if (element->m_left) result->m_left = CloneElement(element->m_left);
        else result->m_left = nullptr;
        if (element->m_right) result->m_right = CloneElement(element->m_right);
        else result->m_right = nullptr;
        return result;
    }

    BinaryTree<T> *Clone() {
        auto *result = new BinaryTree<T>();
        result->m_root = CloneElement(m_root);
        result->size = GetSize();
        return result;
    }

    BinaryTree<T>& operator=(BinaryTree<T> *tree1) {
        if (this->m_root != nullptr) this->DeleteTree(this->m_root);
        this = tree1->Clone();
        return *this;
    }

    tree_element<T>* GetRoot() {
        return m_root;
    }



    static bool IsEquals(tree_element<T>* first, tree_element<T>* second) {

        if (second->m_right == nullptr && second->m_left == nullptr && first->m_value == second->m_value) {

            return true;
        }

        if (second->m_left != nullptr && first->m_left == nullptr) {
            return false;
        }

        if (second->m_right != nullptr && first->m_right == nullptr)
            return false;

        if (first->m_value != second->m_value)
            return false;

        if (first->m_right != nullptr && second->m_right!= nullptr && second->m_left == nullptr)
            return IsEquals(first->m_right,second->m_right);

        if (first->m_left != nullptr && second->m_left!= nullptr && second->m_right == nullptr)
            return IsEquals(first->m_left,second->m_left);


        if (first->m_left != nullptr && second->m_left != nullptr && first->m_value == second->m_value)
            return IsEquals(first->m_left,second->m_left);

        if (first->m_right != nullptr && second->m_right != nullptr && first->m_value == second->m_value)
            return IsEquals(first->m_right,second->m_right);

    }

    void UpgradeSubTree(BinaryTree<T>* result,tree_element<T>* current) {
        if(current){
            UpgradeSubTree(result,current->m_left);
            result->Insert(current->m_value);
            UpgradeSubTree(result,current->m_right);
        }
    }


    bool IsSubtree(BinaryTree<T>* second) {

        tree_element<T>* current = m_root;
        while(current && current->m_value != second->m_root->m_value){
            if(current->m_value > second->m_root->m_value)
                current = current->m_left;
            else
                current = current->m_right;
        }

        return IsEquals(current,second->m_root);
    }


    BinaryTree<T>* GetSubTree(T value) {

        tree_element<T>* current = m_root;
        while (current && current->m_value!=value)
            if (current->m_value < value) current = current->m_right;
            else current = current->m_left;
        auto* result = new BinaryTree<T>(current->m_value);
        UpgradeSubTree(result,current);

        return result;
    }

    void TreeToStringHelp(tree_element<T>* current,vector<string>& current_str) {
        if(current){
            TreeToStringHelp(current->m_left,current_str);
            current_str.push_back(to_string(current->m_value));
            TreeToStringHelp(current->m_right,current_str);
        }
    }


    string TreeToString() {

        tree_element<T>* current = m_root;
        vector<string> result;
        TreeToStringHelp(current,result);

        string result_string = "";
        for (int i = 0; i < result.size(); i++) {
            result_string += result[i] + " ";
        }
        return result_string;
    }

    void TreeToArrayRecur(tree_element<T>* current,vector<T> &array) {
        if (current) {
            TreeToArrayRecur(current->m_left, array);
            array.push_back(current->m_value);
            TreeToArrayRecur(current->m_right, array);
        }
    }

    vector<T> TreeToArray() {
        tree_element<T>* current = m_root;
        vector<T> result;
        result.reserve(GetSize());
        TreeToArrayRecur(current, result);

        return result;
    }

    void MapRecur(void(*func)(tree_element<T>*),tree_element<T>* current) {
        if (current) {
            func(current);
            MapRecur(func, current->m_left);
            MapRecur(func, current->m_right);
        }
    }

    void WhereRecur(bool(*func)(tree_element<T>*),tree_element<T>* current) {
        if (current) {
            WhereRecur(func, current->m_left);
            WhereRecur(func, current->m_right);
            if (!func(current)) {
                DeleteElement(current->m_value);
            }
        }
    }

    void ReduceRecur(T(*func)(tree_element<T>*,T),tree_element<T>* current,T& current_sum) {
        if (current) {
            ReduceRecur(func, current->m_left,current_sum);
            current_sum = func(current, current_sum);
            ReduceRecur(func, current->m_right,current_sum);
        }
    }

    // Map
    void Map(void(*func)(tree_element<T>*)) {
        tree_element<T>* current = m_root;
        MapRecur(func,current);
    }

    // Where
    void Where(bool(*func)(tree_element<T>*)) {
        tree_element<T>* current = m_root;
        WhereRecur(func,current);
    }

    // Reduce
    T Reduce(T(*func)(tree_element<T>*,T)) {
        tree_element<T>* current = m_root;
        T current_sum = 0;
        ReduceRecur(func,current,current_sum);
        return current_sum;
    }

    //Destructor
    ~BinaryTree() {
        DeleteTree(m_root);
    }
};