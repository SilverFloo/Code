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
int a[100005];
int b[100005];
int dp[100005][205];
int main(){
    int q;
    cin>>q;
    while(q--){
        int n,k;
        cin>>n>>k;
        FOR1(i,n)scanf("%d %d",&a[i],&b[i]);

        FOR(i,n+1){
            FOR(j,2*k+1)dp[i][j]=INF;
        }
        dp[0][k]=0;
        FOR1(i,n){
            FOR(j,2*k+1){
                if(j>0)dp[i][j]=dp[i-1][j-1]+a[i];
                if(j<2*k)dp[i][j]=min(dp[i][j],dp[i-1][j+1]+b[i]);
               // printf("%d ",dp[i][j]);
            }//cout<<endl;
        }
        int ans=INF;
        FOR(i,2*k+1){
            ans=min(ans,dp[n][i]>0?dp[n][i]:INF);
        }
        printf("%d\n",ans);
    }
}
