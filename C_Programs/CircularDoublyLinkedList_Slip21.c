/*
Menu driven circular doubly linked list
*/
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
struct Node { int data; struct Node *prev,*next; };
struct Node *head=NULL;
void insertBegin() {
    struct Node *n,*last; n=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: "); scanf("%d",&n->data);
    if(head==NULL) { head=n; n->next=n; n->prev=n; }
    else { last=head->prev; n->next=head; n->prev=last; last->next=n; head->prev=n; head=n; }
}
void insertEnd() {
    struct Node *n,*last; n=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: "); scanf("%d",&n->data);
    if(head==NULL) { head=n; n->next=n; n->prev=n; }
    else { last=head->prev; n->next=head; n->prev=last; last->next=n; head->prev=n; }
}
void insertPos() {
    int pos,i; struct Node *p,*n;
    printf("Enter position: "); scanf("%d",&pos);
    if(pos==1 || head==NULL) { insertBegin(); return; }
    p=head; for(i=1;i<pos-1 && p->next!=head;i++) p=p->next;
    if(i!=pos-1) { printf("Invalid position"); return; }
    n=(struct Node *)malloc(sizeof(struct Node)); printf("Enter data: "); scanf("%d",&n->data);
    n->next=p->next; n->prev=p; p->next->prev=n; p->next=n;
}
void display() {
    struct Node *p; if(head==NULL) { printf("List empty"); return; }
    p=head; do { printf("%d <-> ",p->data); p=p->next; } while(p!=head); printf("(back to start)");
}
void search() {
    int key,pos=1; struct Node *p; if(head==NULL) { printf("List empty"); return; }
    printf("Enter key: "); scanf("%d",&key); p=head;
    do { if(p->data==key) { printf("Found at position %d",pos); return; } p=p->next; pos++; } while(p!=head);
    printf("Not found");
}
void deleteBegin() {
    struct Node *p,*last; if(head==NULL) { printf("List empty"); return; }
    p=head; if(head->next==head) head=NULL;
    else { last=head->prev; head=head->next; head->prev=last; last->next=head; } free(p);
}
void deleteEnd() {
    struct Node *p,*last; if(head==NULL) { printf("List empty"); return; }
    last=head->prev; if(last==head) head=NULL;
    else { p=last->prev; p->next=head; head->prev=p; } free(last);
}
void deletePos() {
    int pos,i; struct Node *p;
    printf("Enter position: "); scanf("%d",&pos);
    if(head==NULL || pos<1) { printf("Invalid position"); return; }
    if(pos==1) { deleteBegin(); return; }
    p=head; for(i=1;i<pos && p->next!=head;i++) p=p->next;
    if(p==head || i!=pos) { printf("Invalid position"); return; }
    p->prev->next=p->next; p->next->prev=p->prev; free(p);
}
void main() {
    int ch; clrscr();
    do {
        printf("\n1.Display\n2.Insert at Beginning\n3.Insert at End\n4.Insert at Position");
        printf("\n5.Search\n6.Delete from Beginning\n7.Delete from End\n8.Delete from Position\n9.Exit");
        printf("\nChoice: "); scanf("%d",&ch);
        switch(ch) {
            case 1: display(); break; case 2: insertBegin(); break; case 3: insertEnd(); break;
            case 4: insertPos(); break; case 5: search(); break; case 6: deleteBegin(); break;
            case 7: deleteEnd(); break; case 8: deletePos(); break; case 9: break;
            default: printf("Invalid choice");
        }
    } while(ch!=9);
    getch();
}
