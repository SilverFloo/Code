#include<bits/stdc++.h>
using namespace std;
const int INF=10e9;
typedef struct edge{
int u,v,w;
edge(int u,int v,int w):u(u),v(v),w(w){}
}edge;
int main(){
int q;
scanf("%d",&q);
while(q--){
int n,m;
scanf("%d%d",&n,&m);
vector<edge> e;
for(int i=0;i<m;i++){
int u,v,w;
scanf("%d %d %d",&u,&v,&w);
e.emplace_back(u,v,w);
}
int dist[n];
for(int i=0;i<n;i++){dist[i]=INF;}
dist[0]=0;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(dist[e[j].u]!=INF&&dist[e[j].u]+e[j].w<dist[e[j].v]){
dist[e[j].v]=dist[e[j].u]+e[j].w;
}
}
}
int ch=0;
for(int i=0;i<m;i++){
if(dist[e[i].u]!=INF&&dist[e[i].u]+e[i].w<dist[e[i].v]){printf("possible\n");ch=1;break;}
}
if(!ch)printf("not possible\n");
}

}
