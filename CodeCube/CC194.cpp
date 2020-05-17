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
#define ii pair<ll,ll>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
ii t[100005<<2];
int tab[100005];
void update(int x,ii v,int p=1,int l=0,int r=100005){
    if(l==r){
        t[p]=v;
        return ;
    }
    int m=(l+r)/2;
    if(x<=m)update(x,v,p<<1,l,m);
    else update(x,v,p<<1|1,m+1,r);
    t[p]=max(t[p<<1],t[p<<1|1]);
}
ii query(int st,int ed,int p=1,int l=0,int r=100005){
    if(r<st||l>ed)return {0,0};
    if(st<=l&&r<=ed)return t[p];
    int m=(l+r)/2;
    return max(query(st,ed,p<<1,l,m),query(st,ed,(p<<1)|1,m+1,r));
}
ii pl(ii a,ii b){
    return {a.f+b.f,a.s+b.s};
}
int main(){
    map<int,int> m;
    int n;
    cin>>n;
    FOR(i,n){
        scanf("%d",&tab[i]);
        m[tab[i]]=1;
    }
    int cnt=0;
    for(auto &i:m)i.s=cnt++;
    FOR(i,n){

        ii x=pl(query(0,m[tab[i]]),mp(1,(ll)tab[i]));
        update(m[tab[i]],x);
    }
    ii ans = query(0,100005);
    printf("%lld %lld",ans.f,ans.s);
}
