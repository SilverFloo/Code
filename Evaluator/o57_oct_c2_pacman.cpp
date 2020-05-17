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
ll dp[3][1010][1010];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ll v;
            scanf("%lld",&v);
            dp[0][i][j]=max(max(dp[1][i-1][j],dp[1][i][j-1]),max(dp[2][i-1][j],dp[2][i][j-1]));
            dp[0][i][j]=max(dp[0][i][j],max(dp[0][i-1][j],dp[0][i][j-1]));
            dp[1][i][j]=max(dp[0][i-1][j]+v,dp[0][i][j-1]+v);
            dp[2][i][j]=max(dp[1][i-1][j]+v,dp[1][i][j-1]+v);
        }
    }
    printf("%lld",max(max(dp[0][n][m],dp[1][n][m]),dp[2][n][m]));
}
