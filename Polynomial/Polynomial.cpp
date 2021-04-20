// Polynomial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term* terms;
};

void create(struct Poly* p)
{
    int i;
    printf("Number of terms?");
    scanf_s("%d", &p->n);
    p->terms = (struct Term*)malloc(p->n * sizeof(struct Term));

    printf("Enter terms\n");
    for (i = 0; i < p->n; i++)
    {
        scanf_s("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
    }
}

void display(struct Poly p)
{
    int i;
    for (i = 0; i < p.n; i++)
    {
        printf("%dx%d+", p.terms[i].coeff, p.terms[i].exp);
    }
    printf("\n");
}

struct Poly* add(struct Poly* p1, struct Poly* p2)
{
    struct Poly* sum;
    int i, j, k;

    sum = (struct Poly*)malloc(sizeof(struct Poly));

    sum->terms = (struct Term*)malloc((p1->n + p2->n) * sizeof(struct Term));
    i = j = k = 0;

    while (i < p1->n && j < p2->n)
    {
        if (p1->terms[i].exp > p2->terms[j].exp)
            sum->terms[k++] = p1->terms[i++];
        else if(p1->terms[i].exp < p2->terms[j].exp)
            sum->terms[k++] = p2->terms[j++];
        else
        {
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }
    for (; i < p1->n; i++)
        sum->terms[k++] = p1->terms[i];
    for (; j < p2->n; j++)
        sum->terms[k++] = p2->terms[j];

    sum->n = k;

    return sum;
}

int main()
{
    struct Poly p1,p2,*p3;

    create(&p1);
    create(&p2);

    p3 = add(&p1, &p2);

    printf("\n");
    display(p1);
    printf("\n");
    display(p2);
    printf("\n");
    display(*p3);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
