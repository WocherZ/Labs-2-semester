#include "lib_polynom.h"

//Многочлен
//Коэффициенты:
// −Целые числа
// −Вещественные числа
// Сложение, умножение,
// умножение на скаляр,
// вычисление значения для заданного значения
// аргумента, композиция

const char *FIRST_MENU[] = {"0. Exit", "1. Create first polynom", "2. Create second polynom", "3. Go to operations"};
const int FIRST_MENU_SIZE = sizeof(FIRST_MENU) / sizeof(FIRST_MENU[0]);

const char *SECOND_MENU[] = {"0. Back","1. Account polynom", "2. Mult on scalar", "3. Print polynom", "4. Sum first and second polynoms", "5. Mult first and second polynoms", "6. Composition polynoms"};
const int SECOND_MENU_SIZE = sizeof(SECOND_MENU) / sizeof(SECOND_MENU[0]);

const char *CHOICE_POLYNOM[] = {"0. First polynom", "1. Second polynom"};
const int CHOICE_POLYNOM_SIZE = sizeof(CHOICE_POLYNOM) / sizeof(CHOICE_POLYNOM[0]);


int main() {
    printf("Start!\n");
    struct polynom *p1 = NULL;
    struct polynom *p2 = NULL;
    struct polynom *p3 = NULL;
    struct polynom *p = NULL;
    int c1, c2, s, x_int, sc_int, choice;
    double x_double, sc_double;
    do {
        c1 = dialog(FIRST_MENU, FIRST_MENU_SIZE);
        switch (c1) {
            case 0: // 0. Exit
                break;
            case 1: // 1. Create first polynom
                p1 = create_polynom();
                break;
            case 2: // 2. Create second polynom
                p2 = create_polynom();
                break;
            case 3: // 3. Go to operations
                break;
        }
        if (c1 == 3) {
            do {
                c2 = dialog(SECOND_MENU, SECOND_MENU_SIZE);
                switch (c2) {
                    case 0: // 0. Back
                        break;
                    case 1: // 1. Account polynom
                        s = dialog(CHOICE_TYPE, CHOICE_TYPE_SIZE);
                        if (s == 0) {
                            printf("Enter integer X:\n");
                            scanf("%d", &x_int);
                            account_polynom(p1, (void *) &x_int, INT_SIZE);
                        } else if (s == 1) {
                            printf("Enter float X:\n");
                            scanf("%lf", &x_double);
                            account_polynom(p1, (void *) &x_double, DOUBLE_SIZE);
                        }
                        break;
                    case 2: // 2. Mult on scalar
                        choice = dialog(CHOICE_POLYNOM, CHOICE_POLYNOM_SIZE);
                        s = dialog(CHOICE_TYPE, CHOICE_TYPE_SIZE);
                        if (choice == 0) p = p1;
                        if (choice == 1) p = p2;
                        switch(s) {
                            case 0: //Int scalar
                                if (p->size == INT_SIZE) {
                                    printf("Enter integer scalar:\n");
                                    scanf("%d", &sc_int);
                                    p = multScalar(p, (void* )&sc_int, mult_int_scalar);
                                } else {
                                    printf("Scalar and polynom have different date types\n");
                                }
                                break;
                            case 1: //Double scalar
                                if (p->size == DOUBLE_SIZE) {
                                    printf("Enter float scalar:\n");
                                    scanf("%lf", &sc_double);
                                    p = multScalar(p, (void* )&sc_double, mult_double_scalar);
                                } else {
                                    printf("Scalar and polynom have different date types\n");
                                }
                                break;
                        }
                        break;
                    case 3: // 3. Print polynoms (for check)
                        printf("Polynom 1:\n");
                        print_polynom(p1);
                        printf("Polynom 2:\n");
                        print_polynom(p2);
                        printf("Polynom 3:\n");
                        print_polynom(p3);
                        break;
                    case 4: // 4. Sum first and second polynoms
                        if (p1 && p2) {
                            p3 = sum_polynom(p1, p2);
                            printf("Result of sum polynoms:\n");
                            print_polynom(p3);
                        } else {
                            if (p1 == NULL) printf("Go back and determine first polynom\n");
                            if (p2 == NULL) printf("Go back and determine second polynom\n");
                        }
                        break;
                    case 5: // 5. Mult first and second polynoms
                        if (p1 && p2) {
                            p3 = mult_polynoms(p1, p2);
                            printf("Result of mult polynoms:\n");
                            print_polynom(p3);
                        } else {
                            if (p1 == NULL) printf("Go back and determine first polynom\n");
                            if (p2 == NULL) printf("Go back and determine second polynom\n");
                        }
                        break;
                    case 6: // 6. Composition polynoms
                        if (p1 && p2) {
                            p3 = composition_polynom(p1, p2);
                            printf("Result of composition polynoms:\n");
                            print_polynom(p3);
                        } else {
                            if (p1 == NULL) printf("Go back and determine first polynom\n");
                            if (p2 == NULL) printf("Go back and determine second polynom\n");
                        }
                        break;
                }
            } while (c2 != 0);
        }
    } while (c1 != 0);
    printf("End!\n");
    return 0;
}