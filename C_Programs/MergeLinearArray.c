/*
Write a program for merging operation on linear array
*/
#include <stdio.h>
#include <conio.h>
void main()
{
    int a[50], b[50], c[100], n, m, i;
    clrscr();
    printf("Enter size of first array: "); scanf("%d",&n);
    printf("Enter first array elements:\n");
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    printf("Enter size of second array: "); scanf("%d",&m);
    printf("Enter second array elements:\n");
    for(i=0;i<m;i++) scanf("%d",&b[i]);
    for(i=0;i<n;i++) c[i]=a[i];
    for(i=0;i<m;i++) c[n+i]=b[i];
    printf("Merged array: ");
    for(i=0;i<n+m;i++) printf("%d ",c[i]);
    getch();
}
