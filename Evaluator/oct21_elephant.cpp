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
int dp[100005];
int main(){
    int n;
    cin>>n;
    int a,b;
    scanf("%d %d",&a,&b);
    for(int i=3;i<=n;i++){
        int x;
        scanf("%d",&x);
        dp[i]=max(dp[i-1],dp[i-3]+x);
    }
    printf("%d",dp[n]);
}
