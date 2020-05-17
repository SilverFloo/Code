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
int tab[505][505],dp[2][505][55];
int main(){
    int n,x;int ans=0;
    cin>>n>>x;
    FOR(i,n)FOR(j,n)scanf("%d",&tab[i][j]);
    int nxt=0,now=1;
    FOR(j,n)FOR(k,x)dp[now][j][k]=-INF;
    dp[now][0][0]=1;
    dp[now][0][1]=tab[0][0]+1;

    FOR(i,n){
    FOR(j,n)FOR(k,x)dp[nxt][j][k]=-INF;
    FOR(j,n){
    FOR(k,x+1){
      //  printf("%d %d %d->%d\n",i,j,k,dp[now][j][k]-1);
    ans=max(ans,dp[now][j][k]);
    dp[nxt][j][k+1]=max(dp[nxt][j][k+1],dp[now][j][k]+tab[i+1][j]);
    dp[nxt][j][0]=max(dp[nxt][j][0],dp[now][j][k]);
    dp[now][j+1][k+1]=max(dp[now][j+1][k+1],dp[now][j][k]+tab[i][j+1]);
    dp[now][j+1][0]=max(dp[now][j+1][0],dp[now][j][k]);
    }
    }

    swap(now,nxt);
    }
    printf("%d",ans-1);
}
