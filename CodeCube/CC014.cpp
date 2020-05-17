#include<bits/stdc++.h>
using namespace std;
#define s second
#define f first
const int INF=2e9;
#define pii pair<int,pair<int,int>>
#define mp make_pair
typedef struct edge{
    int u,v,w;
}edge;
int n,m;
edge e[5005];
int xxxx;
int ans=INF;
int sssp(int mid){
    vector<pair<int,int>> path[5+n];
    for(int i=0;i<mid;i++){
        path[e[i].u].emplace_back(e[i].v,e[i].w);
        path[e[i].v].emplace_back(e[i].u,e[i].w);
    }
    int dist[2][n+5];
    bool visit[2][n+5];
    for(int i=0;i<n;i++){visit[0][i]=0;visit[1][i]=0;dist[0][i]=INF;dist[1][i]=INF;}
    dist[1][0]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.emplace(0,mp(0,1));
    while(!pq.empty()){
        int u=pq.top().s.f;
        int st=pq.top().s.s;
        pq.pop();
        if(!visit[st][u]){
            visit[st][u]=1;
            for(auto i:path[u]){
                if(dist[!st][i.f]>dist[st][u]+i.s){
                    dist[!st][i.f]=dist[st][u]+i.s;
                    pq.emplace(dist[!st][i.f],mp(i.f,!st));
                }
            }
        }
    }
   return dist[0][n-1];
}



int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
        e[i].u--;
        e[i].v--;
    }
    xxxx=sssp(m);
    int l=0;int r=m-1;
    while(l<=r){
    //printf("//%d %d %d\n ",(l+r)/2);
        int mid=(l+r)/2;
        int val=sssp(mid+1);
        if(val==xxxx){ans=min(ans,mid);r=mid-1;}
        else if(val>xxxx){l=mid+1;}
        else r=mid-1;
    }
    printf("%d %d",ans+1,xxxx);
}
