#include<bits/stdc++.h>
#define FOR(i,a) for(ll i=0;i<a;i++)
#define FOR1(i,a) for(ll i=1;i<=a;i++)
#define db(a) prllf("<%d> ",a)
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
const ll INF=1e9;
ll tab[200005];
pair<ll,ll> d[200005];
ll dp[200005][2];
ll val[200005];
ll pos[200005];
int main(){
    ll n;
    cin>>n;
    ll sum=0;
    FOR1(i,n){
        scanf("%lld",&tab[i]);
        d[i].f=tab[i];
        d[i].s=i;
        sum+=tab[i];
    }
    ll ans=1e18;
    FOR1(i,n){
        ll x = min(tab[i-1],tab[i+1])-1;
        if(x<=0)continue;
        ans=min(ans,tab[i]-x);
    }
    sort(d+1,d+n+1,greater<pair<ll,ll>>());
    for(ll x=1;x<=n;x++){
        ll i=d[x].s;
    if(tab[i]==0)continue;
        ll st,ed;
        if(pos[i-1]==0&&pos[i+1]==0){
            dp[i][0]=tab[i];
            pos[i]=i;
            st=i;ed=i;
        }
        else if(pos[i-1]==0){
            st=i;
            ed=pos[i+1];
            dp[st][0]=dp[ed][0]+tab[i];
            dp[ed][0]=dp[ed][0]+tab[i];
            if(dp[ed][1]!=0)dp[st][1]=dp[ed][1]+tab[i];
            if(dp[ed][1]!=0)dp[ed][1]+=tab[i];
            pos[st]=ed;
            pos[ed]=st;
        }
        else if(pos[i+1]==0){
            st=pos[i-1];
            ed=i;
            dp[ed][0]=dp[st][0]+tab[i];
            dp[st][0]=dp[st][0]+tab[i];
            if(dp[st][1]!=0)dp[ed][1]=dp[st][1]+tab[i];
            if(dp[st][1]!=0)dp[st][1]+=tab[i];
            pos[st]=ed;
            pos[ed]=st;
        }
        else{
           st = pos[i-1];
           ed = pos[i+1];
           ll l0 = dp[i-1][0];
           ll l1 = dp[i-1][1];
           if(l1!=0)l1+=tab[i]*(ed-i+1);
           ll r0 = dp[i+1][0];
           ll r1 = dp[i+1][1];
           if(r1!=0)r1+=tab[i]*(i-st+1);
           ll dp0=0,dp1=0;
           if(l0+tab[i]*(ed-i+1)>r0+tab[i]*(i-st+1)){
                dp0=l0+tab[i]*(ed-i+1);
           }
           else{
                dp0=r0+tab[i]*(i-st+1);
           }
           dp1=max(l1,r1);
           dp1=max(dp1,l0+r0+tab[i]);
           pos[st]=ed;
           pos[ed]=st;
           dp[st][0]=dp[ed][0]=dp0;
           if(l0!=tab[i]*(i-st)&&r0!=tab[i]*(ed-i))dp[st][1]=dp[ed][1]=dp1;
        }

      //prllf("%lld %lld %lld %lld\n",st,ed,dp[st][0],dp[st][1]);
    }
    ll xx=0;
    FOR1(i,n)xx=max(xx,dp[i][1]);
    if(xx==0){
        if(ans!=1e18){
            printf("%lld",sum-ans);
        }
        else printf("-1");
    }
    else  printf("%lld",xx);
}
