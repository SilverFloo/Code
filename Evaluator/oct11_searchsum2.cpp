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
int dp[1005];
int main(){
    int n,m;
    cin>>n>>m;
    FOR1(i,n)scanf("%d",&dp[i]),dp[i]+=dp[i-1];
    FOR(i,m){
        int x;
        scanf("%d",&x);
        int ans=0;
        int pos=0;
        for(int j=0;j<n;j++){
            while(pos<n&&x>=dp[pos+1]-dp[j]){pos++;}
            ans=max(ans,pos-j);
        }
        printf("%d\n",ans);
    }
}


