#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9;
const int MAX=20005;
vector<int> t[MAX<<2];
int x[MAX];
int n,q;
void built(int p=1,int l=1,int r=n){
    if(l==r){t[p].pb(x[l]);return;}
    int mid=(l+r)/2;
    built(p<<1,l,mid);
    built(p<<1|1,mid+1,r);
        auto a=t[p<<1].begin();
        auto b=t[p<<1|1].begin();
        while(a!=t[p<<1].end()&&b!=t[p<<1|1].end()){
            if(*a>*b)t[p].pb(*b++);
            else t[p].pb(*a++);
        }
        while(a!=t[p<<1].end())t[p].pb(*a++);
        while(b!=t[p<<1|1].end())t[p].pb(*b++);
           //  printf("%d %d : ",l,r);
        //for(auto i:t[p])printf("%d ",i);
       // printf("\n");
}
int query(int st,int ed,int a,int b,int p=1,int l=1,int r=n){
    if(ed<l||r<st){return 0;}
    else if(l>=st&&r<=ed){return upper_bound(all(t[p]),b)-lower_bound(all(t[p]),a);}
    int mid=(l+r)/2;
    return query(st,ed,a,b,p<<1,l,mid)+query(st,ed,a,b,p<<1|1,mid+1,r);
}
int main(){
    cin>>n>>q;
    FOR1(i,n){
    scanf("%d",&x[i]);
    }
    built();
    while(q--){
    int a,b,st,ed;
    scanf("%d %d %d %d",&st,&ed,&a,&b);
    printf("%d ",query(st,ed,a,b));
    }
}
