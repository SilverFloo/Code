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
int main(){
    int n,m;
    cin>>n>>m;
    int dp[2][m];
    int now=0,prev=1;
    int ans=0;
    FOR(i,n){FOR(j,m){int a;scanf("%1d",&dp[now][j]);if(dp[now][j]==1)dp[now][j]=0;else dp[now][j]=1;

       if(i==0||j==0){}
    else if(dp[now][j]==1)dp[now][j]=min(dp[prev][j],min(dp[now][j-1],dp[prev][j-1]))+1;
    ans=max(ans,dp[now][j]);
    }swap(now,prev);
    }
    printf("%d",ans);

}
