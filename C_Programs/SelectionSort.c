/*
Write a program for Selection Sort
*/
#include <stdio.h>
#include <conio.h>
void main()
{
    int a[100],n,i,j,min,temp;
    clrscr();
    printf("Enter size: "); scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n-1;i++) {
        min=i;
        for(j=i+1;j<n;j++) if(a[j]<a[min]) min=j;
        temp=a[i]; a[i]=a[min]; a[min]=temp;
    }
    printf("Sorted array: ");
    for(i=0;i<n;i++) printf("%d ",a[i]);
    getch();
}
