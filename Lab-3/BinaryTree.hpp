#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
class tree_element { // Element of tree
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

    //конструктор с добавлением корня
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
            //cout << "PrintTree" << endl;
            if (current->m_left) PrintTree(current->m_left);
            cout << current->m_value << " ";
            if (current->m_right) PrintTree(current->m_right);
        }
    }

    //печать дерева
    void Print() {
        PrintTree(m_root);
        cout << endl;
    }


    //поиск элемента в дереве
    bool Find(T value) {//поиск значения

        tree_element<T>* current = m_root;
        while(current && current->m_value != value){
            if(current->m_value > value)
                current = current->m_left;
            else
                current = current->m_right;
        }
        return (bool)current;
    }


    //добавление элемента
    void Insert(T value) {//добавление нового элемента в дерево
        if (m_root == nullptr) {
            m_root = new tree_element<T>(value);
            size = 1;
        } else {
            tree_element<T>* current = m_root;
            while(current && current->m_value != value) {
                if (current->m_value > value) {//переход в левое поддерево
                    if (current->m_left)//если есть возможность,то так как добавляемое значение меньше того,
                        //что в узле current,
                        //то мы спускаемся в левое поддерево ещё раз(переход для следующей итерации)
                        current = current->m_left;
                    else {//если же возможность спуститься ещё ниже нет,то мы добавляем новый элемент в дерево
                        //(так как мы уже находимся на том месте,куда нужно добавить новый элемент)
                        current->m_left = new tree_element<T>(value);
                        size++;
                        return;
                    }
                }//для правого поддерева аналогично
                else{//переход в правое поддерево
                    if (current->m_right)
                        current = current->m_right;
                    else{
                        current->m_right = new tree_element<T>(value);
                        size++;
                        return;
                    }
                }
            }
        }
    }

    //удаление элемента
    void DeleteElement(T value) {
        tree_element<T>* current = m_root;
        tree_element<T>* prev = nullptr;
        //поиск удаляемого элемента
        while(current && current->m_value != value) {
            prev = current;//запоминаем значение current,которое изменится на следующем действии
            if(current->m_value > value){
                current = current->m_left;
            }
            else
                current = current->m_right;
        }
        if (!current)//проверка на то,существует ли тот элемент,который мы хотим удалить
            return;


        if(prev->m_right == current) {//если удаляемый элемент является правым наследником
            if (current->m_right == nullptr && current->m_left == nullptr){//если удаляемый элемент вообще не имеет поддеревьев
                prev->m_right = nullptr;
                delete[] current;
                size--;
                return;
            }
            if (current->m_left == nullptr) {//если у удаляемого элемента нет левого поддерева
                prev->m_right = current->m_right;
                delete[] current;
                size--;
                return;
            }
            if (current->m_right == nullptr) {//если у удаляемого элемента нет правого поддерева
                prev->m_right = current->m_left;
                delete[] current;
                size--;
                return;
            }
        }

        if (prev->m_left == current) {//если удаляемый элемент является левым наследником
            if (current->m_right == nullptr && current->m_left == nullptr) {//если удаляемый элемент вообще не имеет поддеревьев
                prev->m_left = nullptr;
                delete[] current;
                size--;
                return;
            }
            if (current->m_left == nullptr) {//если у удаляемого элемента нет левого поддерева
                prev->m_left = current->m_right;
                delete[] current;
                size--;
                return;
            }
            if (current->m_right == nullptr) {//если у удаляемого элемента нет правого поддерева
                prev->m_left = current->m_left;
                delete[] current;
                size--;
                return;
            }
        }

        //если у удаляемого элемента есть оба поддерева,то на место удаляемого
        //мы должны поставить минимальный элемент из его правого поддерева

        tree_element<T>* tmp = current->m_right;//временная переменная для поиска минимума в правом поддереве
        while (tmp->m_left) tmp = tmp->m_left;

        T minimum = tmp->m_value;//сохранение значения переменной tmp для последующего удаления



        if (prev->m_left == current) {//если удаляемый элемент является левым наследником
            DeleteElement(tmp->m_value);//удаление минимального элемента в правом поддереве
            prev->m_left = new tree_element<T>(minimum,current->m_left,current->m_right);
            delete[] current;
            size--;
            return;
        }
        if (prev->m_right == current) {//если удаляемый элемент является правым наследником
            DeleteElement(tmp->m_value);//удаление минимального элемента в правом поддереве
            prev->m_right = new tree_element<T>(minimum,current->m_left,current->m_right);
            delete[] current;
            size--;
            return;
        }
    }

    //удаление дерева
    void DeleteTree(tree_element<T>* current) {
        if(current) {
            DeleteTree(current->m_left);
            DeleteTree(current->m_right);
            delete[] current;
        }
    }

    tree_element<T> *CloneElement(tree_element<T>* element) {
        tree_element<T> *result = new tree_element(element->m_value);
        if (element->m_left) *result->m_left = CloneElement(element->m_left);
        else result->m_left = nullptr;
        if (element->m_right) *result->m_right = CloneElement(element->m_right);
        else result->m_right = nullptr;

        return result;
    }

    BinaryTree<T> *Clone() {
        auto *result = new BinaryTree<T>;
        result->m_root = Clone_element(m_root);
        result->size = GetSize();
        return result;
    }

    BinaryTree<T>& operator=(BinaryTree<T> *tree1) {
        return *this;
    }

    tree_element<T>* GetRoot() {
        return m_root;
    }


    //ЗАВИСИТ ОТ ТОГО,ЧТО ЯВЛЯЕТСЯ КОРНЕМ ! ! !
    static bool IsEquals(tree_element<T>* first, tree_element<T>* second) {//обход реализован корректно
        //проверки на разные поддеревья у предположительно
        //совпадающих узлов
        if (second->m_right == nullptr && second->m_left == nullptr && first->m_value == second->m_value) {
            //проверка случая,когда в искомом дереве нет возможности идти влево/вправо
            // и значения с узлом дерева,в котором ищем совпадают
            return true;
        }

        if (second->m_left != nullptr && first->m_left == nullptr) {//влево нельзя/можно
            return false;
        }

        if (second->m_right != nullptr && first->m_right == nullptr)//вправо нельзя/можно
            return false;

        if (first->m_value != second->m_value)//несовпадающие значения
            return false;

        if (first->m_right != nullptr && second->m_right!= nullptr && second->m_left == nullptr)//в том дереве,которое ищу,могу двигаться только вправо
            return IsEquals(first->m_right,second->m_right);

        if (first->m_left != nullptr && second->m_left!= nullptr && second->m_right == nullptr)//в том дереве,которое ищу,могу двигаться только влево
            return IsEquals(first->m_left,second->m_left);

        //возможность двигаться влево/вправо в случае ненулевых указателей и совпадающих значений
        if (first->m_left != nullptr && second->m_left != nullptr && first->m_value == second->m_value)
            return IsEquals(first->m_left,second->m_left);

        if (first->m_right != nullptr && second->m_right != nullptr && first->m_value == second->m_value)
            return IsEquals(first->m_right,second->m_right);

    }

    void UpgradeSubTree(BinaryTree<T>* result,tree_element<T>* current) {//для рекурсивного заполнения нового экземпляра
        if(current){
            UpgradeSubTree(result,current->m_left);
            result->Insert(current->m_value);
            UpgradeSubTree(result,current->m_right);
        }
    }

    //проверка на то,является ли second поддеревом first
    bool IsSubtree(BinaryTree<T>* second) {

        tree_element<T>* current = m_root;//проверка того,что корень искомого дерева находится в том,
        while(current && current->m_value != second->m_root->m_value){// в котором мы ищем
            if(current->m_value > second->m_root->m_value)
                current = current->m_left;
            else
                current = current->m_right;
        }

        return IsEquals(current,second->m_root);
    }

    //получение поддерева по узлу
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

    //представление дерева в виде строки
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

    void TreeToArrayHelp(tree_element<T>* current,vector<T> &array) {
        if (current) {
            TreeToArrayHelp(current->m_left, array);
            array.push_back(current->m_value);
            TreeToArrayHelp(current->m_right, array);
        }
    }

    vector<T> TreeToArray() {
        tree_element<T>* current = m_root;
        vector<T> result;
        TreeToArrayHelp(current, result);

        return result;
    }

    void MapHelp(void(*func)(tree_element<T>*),tree_element<T>* current) {//для рекурсивного выполнения Map
        if (current) {
            func(current);
            MapHelp(func, current->m_left);
            MapHelp(func, current->m_right);
        }
    }

    void WhereHelp(bool(*func)(tree_element<T>*),tree_element<T>* current) {//для рекурсивного выполнения Where
        if (current) {
            WhereHelp(func, current->m_left);
            WhereHelp(func, current->m_right);
            if (!func(current)) {
                DeleteElement(current->m_value);
            }
        }
    }

    void ReduceHelp(T(*func)(tree_element<T>*,T),tree_element<T>* current,T& current_sum) {//для рекурсивного выполнения Reduce
        if (current) {
            ReduceHelp(func, current->m_left,current_sum);
            current_sum = func(current, current_sum);
            ReduceHelp(func, current->m_right,current_sum);
        }
    }

    // Map
    void Map(void(*func)(tree_element<T>*)) {//необходимо задать current,поэтому создана вспомогательная функция
        tree_element<T>* current = m_root;
        MapHelp(func,current);
    }

    // Where
    void Where(bool(*func)(tree_element<T>*)) {//необходимо задать current,поэтому создана вспомогательная функция
        tree_element<T>* current = m_root;
        WhereHelp(func,current);
    }

    // Reduce
    T Reduce(T(*func)(tree_element<T>*,T)) {
        tree_element<T>* current = m_root;
        T current_sum = 0;
        ReduceHelp(func,current,current_sum);
        return current_sum;
    }

    //Destructor
    ~BinaryTree() {
        DeleteTree(m_root);
    }
};