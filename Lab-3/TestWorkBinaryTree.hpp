#pragma once

#include "BinaryTree.hpp"

void TestIntTree() {
    auto tree1 = new BinaryTree<int>();
    tree1->Insert(6);
    tree1->Insert(4);
    tree1->Insert(8);
    tree1->Insert(5);
    tree1->Insert(3);
    cout << "First tree: ";
    tree1->Print();

    auto tree2 = new BinaryTree<int>();
    tree2->Insert(6);
    tree2->Insert(4);
    tree2->Insert(8);
    cout << "Second tree: ";
    tree2->Print();

    cout << "OPERATIONS" << endl;

    cout << "Find elements in queue: " << endl;
    cout << "4 in first tree - " << print_bool(tree1->Find(4)) << endl;
    cout << "4 in second tree - " << print_bool(tree2->Find(4)) << endl;
    cout << "5 in first tree - " << print_bool(tree1->Find(5)) << endl;
    cout << "5 in second tree - " << print_bool(tree2->Find(5)) << endl;

    cout << endl;

    cout << "Second tree is subtree first tree - " << print_bool(tree1->IsSubtree(tree2)) << endl;

    cout << endl;
    cout << "For first tree: " << endl;
    cout << "Use square for elements(Map): ";
    tree1->Map(square);
    tree1->Print();

    cout << "Use choose even number(Where): ";
    tree1->Where(even_number);
    tree1->Print();

    cout << "Use sum elements(Reduce): ";
    cout << tree1->Reduce(sum) << endl;

    cout << endl;
    cout << "For second tree: " << endl;
    cout << "Use square for elements(Map): ";
    tree2->Map(square);
    tree2->Print();

    cout << "Use choose even number(Where): ";
    tree2->Where(even_number);
    tree2->Print();

    cout << "Use sum elements(Reduce): ";
    cout << tree2->Reduce(sum) << endl;

    tree1->Balance();
}


void TestDoubleTree() {
    auto tree1 = new BinaryTree<double>();
    tree1->Insert(6.6);
    tree1->Insert(4.4);
    tree1->Insert(8.8);
    tree1->Insert(5.5);
    tree1->Insert(3.3);
    cout << "First tree: ";
    tree1->Print();

    auto tree2 = new BinaryTree<double>();
    tree2->Insert(6.6);
    tree2->Insert(4.4);
    tree2->Insert(8.8);
    cout << "Second tree: ";
    tree2->Print();

    cout << "OPERATIONS" << endl;

    cout << "Find elements in queue: " << endl;
    cout << "4.4 in first tree - " << print_bool(tree1->Find(4.4)) << endl;
    cout << "4.4 in second tree - " << print_bool(tree2->Find(4.4)) << endl;
    cout << "5.5 in first tree - " << print_bool(tree1->Find(5.5)) << endl;
    cout << "5.5 in second tree - " << print_bool(tree2->Find(5.5)) << endl;

    cout << endl;

    cout << "Second tree is subtree first tree - " << print_bool(tree1->IsSubtree(tree2)) << endl;

    cout << endl;
    cout << "For first tree: " << endl;
    cout << "Use square for elements(Map): ";
    tree1->Map(fractional_part);
    tree1->Print();
    cout << "Use sum elements(Reduce): ";
    cout << tree1->Reduce(sum) << endl;

    cout << endl;
    cout << "For second tree: " << endl;
    cout << "Use square for elements(Map): ";
    tree2->Map(fractional_part);
    tree2->Print();
    cout << "Use sum elements(Reduce): ";
    cout << tree2->Reduce(sum) << endl;

    tree1->Balance();
}

void TestCharTree() {
    auto tree1 = new BinaryTree<char>();
    tree1->Insert('d');
    tree1->Insert('b');
    tree1->Insert('c');
    tree1->Insert('f');
    tree1->Insert('a');
    cout << "First tree: ";
    tree1->Print();

    auto tree2 = new BinaryTree<char>();
    tree2->Insert('d');
    tree2->Insert('b');
    tree2->Insert('c');
    cout << "Second tree: ";
    tree2->Print();

    cout << "OPERATIONS" << endl;

    cout << "Find elements in queue: " << endl;
    cout << "'a' in first tree - " << print_bool(tree1->Find('a')) << endl;
    cout << "'a' in second tree - " << print_bool(tree2->Find('a')) << endl;
    cout << "'b' in first tree - " << print_bool(tree1->Find('b')) << endl;
    cout << "'b' in second tree - " << print_bool(tree2->Find('b')) << endl;

    cout << endl;

    cout << "Second tree is subtree first tree - " << print_bool(tree1->IsSubtree(tree2)) << endl;

    tree1->Balance();
}


void TestWorkBinaryTree() {
    int choice_type = 0;
    while (choice_type != 4) {
        cout << "Choose type of element for test:" << endl;
        cout << "1. Int" << endl;
        cout << "2. Double" << endl;
        cout << "3. Char" << endl;
        cout << "4. Back" << endl;
        cin >> choice_type;

        switch (choice_type) {
            case 1: {
                TestIntTree();
                cout << endl;
                break;
            }
            case 2: {
                TestDoubleTree();
                cout << endl;
                break;
            }
            case 3: {
                TestCharTree();
                cout << endl;
                break;
            }
            case 4: {
                break;
            }
            default: {
                cout << "Enter a number from the list!" << endl;
            }
        }
        cout << endl;
    }
}