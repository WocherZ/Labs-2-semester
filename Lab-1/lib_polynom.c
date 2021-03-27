#include "lib_polynom.h"

const char *CHOICE_TYPE[2] = {"0. Integer", "1. Double(float)"};
const int CHOICE_TYPE_SIZE = sizeof(CHOICE_TYPE) / sizeof(CHOICE_TYPE[0]);

int dialog(const char *msgs[], int n) {
    char *error = "You're wrong. Try again!\n";
    int choice;
    do {
        for (int i = 0; i < n; ++i) {
            puts(msgs[i]);
        }
        puts("Make your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n') {}
        if (choice < 0 || choice >= n) puts(error);
    } while (choice < 0 || choice >= n);
    return choice;
}

int max(int n1, int n2) {
    if (n1 > n2) return n1;
    else return n2;
}

void print_int_mass(void* mass, int n) { //Печать массива int-ов
    int *m = mass;
    for(int i = 0; i < n; i++) {
        printf("%d ", m[i]);
    }
}

void print_double_mass(void* mass, int n) { //Печать массива double-ов
    double *m = mass;
    for(int i = 0; i < n; i++) {
        printf("%lf ", m[i]);
    }
}

void print_polynom(struct polynom *P){ //Печать многочлена
    if (P != NULL) {
        printf("Polynom with %d elements and %d size\n", P->number, P->size);
        printf("Coefficients of polynom: ");
        if (P->size == INT_SIZE) {
            print_int_mass(P->massive, P->number);
        }
        if (P->size == DOUBLE_SIZE) {
            print_double_mass(P->massive, P->number);
        }
    } else {
        printf("Polynom wasn't determined");
    }

    printf("\n");
}

int degrees_int(int* x, int degree) { //Возведение целого числа в целую степень
    int result = 1;
    for(int i = 0; i < degree; i++) {
        result *= *x;
    }
    return result;
}

double degrees_double(double* x, int degree) { //Возведение вещественного числа в целую степень
    double result = 1;
    for(int i = 0; i < degree; i++) {
        result *= *x;
    }
    return result;
}

void account_polynom(struct polynom *P, void* x, int size_x) { //Вычисление значения для заданного значения аргумента(x)
    if ((size_x == INT_SIZE) && (P->size == INT_SIZE))  {
        int sum = 0;
        for(int i = 0; i < P->number; i++) {
            sum += degrees_int((int* ) x, i) * (*((int*)(P->massive) + i));
        }
        printf("Polynomial calculation result: %d; X = %d", sum, *((int* ) x));
    } else if ((size_x == DOUBLE_SIZE) && (P->size == INT_SIZE)) {
        double sum = 0;
        for (int i = 0; i < P->number; i++) {
            sum += degrees_double((double *) x, i) * *((int *) (P->massive) + i);
        }
        printf("Polynomial calculation result: %lf; X = %lf", sum, *((double* ) x));
    } else if ((size_x == INT_SIZE) && (P->size == DOUBLE_SIZE)) {
        double sum = 0;
        for (int i = 0; i < P->number; i++) {
            sum += degrees_int((int *) x, i) * *((double *) (P->massive) + i);
        }
        printf("Polynomial calculation result: %lf; X = %d", sum, *((int* ) x));

    } else if ((size_x == DOUBLE_SIZE) && (P->size == DOUBLE_SIZE)){
        double sum = 0;
        for (int i = 0; i < P->number; i++) {
            sum += degrees_double((double *) x, i) * *((double *) (P->massive) + i);
        }
        printf("Polynomial calculation result: %lf; X = %lf", sum, *((double* ) x));
    } else {
        printf("Error calculate! Wrong size!");
    }
    printf("\n");
}

struct polynom *mult_int_scalar(struct polynom *p, void* scalar) {
    int sc = (*(int* )scalar);
    int* new_mass = calloc(p->number, INT_SIZE);
    for(int i = 0; i < p->number; i++) {
        *(new_mass + i)  = sc * (int )(*((int* ) (p->massive) + i));
    }
    p->massive = (void* ) new_mass;
    return p;
}

struct polynom *mult_double_scalar(struct polynom *p, void* scalar) {
    double sc = (*(double* )scalar);
    double* new_mass = malloc(p->number * DOUBLE_SIZE);
    for(int i = 0; i < p->number; i++) {
        *(new_mass + i)  = sc * (double )(*((double* ) (p->massive) + i));
    }
    p->massive = (void* ) new_mass;
    return p;
}

struct polynom *multScalar(struct polynom *P, void *scalar, struct polynom*(*function_mult_scalar)(struct polynom* , void* )) {
    return function_mult_scalar(P, scalar);
}

struct polynom *sum_int_polynom(struct polynom* P1, struct polynom* P2) {
    struct polynom *result = NULL;
    if ((P1->size == INT_SIZE) && (P2->size == INT_SIZE)) {
        int n = max(P1->number, P2->number);
        result = malloc(sizeof(struct polynom));
        int *new_mass = calloc(n, INT_SIZE);
        for(int i = 0; i < P1->number; i++) {
            new_mass[i] += (int)*((int* )P1->massive + i);
        }
        for(int i = 0; i < P2->number; i++) {
            new_mass[i] += (int)*((int* )P2->massive + i);
        }
        result->number = n;
        result->size = INT_SIZE;
        result->massive = (void* ) new_mass;
    } else {
        printf("Error size! Result of sum integer is NULL!\n");
    }
    return result;
}

struct polynom *sum_double_polynom(struct polynom* P1, struct polynom* P2) {
    struct polynom *result = NULL;
    if ((P1->size == DOUBLE_SIZE) && (P2->size == DOUBLE_SIZE)) {
        int n = max(P1->number, P2->number);
        result = malloc(sizeof(struct polynom));
        double *new_mass = calloc(n, INT_SIZE);
        for(int i = 0; i < P1->number; i++) {
            new_mass[i] += (double )*((double* )P1->massive + i);
        }
        for(int i = 0; i < P2->number; i++) {
            new_mass[i] += (double )*((double* )P2->massive + i);
        }
        result->number = n;
        result->size = DOUBLE_SIZE;
        result->massive = (void* ) new_mass;
    } else {
        printf("Error size! Result of sum float is NULL!\n");
    }
    return result;
}

struct polynom *sum_polynom(struct polynom *P1, struct polynom *P2, struct polynom*(*function_sum)(struct polynom*, struct polynom*) ) {
    return function_sum(P1, P2);
}

struct polynom *create_polynom() {
    struct polynom *P = malloc(sizeof(struct polynom));
    int n, s;
    printf("Enter count of elements:\n");
    scanf("%d", &n);
    P->number = n;
    s = dialog(CHOICE_TYPE, CHOICE_TYPE_SIZE);
    if (s == 0) {
        P->size = INT_SIZE;
        int *mass = malloc(P->size * P->number);
        printf("Enter coefficients :\n");
        for(int i = 0; i < n; i++) {
            scanf("%d", &mass[i]);
        }
        P->massive = (void* ) mass;
    }
    if (s == 1) {
        P->size = DOUBLE_SIZE;
        double *mass = malloc(P->size * P->number);
        printf("Enter coefficients :\n");
        for(int i = 0; i < n; i++) {
            scanf("%lf", &mass[i]);
        }
        P->massive = (void* ) mass;
    }
    return P;
}

struct polynom *mult_int_polynoms(struct polynom *P1, struct polynom *P2) {
    if ((P1->size == INT_SIZE) && (P2->size == INT_SIZE)) {
        struct polynom *result = malloc(sizeof(struct polynom));
        result->number = P1->number + P2->number - 1;
        struct polynom *p3;
        struct polynom *p4;
        if (P1->number >= P2 ->number) {
            p3 = P1;
            p4 = P2;
        } else {
            p3 = P2;
            p4 = P1;
        }
        result->size = INT_SIZE;
        int *massive = calloc(result->number + 1, INT_SIZE);
        int mn1;
        int mn2;
        for(int i = 0; i < p3->number; i++) {
            for(int j = 0; j < p4->number; j++) {
                mn1 = (int )*((int* )p3->massive + i);
                mn2 = (int )*((int* )p4->massive + j);
                massive[i + j] += (mn1 * mn2);
            }
        }
        result->massive = (void* ) massive;
        return result;
    } else {
        printf("Error size! Result of integer mult is NULL!\n");
        return NULL;
    }
}

struct polynom *mult_double_polynoms(struct polynom *P1, struct polynom *P2) {
    if ((P1->size == DOUBLE_SIZE) && (P2->size == DOUBLE_SIZE)) {
        struct polynom *result = malloc(sizeof(struct polynom));
        result->number = P1->number + P2->number - 1;
        struct polynom *p3 = NULL;
        struct polynom *p4 = NULL;
        if (P1->number >= P2 ->number) {
            p3 = P1;
            p4 = P2;
        } else {
            p3 = P2;
            p4 = P1;
        }
        result->size = DOUBLE_SIZE;
        double *massive = calloc(result->number + 1, DOUBLE_SIZE);
        double mn1 ;
        double mn2;
        for(int i = 0; i < p3->number; i++) {
            for(int j = 0; j < p4->number; j++) {
                mn1 = (double )*((double* )p3->massive + i);
                mn2 = (double )*((double* )p4->massive + j);
                massive[i + j] += (mn1 * mn2);
            }
        }
        result->massive = (void* ) massive;
        return result;
    } else {
        printf("Error size! Result of float mult is NULL!\n");
        return NULL;
    }
}

struct polynom *mult_polynoms(struct polynom *P1, struct polynom *P2, struct polynom*(*function_mult)(struct polynom*, struct polynom*)) {
    return function_mult(P1, P2);
}

struct polynom *copy(struct polynom *P) {
    struct polynom *res = malloc(sizeof(struct polynom));
    res->number = P->number;
    res->size = P->size;
    if (P->size == INT_SIZE) {
        int *mass = malloc(P->number * INT_SIZE);
        for(int i = 0; i < P->number; i++) {
            mass[i] = *((int* )P->massive + i);
        }
        res->massive = (void* ) mass;
    } else if (P->size == DOUBLE_SIZE) {
        double *mass = malloc(P->number * DOUBLE_SIZE);
        for(int i = 0; i < P->number; i++) {
            mass[i] = *((double* )P->massive + i);
        }
        res->massive = (void* ) mass;
    } else {
        printf("Error copy polynom! Wrong size!\n");
    }
    return res;
}

struct polynom *int_polynom_in_degree(struct polynom *p, int degree) {
    if ((degree > 0) && (p->size == INT_SIZE)) {
        struct polynom *result = copy(p);
        for(int i = 1; i < degree; i++) {
            result = mult_int_polynoms(result, p);
        }
        return result;
    } else {
        printf("Error degrees polynom\n");
        return NULL;
    }
}

struct polynom *double_polynom_in_degree(struct polynom *p, int degree) {
    if ((degree > 0) && (p->size == DOUBLE_SIZE)) {
        struct polynom *result = copy(p);
        for(int i = 1; i < degree; i++) {
            result = mult_int_polynoms(result, p);
        }
        return result;
    } else {
        printf("Error degrees polynom\n");
        return NULL;
    }
}

struct polynom *degrees_polynom(struct polynom *P, int degree, struct polynom*(*polynom_in_degree)(struct polynom*, int ) )  {
    return polynom_in_degree(P, degree);
}

struct polynom *composition_int_polynom(struct polynom *F, struct polynom *G) {
    if ((F->size == INT_SIZE) && (G->size == INT_SIZE)) {
        struct polynom *result = malloc(sizeof(struct polynom));
        struct polynom *prom = NULL;
        int n = (F->number - 1) * (G->number - 1) + 1;
        int *new_mass = calloc(n, INT_SIZE);
        new_mass[0] = (int )*((int *) F->massive);
        result->number = n;
        result->size = INT_SIZE;
        result->massive = (void *) new_mass;
        for (int i = 1; i < F->number; i++) {
            prom = multScalar(degrees_polynom(G, i, int_polynom_in_degree), (F->massive + i), mult_int_scalar);
            result = sum_polynom(result, prom, sum_int_polynom);
        }
        return result;
    } else {
        printf("Error composition int polynoms!\n");
        return NULL;
    }
}

struct polynom *composition_double_polynom(struct polynom *F, struct polynom *G) {
    if ((F->size == DOUBLE_SIZE) && (G->size == DOUBLE_SIZE)) {
        struct polynom *result = malloc(sizeof(struct polynom));
        struct polynom *prom;
        int n = (F->number - 1) * (G->number - 1) + 1;
        double *new_mass = calloc(n, DOUBLE_SIZE);
        new_mass[0] += (double )*((double *) F->massive);
        result->number = n;
        result->size = DOUBLE_SIZE;
        result->massive = (void *) new_mass;
        for (int i = 1; i < F->number; i++) {
            prom = multScalar(degrees_polynom(G, i, double_polynom_in_degree), (F->massive + i), mult_double_scalar);
            result = sum_polynom(result, prom, sum_double_polynom);
        }
        return result;
    } else {
        printf("Error composition float polynoms!\n");
        return NULL;
    }
}

struct polynom *composition_polynom(struct polynom *F, struct polynom *G, struct polynom*(*function_composition)(struct polynom* , struct polynom* )) {
    return function_composition(F, G);
}

