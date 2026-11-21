/*
Write a program for accessing an element in a 2D Matrix
*/
#include <stdio.h>
#include <conio.h>
void main()
{
    int a[10][10],r,c,i,j,row,col;
    clrscr();
    printf("Enter rows and columns: "); scanf("%d%d",&r,&c);
    for(i=0;i<r;i++) for(j=0;j<c;j++) {
        printf("Enter a[%d][%d]: ",i,j); scanf("%d",&a[i][j]);
    }
    printf("Enter row and column to access (1-based): "); scanf("%d%d",&row,&col);
    if(row>=1 && row<=r && col>=1 && col<=c)
        printf("Element = %d",a[row-1][col-1]);
    else printf("Invalid index");
    getch();
}
