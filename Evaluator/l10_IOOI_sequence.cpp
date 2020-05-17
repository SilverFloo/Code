#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
int dp[2][5005];
int sum[2][5005];
int mod = 2553;
int main(){
    int n,k;
    cin>>n>>k;
    dp[0][0]=1;
    sum[0][0]=1;
    FOR1(i,n)sum[0][i]=1;
    int ans=0;
    int now=1,bf=0;
    FOR1(i,n){
        sum[now][0]=0;
        FOR1(j,n){
            dp[now][j]=sum[bf][j-1];
            if(j-1-k>=0)dp[now][j]-=sum[bf][j-1-k];
            dp[now][j]+=mod;
            dp[now][j]%=mod;
            sum[now][j]=sum[now][j-1]+dp[now][j];
            sum[now][j]%=mod;
            //printf("%d ",dp[now][j]);
        }
       //cout<<endl;
        ans+=((dp[now][n]*dp[now][n])%mod)*dp[now][n];
        ans%=mod;
        swap(now,bf);
    }
    printf("%d",ans);
}
