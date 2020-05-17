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
int card[100005];
int fav[100005];
int val[5005];
ll dp[505][5005];
int main(){
    int n,k;
    cin>>n>>k;
    FOR(i,n*k){
    int a;
    scanf("%d",&a);
    card[a]++;
    }
    FOR(i,n){
    int a;
    scanf("%d",&a);
    fav[a]++;
    }
    FOR1(i,k){
    scanf("%d",&val[i]);
    }
    //dp[0][0]=1;
    FOR1(i,n){
        FOR(j,n*k+1){
            for(int x=0;x<=k&&j-x>=0;x++){
            dp[i][j]=max(dp[i-1][j-x]+val[x],dp[i][j]);
            }
         //   printf("%d ",dp[i][j]);
        }
       // cout<<endl;
    }
    ll ans=0;
    FOR(i,100005){
        //printf("%d/",dp[1][1]);
        ans+=dp[fav[i]][card[i]];
    }
    printf("%lld",ans);
}
