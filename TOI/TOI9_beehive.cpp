#include <bits/stdc++.h>

using namespace std;
int dp[1035][1035];

main(){
    int n,m;
    scanf("%d %d",&m,&n);
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        dp[0][i] = a[0][i];
    }
    for(int i=1;i<m;i++){
        if(!(i%2)){
            dp[i][0] = dp[i-1][0]+a[i][0];
            for(int j=0;j<n;j++){
                dp[i][j] = max(dp[i][j],dp[i-1][j]+a[i][j]);
            }
        }else{
            dp[i][n-1] = dp[i-1][n-1]+a[i][n-1];
            for(int j=0;j<n;j++){
                dp[i][j] = max(dp[i][j],dp[i-1][j]+a[i][j]);
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    int ma = -1;
    for(int i=0;i<n;i++){
        ma = max(ma,dp[m-1][i]);
    }
    printf("%d",ma);
}
