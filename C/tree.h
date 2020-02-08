#include<stdio.h>
#include<stdlib.h>

typedef struct node *nodep;//node pointer
typedef struct node{
    int val, q, level;//q - quantity
    nodep l, r;//left, right
}node;

void addnode(nodep root, int n, int *mlevel){
    if(n==root->val)root->q++;
    else if(n < root->val && root->l==NULL){
        nodep nod=(nodep)calloc(1, sizeof(node));
        nod->val=n; nod->q=1; nod->level=root->level+1;
        if(nod->level>*mlevel)*mlevel=nod->level;
        nod->l=NULL; nod->r=NULL;
        root->l=nod;
    }
    else if(n < root->val && root->l!=NULL)addnode(root->l, n, mlevel);
    else if(n>=root->val && root->r==NULL){
        nodep nod=(nodep)calloc(1, sizeof(node));
        nod->val=n; nod->q=1; nod->level=root->level+1;
        if(nod->level>*mlevel)*mlevel=nod->level;
        nod->l=NULL; nod->r=NULL;
        root->r=nod;
    }
    else if(n>=root->val && root->r!=NULL)addnode(root->r, n, mlevel);
}

nodep initroot(int n){
    nodep root=(nodep)calloc(1, sizeof(node));
    root->val=n; root->q=1; root->level=0;
    root->l=NULL; root->r=NULL;
    return root;
}

int countnodes(node *root){
    int n=1;
    if(root->l!=NULL)n+=countnodes(root->l);
    if(root->r!=NULL)n+=countnodes(root->r);
    return n;
}

void printtree(nodep root){
    printf("%d: %d\n", root->level, root->val);
    if(root->l!=NULL)printtree(root->l);
    if(root->r!=NULL)printtree(root->r);
}
