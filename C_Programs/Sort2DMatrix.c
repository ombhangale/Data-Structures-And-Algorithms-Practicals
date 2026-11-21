/*
Write a program for sorting in 2D Matrix
*/
#include <stdio.h>
#include <conio.h>
void main()
{
    int a[10][10],r,c,i,j,k,temp;
    clrscr();
    printf("Enter rows and columns: "); scanf("%d%d",&r,&c);
    for(i=0;i<r;i++) for(j=0;j<c;j++) scanf("%d",&a[i][j]);
    for(i=0;i<r*c-1;i++)
        for(j=i+1;j<r*c;j++)
            if(a[i/c][i%c]>a[j/c][j%c]) {
                temp=a[i/c][i%c]; a[i/c][i%c]=a[j/c][j%c]; a[j/c][j%c]=temp;
            }
    printf("Sorted matrix:\n");
    for(i=0;i<r;i++) { for(j=0;j<c;j++) printf("%d\t",a[i][j]); printf("\n"); }
    getch();
}
