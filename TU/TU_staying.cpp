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
int dp[2005][5][5];
int di=1e9+7;
int main(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    for(int i=0;i<a;i++)dp[1+i][0][0]=1;
    for(int i=1;i<=n;i++){
        FOR(k,4){
            FOR1(j,a){dp[i+j][0][k]+=dp[i][2][k];dp[i+j][0][k]%=di;}
            FOR1(j,b){dp[i+j][1][k|1]+=dp[i][0][k];dp[i+j][1][k|1]%=di;}
            FOR1(j,c){dp[i+j][2][k|2]+=(dp[i][0][k]+dp[i][1][k])%di;
            dp[i+j][2][k|2]%=di;}
         //   printf("<%d> %d %d %d ",k,dp[i][0][k],dp[i][1][k],dp[i][2][k]);
        }
      // printf("\n");
    }

    printf("%d",((dp[n][0][3]+dp[n][1][3])%di+dp[n][2][3])%di);
}
