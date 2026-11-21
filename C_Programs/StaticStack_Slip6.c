/*
Menu driven static stack implementation
*/
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
struct Node { int data; struct Node *next; };
struct Node *top=NULL;
void push() {
    struct Node *n; n=(struct Node *)malloc(sizeof(struct Node));
    if(n==NULL) { printf("Memory not available"); return; }
    printf("Enter value: "); scanf("%d",&n->data); n->next=top; top=n;
}
void pop() {
    struct Node *p; if(top==NULL) { printf("Stack Underflow"); return; }
    p=top; printf("Deleted = %d",p->data); top=top->next; free(p);
}
void peek() { if(top==NULL) printf("Stack empty"); else printf("Top = %d",top->data); }
void show() { struct Node *p=top; if(p==NULL) printf("Stack empty"); while(p!=NULL) { printf("%d\n",p->data); p=p->next; } }
void size() { int n=0; struct Node *p=top; while(p!=NULL) { n++; p=p->next; } printf("Size = %d",n); }
void main() {
    int ch; clrscr();
    do {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Show\n5.Size\n6.Is Empty\n7.Exit");
        printf("\nChoice: "); scanf("%d",&ch);
        switch(ch) {
            case 1: push(); break; case 2: pop(); break; case 3: peek(); break;
            case 4: show(); break; case 5: size(); break;
            case 6: if(top==NULL) printf("Empty"); else printf("Not empty"); break;
            case 7: break; default: printf("Invalid choice");
        }
    } while(ch!=7);
    getch();
}
