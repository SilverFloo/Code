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
const ll INF=1e18;
const int MAX=5e4+10;
ll tab[MAX];
ll dp[2][MAX];
int main(){
	int n,m,k;
	cin>>n>>k>>m;
	int pre=1,now=0;
	dp[0][1]=dp[0][0]=INF;
	for(int i=2;i<n+2;i++)scanf("%lld",&tab[i]),tab[i]+=tab[i-1];
	for(int i=1;i<=k;i++){
            ll minn=INF;
	if(i==3)dp[pre][1]=INF,dp[pre][0]=INF;
	for(int j=2;j<n+2;j++){
	ll mn=INF;
	if(j-m>0)minn = min(minn+tab[j]-tab[j-1],dp[pre][j-m-1]+tab[j]-tab[j-m]);
	mn=min(mn,minn);
	if(j>2)dp[now][j]=min(mn,dp[now][j-1]);
	else dp[now][j]=mn;
   //printf("%lld ",dp[now][j]);
	}//printf("\n");
	swap(pre,now);
	}

	printf("%lld",tab[n+1]-dp[pre][n+1]);
}
