#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define ii pair<int,int>
using namespace std;
int n,t;
ii pl(ii i,int j){
if(i.s+j<=t)return ii(i.f,i.s+j);
else return ii(i.f+1,j);

}
int w1[1005],w2[1005];
ii dp[1005][1005];
int main(){

cin>>t>>n;
FOR1(i,n)scanf("%d",&w1[i]);
FOR1(i,n)scanf("%d",&w2[i]);
FOR(i,n+1){
FOR(j,n+1){

if(i==0&&j==0)continue;
if(i==0)dp[i][j]=pl(dp[i][j-1],w2[j]);
else if(j==0)dp[i][j]=pl(dp[i-1][j],w1[i]);
else{
ii a=pl(dp[i-1][j],w1[i]);
ii b=pl(dp[i][j-1],w2[j]);

dp[i][j]=min(a,b);
//printf("%d %d ->%d %d %d %d %d %d\n",i,j,a.f,a.s,b.f,b.s,dp[i][j].f,dp[i][j].s);

}
}

}
printf("%d\n%d",dp[n][n].f+1,dp[n][n].s);
}
