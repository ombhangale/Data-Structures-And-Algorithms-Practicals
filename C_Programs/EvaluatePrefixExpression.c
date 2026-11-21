/*
Write a program to evaluate prefix expression using a stack
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
void main()
{
    char exp[50],ch; int st[50],top=-1,i,a,b;
    clrscr();
    printf("Enter prefix expression (single digit operands): ");
    scanf("%s",exp);
    for(i=strlen(exp)-1;i>=0;i--) {
        ch=exp[i];
        if(isdigit(ch)) st[++top]=ch-'0';
        else {
            if(top<1) { printf("Invalid expression"); getch(); return; }
            a=st[top--]; b=st[top--];
            if(ch=='+') st[++top]=a+b;
            else if(ch=='-') st[++top]=a-b;
            else if(ch=='*') st[++top]=a*b;
            else if(ch=='/') { if(b==0) { printf("Divide by zero"); getch(); return; } st[++top]=a/b; }
        }
    }
    if(top==0) printf("Result = %d",st[top]); else printf("Invalid expression");
    getch();
}
