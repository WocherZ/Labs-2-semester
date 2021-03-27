#include <stdio.h>
#include <stdlib.h>

#ifndef LIB_POLYNOM_H
#define LIB_POLYNOM_H

#define INT_SIZE sizeof(int)
#define DOUBLE_SIZE sizeof(double)

const char *CHOICE_TYPE[2];
const int CHOICE_TYPE_SIZE;

struct polynom { //Структура многочлена
    int number;
    int size;
    void *massive; // a0 + a1*x^1 + a2*x^2 + ... +an*x^n
};


int dialog(const char *msgs[], int n);
int max(int n1, int n2);
void print_int_mass(void* mass, int n);
void print_double_mass(void* mass, int n);
void print_polynom(struct polynom *P);
int degrees_int(int* x, int degree);
double degrees_double(double* x, int degree);
void account_polynom(struct polynom *P, void* x, int size_x);
struct polynom *mult_int_scalar(struct polynom *p, void* scalar);
struct polynom *mult_double_scalar(struct polynom *p, void* scalar);
struct polynom *multScalar(struct polynom *P, void *scalar, struct polynom*(*function_mult_scalar)(struct polynom*, void *scalar));
struct polynom *sum_int_polynom(struct polynom* P1, struct polynom* P2);
struct polynom *sum_double_polynom(struct polynom* P1, struct polynom* P2);
struct polynom *sum_polynom(struct polynom *P1, struct polynom *P2, struct polynom*(*SUMpolynoms)(struct polynom*, struct polynom*));
struct polynom *create_polynom();
struct polynom *mult_int_polynoms(struct polynom *P1, struct polynom *P2);
struct polynom *mult_double_polynoms(struct polynom *P1, struct polynom *P2);
struct polynom *mult_polynoms(struct polynom *P1, struct polynom *P2, struct polynom*(*function_mult)(struct polynom*, struct polynom*));
struct polynom *copy(struct polynom *P);
struct polynom *degrees_polynom(struct polynom *P, int degree, struct polynom*(*polynom_in_degree)(struct polynom*, int degree)) ;
struct polynom *composition_int_polynom(struct polynom *F, struct polynom *G);
struct polynom *composition_double_polynom(struct polynom *F, struct polynom *G);
struct polynom *composition_polynom(struct polynom *F, struct polynom *G, struct polynom*(*function_composition)(struct polynom *F, struct polynom *G));

#endif //UNTITLED2_LIB_POLYNOM_H
