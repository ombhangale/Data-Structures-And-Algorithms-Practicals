/*
Write a program for linear search
*/
#include <stdio.h>
#include <conio.h>
void main()
{
    int a[100], n, i, key, found=0;
    clrscr();
    printf("Enter array size: "); scanf("%d",&n);
    if(n<1 || n>100) { printf("Invalid size"); getch(); return; }
    for(i=0;i<n;i++) { printf("Enter element: "); scanf("%d",&a[i]); }
    printf("Enter element to search: "); scanf("%d",&key);
    for(i=0;i<n;i++)
        if(a[i]==key) { printf("Element found at position %d",i+1); found=1; break; }
    if(!found) printf("Element not found");
    getch();
}
