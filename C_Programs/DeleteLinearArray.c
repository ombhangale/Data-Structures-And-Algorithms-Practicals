/*
Write a program for deletion operation on linear array
*/
#include <stdio.h>
#include <conio.h>
void main()
{
    int a[100], n, i, pos;
    clrscr();
    printf("Enter array size: "); scanf("%d",&n);
    if(n<1 || n>100) { printf("Invalid size"); getch(); return; }
    for(i=0;i<n;i++) { printf("Enter element: "); scanf("%d",&a[i]); }
    printf("Enter position to delete (1 to %d): ",n); scanf("%d",&pos);
    if(pos<1 || pos>n) printf("Invalid position");
    else {
        for(i=pos-1;i<n-1;i++) a[i]=a[i+1];
        n--;
        printf("Array after deletion: ");
        for(i=0;i<n;i++) printf("%d ",a[i]);
    }
    getch();
}
