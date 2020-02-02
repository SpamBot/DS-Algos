#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define eps 0.000001


typedef struct{
    double x, y;
}point;

int req(double a, double b){return abs(a-b)<=eps;}
int rmo(double a, double b){return a-b>eps;}
int rmoeq(double a, double b){return a-b>=eps;}
int rle(double a, double b){return b-a>eps;}
int rleeq(double a, double b){return b-a>=eps;}

int eqpoint(point *a, point *b){return req(a->x, b->x) && req(a->y, b->y);}

double dist(point *a, point *b){//distance between 2 2D points
    return sqrt((a->x-b->x)*(a->x-b->x)+(a->y-b->y)*(a->y-b->y));
}

void pptov(point *a, point *b){//turns first point into 2D point-vector with start at b
    a->x-=b->x; a->y-=b->y;
}

double psmult(point *a, point *b){//scalar multiplication for point-vectors
    return a->x*b->x+a->y*b->y;//=cos(x)*|a|*|b|
}
/*
double s3(point *a, point *b, point *c){//Area of a triangle
    double S, sprodab, //scalar prod of ca and cb
    lca=dist(a, c), lcb=dist(b, c);//length of ca, len of cb
    pptov(a, c); pptov(b, c);//turning points to vectors
    sprodab=psmult(a, b);
    S=sqrt(lca*lca*lcb*lcb-sprodab*sprodab)/2;//S=sqrt(|a|^2*|b|^2-(a•b)^2)
    return S;
}
*/
double s3(point *a, point *b, point *c){//Area of a triangle #2
    pptov(a, c); pptov(b, c);
    double S=abs(a->x*b->y-a->y*b->x);//by vector cross-product
    return S/2;
}

typedef struct{
    int dim;
    double *val;
}vect;

vect initvect(int n){
    vect v; v.dim=n;
    v.val=(double *)calloc(v.dim, sizeof(double));
}

void addvect(vect *v, vect *w){//vector addition
    if(v->dim==w->dim){
        int i;
        for(i=0; i<v->dim; i++) v->val[i]+=w->val[i];
    }
}

void subvect(vect *v, vect *w){//vector substraction
    if(v->dim==w->dim){
        int i;
        for(i=0; i<v->dim; i++) v->val[i]-=w->val[i];
    }
}

void vectmc(vect *v, double d){//vector multiplication with constant
    int i;
    for(i=0; i<v->dim; i++) v->val[i]*=d;
}

double scmult(vect *v, vect *w){//scalar multiplication
    if(v->dim==w->dim){
        int i;
        double out=0;
        for(i=0; i<v->dim; i++) out+=v->val[i]*w->val[i];
        return out;
    }
}

typedef struct{
    point p1, p2;
    double k, b;//kx+b
}line;

line ppmakel(point *a, point *b){
    line l;
    l.p1=*a; l.p2=*b; l.k=(a->x-b->x)/(a->y-b->y);
}

/*point intersec(line *l, line *k){
    
}*/

