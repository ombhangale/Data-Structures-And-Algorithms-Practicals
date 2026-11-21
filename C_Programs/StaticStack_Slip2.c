/*
Menu driven static stack implementation
*/
#include <stdio.h>
#include <conio.h>
#define MAX 5
int stack[MAX],top=-1;
void push() {
    int x; if(top==MAX-1) { printf("Stack Overflow"); return; }
    printf("Enter value: "); scanf("%d",&x); stack[++top]=x;
}
void pop() {
    if(top==-1) printf("Stack Underflow");
    else printf("Deleted element = %d",stack[top--]);
}
void peek() {
    if(top==-1) printf("Stack is empty"); else printf("Top = %d",stack[top]);
}
void show() {
    int i; if(top==-1) { printf("Stack is empty"); return; }
    for(i=top;i>=0;i--) printf("%d\n",stack[i]);
}
void main() {
    int ch; clrscr();
    do {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Show\n5.Is Empty\n6.Is Full\n7.Size\n8.Exit");
        printf("\nChoice: "); scanf("%d",&ch);
        switch(ch) {
            case 1: push(); break; case 2: pop(); break; case 3: peek(); break;
            case 4: show(); break; case 5: if(top==-1) printf("Empty"); else printf("Not empty"); break;
            case 6: if(top==MAX-1) printf("Full"); else printf("Not full"); break;
            case 7: printf("Size = %d",top+1); break; case 8: break;
            default: printf("Invalid choice");
        }
    } while(ch!=8);
    getch();
}
