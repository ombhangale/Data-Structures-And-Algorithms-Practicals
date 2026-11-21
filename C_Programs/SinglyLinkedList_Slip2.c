/*
Menu driven singly linked list (Insert, Display, Search/other requested operation)
*/
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
struct Node { int data; struct Node *next; };
struct Node *head=NULL;
void insertEnd() {
    struct Node *n,*p; n=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: "); scanf("%d",&n->data); n->next=NULL;
    if(head==NULL) head=n; else { p=head; while(p->next!=NULL) p=p->next; p->next=n; }
}
void insertBegin() {
    struct Node *n; n=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: "); scanf("%d",&n->data); n->next=head; head=n;
}
void insertPos() {
    int pos,i; struct Node *n,*p;
    printf("Enter position: "); scanf("%d",&pos);
    if(pos<1) { printf("Invalid position"); return; }
    if(pos==1) { insertBegin(); return; }
    p=head; for(i=1;p!=NULL && i<pos-1;i++) p=p->next;
    if(p==NULL) { printf("Invalid position"); return; }
    n=(struct Node *)malloc(sizeof(struct Node)); printf("Enter data: "); scanf("%d",&n->data);
    n->next=p->next; p->next=n;
}
void display() {
    struct Node *p; if(head==NULL) { printf("List is empty"); return; }
    p=head; while(p!=NULL) { printf("%d -> ",p->data); p=p->next; } printf("NULL");
}
void search() {
    int key,pos=1; struct Node *p=head;
    printf("Enter key: "); scanf("%d",&key);
    while(p!=NULL) { if(p->data==key) { printf("Found at position %d",pos); return; } p=p->next; pos++; }
    printf("Not found");
}
void deleteBegin() {
    struct Node *p; if(head==NULL) { printf("List is empty"); return; }
    p=head; head=head->next; free(p); printf("First node deleted");
}
void deleteEnd() {
    struct Node *p,*q; if(head==NULL) { printf("List is empty"); return; }
    if(head->next==NULL) { free(head); head=NULL; }
    else { p=head; while(p->next->next!=NULL) p=p->next; q=p->next; p->next=NULL; free(q); }
    printf("Last node deleted");
}
void deletePos() {
    int pos,i; struct Node *p,*q;
    printf("Enter position: "); scanf("%d",&pos);
    if(pos<1 || head==NULL) { printf("Invalid position"); return; }
    if(pos==1) { deleteBegin(); return; }
    p=head; for(i=1;p!=NULL && i<pos-1;i++) p=p->next;
    if(p==NULL || p->next==NULL) { printf("Invalid position"); return; }
    q=p->next; p->next=q->next; free(q); printf("Node deleted");
}
void length() {
    int count=0; struct Node *p=head; while(p!=NULL) { count++; p=p->next; }
    printf("Length = %d",count);
}
void main() {
    int ch; clrscr();
    do {
        printf("\n\n1.Insert at End\n2.Insert at Beginning\n3.Insert at Position");
        printf("\n4.Display\n5.Search\n6.Delete from Beginning\n7.Delete from End\n8.Delete from Position\n9.Length\n10.Exit");
        printf("\nEnter choice: "); scanf("%d",&ch);
        switch(ch) {
            case 1: insertEnd(); break;
            case 2: insertBegin(); break;
            case 3: insertPos(); break;
            case 4: display(); break;
            case 5: search(); break;
            case 6: deleteBegin(); break;
            case 7: deleteEnd(); break;
            case 8: deletePos(); break;
            case 9: length(); break;
            case 10: break;
            default: printf("Invalid choice");
        }
    } while(ch!=10);
    getch();
}
