#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
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
bool st[1<<21];
bool fin[1<<21];
int k,m;
void check(int p){
    if(fin[p<<1]&&fin[p<<1|1])if(st[p])fin[p]=1;
    if(p>=(1<<k)&&st[p])fin[p]=1;
}
void up(int p){
    if(st[p<<1]&&st[p<<1|1])st[p]=1;
    if(st[p]&&st[p<<1]&&st[p<<1|1]==0){st[p<<1|1]=1;up(p<<1|1);}
    if(st[p]&&st[p<<1|1]&&st[p<<1]==0){st[p<<1]=1;up(p<<1);}
    check(p);
}
void update(int lv,int x,int p=1,int l=1,int r=1<<k){
    if(p>=(1<<k))fin[p]=1;
    if(lv==0){
        st[p]=1;
        up(p);
        return;
    }
    int m=(l+r)/2;
    if(x<=m)update(lv-1,x,p<<1,l,m);
    else update(lv-1,x,p<<1|1,m+1,r);
    up(p);
}
int main(){
    cin>>k>>m;
    FOR(i,m){
        int a,b;
        scanf("%d %d",&a,&b);
        update(k-a,b+1);
        if(fin[1]){
            printf("%d",i+1);
            return 0;
        }
    }
}
/*
    idea : use tree
    if you can find root and you can find every node in left & right sub tree then you can find all tree
    if you can find 2 from 3 of t[p] t[p<<1] t[p<<1|1] then you can find the last one

    55 min 10%
        change || to && in check
    60 min 15%
        add up(p) at line 31
    60 min 100%
*/
