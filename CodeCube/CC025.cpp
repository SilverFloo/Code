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
int tab[605];
ll dp[605][605];
int main(){
    int n;
    cin>>n;
    FOR1(i,n)scanf("%d",&tab[i]),tab[i]+=tab[i-1];
    for(int l=1;l<n;l++){
    for(int i=1;i<=n-l;i++){
    int j=i+l;
    ll mx=0;
    for(int k=i;k<j;k++){
            //printf("<%d %d %d>",i,k,j);
        ll a=tab[k]-tab[i-1];
        ll b=tab[j]-tab[k];
        if(a>b)swap(a,b);//printf("<%d %d %d %lld %lld>",i,k,j,dp[i][k],dp[k][j]);
        mx=max(mx,dp[i][k]+dp[k+1][j]+2*a+b);
    }
   // printf("%d %d->%lld\n",i,j,mx);
    dp[i][j]=mx;
    }
    }
    printf("%lld",dp[1][n]);
}
