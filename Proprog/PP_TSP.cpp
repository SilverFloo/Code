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
const int INF=2e9+5;
int dp[17][1<<17];
ii pos[17];int n;
int dis(ii a,ii b){
    return abs(a.f-b.f)+abs(a.s-b.s);
}
int tsp(int p,int st){
    if(dp[p][st]!=0)return dp[p][st];
    int nst=st|1<<p;
    if(nst==(1<<n+1)-1){dp[p][st]=dis(pos[0],pos[p]);return dp[p][st];}
    int mn=INF;
    FOR(i,n+1){
        if((nst&(1<<i))==0){mn=min(mn,dis(pos[p],pos[i])+tsp(i,nst));}
    }

    dp[p][st]=mn;
    return mn;
}
int main(){
    scanf("%d %d",&pos[0].f,&pos[0].s);

    cin>>n;
    FOR1(i,n){
        scanf("%d %d",&pos[i].f,&pos[i].s);
    }
    printf("%d",tsp(0,0));
}
