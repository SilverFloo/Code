#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
pair<ii,int> pipe[20005];
map<int,int> mp;
int pos[40005];
int dp[40005];
int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,m){
        scanf("%d %d %d",&pipe[i].f.f,&pipe[i].f.s,&pipe[i].s);
        mp[pipe[i].f.f]=1;
        mp[pipe[i].f.s]=1;
    }
    int ptr=0;
    for(auto &i:mp)pos[ptr]=i.f,i.s=ptr++;
    int x=mp.size();
    int ans=0;
    FOR(i,m){
        int mx=0;
        for(int j=0;j<x;j++){
            mx=max(mx,dp[j]-abs(pipe[i].f.f-pos[j]));
        }
        int mx2=0;
        for(int j=0;j<x;j++){
            mx2=max(mx2,dp[j]-abs(pipe[i].f.s-pos[j]));
        }
        mx+=pipe[i].s;
        mx2+=pipe[i].s;
        ans=max(ans,max(mx,mx2));
        printf("%d\n",ans);
        dp[mp[pipe[i].f.s]]=max(dp[mp[pipe[i].f.s]],mx);
        dp[mp[pipe[i].f.f]]=max(dp[mp[pipe[i].f.f]],mx2);

        //printf("===%d===\n",i);
    }
}
