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
const int MAX=1e4+5;
vector<ii> e[MAX];
ll dp[2][MAX];
int main(){
	int n,m,t;
	int st,ed;
	cin>>n>>m>>t>>st>>ed;
	FOR(i,m){
	int a,b,w;
	scanf("%d %d %d",&a,&b,&w);
	e[a].pb(b,w);
	}
	int now=1,pre=0;
	dp[pre][st]=1;
	ll mn=INF;
	for(int i=2;i<7000;i++){
			ll mx=INF;
		FOR1(j,n){
		   // printf("%d ",dp[pre][j]);
		if(dp[pre][j]!=0){
		mx=min(mx,dp[pre][j]);
		for(auto v:e[j]){
		if(dp[now][v.f]!=0)dp[now][v.f]=min(dp[now][v.f],dp[pre][j]+v.s);
		else dp[now][v.f]=dp[pre][j]+v.s;
		}
		dp[pre][j]=0;
		}
		}
		if(i%t==0){

		if(dp[now][ed]>0){mn=min(dp[now][ed],mn);}
		//printf("<%lld>",mx);
		if(mx>mn||mn==-INF)break;
		}


	   //printf("\n");
		swap(now,pre);
	}
	//if(mn==INF)exit(1);
	printf("%lld",mn==INF?-1:mn-1);
}
