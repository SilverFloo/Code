#include<bits/stdc++.h>
using namespace std;
int elec[500002];
int dp[500002];
int main()
{
    int n,k,ans,s;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&elec[i]);
        dp[1]=elec[1];
    for(int i=1;i<n;)
    {
        ans=2e9;
        for(int j=i+1;j<=min(i+k,n);j++){
            if(dp[j]==0)
            dp[j]=elec[j]+dp[i];
        else dp[j]=min(dp[j],elec[j]+dp[i]);
        if(ans>dp[j])
        {
            ans=dp[j];
            s=j;
        }
        }
        i=s;
    }
    printf("%d",dp[n]);
}
