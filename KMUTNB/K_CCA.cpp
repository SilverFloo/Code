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
int dp[2][(int)2e6+5];
int coin[21];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int now=0,prev=1;
    dp[now][0]=1;
    FOR(i,n){cin>>coin[i];}
    FOR(i,n){
    FOR(j,m+k+1){
        int l=INF;
        int r=INF;
        if(dp[prev][j]>0)l=dp[prev][j];
        if(j-coin[i]>=0)if(dp[now][j-coin[i]]>0)r=dp[now][j-coin[i]]+1;
        dp[now][j]=min(l,r);
        if(dp[now][j]==INF)dp[now][j]=0;
        //printf("%d ",dp[now][j]);
        if(i==0&&j==0)dp[now][j]=1;
    }
    //printf("\n");
    swap(now,prev);
    }
    int mn=INF,ans;
    for(int i=m;i<=m+k;i++){
        if(dp[prev][i]<mn&&dp[prev][i]!=0)mn=dp[prev][i],ans=i-m;
        }
    if(mn==INF){printf("-1");}
    else printf("%d\n%d",mn-1,ans);
}
