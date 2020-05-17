#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<(a);i++)
#define f first
#define s second
#define mp make_pair
#define pi pair<int,int>
using namespace std;
const int INF=1e9;
int main(){
int t;
cin>>t;
while(t--){
int n,m,s,t,p;
cin>>n>>m>>s>>t>>p;s--;t--;
vector<pair<int,int>> e[n];
vector<pair<int,int>> e2[n];
vector<pair<int,pi>> edge;
FOR(i,m){
int u,v,w;
scanf("%d %d %d",&u,&v,&w);u--;v--;
e[u].emplace_back(v,w);
e2[v].emplace_back(u,w);
edge.emplace_back(w,mp(u,v));
}
sort(edge.begin(),edge.end());
int dist1[n];
bool visit[n];
priority_queue<pi,vector<pi>,greater<pi>> pq;
FOR(i,n){dist1[i]=INF;visit[i]=0;}
pq.push(mp(0,s));
dist1[s]=0;

while(!pq.empty()){
    int u=pq.top().s;
    pq.pop();
    if(!visit[u]){
        visit[u]=1;
        for(auto i:e[u]){
            if(!visit[i.f]&&dist1[i.f]>dist1[u]+i.s){
                dist1[i.f]=dist1[u]+i.s;
                pq.push(mp(dist1[i.f],i.f));
            }
        }
    }
}


int dist2[n];
FOR(i,n){dist2[i]=INF;visit[i]=0;}
pq.push(mp(0,t));
dist2[t]=0;

while(!pq.empty()){
    int u=pq.top().s;
    pq.pop();
    if(!visit[u]){
        visit[u]=1;
        for(auto i:e2[u]){
            if(!visit[i.f]&&dist2[i.f]>dist2[u]+i.s){
                dist2[i.f]=dist2[u]+i.s;
                pq.push(mp(dist2[i.f],i.f));
            }
        }
    }
}

for(auto i:dist1)printf("-%d ",i);cout<<endl;
for(auto i:dist2)printf("-%d ",i);cout<<endl;
int ch=0;
for(int i=edge.size()-1;i>=0;i--){
int u=edge[i].s.f,v=edge[i].s.s,w=edge[i].f;
if(dist1[u]+dist2[v]+w<=p){printf("%d\n",w);ch=1;break;}

}
if(ch==0)printf("-1\n");

}
}
