#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define _1 first
#define _2 second
const int INF =2e9;
const int MAX=2e4+5;
typedef pair<int,int> pi;
vector<pi> edge[MAX];
int dist[MAX];
bool visited[MAX];
priority_queue<pi,vector<pi>,greater<pi> > pq;
int main(){
    int c=1;
int q;scanf("%d",&q);
while(q--){
int n,m,s,t;
scanf("%d %d %d %d",&n,&m,&s,&t);
for(int i=0;i<m;i++){
int u,v,w;
scanf("%d %d %d",&u,&v,&w);
edge[u].emplace_back(v,w);
edge[v].emplace_back(u,w);
}
for(int i=0;i<n;i++)dist[i]=INF;
dist[s]=0;
pq.push(mp(0,s));
while(!pq.empty()){
int u,w;
u=pq.top().second;
w=pq.top().first;
pq.pop();
if(!visited[u]){
visited[u]=1;
for(int i=0;i<edge[u].size();i++){
if(!visited[edge[u][i]._1]){
if(dist[edge[u][i]._1]>dist[u]+edge[u][i]._2){
dist[edge[u][i]._1]=dist[u]+edge[u][i]._2;
pq.push(mp(dist[edge[u][i]._1],edge[u][i]._1));
}

}

}
}
}
printf("Case #%d: ",c);c++;
if(dist[t]==INF)printf("unreachable\n");
else printf("%d\n",dist[t]);
for(int i=0;i<n;i++){edge[i].clear();visited[i]=0;}
}

}
