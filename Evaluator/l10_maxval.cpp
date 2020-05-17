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
const int INF=2e9;
int dp[1000005];
int main(){
    int n,k;
    cin>>n>>k;
    FOR1(i,n)scanf("%d",&dp[i]),dp[i]+=dp[i-1];
    int ans=-INF;
    for(int i=k;i<=n;i++){
        ans=max(ans,dp[i]-dp[i-k]);
    }
    printf("%d",ans);
}
