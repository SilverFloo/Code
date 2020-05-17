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
int tab[105];
int dp[105][105];
int main(){
    int n;
    cin>>n;
    n<<=1;
    FOR(i,n)scanf("%d",&tab[i]);
    for(int l=1;l<n;l++){
        for(int i=0;i<n-l;i++){
            int j=i+l;
            if(l%2!=0){

                dp[i][j]=max(dp[i+1][j]+tab[i],dp[i][j-1]+tab[j]);
            }
            else {
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
           // printf("%d %d %d\n",i,j,dp[i][j]);
        }
    }
    printf("%d",dp[0][n-1]);
}
