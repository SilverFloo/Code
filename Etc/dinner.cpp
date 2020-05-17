#include<bits/stdc++.h>
using namespace std;
int dp[10005];
int main(){int a,b,t;
while(scanf("%d%d%d",&a,&b,&t)!=-1){


for(int i=0;i<=t;i++){
int l=0,r=0;
if(i-a>=0)if(dp[i-a]!=0)l=dp[i-a]+1;
else if(i==a){l=1;}
if(i-b>=0)if(dp[i-b]!=0)r=dp[i-b]+1;
else if(i==b)r=1;

dp[i]=max(l,r);
//printf("%d:%d\n",i,dp[i]);
}
for(int i=t;i>=0;i--){if(dp[i]>0){printf("%d",dp[i]);if(t-i!=0)printf(" %d",t-i);break;}
}
if(a>t&&b>t)printf("0 %d",t);
printf("\n");
}
}
