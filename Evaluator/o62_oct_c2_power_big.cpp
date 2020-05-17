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
int d=1;
ll tu[200005<<2],td[200005<<2];
void update(ll *t,int x,ll v,int p=1,int l=0,int r=200005){
    if(l==r){
        if(d==1)t[p]=v;
        else t[p]=max(t[p],v);
        return;
    }
    int m=(l+r)/2;
    if(x<=m)update(t,x,v,p<<1,l,m);
    else update(t,x,v,p<<1|1,m+1,r);
    t[p]=max(t[p<<1],t[p<<1|1]);
    //if(d==0)printf("%lld",t[p]);
}
ll query(ll *t,int st,int ed,int p=1,int l=0,int r=200005){
    if(st<=l&&r<=ed)return t[p];
    if(r<st||l>ed)return -1e18;
    int m=(l+r)/2;
    ll x=max(query(t,st,ed,p<<1,l,m),query(t,st,ed,p<<1|1,m+1,r));
   // printf("%d %d %d %d %lld\n",l,r,st,ed,x);
    return x;
}

int main(){
    int n,m;
    cin>>n>>m;
    ll ans=0;

    for(int i=0;i<=200005;i++){
            update(tu,i,-(ll)200005+(ll)i);
            update(td,i,-(ll)i);
        }
    FOR(i,m){
        int st,ed;
        ll w;
        scanf("%d %d %lld",&st,&ed,&w);
       d=0;
        ll x = max(query(tu,0,st)+(ll)200005-(ll)st,query(td,st,(ll)200005)+(ll)st)+w;
        ll y = max(query(tu,0,ed)+(ll)200005-(ll)ed,query(td,ed,(ll)200005)+(ll)ed)+w;
       // printf("%lld %lld//\n",x,y);
        ans=max(max(ans,x),y);
        printf("%lld\n",ans);
        update(tu,st,y-(ll)200005+(ll)st);
        update(td,st,y-(ll)st);
        update(tu,ed,x-(ll)200005+(ll)ed);
        update(td,ed,x-(ll)ed);
       // printf("%lld",x-200005+st);
    }
}
