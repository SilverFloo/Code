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
int val[3005];
int dp[3005];
int main(){
    int n,k;
    cin>>n>>k;
    FOR(i,n)scanf("%d",&val[i]);
    dp[0]=val[0];
    deque<int> q;
    q.pb(0);
    for(int i=1;i<n;i++){
        while(!q.empty()&&q.front()<i-k+1)q.pop_front();
        dp[i]=dp[q.front()]+val[i];
        while(!q.empty()&&dp[q.back()]>dp[i])q.pop_back();
        q.pb(i);
       // printf("%d ",dp[i]);
    }
    int ans=INF;
    for(int i=n-k;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            ans=min(ans,dp[i]+val[j]);
            //printf("%d %d\n",dp[i],val[j]);
        }
    }
    printf("%d",ans);
}
