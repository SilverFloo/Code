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
int a[2005],b[2005];
int sa[2005],sb[2005];
int dp[2005][2005];
int main(){
    int n,m;
    cin>>n;
    FOR1(i,n)scanf("%d",&a[i]),sa[i]=sa[i-1]+a[i];
    cin>>m;
    FOR1(i,m)scanf("%d",&b[i]),sb[i]=sb[i-1]+b[i];
    dp[0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0&&j==0)continue;
            if(j==0&&sa[i]>0)dp[i][j]=dp[i-1][j];
            if(i==0&&sb[j]>0)dp[i][j]=dp[i][j-1];
            if(i==0||j==0)continue;
            if(sa[i]+sb[j]>0){
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
                dp[i][j]%=1000000007;
            }
           // printf("%d ",dp[i][j]);
        }//cout<<endl;
    }
    printf("%d",dp[n][m]);
}
