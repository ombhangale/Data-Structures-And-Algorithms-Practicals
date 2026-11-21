/*
Write a program to accept and display an array
*/
#include <stdio.h>
#include <conio.h>
void main()
{
    int a[100], n, i;
    clrscr();
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if(n<1 || n>100) { printf("Invalid size"); getch(); return; }
    for(i=0; i<n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("\nArray elements are:\n");
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    getch();
}
