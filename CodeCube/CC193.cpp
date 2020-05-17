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
ll dp[200005];pair<ll,ll> tab[200005];
int main(){
    int n,k;
    cin>>n>>k;
    FOR1(i,n){scanf("%lld %lld",&tab[i].f,&tab[i].s);}
    sort(tab+1,tab+n+1);
    deque<int> q;
    q.pb(1);
    for(int i=2;i<=n;i++){
        while(!q.empty()&&tab[q.front()].f<tab[i].f-k)q.pop_front();
        if(!q.empty())dp[i]=dp[q.front()-1]+tab[q.front()].s+tab[q.front()].f-tab[i].f+tab[i].s;
        dp[i]=max(dp[i],dp[i-1]);
        while(!q.empty()&&dp[q.back()-1]+tab[q.back()].s+tab[q.back()].f<dp[i-1]+tab[i].s+tab[i].f)q.pop_back();
        q.pb(i);
      //  printf("%d ",dp[i]);
    }
//
printf("%lld",dp[n]);
}
