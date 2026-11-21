/*
Menu driven static queue implementation
*/
#include <stdio.h>
#include <conio.h>
#define MAX 5
int q[MAX],front=-1,rear=-1;
void enqueue() {
    int x; if(rear==MAX-1) { printf("Queue Overflow"); return; }
    printf("Enter value: "); scanf("%d",&x);
    if(front==-1) front=0; q[++rear]=x;
}
void dequeue() {
    if(front==-1 || front>rear) { printf("Queue Underflow"); front=rear=-1; }
    else { printf("Deleted = %d",q[front++]); if(front>rear) front=rear=-1; }
}
void display() {
    int i; if(front==-1) { printf("Queue empty"); return; }
    for(i=front;i<=rear;i++) printf("%d ",q[i]);
}
void length() { if(front==-1) printf("Length = 0"); else printf("Length = %d",rear-front+1); }
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
