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
ll flcm(ll a,ll b){
   // printf("<%lld %lld %lld>",a,b,a*b/__gcd(a,b));
    return a*b/__gcd(a,b);
    //printf("")
}
vector<ll> d;
int main(){
    ll a,b;
    cin>>a>>b;
    ll dist=abs(a-b);
    ll lcm=1e18+5;
    ll ans=0;
    for(ll i=1;i<=sqrt(dist);i++){
        if(dist%i!=0)continue;
        d.pb(i);
        d.pb(dist/i);
    }
    for(auto i:d){
        ll x=a%i;
        if(x!=0)x=i-x;
        ll tmp = flcm(a+x,b+x);
        if(tmp==lcm)if(x<ans)ans=x;
        if(tmp<lcm){lcm=tmp;ans=x;}
    }//printf("%lld %lld %lld/",(dist/i),x,tmp);
    printf("%lld ",ans);
/*
    lcm=1e18+5;
    for(ll i=0;i<1e6;i++){
        ll tmp=flcm(a+i,b+i);
        if(tmp==lcm)if(i<ans)ans=i;
        if(tmp<lcm){lcm=tmp;ans=i;}
    }
    printf("%lld",ans);*/
}
