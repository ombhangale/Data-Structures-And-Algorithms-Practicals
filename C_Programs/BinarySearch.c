/*
Write a program for binary search
*/
#include <stdio.h>
#include <conio.h>
void main()
{
    int a[100], n, i, key, low, high, mid, found=0;
    clrscr();
    printf("Enter sorted array size: "); scanf("%d",&n);
    for(i=0;i<n;i++) { printf("Enter element in ascending order: "); scanf("%d",&a[i]); }
    printf("Enter element to search: "); scanf("%d",&key);
    low=0; high=n-1;
    while(low<=high) {
        mid=(low+high)/2;
        if(a[mid]==key) { printf("Found at position %d",mid+1); found=1; break; }
        else if(key<a[mid]) high=mid-1;
        else low=mid+1;
    }
    if(!found) printf("Element not found");
    getch();
}
