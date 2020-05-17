#include<bits/stdc++.h>
using namespace std;
unsigned long long dp[25][10005];
int main(){
for(int i=0;i<=22;i++){
int val=i*i*i;
for(int j=0;j<=10000;j++){
if(j==0)dp[i][j]=1;
else if(i==0)dp[i][j]==0;
else if(j-val<0)dp[i][j]=dp[i-1][j];
else dp[i][j]=dp[i][j-val]+dp[i-1][j];
}
}
int n;
while(scanf("%d",&n)!=-1){
printf("%llu\n",dp[22][n]);
}

}
