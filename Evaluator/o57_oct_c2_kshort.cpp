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
vector<ii> edge[10005],ex[10005];
int dist[10005][55];
int main(){
    int n,m,s,x;
    cin>>n>>m>>s>>x;
    FOR(i,m){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        edge[a].pb(b,c);
    }
    FOR(i,s){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        ex[a].pb(b,c);
    }
    FOR1(i,n)FOR(j,x+1)dist[i][j]=INF;
    dist[1][0]=0;
    priority_queue<pair<int,ii>,vector<pair<int,ii>>,greater<pair<int,ii>>> q;
    q.p(0,mp(1,0));
    while(!q.empty()){
        int l=q.top().f;
        int u=q.top().s.f;
        int st=q.top().s.s;
        q.pop();

        if(dist[u][st]!=l)continue;
        if(u==n){
            printf("%d",dist[u][st]);
            return 0;
        }

        for(auto v:edge[u]){
            if(dist[v.f][st]>l+v.s){
                dist[v.f][st]=l+v.s;
                q.p(dist[v.f][st],mp(v.f,st));
            }
        }
        if(st<x){
            for(auto v:ex[u]){
                if(dist[v.f][st+1]>l+v.s){
                    dist[v.f][st+1]=l+v.s;
                    q.p(dist[v.f][st+1],mp(v.f,st+1));
                }
            }
        }
    }
}
