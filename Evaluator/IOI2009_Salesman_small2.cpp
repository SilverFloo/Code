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
#define ii pair<long long,long long>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
const int MAX=500005;
ll up[MAX<<2],down[MAX<<2];
void update(ll *t,int x,ll v,int p=1,int l=0,int r=MAX){
    if(l==r){t[p]=v;return;}
    int m=(l+r)/2;
    if(x<=m)update(t,x,v,p<<1,l,m);
    else update(t,x,v,p<<1|1,m+1,r);
    t[p]=max(t[p<<1],t[p<<1|1]);
    //printf("/%lld/",t[p]);
}
ll query(ll* t,int st,int ed,int p=1,int l=0,int r=MAX){
    if(st<=l&&r<=ed)return t[p];
    if(r<st||l>ed)return -1e18;
    int m=(l+r)/2;
    //printf("/%lld/",max(query(t,st,ed,p<<1,l,m),query(t,st,ed,p<<1|1,m+1,r)));
    return max(query(t,st,ed,p<<1,l,m),query(t,st,ed,p<<1|1,m+1,r));
}
vector<ii> tab[MAX];
int n,u,d,s;
ll cost(int s,int e){
    if(s>e)return (s-e)*u;
    else return (e-s)*d;
}
int main(){
    ll ans=0;
    cin>>n>>u>>d>>s;
    FOR(i,n){
        int a;
        ii b;
        scanf("%d %lld %lld",&a,&b.f,&b.s);
        tab[a].pb(b);
    }
    for(int i=0;i<MAX<<2;i++)up[i]=down[i]=-1e18;
    FOR(i,MAX){
        for(int j=0;j<tab[i].size();j++){
            ll l = tab[i][j].f;
            ll p = tab[i][j].s;
            ll x=p-cost(s,l);
            ll a;

            a=query(up,0,l);
            x=max(x,a+((ll)(MAX-l))*d+p);

            a=query(down,l,MAX-1);
            x=max(x,a+(ll)l*u+p);

            update(up,l,-((MAX-l))*d+x);
            update(down,l,-l*u+x);
            ans = max(ans,x-cost(l,s));
           // printf("%lld %lld %lld\n",dp[i],-((ll)(MAX-tab[i].l))*d+dp[i],-(ll)tab[i].l*u+dp[i]);
        }
    }
    printf("%lld",ans);
}
/*
10 10 5 129
43 277 3757
186 473 344
219 238 1792
244 258 2816
154 58 2477
415 103 1746
448 124 699
98 143 71
407 464 3563
245 272 3102

*/
