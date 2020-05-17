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
using namespace std;
const int INF=1e9;


template <class T>
class p_segtree{
    struct node{node *l,*r;T d;};
    int cv=0;
    int n;
    node* ver[100005];
public:
    p_segtree(int x,T tab[]){
        n=x;
        ver[0]=built(0,n-1,tab);
    }
    p_segtree(int x){
        n=x;
        int tab[x]={};
        ver[0]=built(0,n-1,tab);
    }
    void update(int x,int v){
        cv++;
        ver[cv]=up(0,n-1,v,x,ver[cv-1]);
    }
    T query(int v,int st,int ed){
        return qu(st,ed,0,n-1,ver[v]);
    }
private:
    node* built(int l,int r,T tab[]){
        if(l==r){
           node* tmp=(node*)malloc(sizeof(node));
           tmp->l=NULL;
           tmp->r=NULL;
           tmp->d=tab[l];
           return tmp;
        }
        node* tmp=(node*)malloc(sizeof(node));
        int m=(l+r)>>1;
        tmp->l=built(l,m,tab);
        tmp->r=built(m+1,r,tab);
        tmp->d=tmp->l->d+tmp->r->d;
        return tmp;
    }
     node* up(int l,int r,int v,int x,node* p){
        if(l==r){
            node* tmp=(node*)malloc(sizeof(node));
            tmp->l=NULL;
            tmp->r=NULL;
            tmp->d=v;
            return tmp;
        }
        int m=(l+r)/2;
        node* tmp=(node*)malloc(sizeof(node));
        if(x<=m){
            tmp->l=up(l,m,v,x,p->l);
            tmp->r=p->r;
        }
        else{
            tmp->r=up(m+1,r,v,x,p->r);
            tmp->l=p->l;
        }
        tmp->d=tmp->l->d+tmp->r->d;
        return tmp;
    }

    T qu(int st,int ed,int l,int r,node* p){
        if(st<=l&&r<=ed){return p->d;}
        if(r<st||l>ed)return 0;
        int m=(l+r)/2;
        return qu(st,ed,l,m,p->l)+qu(st,ed,m+1,r,p->r);
    }
};

int main(){
    int n;
    cin>>n;
    p_segtree<int> arr(n);
    while(1){
        int a,b,c,d;
        cin>>a>>b>>c;
        if(a==0){
                cin>>d;
            cout<<arr.query(b,c,d)<<endl;
        }
        else{
            arr.update(b,c);
        }
    }
}
