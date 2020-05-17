#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int dp[2][m+1];
    FOR1(i,m)dp[1][i]=0;
    dp[0][0]=1;
    dp[1][0]=1;
    int now=0;int prev=1;int v;
    FOR1(i,n){
        scanf("%d",&v);
        FOR1(j,m){
            dp[now][j]=dp[prev][j];
            if(j-v>=0)dp[now][j]+=dp[prev][j-v];
            dp[now][j]%=1000007;
        }
        swap(now,prev);
    }
    printf("%d",dp[prev][m]);
}
