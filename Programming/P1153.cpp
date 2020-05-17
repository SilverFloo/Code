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
int dp[1005];
vector<ii> e[1005];
int main(){
int ans=0;
    int n;
    cin>>n;
    FOR(i,n){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    e[b].pb(a,c);
    }
    FOR(i,1005){
    int mx=0;
    for(auto j:e[i]){
    if(dp[j.f]+j.s>mx)mx=dp[j.f]+j.s;
    }
    dp[i]=mx;
    if(mx>ans)ans=mx;

    }
    printf("%d",ans);
}
