#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
using namespace std;
const int INF=1e9;
bool dp[3][1005][1005];
int main(){
    int x=20;
while(x--){
int n;
cin>>n;
int s[n];
FOR(i,n){scanf("%1d",&s[i]);}
FOR(l,n){
for(int i=l;i<n;i++){
if(l==0)dp[s[i]][i][i]=1;
else{
int j=i-l;
for(int k=0;k<l;k++){
//printf("%d %d %d %d\n",j,i-k-1,i-k,i);
if(dp[0][j][i-k-1]&&dp[0][i-k][i])dp[2][j][i]=1;

if(dp[0][j][i-k-1]&&dp[1][i-k][i])dp[1][j][i]=1;

if(dp[0][j][i-k-1]&&dp[2][i-k][i])dp[0][j][i]=1;

if(dp[1][j][i-k-1]&&dp[0][i-k][i])dp[2][j][i]=1;

if(dp[1][j][i-k-1]&&dp[1][i-k][i])dp[1][j][i]=1;

if(dp[1][j][i-k-1]&&dp[2][i-k][i])dp[1][j][i]=1;

if(dp[2][j][i-k-1]&&dp[0][i-k][i])dp[1][j][i]=1;

if(dp[2][j][i-k-1]&&dp[1][i-k][i])dp[2][j][i]=1;

if(dp[2][j][i-k-1]&&dp[2][i-k][i])dp[1][j][i]=1;

}
}
}
}
printf("%s\n",dp[0][0][n-1]?"yes":"no");
FOR(i,3)FOR(j,1005)FOR(k,1005)dp[i][j][k]=0;
}
}

//5 01200
//0110
//
// 1200 110 10 2
