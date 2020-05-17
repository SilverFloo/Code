#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9;
int dp[300000][40][2];
int x[300000];
int main(){
    int n;
    cin>>n;
    int ans=-1;
    FOR(i,n)scanf("%d",&x[i]);
    FOR(i,n){
        //cout<<i<<'>'<<x[i]<<'>';
        ans=max(ans,x[i]);
        dp[i][x[i]][0]=1;
        dp[i][x[i]][1]=i;
        int a=i,b=x[i];
        if(dp[a][b][0]==1){
            while(a>0&&dp[a-1][b][0]==1){

                //printf("%d %d %d/",a-1,b,dp[a-1][b][1]);
                a=dp[a-1][b][1];
                b++;
                dp[i][b][0]=1;
                dp[i][b][1]=a;
            }
            ans = max(ans,b);
        }
      //cout<<b<<endl;
    }
    printf("%d",ans);
}
