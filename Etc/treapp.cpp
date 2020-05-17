#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
struct node{
    int data;
    int pr;
    node* l,r;
    node(int data,int pr):data(data),pr(pr),l(NULL),r(NULL){};
};
void split(node* t,int x,node* &l,node* &r){
    if(t==NULL){
        l=r=NULL;
    }
    else if(t->data <= x){
        l=t;
        split(t->r,x,t->r,r);
    }
    else{
        r=t;
        split(t->l,x,l,t->l);
    }
}
void merge(node* &t,node* l,node *r){
    if(l==NULL){
        t=r;
    }
    else if(r==NULL){
        t=l;
    }
    else if(l->pr>r->pr){
        t=l;
        merge(l->r,l->r,r);
    }
    else{
        t=r;
        merge(r->l,l,r->l);
    }
}
void insert(node* &t,int data){
    node tmp = malloc(size_of(node));
    tmp = tmp(data,rand());
    node *w = *t;
    while(w!=NULL&&w->pr>tmp->pr){
        if(tmp->data==w->data)return;
        if(tmp->data<w->data){
            w=w->l;
        }
        else w=w->r;
    }
    node *l,*r;
    split(w,tmp->data,&l,&r);
    w=tmp
    tmp->l=l;
    tmp->r=r;
}
void erase(node* t,int data){
    node *w = *t;
    while(w!=NULL){
        if(w->data==data)break;
        bf=w;
        else if(w->data>data)w=w->l
        else w=w->r;
    }
    merge(&w,w->l,w->r)
}
int main(){
    srand(time(NULL));
}
