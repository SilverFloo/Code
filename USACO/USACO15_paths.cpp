#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_bajck
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("_working/input.in","r",stdin)
#define pf() freopen("_working/output.out","w+",stdout)
using namespace std;
const int INF=1e9;
char tab[505][505];
int dp[2][505][505];
int main(){
    //rf();
    freopen("palpath.in","r",stdin);
    freopen("palpath.out","w+",stdout);
    int n;
    cin>>n;
    FOR(i,n){
        FOR(j,n)cin>>tab[i][j];
    }
    FOR(i,n)dp[0][i][i]=1;
    int now = 1,bf=0;
    for(int k=1;k<n;k++){
        for(int i=0;i<n-k;i++){
            for(int j=k;j<n;j++){
                dp[now][i][j]=0;
            //printf("/%d %d %c/%d %d %c/",i,n-k-i-1,,j,n+k-j-1);
                if(tab[i][n-k-i-1]==tab[j][n+k-j-1]){
                     if(j>0)dp[now][i][j] += dp[bf][i][j-1];
                     dp[now][i][j]%= 1000000007;
                     dp[now][i][j] += dp[bf][i][j];
                     dp[now][i][j]%= 1000000007;
                     if(i<n-1)dp[now][i][j] += dp[bf][i+1][j];
                     dp[now][i][j]%= 1000000007;
                     if(j>0&&i<n-1)dp[now][i][j] += dp[bf][i+1][j-1];
                     dp[now][i][j]%= 1000000007;
                     
                }
               // printf("%d %d %d -> %d\n",k,i,j,dp[now][i][j]);
            }
        }
        swap(now,bf);
    }
    printf("%d",dp[bf][0][n-1]);
}