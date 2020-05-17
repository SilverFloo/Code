//https://www.codecube.in.th/task/117
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
bool dp[100010][2];
int main(){
	int q;
	cin>>q;
	FOR(a,q){
		int n,k;
		cin>>n>>k;
		int prev=1,now=0;
		fill(dp[prev],dp[prev]+k,0);
		dp[prev][0]=1;
		FOR(i,n){
		int x;
		scanf("%d",&x);
			FOR(j,k){
				dp[now][j]=dp[prev][j];
				if(dp[prev][j]){dp[now][(j+x)%k]=1;}
			}
			swap(now,prev);
		}
		for(int i=k-1;i>=0;i--){
				if(dp[prev][i]){
		printf("Case #%d: %d\n",a+1,i);break;}
		}
	}
}
