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
int cnt[1005];
int tab[35][35];
int dp[35][35][35][35];
int val[35][35][35][35];
int sur(int si,int ei,int sj,int ej){

    if(val[si][ei][sj][ej]>=0)return val[si][ei][sj][ej];
    int x[1005];
    FOR(i,1005)x[i]=0;
    for(int i=si;i<=ei;i++){
        for(int j=sj;j<=ej;j++){
            x[tab[i][j]]++;
        }
    }
    int ans=0;
    FOR(i,1005){
        if(cnt[i]==x[i]&&cnt[i]!=0)ans++;
    }
    val[si][ei][sj][ej]=ans;
    return ans;
}
int find(int si,int ei,int sj,int ej){
    if(dp[si][ei][sj][ej]>=0)return dp[si][ei][sj][ej];
    if(si==ei||sj==ej)dp[si][ei][sj][ej]=sur(si,ei,sj,ej);
    else{
        dp[si][ei][sj][ej]=max(dp[si][ei][sj][ej],find(si+1,ei,sj,ej)+sur(si,si,sj,ej));
        dp[si][ei][sj][ej]=max(dp[si][ei][sj][ej],find(si,ei-1,sj,ej)+sur(ei,ei,sj,ej));
        dp[si][ei][sj][ej]=max(dp[si][ei][sj][ej],find(si,ei,sj+1,ej)+sur(si,ei,sj,sj));
        dp[si][ei][sj][ej]=max(dp[si][ei][sj][ej],find(si,ei,sj,ej-1)+sur(si,ei,ej,ej));
    }
    //printf("%d %d %d %d -> %d\n",si,ei,sj,ej,dp[si][ei][sj][ej]);
    return dp[si][ei][sj][ej];
}
int main(){
    int n,m,x;
    cin>>n>>m>>x;
    FOR(i,35)FOR(j,35)FOR(k,35)FOR(l,35)val[i][j][k][l]=dp[i][j][k][l]=-1;
    FOR(i,n){
        FOR(j,m){
            scanf("%d",&tab[i][j]);
            cnt[tab[i][j]]++;
        }
    }
    find(0,n-1,0,m-1);
    printf("%d",dp[0][n-1][0][m-1]);
}
