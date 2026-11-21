/*
Write a program to evaluate infix expression using a stack
*/
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
void main()
{
    char exp[50],op[50],ch; int val[50],topV=-1,topO=-1,i,a,b;
    clrscr();
    printf("Enter infix expression (single digits, no spaces): ");
    scanf("%s",exp);
    for(i=0;exp[i]!='\0';i++) {
        ch=exp[i];
        if(isdigit(ch)) val[++topV]=ch-'0';
        else if(ch=='(') op[++topO]=ch;
        else if(ch==')') {
            while(topO>=0 && op[topO]!='(') {
                b=val[topV--]; a=val[topV--]; ch=op[topO--];
                if(ch=='+') val[++topV]=a+b;
                else if(ch=='-') val[++topV]=a-b;
                else if(ch=='*') val[++topV]=a*b;
                else if(ch=='/') val[++topV]=a/b;
            }
            if(topO>=0) topO--;
        } else {
            while(topO>=0 && op[topO]!='(' &&
                  ((op[topO]=='*' || op[topO]=='/') ||
                  ((ch=='+' || ch=='-') && (op[topO]=='+' || op[topO]=='-')))) {
                b=val[topV--]; a=val[topV--]; ch=op[topO--];
                if(ch=='+') val[++topV]=a+b;
                else if(ch=='-') val[++topV]=a-b;
                else if(ch=='*') val[++topV]=a*b;
                else if(ch=='/') val[++topV]=a/b;
            }
            op[++topO]=exp[i];
        }
    }
    while(topO>=0) {
        ch=op[topO--]; b=val[topV--]; a=val[topV--];
        if(ch=='+') val[++topV]=a+b;
        else if(ch=='-') val[++topV]=a-b;
        else if(ch=='*') val[++topV]=a*b;
        else if(ch=='/') val[++topV]=a/b;
    }
    printf("Result = %d",val[topV]);
    getch();
}
