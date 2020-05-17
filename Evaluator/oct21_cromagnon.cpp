#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace

#define ll long long
using namespace std;
const int INF=1e9;
int op[25][25];
int dp[105][105][25];
int val[105];
int main(){
    int x,n;
    cin>>x;
    FOR(i,x)FOR(j,x)scanf("%d",&op[i][j]);
    cin>>n;
    FOR(i,n)scanf("%d",&val[i]),dp[i][i][val[i]]=1;
    for(int l=1;l<=n;l++){
        for(int i=0;i<n-l;i++){
            int j=i+l;
            for(int k=i+1;k<=j;k++){
                for(int ii=0;ii<x;ii++)
                    for(int jj=0;jj<x;jj++){
                        dp[i][j][op[ii][jj]]+=dp[i][k-1][ii]*dp[k][j][jj];
                        dp[i][j][op[ii][jj]]%=2009;
                   //f(dp[i][k-1][ii]>0&&dp[k][j][jj]>0)printf("%d %d %d %d\n",i,k,j,op[ii][jj]);
                   //printf("%d %d %d\n",i,j,k);
                }
            }
        }
    }
   FOR(i,x)printf("%d\n",dp[0][n-1][i]);
}
