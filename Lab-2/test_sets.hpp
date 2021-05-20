#pragma once

#include <cmath>
#include "sets.hpp"

int square(int n) {
    return n * n;
}

bool even_number(int n) {
    if (n % 2) return false;
    else return true;
}

double fractional_part(double number) {
    return modf(number, &number);
}

string print_bool(bool t) {
    if (t) return "True";
    else return "False";
}

void test_int_set() {
    cout << "TEST INT SET" << endl;
    const int n1 = 8;
    int elements1[n1] = {1, 2, 3, 4, 5, 6, 7, 8};
    Set<int> set1(new ArraySequence<int>(elements1, n1));
    cout << "First set: ";
    set1.Print();

    const int n2 = 4;
    int elements2[n2] = {7, 8, 9, 10};
    Set<int> set2(new ArraySequence<int>(elements2, n2));
    cout << "Second set: ";
    set2.Print();

    cout << endl << "OPERATIONS " << endl;

    cout << "Union sets: ";
    set1.Union(set2)->Print();

    cout << "Cross sets: ";
    set1.Cross(set2)->Print();

    cout << "Subtraction second set from first set: ";
    set1.Subtraction(set2)->Print();

    cout << "Subtraction first set from second set: ";
    set2.Subtraction(set1)->Print();

    cout << "For first set use Map - square: ";
    set1.Map(square)->Print();

    cout << "For second set use Map - square: ";
    set2.Map(square)->Print();

    cout << "For first set use Where - even_number: ";
    set1.Where(even_number)->Print();

    cout << "For second set use Where - even_number: ";
    set2.Where(even_number)->Print();

    cout << endl << "CHECK ENTERING ELEMENT IN SETS" << endl;
    int element1 = 5;
    cout << "5 in first set - " << print_bool(set1.InSet(element1)) << endl;
    cout << "5 in second set - " << print_bool(set2.InSet(element1)) << endl;

    int element2 = 7;
    cout << "7 in first set - " << print_bool(set1.InSet(element2)) << endl;
    cout << "7 in second set - " << print_bool(set2.InSet(element2)) << endl;
}

void test_double_set() {
    cout << "TEST DOUBLE SET" << endl;
    const int n1 = 7;
    double elelments1[n1] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    Set<double> set1(new ArraySequence<double>(elelments1, n1));
    cout << "Fisrt set: ";
    set1.Print();

    const int n2 = 4;
    double elelments2[n2] = {6.6, 7.7, 8.8, 9.9};
    Set<double> set2(new ArraySequence<double>(elelments2, n2));
    cout << "Second set: ";
    set2.Print();

    cout << endl << "OPERATIONS " << endl;

    cout << "Union sets: ";
    set1.Union(set2)->Print();

    cout << "Cross sets: ";
    set1.Cross(set2)->Print();

    cout << "Subtraction second set from first set: ";
    set1.Subtraction(set2)->Print();

    cout << "Subtraction first set from second set: ";
    set2.Subtraction(set1)->Print();

    cout << "For first set use Map - fractional part: ";
    set1.Map(fractional_part)->Print();

    cout << "For second set use Map - fractional part: ";
    set2.Map(fractional_part)->Print();

    cout << endl << "CHECK ENTERING ELEMENT IN SETS" << endl;
    double element1 = 3.3;
    cout << "3.3 in first set - " << print_bool(set1.InSet(element1)) << endl;
    cout << "3.3 in second set - " << print_bool(set2.InSet(element1)) << endl;

    double element2 = 7.7;
    cout << "7.7 in first set - " << print_bool(set1.InSet(element2)) << endl;
    cout << "7.7 in second set - " << print_bool(set2.InSet(element2)) << endl;
}


void test_char_set() {
    cout << "TEST CHAR SET" << endl;
    const int n1 = 6;
    char elements1[n1] = {'a', 'b', 'c', 'd', 'e', 'f'};
    Set<char> set1(new ArraySequence<char>(elements1, n1));
    cout << "First set: ";
    set1.Print();

    const int n2 = 4;
    char elements2[n2] = {'e', 'f', 'g', 'h'};
    Set<char> set2(new ArraySequence<char>(elements2, n2));
    cout << "Second set: ";
    set2.Print();

    cout << endl << "OPERATIONS " << endl;

    cout << "Union sets: ";
    set1.Union(set2)->Print();

    cout << "Cross sets: ";
    set1.Cross(set2)->Print();

    cout << "Subtraction second set from first set: ";
    set1.Subtraction(set2)->Print();

    cout << "Subtraction first set from second set: ";
    set2.Subtraction(set1)->Print();

    cout << endl << "CHECK ENTERING ELEMENT IN SETS" << endl;
    char element1 = 'b';
    cout << "'b' in first set - " << print_bool(set1.InSet(element1)) << endl;
    cout << "'b' in second set - " << print_bool(set2.InSet(element1)) << endl;

    char element2 = 'f';
    cout << "'f' in first set - " << print_bool(set1.InSet(element2)) << endl;
    cout << "'f' in second set - " << print_bool(set2.InSet(element2)) << endl;
}


void test_string_set() {
    cout << "TEST STRING SET" << endl;
    const int n1 = 6;
    string elements1[n1] = {"a", "b", "c", "d", "e", "f"};
    Set<string> set1(new ArraySequence<string>(elements1, n1));
    cout << "First set: ";
    set1.Print();

    const int n2 = 4;
    string elements2[n2] = {"e", "f", "g", "h"};
    Set<string> set2(new ArraySequence<string>(elements2, n2));
    cout << "Second set: ";
    set2.Print();

    cout << endl << "OPERATIONS " << endl;

    cout << "Union sets: ";
    set1.Union(set2)->Print();

    cout << "Cross sets: ";
    set1.Cross(set2)->Print();

    cout << "Subtraction second set from first set: ";
    set1.Subtraction(set2)->Print();

    cout << "Subtraction first set from second set: ";
    set2.Subtraction(set1)->Print();

    cout << endl << "CHECK ENTERING ELEMENT IN SETS" << endl;
    string element1 = "b";
    cout << "String 'b' in first set - " << print_bool(set1.InSet(element1)) << endl;
    cout << "String 'b' in second set - " << print_bool(set2.InSet(element1)) << endl;

    string element2 = "f";
    cout << "String 'f' in first set - " << print_bool(set1.InSet(element2)) << endl;
    cout << "String 'f' in second set - " << print_bool(set2.InSet(element2)) << endl;
}
