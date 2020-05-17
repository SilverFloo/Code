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
int dp[1005][1005][2];
int main(){
    int n;
    cin>>n;
    dp[0][1][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i==0&&j==0)continue;
            if(i==0&&j==1)continue;
            if(i==0){
                dp[i][j][0]=max(dp[i][j][0],dp[i][j-1][1]+1);
                dp[i][j][1]=dp[i][j-1][0];
                dp[i][j][0]=max(dp[i][j][0],dp[i][j][1]);
                continue;
            }
            if(i==j)dp[i][j][0]=dp[i-1][j][1]+1;
            else dp[i][j][0]=max(dp[i-1][j][0]+dp[i][j-1][1]+1,dp[i-1][j][1]+dp[i][j-1][0]+1);
            if(i==j)dp[i][j][1]=dp[i-1][j][0];
            dp[i][j][1]=dp[i][j-1][0]+dp[i-1][j][0];
            dp[i][j][0]=max(dp[i][j][0],dp[i][j][1]);
            dp[i][j][0]%=(int)1e9+7;
            dp[i][j][1]%=(int)1e9+7;
        }
    }
    printf("%d",dp[n][n][0]);
}
