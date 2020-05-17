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
ll dp[105][105];
ll mod = 1e9+7;
int main(){
    int n,x;
    cin>>n>>x;
    FOR1(j,n){
        FOR1(i,j){
            for(int k=1;k<j;k++){
                dp[i][j]+=((dp[i-1][j-k-1]+1)*max(k,x))%mod;
                dp[i][j]%=mod;
            }
            for(int k=1;k<x;k++){
                dp[i][j]+=dp[i-k-1][j-1]+1;
                dp[i][j]%=mod;
            }
            printf("%lld ",dp[i][j]);
            dp[j][i]=dp[i][j];
        }
        cout<<endl;
    }
    printf("%d",dp[n][n]);
}
