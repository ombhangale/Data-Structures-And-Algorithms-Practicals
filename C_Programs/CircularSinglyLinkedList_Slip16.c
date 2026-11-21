/*
Menu driven circular singly linked list
*/
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
struct Node { int data; struct Node *next; };
struct Node *last=NULL;
void insertBegin() {
    struct Node *n; n=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: "); scanf("%d",&n->data);
    if(last==NULL) { last=n; n->next=n; }
    else { n->next=last->next; last->next=n; }
}
void insertEnd() {
    struct Node *n; n=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: "); scanf("%d",&n->data);
    if(last==NULL) { last=n; n->next=n; }
    else { n->next=last->next; last->next=n; last=n; }
}
void insertPos() {
    int pos,i; struct Node *p,*n;
    printf("Enter position: "); scanf("%d",&pos);
    if(pos==1 || last==NULL) { insertBegin(); return; }
    p=last->next;
    for(i=1;i<pos-1 && p!=last;i++) p=p->next;
    if(i!=pos-1) { printf("Invalid position"); return; }
    n=(struct Node *)malloc(sizeof(struct Node)); printf("Enter data: "); scanf("%d",&n->data);
    n->next=p->next; p->next=n; if(p==last) last=n;
}
void display() {
    struct Node *p; if(last==NULL) { printf("List empty"); return; }
    p=last->next; do { printf("%d -> ",p->data); p=p->next; } while(p!=last->next);
    printf("(back to start)");
}
void search() {
    int key,pos=1; struct Node *p; if(last==NULL) { printf("List empty"); return; }
    printf("Enter key: "); scanf("%d",&key); p=last->next;
    do { if(p->data==key) { printf("Found at position %d",pos); return; } p=p->next; pos++; } while(p!=last->next);
    printf("Not found");
}
void deleteBegin() {
    struct Node *p; if(last==NULL) { printf("List empty"); return; }
    p=last->next; if(p==last) last=NULL; else last->next=p->next; free(p);
}
void deleteEnd() {
    struct Node *p; if(last==NULL) { printf("List empty"); return; }
    p=last->next; if(p==last) { free(last); last=NULL; return; }
    while(p->next!=last) p=p->next;
    p->next=last->next; free(last); last=p;
}
void deletePos() {
    int pos,i; struct Node *p,*q;
    printf("Enter position: "); scanf("%d",&pos);
    if(last==NULL || pos<1) { printf("Invalid position"); return; }
    if(pos==1) { deleteBegin(); return; }
    p=last->next; for(i=1;i<pos-1 && p!=last;i++) p=p->next;
    if(p==last || p->next==last->next) { printf("Invalid position"); return; }
    q=p->next; p->next=q->next; if(q==last) last=p; free(q);
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
