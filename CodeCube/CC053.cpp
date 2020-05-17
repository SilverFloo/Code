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
using namespace std;
const int INF=1e9;
int dp[2][65][105][105];
int A[35],B[35],V[35];
int main(){
	int T;
	cin>>T;
	while(T--){
	int n,a,b,kk;
	cin>>n>>a>>b>>kk;
	FOR1(i,n)cin>>A[i]>>B[i]>>V[i];
	if(kk==0){
            printf("0\n");
            continue;
        }
	a--;b--;
	int ans=0;
	for(int i=0;i<=1;i++){
		for(int j=0;j<=60;j++){
			for(int k=0;k<=a;k++){
				for(int l=0;l<=b;l++){
					dp[i][j][k][l]=-INF;
				}
			}
		}
	}
	for(int i=0;i<=a;i++)dp[0][30][i][0]=0;
	for(int i=0;i<=b;i++)dp[0][30][0][i]=0;
	int pre=0,now=1;
	for(int i=1;i<=n;i++){
		for(int k=0;k<=a;k++){
			for(int l=0;l<=b;l++){
				for(int j=30-n;j<=30+n;j++){
					dp[now][j][k][l]=-INF;
					if(k-A[i]>=0)dp[now][j][k][l]=max(dp[now][j][k][l],dp[pre][j-1][k-A[i]][l]+V[i]);
					if(l-B[i]>=0)dp[now][j][k][l]=max(dp[now][j][k][l],dp[pre][j+1][k][l-B[i]]+V[i]);
					if(i>0)dp[now][j][k][l]=max(dp[now][j][k][l],dp[pre][j][k][l]);
					if(k>0)dp[now][j][k][l]=max(dp[now][j][k][l],dp[now][j][k-1][l]);
					if(l>0)dp[now][j][k][l]=max(dp[now][j][k][l],dp[now][j][k][l-1]);
					if(abs(j-30)<=kk)ans=max(ans,dp[now][j][k][l]);
				   // if(dp[i][j][k][l]>=0)printf("%d %d %d %d->%d\n",i,k,l,j-30,dp[i][j][k][l]);
				}
			}
		}
		swap(pre,now);
	}
	printf("%d\n",ans);
	}
}

