#include<bits/stdc++.h>
using namespace std;
int main(){

int n;int ch=0;
scanf("%d",&n);
int tab[n+1];int sum=0;
for(int i=1;i<=n;i++){scanf("%d",&tab[i]);sum+=tab[i];}
ch=sum%2;
sum/=2;
bool dp[n+1][sum+1];
for(int i=0;i<n;i++){
for(int j=0;j<=sum;j++){
dp[i][j]=0;
}
}

for(int i=0;i<=n;i++){
for(int j=0;j<=sum;j++){
if(j==0)dp[i][j]=1;
else if(i==0) dp[i][j]=0;
else if(j-tab[i]<0)dp[i][j]=dp[i-1][j];
else dp[i][j]=dp[i-1][j]||dp[i-1][j-tab[i]];
//printf(">%d<",dp[0][5]);
//printf("%d ",dp[i][j]);
}//printf("\n");
}
for(int i=sum;i>=0;i--){if(dp[n][i]){printf("%d\n",2*(sum-i)+ch);break;}}



}
