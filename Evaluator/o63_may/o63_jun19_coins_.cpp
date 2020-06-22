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
#define rf() freopen("_working/input.in","r",stdin)
#define pf() freopen("_working/output.out","w+",stdout)
using namespace std;
const ll INF=1e18;
vector<int> tab[1000005];
int dist[1000005];
pair<ll,ll> t[1000005<<2];
ll sum1[1000005],sum2[1000005];
int n;
void update(int x,pair<ll,ll> v,int p = 1,int l = 0,int r = n){
    if(l==r){
        t[p]=v;
        return;
    }
    int m=(l+r)/2;
    if(x<=m)update(x,v,p<<1,l,m);
    else update(x,v,p<<1|1,m+1,r);
    t[p]=min(t[p<<1|1],t[p<<1]);
}
pair<ll,ll> query(int st,int ed,int p = 1,int l = 0,int r = n){
    if(r<st||l>ed){
        return {INF,INF};
    }
    if(st<=l&&r<=ed){
        return t[p];
    }
    int m = (l+r)/2;
    pair<ll,ll> a = query(st,ed,p<<1,l,m);
    pair<ll,ll> b = query(st,ed,p<<1|1,m+1,r);
    return {min(a.f,b.f),min(a.s,b.s)};
}
int main(){
    rf();
    cin>>n;
    FOR(i,n){
        int x;
        scanf("%d",&x);
        tab[x].pb(i);
    }
    FOR(i,n)scanf("%d",&dist[i]);
    FOR(i,n){update(i,{INF,INF});}
    FOR(i,n){sum1[i]=(ll)dist[i]+sum1[i-1];}
    for(int i=n-1;i>=0;i--){sum2[i]=(ll)dist[i]+sum2[i+1];}
    ll ans;
    int cnt=0;
    for(auto x:tab[1]){
        ll d=0;
        if(cnt>0)d = max(d,sum1[tab[1][cnt]-1]-sum1[tab[1][cnt-1]-1]);
        if(cnt<tab[1].size()-1)d = max(d,sum1[tab[1][cnt+1]-1]-sum1[tab[1][cnt]-1]);
        cnt++;
        if(tab[1].size()>1){
            
            update(x,{sum1[x]+d,sum2[x]+d});
            continue;
        }
        update(x,{sum1[x],sum2[x]});
    }
    for(int i=2;i<=n;i++){
        if(!tab[i].empty())ans=INF;
        int cnt=0;
        for(auto x:tab[i]){
            int y = n/2;
            pair<ll,ll> r = query(x,n-1);
            pair<ll,ll> l = query(0,x);
            ll a = min(r.f,l.f+sum1[n-1])-sum1[x];
            ll b = min(l.s,r.s+sum1[n-1])-sum2[x];
            ll c = min(a,b);
            if(tab[i].size()==1){
                update(x,{c+sum1[x],c+sum2[x]});
                continue;
            }
            ll d = sum1[tab[i][cnt]-1]-sum1[tab[i][cnt]-1];
            update(tab[i][(cnt-1+n)%n],{c+d+sum1[tab[i][(cnt-1+n)%n]],c+d+sum2[tab[i][(cnt-1+n)%n]]});
            ll d = 
            cnt++;
            if(tab[i].size()>1)c+=sum1[n-1]-d;
            ans = min(ans,c);
            update(x,{c+sum1[x],c+sum2[x]});
        }
        for(auto x:tab[i-1]){
            update(x,{INF,INF});
        }
    }
    cout<<ans;
}