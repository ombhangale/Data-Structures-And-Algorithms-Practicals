/*
Binary Search Tree traversals (preorder, inorder, postorder)
*/
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
struct Node { int data; struct Node *left,*right; };
struct Node *root=NULL;
struct Node *insert(struct Node *r,int x) {
    if(r==NULL) {
        r=(struct Node *)malloc(sizeof(struct Node));
        r->data=x; r->left=r->right=NULL;
    } else if(x<r->data) r->left=insert(r->left,x);
    else if(x>r->data) r->right=insert(r->right,x);
    return r;
}
void inorder(struct Node *r) { if(r!=NULL) { inorder(r->left); printf("%d ",r->data); inorder(r->right); } }
void preorder(struct Node *r) { if(r!=NULL) { printf("%d ",r->data); preorder(r->left); preorder(r->right); } }
void postorder(struct Node *r) { if(r!=NULL) { postorder(r->left); postorder(r->right); printf("%d ",r->data); } }
int height(struct Node *r) {
    int l,h; if(r==NULL) return 0;
    l=height(r->left); h=height(r->right); return (l>h?l:h)+1;
}
int countNodes(struct Node *r) { if(r==NULL) return 0; return 1+countNodes(r->left)+countNodes(r->right); }
int countLeaves(struct Node *r) {
    if(r==NULL) return 0; if(r->left==NULL && r->right==NULL) return 1;
    return countLeaves(r->left)+countLeaves(r->right);
}
int countNonLeaf(struct Node *r) {
    if(r==NULL || (r->left==NULL && r->right==NULL)) return 0;
    return 1+countNonLeaf(r->left)+countNonLeaf(r->right);
}
int countOdd(struct Node *r) {
    if(r==NULL) return 0; return (r->data%2!=0)+countOdd(r->left)+countOdd(r->right);
}
void levelOrder(struct Node *r) {
    struct Node *q[100]; int f=0,rear=0;
    if(r==NULL) { printf("Tree empty"); return; }
    q[rear++]=r;
    while(f<rear) {
        r=q[f++]; printf("%d ",r->data);
        if(r->left!=NULL && rear<100) q[rear++]=r->left;
        if(r->right!=NULL && rear<100) q[rear++]=r->right;
    }
}
void main() {
    int ch,x; clrscr();
    do {
        printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Height");
        printf("\n6.Ascending Order\n7.Level Order\n8.Total Nodes\n9.Leaf Nodes");
        printf("\n10.Non-leaf Nodes\n11.Odd Numbers\n12.Exit\nChoice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: printf("Enter value: "); scanf("%d",&x); root=insert(root,x); break;
            case 2: printf("Inorder: "); inorder(root); break;
            case 3: printf("Preorder: "); preorder(root); break;
            case 4: printf("Postorder: "); postorder(root); break;
            case 5: printf("Height = %d",height(root)); break;
            case 6: printf("Ascending: "); inorder(root); break;
            case 7: printf("Level order: "); levelOrder(root); break;
            case 8: printf("Total nodes = %d",countNodes(root)); break;
            case 9: printf("Leaf nodes = %d",countLeaves(root)); break;
            case 10: printf("Non-leaf nodes = %d",countNonLeaf(root)); break;
            case 11: printf("Odd nodes = %d",countOdd(root)); break;
            case 12: break;
            default: printf("Invalid choice");
        }
    } while(ch!=12);
    getch();
}
