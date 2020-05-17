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
class p_array{
    struct node{node *l,*r;T d;};
    int cv=0;
    int n;
    node* ver[100005];
public:
    p_array(int x,T tab[]){
        n=x;
        ver[0]=built(0,n-1,tab);
    }
    void update(int x,int v){
        cv++;
        ver[cv]=up(0,n-1,v,x,ver[cv-1]);
    }
    T query(int v,int x){
        return qu(x,0,n-1,ver[v]);
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
        return tmp;
    }

    T qu(int x,int l,int r,node* p){
        if(l==r)return p->d;
        int m=(l+r)/2;
        if(x<=m)return qu(x,l,m,p->l);
        else return qu(x,m+1,r,p->r);
    }
};
int main(){
    int n;
    cin>>n;
    int tab[n];
    FOR(i,n)cin>>tab[i];
    p_array<int> arr(n,tab);
    while(1){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0){
            cout<<arr.query(b,c)<<endl;
        }
        else{
            arr.update(b,c);
        }
    }
}
