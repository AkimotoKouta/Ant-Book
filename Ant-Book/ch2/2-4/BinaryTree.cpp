#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

struct node {
    int val;
    node *lchild, *rchild;
};

node *insert(node *p, int x){
    if(p == NULL){
        node *q = new node;
        q->val = x;
        q->lchild = q->rchild = NULL;
        return q;
    }else{
        if(x < p->val) p->lchild = insert(p->lchild, x);
        else p->rchild = insert(p->rchild, x);
        return p;
    }
}

bool find(node *p, int x) {
    if (p == NULL) return false;
    else if(x == p->val) return true;
    else if(x < p->val) return find(p->lchild, x);
    else return find(p->rchild, x);
}

node *remove(node *p, int x){
    if(p == NULL) return NULL;
    else if(x < p->val) p->lchild = remove(p->lchild, x);
    else if(x > p->val) p->lchild = remove(p->rchild, x);
    else if(p->lchild == NULL){
        node *q = p->rchild;
        delete p;
        return q;
    }else if(p->lchild->rchild == NULL){
        node *q = p->lchild;
        q->rchild = p->rchild;
        delete p;
        return q;
    }else{
        node *q;
        for (q = p->lchild; q->rchild->rchild != NULL; q = q->rchild);
        node *r = q->rchild;
        q->rchild = r->lchild;
        r->lchild = p->lchild;
        r->rchild = p->rchild;
        delete p;
        return r;
    }
    return p;
}

int main(){

}