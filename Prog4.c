//Test 4 Polynomial addition
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    float coef;
    int exp;
} Poly;

Poly terms[MAX];
int avail = 0;

void addPoly(int StartA, int EndA, int StartB, int EndB,
             int *StartD, int *EndD);
void attach(float coef, int exp);
void display(int StartD, int EndD);

int main() {
    int degreeA, degreeB, i, coef;
    int StartA = 0, EndA;
    int StartB, EndB;
    int StartD, EndD;

    printf("Enter degree of Polynomial A: ");
    scanf("%d", &degreeA);

    for (i = degreeA; i >= 0; i--) {
        printf("Enter coefficient of x^%d (A): ", i);
        scanf("%d", &coef);
        if (coef != 0) {
            terms[avail].coef = coef;
            terms[avail].exp = i;
            avail++;
        }
    }
    EndA = avail - 1;

    printf("\nEnter degree of Polynomial B: ");
    scanf("%d", &degreeB);

    StartB = avail;
    for (i = degreeB; i >= 0; i--) {
        printf("Enter coefficient of x^%d (B): ", i);
        scanf("%d", &coef);
        if (coef != 0) {
            terms[avail].coef = coef;
            terms[avail].exp = i;
            avail++;
        }
    }
    EndB = avail - 1;

    addPoly(StartA, EndA, StartB, EndB, &StartD, &EndD);

    printf("\nResultant Polynomial:\n");
    display(StartD, EndD);

    return 0;
}

void addPoly(int StartA, int EndA, int StartB, int EndB,
             int *StartD, int *EndD) {

    float sum;
    *StartD = avail;

    while (StartA <= EndA && StartB <= EndB) {
        if (terms[StartA].exp > terms[StartB].exp) {
            attach(terms[StartA].coef, terms[StartA].exp);
            StartA++;
        }
        else if (terms[StartA].exp < terms[StartB].exp) {
            attach(terms[StartB].coef, terms[StartB].exp);
            StartB++;
        }
        else {
            sum = terms[StartA].coef + terms[StartB].coef;
            if (sum != 0)
                attach(sum, terms[StartA].exp);
            StartA++;
            StartB++;
        }
    }

    while (StartA <= EndA) {
        attach(terms[StartA].coef, terms[StartA].exp);
        StartA++;
    }

    while (StartB <= EndB) {
        attach(terms[StartB].coef, terms[StartB].exp);
        StartB++;
    }

    *EndD = avail - 1;
}

void attach(float coef, int exp) {
    if (avail >= MAX) {
        printf("Too many terms in polynomial\n");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail].exp = exp;
    avail++;
}

void display(int StartD, int EndD) {
    int i;
    for (i = StartD; i < EndD; i++)
        printf("%.1fx^%d + ", terms[i].coef, terms[i].exp);
    printf("%.1fx^%d\n", terms[i].coef, terms[i].exp);
}
