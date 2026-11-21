/*
Write a program for insertion operation on linear array
*/
#include <stdio.h>
#include <conio.h>
void main()
{
    int a[100], n, i, pos, value;
    clrscr();
    printf("Enter array size: "); scanf("%d", &n);
    if(n<0 || n>=100) { printf("Invalid size"); getch(); return; }
    for(i=0; i<n; i++) { printf("Enter element: "); scanf("%d",&a[i]); }
    printf("Enter position (1 to %d): ", n+1); scanf("%d",&pos);
    if(pos<1 || pos>n+1) printf("Invalid position");
    else {
        printf("Enter value: "); scanf("%d",&value);
        for(i=n; i>=pos; i--) a[i]=a[i-1];
        a[pos-1]=value; n++;
        printf("Array after insertion: ");
        for(i=0;i<n;i++) printf("%d ",a[i]);
    }
    getch();
}
