#include<bits/stdc++.h>
#define FOR(i,a) for(ll i=0;i<a;i++)
#define FOR1(i,a) for(ll i=1;i<=a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<ll,ll>
#define ll long long
using namespace std;
const ll INF=(1e9)+7;
ll t[300005<<3],lz[300005<<3];
void uplz(ll l,ll r,ll p,ll v){
    t[p]+=v;
    lz[p]+=v;
}
void dolz(ll l,ll r,ll p){
    if(lz[p]==0)return;
    ll m=(l+r)/2;
    uplz(l,m,p<<1,lz[p]);
    uplz(m+1,r,p<<1|1,lz[p]);
    lz[p]=0;

}
void update(ll st,ll ed,ll v,ll p=1,ll l=0,ll r=300005){
    if(st>r||ed<l)return;
    if(st<=l&&r<=ed){
        uplz(l,r,p,v);
        return;
    }
    ll m=(l+r)/2;
    dolz(l,r,p);
    update(st,ed,v,p<<1,l,m);
    update(st,ed,v,p<<1|1,m+1,r);
    t[p]=min(t[p<<1],t[p<<1|1]);
}
ll query(ll st,ll ed,ll p=1,ll l=0,ll r=300005){
    if(st>r||ed<l)return INF;
    if(st<=l&&r<=ed)return t[p];
    ll m=(l+r)/2;
    dolz(l,r,p);
    return min(query(st,ed,p<<1,l,m),query(st,ed,p<<1|1,m+1,r));
}
ll n,x;

pair<ll,ii> tab[300005];
int main(){
    cin>>n>>x;
    FOR1(i,n){
        scanf("%lld %lld %lld",&tab[i].f,&tab[i].s.f,&tab[i].s.s);
    }
    tab[n+1].f=x;
    sort(tab,tab+n+2);
    for(ll i=1;i<n+2;i++){
        update(i,i,(ll)(tab[i-1].f-tab[i].f+tab[i-1].s.f)+query(i-1,i-1));
    }
    priority_queue<ii,vector<ii>,greater<ii>> q;
    for(ll i=1;i<=n;i++){
        q.emplace(tab[i].s.s,i);
    }
    ll ans=0;
    while(query(0,n+1)<0){
   // print();
        ll x=query(0,n+1);
        update(0,n+1,-x);
        ans+=-x;
   // print();
        while(!q.empty()&&q.top().f<ans){
            ll x = q.top().s;
           // printf("<%d/%d>",x,tab[x].s.f);
            update(x+1,n+1,-(ll)tab[x].s.f);
            //print();
            q.pop();
        }
    }
    cout<<ans;
}




