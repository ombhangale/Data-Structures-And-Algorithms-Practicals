/*
Write a program to add two polynomials using a linked list
*/
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
struct Node { int coeff, exp; struct Node *next; };
void main()
{
    struct Node *a,*b,*c,*p,*q,*t;
    int i,n,m;
    clrscr(); a=NULL; b=NULL; c=NULL;
    printf("Enter number of terms in first polynomial: "); scanf("%d",&n);
    for(i=0;i<n;i++) {
        t=(struct Node *)malloc(sizeof(struct Node));
        printf("Enter coefficient and exponent: "); scanf("%d%d",&t->coeff,&t->exp);
        t->next=a; a=t;
    }
    printf("Enter number of terms in second polynomial: "); scanf("%d",&m);
    for(i=0;i<m;i++) {
        t=(struct Node *)malloc(sizeof(struct Node));
        printf("Enter coefficient and exponent: "); scanf("%d%d",&t->coeff,&t->exp);
        t->next=b; b=t;
    }
    p=a;
    while(p!=NULL) {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->coeff=p->coeff; t->exp=p->exp; t->next=c; c=t; p=p->next;
    }
    q=b;
    while(q!=NULL) {
        p=c;
        while(p!=NULL && p->exp!=q->exp) p=p->next;
        if(p!=NULL) p->coeff+=q->coeff;
        else { t=(struct Node *)malloc(sizeof(struct Node)); t->coeff=q->coeff; t->exp=q->exp; t->next=c; c=t; }
        q=q->next;
    }
    printf("Sum (coefficient, exponent):\n");
    for(p=c;p!=NULL;p=p->next) printf("%dx^%d ",p->coeff,p->exp);
    getch();
}
