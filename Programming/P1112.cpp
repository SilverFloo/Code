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
int dp[2][10005];
int main(){
    int n,k;
    cin>>n>>k;
    int now=0,pre=1;
    dp[pre][0]=1;
    dp[now][0]=1;


    for(int i=2;i<=n;i++){
    int sum=0;
        for(int j=0;j<=k;j++){
            if(j-i>=0)sum-=dp[pre][j-i];
            sum+=dp[pre][j];
            sum%=2012;
            dp[now][j]=sum;

        }
        swap(now,pre);
    }
    printf("%d",dp[pre][k]);
}
