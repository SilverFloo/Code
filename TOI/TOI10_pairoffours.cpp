#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
using namespace std;
const int INF=1e9;
int n;
char s[1005];
int dp[1005][1005];
int main(){
cin>>n;
FOR(i,n)scanf(" %c",&s[i]);
for(int l=1;l<n;l++){
for(int i=0,j=l;j<n;i++,j++){
if(s[i]==s[j])dp[i][j]=dp[i+1][j-1]+1;
else for(int k=0;k<l;k++){
dp[i][j]=max(dp[i][j],dp[i][i+k]+dp[i+k+1][j]);
}

}}
printf("%d",dp[0][n-1]);

}
