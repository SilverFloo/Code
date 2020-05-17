#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<(a);i++)
#define f first
#define s second
#define p pair<int,int>
#define mp make_pair
using namespace std;
const int INF=2e9;
vector<p> e[10005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int x,y,z;
    cin>>x>>y>>z;
    FOR(i,m){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        e[u].emplace_back(v,w);
        e[v].emplace_back(u,w);
    }
    priority_queue<p,vector<p>,greater<p>> pq;
    int dist[n];
    bool visit[n];
    FOR(i,n){dist[i]=INF;visit[i]=0;}
    dist[x]=0;
    pq.push(mp(0,x));
    while(!pq.empty()){
        int u=pq.top().s;
        int w=pq.top().f;
        pq.pop();
        if(!visit[u]){
            for(auto i:e[u]){
                if(dist[i.f]>dist[u]+i.s){dist[i.f]=dist[u]+i.s;if(!visit[i.f])pq.push(mp(dist[i.f],i.f));}
            }
        }
    }
    if(dist[y]<=z){printf("%d %d %d",y,dist[y],0);exit(0);}

    int distb[n];

    FOR(i,n){distb[i]=INF;visit[i]=0;}
    distb[y]=0;
    pq.push(mp(0,y));
    while(!pq.empty()){
        int u=pq.top().s;
        int w=pq.top().f;
        pq.pop();
        if(!visit[u]){
            for(auto i:e[u]){
                if(distb[i.f]>distb[u]+i.s){distb[i.f]=distb[u]+i.s;if(!visit[i.f])pq.push(mp(distb[i.f],i.f));}
            }
        }
    }
    int ans2=0,ans3=INF;
    FOR(i,n){
        if(dist[i]<=z&&distb[i]<ans3){ans3=distb[i];ans2=i;}
    }
    printf("%d %d %d",ans2,dist[ans2],ans3);
}
