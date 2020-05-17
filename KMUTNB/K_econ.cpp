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
int dp[205][205];
int tab[205][205];

int main(){
    int n;
    cin>>n;
    FOR(i,n){
    FOR(j,n){
    scanf("%d",&tab[i][j]);
    }
    }
    //int ans=0;
    FOR(i,n){
    FOR(j,n){
        if(i==0||j==0)dp[i][j]=tab[i][j];
        else{
            dp[i][j]=tab[i][j]+dp[i-1][j-1];
        }
        if(j>0)dp[i][j]=max(dp[i][j],dp[i][j-1]);
        if(i>0)dp[i][j]=max(dp[i][j],dp[i-1][j]);
        //ans=max(ans,dp[i][j]);
        //printf("%3d ",dp[i][j]);
    }
   // printf("\n");
    }
    printf("%d",dp[n-1][n-1]);
}
/*6
25 22 22 9 7 11
1 3 11 20 22 17
21 5 25 11 22 17
27 23 11 14 8 26
5 5 0 6 11 4
8 24 25 20 23 0


4
5 2 3 1
4 6 2 7
3 6 2 4
2 7 5 3*/
