/*
Write a program for searching in 2D Matrix
*/
#include <stdio.h>
#include <conio.h>
void main()
{
    int a[10][10],r,c,i,j,key,found=0;
    clrscr();
    printf("Enter rows and columns: "); scanf("%d%d",&r,&c);
    for(i=0;i<r;i++) for(j=0;j<c;j++) scanf("%d",&a[i][j]);
    printf("Enter element to search: "); scanf("%d",&key);
    for(i=0;i<r;i++) for(j=0;j<c;j++)
        if(a[i][j]==key) { printf("Found at row %d column %d",i+1,j+1); found=1; }
    if(!found) printf("Element not found");
    getch();
}
