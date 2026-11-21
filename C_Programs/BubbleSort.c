/*
Write a program for Bubble Sort
*/
#include <stdio.h>
#include <conio.h>
void main()
{
    int a[100], n, i, j, temp;
    clrscr();
    printf("Enter array size: "); scanf("%d",&n);
    if(n<1 || n>100) { printf("Invalid size"); getch(); return; }
    for(i=0;i<n;i++) { printf("Enter element: "); scanf("%d",&a[i]); }
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(a[j]>a[j+1]) { temp=a[j]; a[j]=a[j+1]; a[j+1]=temp; }
    printf("Sorted array: ");
    for(i=0;i<n;i++) printf("%d ",a[i]);
    getch();
}
