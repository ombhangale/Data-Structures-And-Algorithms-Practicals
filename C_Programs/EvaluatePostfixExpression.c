/*
Write a program to evaluate postfix expression using a stack
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
void main()
{
    char exp[50],ch; int st[50],top=-1,i,a,b;
    clrscr();
    printf("Enter postfix expression (single digit operands): ");
    scanf("%s",exp);
    for(i=0;exp[i]!='\0';i++) {
        ch=exp[i];
        if(isdigit(ch)) st[++top]=ch-'0';
        else {
            if(top<1) { printf("Invalid expression"); getch(); return; }
            b=st[top--]; a=st[top--];
            if(ch=='+') st[++top]=a+b;
            else if(ch=='-') st[++top]=a-b;
            else if(ch=='*') st[++top]=a*b;
            else if(ch=='/') { if(b==0) { printf("Divide by zero"); getch(); return; } st[++top]=a/b; }
        }
    }
    if(top==0) printf("Result = %d",st[top]); else printf("Invalid expression");
    getch();
}
