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
int dp[1005][1005];
int main(){
    int q;
    cin>>q;
    dp[1][1]=1;
    FOR1(i,1000){
        FOR1(j,1000){
            if(i==1&&j==1)continue;
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*j;
            dp[i][j]%=9871;
        }
    }
    while(q--){
        int n,k;
        cin>>n>>k;
        printf("%d\n",dp[n][k]);
    }
}
