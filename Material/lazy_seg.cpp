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
vector<ii> edge[100005];
void uplz(int l,int r,int p,int v){
    t[p]+=(r-l+1)*v;
    lz[p]+=v;
}
void dolz(int l,int r,int p){
    if(lz[p]==0)return;
    int m=(l+r)/2;
    uplz(l,m,p<<1,lz[p]);
    uplz(m+1,r,p<<1|1,lz[p]);
    lz[p]=0;

}
void update(int st,int ed,int v,int p,int l,int r){
    if(st>r||ed<l)return;
    if(st<=l&&r<=ed){
        uplz(l,r,p,v);
        return;
    }
    int m=(l+r)/2;
    dolz(l,r,p);
    update(st,ed,v,p<<1,l,m);
    update(st,ed,v,p<<1|1,m+1,r);
    t[p]=t[p<<1]+t[p<<1|1];
}
int query(int st,int ed,int p,int l,int r){
    if(st>r||ed<l)return 0;
    if(st<=l&&r<=ed)return t[p];
    int m=(l+r)/2;
    dolz(l,r,p);
    return query(st,ed,p<<1,l,m)+query(st,ed,p<<1|1,m+1,r);
}
int main(){

}
