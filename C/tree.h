#include<stdio.h>
#include<stdlib.h>

typedef struct tnode *nodep;//node pointer
typedef struct tnode{
    int val, q, level;//q - quantity
    nodep l, r;//left, right
}tnode;

nodep initnode(int n){
    nodep node=(nodep)calloc(1, sizeof(tnode));
    node->val=n; node->q=1; node->level=0;
    node->l=NULL; node->r=NULL;
    return node;
}

void addnode(tnode *root, int n){
    if(n==root->val)root->q++;
    else if(n < root->val && root->l==NULL){root->l=initnode(n); root->l->level=root->level+1;}
    else if(n < root->val && root->l!=NULL)addnode(root->l, n);
    else if(n >= root->val && root->r==NULL){root->r=initnode(n); root->r->level=root->level+1;}
    else if(n >= root->val && root->r!=NULL)addnode(root->r, n);
}

nodep getmax(node *root){//returns pointer to a node with max val
    nodep p=root;
    while(p->r!=NULL)p=p->r;
    return p;
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

void psorted(nodep root){//print sorted
    if(root->l!=NULL)psorted(root->l);
    printf("%d\n", root->val);
    if(root->r!=NULL)psorted(root->r);
}
