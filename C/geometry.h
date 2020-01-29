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

