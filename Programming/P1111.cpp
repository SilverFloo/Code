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
using namespace std;
const int INF=1e9;
long long dist[100005];
bool visit[100005];
vector<ii> edge[100005];
void go(int n){
visit[n]=1;
    for(auto i:edge[n]){
        if(!visit[i.f]){
            dist[i.f]=dist[n]+i.s;
            go(i.f);
        }
    }
}
int main(){
    int n;
    cin>>n;
    FOR(i,n-1){
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        a--;b--;
        edge[a].pb(b,w);
        edge[b].pb(a,w);
    }
    dist[0]=0;
    go(0);
    long long M=0;
    FOR(i,n){
        if(dist[i]>M)M=dist[i];
    }
    printf("%lld",M);
}
