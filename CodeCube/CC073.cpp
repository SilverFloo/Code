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
int dp1[205][205];
int dp2[205][205];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=n;i>0;i--){
    FOR1(j,m)scanf("%d",&dp1[i][j]),
    dp2[i][j]=dp1[i][j];
    }
    FOR1(i,n){
    FOR1(j,m){
    dp1[i][j]+=max(dp1[i-1][j],dp1[i][j-1]);
    if(i==1&&j!=1)dp2[i][j]+=dp2[i][j-1];
    else if(j==1&&i!=1)dp2[i][j]+=dp2[i-1][j];
    else dp2[i][j]+=min(dp2[i-1][j],dp2[i][j-1]);
   //    printf("%d ",dp2[i][j]);
    }
    }
    printf("%d",dp1[n][m]-dp2[n][m]);
}
