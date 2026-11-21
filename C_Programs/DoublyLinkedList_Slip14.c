/*
Menu driven doubly linked list
*/
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
struct Node { int data; struct Node *prev,*next; };
struct Node *head=NULL;
void insertEnd() {
    struct Node *n,*p; n=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: "); scanf("%d",&n->data); n->next=NULL; n->prev=NULL;
    if(head==NULL) head=n;
    else { p=head; while(p->next!=NULL) p=p->next; p->next=n; n->prev=p; }
}
void insertBegin() {
    struct Node *n; n=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: "); scanf("%d",&n->data);
    n->prev=NULL; n->next=head; if(head!=NULL) head->prev=n; head=n;
}
void insertPos() {
    int pos,i; struct Node *p,*n;
    printf("Enter position: "); scanf("%d",&pos);
    if(pos==1) { insertBegin(); return; }
    p=head; for(i=1;p!=NULL && i<pos-1;i++) p=p->next;
    if(p==NULL || pos<1) { printf("Invalid position"); return; }
    n=(struct Node *)malloc(sizeof(struct Node)); printf("Enter data: "); scanf("%d",&n->data);
    n->next=p->next; n->prev=p; if(p->next!=NULL) p->next->prev=n; p->next=n;
}
void display() {
    struct Node *p=head; if(p==NULL) { printf("List empty"); return; }
    while(p!=NULL) { printf("%d <-> ",p->data); p=p->next; } printf("NULL");
}
void search() {
    int key,pos=1; struct Node *p=head; printf("Enter key: "); scanf("%d",&key);
    while(p!=NULL) { if(p->data==key) { printf("Found at position %d",pos); return; } p=p->next; pos++; }
    printf("Not found");
}
void deleteBegin() {
    struct Node *p; if(head==NULL) { printf("List empty"); return; }
    p=head; head=head->next; if(head!=NULL) head->prev=NULL; free(p);
}
void deleteEnd() {
    struct Node *p; if(head==NULL) { printf("List empty"); return; }
    p=head; while(p->next!=NULL) p=p->next;
    if(p->prev!=NULL) p->prev->next=NULL; else head=NULL; free(p);
}
void deletePos() {
    int pos,i; struct Node *p; printf("Enter position: "); scanf("%d",&pos);
    p=head; for(i=1;p!=NULL && i<pos;i++) p=p->next;
    if(p==NULL || pos<1) { printf("Invalid position"); return; }
    if(p->prev!=NULL) p->prev->next=p->next; else head=p->next;
    if(p->next!=NULL) p->next->prev=p->prev; free(p);
}
void length() {
    int n=0; struct Node *p=head; while(p!=NULL) { n++; p=p->next; } printf("Length = %d",n);
}
void main() {
    int ch; clrscr();
    do {
        printf("\n\n1.Insert at End\n2.Insert at Beginning\n3.Insert at Position");
        printf("\n4.Display\n5.Search\n6.Delete from Beginning\n7.Delete from End\n8.Delete from Position\n9.Length\n10.Exit");
        printf("\nEnter choice: "); scanf("%d",&ch);
        switch(ch) {
            case 1: insertEnd(); break; case 2: insertBegin(); break;
            case 3: insertPos(); break; case 4: display(); break;
            case 5: search(); break; case 6: deleteBegin(); break;
            case 7: deleteEnd(); break; case 8: deletePos(); break;
            case 9: length(); break; case 10: break;
            default: printf("Invalid choice");
        }
    } while(ch!=10);
    getch();
}
