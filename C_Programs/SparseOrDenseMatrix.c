/*
Write a program for Sparse Matrix or Dense Matrix
*/
#include <stdio.h>
#include <conio.h>
void main()
{
    int a[10][10],r,c,i,j,zero=0,nonzero=0;
    clrscr();
    printf("Enter rows and columns: "); scanf("%d%d",&r,&c);
    for(i=0;i<r;i++) for(j=0;j<c;j++) {
        scanf("%d",&a[i][j]);
        if(a[i][j]==0) zero++; else nonzero++;
    }
    printf("Zero elements = %d\nNon-zero elements = %d\n",zero,nonzero);
    if(zero>nonzero) printf("Sparse Matrix");
    else printf("Dense Matrix");
    getch();
}
