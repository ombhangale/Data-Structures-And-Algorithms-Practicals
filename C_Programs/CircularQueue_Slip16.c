/*
Menu driven circular queue implementation
*/
#include <stdio.h>
#include <conio.h>
#define MAX 5
int q[MAX],front=-1,rear=-1;
void enqueue() {
    int x;
    if((front==0 && rear==MAX-1) || (front==rear+1)) { printf("Queue Full"); return; }
    printf("Enter value: "); scanf("%d",&x);
    if(front==-1) front=rear=0; else rear=(rear+1)%MAX;
    q[rear]=x;
}
void dequeue() {
    if(front==-1) { printf("Queue Empty"); return; }
    printf("Deleted = %d",q[front]);
    if(front==rear) front=rear=-1; else front=(front+1)%MAX;
}
void display() {
    int i; if(front==-1) { printf("Queue Empty"); return; }
    i=front; while(1) { printf("%d ",q[i]); if(i==rear) break; i=(i+1)%MAX; }
}
void length() {
    int n=0,i; if(front==-1) { printf("Length = 0"); return; }
    i=front; while(1) { n++; if(i==rear) break; i=(i+1)%MAX; } printf("Length = %d",n);
}
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
