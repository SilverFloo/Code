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
int dp[2005];
int tab[2005];
int main(){
    int n;
    cin>>n;
    FOR1(i,n)scanf("%d",&tab[i]);
    for(int i=3;i<= n;i++){
    dp[i]=max(dp[i-1],dp[i-3]-tab[i]+tab[i-1]+tab[i-2]);
    printf("%d ",dp[i]);
    }
    printf("%d",dp[n]);
}
