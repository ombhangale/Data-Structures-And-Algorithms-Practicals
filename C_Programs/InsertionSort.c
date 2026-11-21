/*
Write a program for Insertion Sort
*/
#include <stdio.h>
#include <conio.h>
void main()
{
    int a[100],n,i,j,key;
    clrscr();
    printf("Enter size: "); scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=1;i<n;i++) {
        key=a[i]; j=i-1;
        while(j>=0 && a[j]>key) { a[j+1]=a[j]; j--; }
        a[j+1]=key;
    }
    printf("Sorted array: ");
    for(i=0;i<n;i++) printf("%d ",a[i]);
    getch();
}
