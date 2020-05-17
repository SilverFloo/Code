#include<bits/stdc++.h>
using namespace std;
double dp[2000000];
main(){
    int n;
    scanf("%d",&n);
    double in[n][n];
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        scanf("%lf",&in[i][j]);}
    }
    for(int i=0;i<(1<<n);i++){
        int c=0;int a=i;
        while(a!=0){c+=a%2;a>>=1;}
        for(int j=0;j<n;j++){
            if(c==1&&(i>>j)==1){
                dp[i]=double(in[0][n-j-1]);
            }else if((i&(~(1<<j)))!=i&&c!=1){
                dp[i]=max(dp[i],dp[i&~(1<<j)]*in[c-1][n-j-1]/100);
            }
        }
    }
    cout.precision(6);
cout<<fixed<<dp[(1 << n)-1];

}
