/*
Write a program for traversing operation on linear array
*/
#include <stdio.h>
#include <conio.h>
void main()
{
    int a[100], n, i;
    clrscr();
    printf("Enter array size: ");
    scanf("%d", &n);
    if(n<1 || n>100) { printf("Invalid size"); getch(); return; }
    for(i=0; i<n; i++) {
        printf("Enter element: ");
        scanf("%d", &a[i]);
    }
    printf("\nTraversing array:\n");
    for(i=0; i<n; i++)
        printf("a[%d] = %d\n", i, a[i]);
    getch();
}
