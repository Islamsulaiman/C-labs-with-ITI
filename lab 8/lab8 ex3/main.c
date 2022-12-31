#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;

void swap(triangle *xp, triangle *yp)
{
    triangle temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
double getarea(triangle tr)
{
    double p = (tr.a + tr.b + tr.c) / 2;

    double area = sqrt(p * (p - tr.a) * (p - tr.b) * (p - tr.c));

    return area;
}

void bubbleSort(triangle arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)

            if (getarea(arr[j]) > getarea(arr[j + 1]))
            {
                swap(&arr[j], &arr[j + 1]);
            }
}

void sort_by_area(triangle *tr, int n)
{
    /**
     * Sort an array a of the length n
     */
    // create an array of areas
    /*
    int areas[n];

    for (int i =0; i<n; i++){
        areas[i] = (tr[i].a + tr[i].b + tr[i].c);
    }
    */

    bubbleSort(tr, n);
    // sort the array
}

int main()
{
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}
