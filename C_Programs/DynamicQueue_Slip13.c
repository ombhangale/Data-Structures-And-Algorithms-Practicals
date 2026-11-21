/*
Menu driven dynamic queue implementation
*/
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
struct Node { int data; struct Node *next; };
struct Node *front=NULL,*rear=NULL;
void enqueue() {
    struct Node *n; n=(struct Node *)malloc(sizeof(struct Node));
    if(n==NULL) { printf("Memory not available"); return; }
    printf("Enter value: "); scanf("%d",&n->data); n->next=NULL;
    if(rear==NULL) front=rear=n; else { rear->next=n; rear=n; }
}
void dequeue() {
    struct Node *p; if(front==NULL) { printf("Queue Underflow"); return; }
    p=front; printf("Deleted = %d",p->data); front=front->next;
    if(front==NULL) rear=NULL; free(p);
}
void display() { struct Node *p=front; if(p==NULL) printf("Queue empty"); while(p!=NULL) { printf("%d ",p->data); p=p->next; } }
void length() { int n=0; struct Node *p=front; while(p!=NULL) { n++; p=p->next; } printf("Length = %d",n); }
void main() {
    int ch; clrscr();
    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Length\n5.Exit");
        printf("\nChoice: "); scanf("%d",&ch);
        switch(ch) {
            case 1: enqueue(); break; case 2: dequeue(); break; case 3: display(); break;
            case 4: length(); break; case 5: break; default: printf("Invalid choice");
        }
    } while(ch!=5);
    getch();
}
