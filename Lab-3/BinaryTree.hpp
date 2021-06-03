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
private:
    tree_element<T>* m_root; // Указатель на корень дерева
    int size; // Размер дерева


    // Вспомогательная рекурентная функция для Map
    void MapRecur(void(*func)(tree_element<T>*),tree_element<T>* current) {
        if (current) {
            func(current);
            MapRecur(func, current->m_left);
            MapRecur(func, current->m_right);
        }
    }

    // Вспомогательная рекурентная функция для Where
    void WhereRecur(bool(*func)(tree_element<T>*),tree_element<T>* current) {
        if (current) {
            WhereRecur(func, current->m_left);
            WhereRecur(func, current->m_right);
            if (!func(current)) {
                DeleteElement(current->m_value);
            }
        }
    }

    // Вспомогательная рекурентная функция для Reduce
    void ReduceRecur(T(*func)(tree_element<T>*,T),tree_element<T>* current,T& current_sum) {
        if (current) {
            ReduceRecur(func, current->m_left,current_sum);
            current_sum = func(current, current_sum);
            ReduceRecur(func, current->m_right,current_sum);
        }
    }

    // Вспомогательная рекурентная функция для получения поддерева
    void UpgradeSubTree(BinaryTree<T>* result,tree_element<T>* current) {
        if(current){
            UpgradeSubTree(result,current->m_left);
            result->Insert(current->m_value);
            UpgradeSubTree(result,current->m_right);
        }
    }

    // Вспомогательная рекурентная функция для представления дерева в виде строки
    void TreeToStringHelp(tree_element<T>* current,vector<string>& current_str) {
        if(current){
            TreeToStringHelp(current->m_left,current_str);
            current_str.push_back(to_string(current->m_value));
            TreeToStringHelp(current->m_right,current_str);
        }
    }

    // Вспомогательная рекурентная функция для представления дерева в виде массива
    void TreeToArrayRecur(tree_element<T>* current,vector<T> &array) {
        if (current) {
            TreeToArrayRecur(current->m_left, array);
            array.push_back(current->m_value);
            TreeToArrayRecur(current->m_right, array);
        }
    }

    // Вспомогательная рекурентная функция для балансировки
    void BalanceRecur(BinaryTree<T>* tree, vector<T> &array, int StartIndex, int EndIndex) {
        if (EndIndex - StartIndex > 1) {
            int n = (StartIndex + EndIndex) / 2;
            tree->Insert(array[n]);
            tree->BalanceRecur(tree, array, StartIndex, n - 1);
            tree->BalanceRecur(tree, array, n + 1, EndIndex);
        } else {
            if (StartIndex == EndIndex) {
                tree->Insert(array[StartIndex]);
            }
            else {
                tree->Insert(array[EndIndex]);
                tree->Insert(array[StartIndex]);
            }
        }
    }


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

    tree_element<T>* GetRoot() {
        return m_root;
    }

    T GetRootValue() {
        return m_root->m_value;
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

    // Поиск
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

    // Вставка
    void Insert(T value) {
        if (m_root == nullptr) {
            m_root = new tree_element<T>(value);
            size = 1;
        } else {
            tree_element<T>* current = m_root;
            while(current || current->m_value != value) {
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

    // Удаление элемента
    void DeleteElement(T key)
    {
        tree_element<T>* current = m_root;
        tree_element<T>* parent = NULL;
        while (current && current->m_value != key)
        {
            parent = current;
            if (current->m_value > key)
            {
                current = current->m_left;
            }
            else
            {
                current = current->m_right;
            }
        }
        if (!current)
            return;
        if (current->m_left == NULL)
        {

            if (parent && parent->m_left == current)
                parent->m_left = current->m_right;
            if (parent && parent->m_right == current)
                parent->m_right = current->m_right;
            size--;
            delete current;
            return;
        }
        if (current->m_right == NULL)
        {

            if (parent && parent->m_left == current)
                parent->m_left = current->m_left;
            if (parent && parent->m_right == current)
                parent->m_right = current->m_left;
            size--;
            delete current;
            return;
        }

        tree_element<T>* replace = current->m_right;
        while (replace->m_left)
            replace = replace->m_left;
        int replace_value = replace->m_value;
        DeleteElement(replace_value);
        current->m_value = replace_value;
    }

    // Удаление дерева
    void DeleteTree(tree_element<T>* current) {
        if(current) {
            DeleteTree(current->m_left);
            DeleteTree(current->m_right);
            delete[] current;
        }
    }

    // Копирование узла
    tree_element<T> *CloneElement(tree_element<T>* element) {
        tree_element<T>* result = new tree_element(element->m_value);
        if (element->m_left) result->m_left = CloneElement(element->m_left);
        else result->m_left = nullptr;
        if (element->m_right) result->m_right = CloneElement(element->m_right);
        else result->m_right = nullptr;
        return result;
    }

    // Копирование дерева
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


    // Равенство двух узлов
    bool IsEquals(tree_element<T>* first, tree_element<T>* second) {

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


    // Поиск поддерева
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


    // Получение поддерева
    BinaryTree<T>* GetSubTree(T value) {

        tree_element<T>* current = m_root;
        while (current && current->m_value!=value)
            if (current->m_value < value) current = current->m_right;
            else current = current->m_left;
        auto* result = new BinaryTree<T>(current->m_value);
        UpgradeSubTree(result,current);

        return result;
    }


    // Представление дерева в виде строки
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


    // Представление дерева массивом
    vector<T> TreeToArray() {
        tree_element<T>* current = m_root;
        vector<T> result;
        result.reserve(GetSize());
        TreeToArrayRecur(current, result);

        return result;
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

    // Балансировка
    BinaryTree<T>* Balance() {
        vector<T> arrayTree = TreeToArray();
        BinaryTree<T>* newtree = new BinaryTree<T>();
        newtree->BalanceRecur(newtree, arrayTree, 0, GetSize()-1);
        return newtree;
    }


    //Destructor
    ~BinaryTree() {
        DeleteTree(m_root);
    }
};