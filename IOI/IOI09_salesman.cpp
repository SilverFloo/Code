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
    if(l==r){t[p]=max(t[p],v);return;}
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
        sort(all(tab[i]));
        ll bf=-INF;
        queue<ii> upup,updown;
        for(int j=0;j<tab[i].size();j++){
            ll l = tab[i][j].f;
            ll p = tab[i][j].s;
            ll x = p-cost(s,l),a;

            a=query(up,0,l);
            x=max(x,a+((ll)(MAX-l))*d+p);

            a=query(down,l,MAX-1);
            x=max(x,a+(ll)l*u+p);

            if(j>0)x=max(x,bf+p-cost(tab[i][j-1].f,l));

            upup.p(l,-((MAX-l))*d+x);
            updown.p(l,-l*u+x);
            ans = max(ans,x-cost(l,s));
            bf=x;
        }

        bf=-INF;
        for(int j=tab[i].size()-1;j>=0;j--){
            ll l = tab[i][j].f;
            ll p = tab[i][j].s;
            ll x = p-cost(s,l),a;

            a=query(up,0,l);
            x=max(x,a+((ll)(MAX-l))*d+p);

            a=query(down,l,MAX-1);
            x=max(x,a+(ll)l*u+p);

            if(j<tab[i].size()-1)x=max(x,bf+p-cost(tab[i][j+1].f,l));

            upup.p(l,-((MAX-l))*d+x);
            updown.p(l,-l*u+x);
            ans = max(ans,x-cost(l,s));
            bf=x;
        }
        while(!upup.empty()){
            update(up,upup.front().f,upup.front().s);
            upup.pop();
        }
        while(!updown.empty()){
            update(down,updown.front().f,updown.front().s);
            updown.pop();
        }
    }
    printf("%lld",ans);
}
