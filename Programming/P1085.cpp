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
const int MAX=5e5+5;
bool visit[MAX];
bool rock[MAX];
vector<int> e[MAX];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int mx=0;
    FOR(i,m){
    int a,b;
    scanf("%d %d",&a,&b);
    e[a].pb(b);
    }
    FOR(i,k){
    int a;
    scanf("%d",&a);
    rock[a]=1;
    }
    visit[1]=1;
    FOR1(i,n){
    if(visit[i]){
    if(!rock[i])visit[i+1]=1;
    for(auto v:e[i])visit[v]=1;
    mx=i;
    }
    }
    if(mx==n)printf("1");
    else printf("0 %d",mx);
}
