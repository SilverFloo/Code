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
const int INF=2e9;
int dp[2][100005];
int tab[100005];
int main(){
	int n,m,k;
	cin>>n>>k>>m;
	FOR1(i,n)scanf("%d",&tab[i]),tab[i]+=tab[i-1];
	if(m*k>=n){printf("%d",tab[n]);return 0;}
	int pre=0,now=1;
	dp[now][0]=-INF;
	FOR(i,k){
	   if(i!=0) dp[pre][0]=-INF,dp[now][0]=-INF;
	FOR1(j,n){
		dp[now][j]=-INF;
	if(j-m>=0)dp[now][j]=dp[pre][j-m]+tab[j]-tab[j-m];
	//printf("/%d/",j-m);
	dp[now][j]=max(dp[now][j],dp[now][j-1]);
   //printf("%d ",dp[now][j]);
	}//printf("\n");
	swap(now,pre);
	}
	printf("%d",dp[pre][n]);
}
