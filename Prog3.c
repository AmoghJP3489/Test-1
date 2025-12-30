//Test 3 Sparse matrix
#include <stdio.h>
#define MAX_TERMS 101

typedef struct
{
    int row;
    int col;
    int value;
} term;

void transpose(term a[], term b[]);
void display(term m[]);

int main()
{
    term a[MAX_TERMS], b[MAX_TERMS];
    int p, q, i, j, k = 1, val, n = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &p, &q);

    a[0].row = p;
    a[0].col = q;

    printf("Enter matrix elements:\n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            scanf("%d", &val);
            if (val != 0)
            {
                a[k].row = i;
                a[k].col = j;
                a[k].value = val;
                k++;
                n++;
            }
        }
    }

    a[0].value = n;

    printf("\nSparse Matrix Representation:\n");
    display(a);

    transpose(a, b);

    printf("\nTranspose of Sparse Matrix:\n");
    display(b);

    return 0;
}

void display(term m[])
{
    int i;
    printf("Row\tColumn\tValue\n");
    for (i = 1; i <= m[0].value; i++)
        printf("%d\t%d\t%d\n", m[i].row, m[i].col, m[i].value);
}

void transpose(term a[], term b[])
{
    int i, j, n = a[0].value, currentb = 1;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;

    for (i = 0; i < a[0].col; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (a[j].col == i)
            {
                b[currentb].row = a[j].col;
                b[currentb].col = a[j].row;
                b[currentb].value = a[j].value;
                currentb++;
            }
        }
    }
}
