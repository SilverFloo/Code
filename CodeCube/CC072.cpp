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
int val[1005];
bool visit[505][505];
int tab[505][505];
    int n,m;
void go(int i,int j,int t){
visit[i][j]=1;
if(!tab[i][j]){
val[t]++;
if(j<m-1&&!visit[i][j+1])go(i,j+1,t+1);
if(i<n-1&&!visit[i+1][j])go(i+1,j,t+1);
}
}
int main(){
ll ans=0;
    cin>>n>>m;
    for(int i=n-1;i>=0;i--){
    FOR(j,m)scanf("%d",&tab[i][j]);
    }
    go(0,0,0);
    FOR(i,1000){
    ans+=(ll)val[i]*val[i];
    }
    printf("%lld",ans);
}
