#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<(a);i++)
#define f first
#define s second
using namespace std;
typedef struct edge{
int v,w,h;
edge(int v,int w,int h):v(v),w(w),h(h){}
}edge;
const int INF=2e9;
int n,m,k,t;int ans=2e9;
const int MAX=1e5+5;
vector<edge> e[MAX];
vector< pair<int,int> > shoes;
void f(int l,int r){

if(l>r)return;
int mid=(l+r)/2;
//printf(">%d %d ",mid,shoes[mid].f);
int dp[MAX];
bool visit[MAX];
FOR(i,n){dp[i]=INF;visit[i]=0;}
dp[0]=0;
priority_queue< pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;
pq.push(make_pair(0,0));
while(!pq.empty()){
int u=pq.top().s;
int w=pq.top().f;
pq.pop();
if(!visit[u]){
visit[u]=1;
for(auto i:e[u]){
if(i.h<=shoes[mid].s){
if(!visit[i.v])if(dp[i.v]>dp[u]+i.w){dp[i.v]=dp[u]+i.w;
pq.push(make_pair(dp[i.v],i.v));
}

}
}

}
}//printf("%d ",dp[n-1]);
if(dp[n-1]<=t){ans=min(ans,shoes[mid].f);f(l,mid-1);}
else {f(mid+1,r);}
}

int main(){

scanf("%d %d %d %d",&n,&m,&k,&t);
FOR(i,m){
int u,v,w,h;
scanf("%d %d %d %d",&u,&v,&h,&w);
u--;v--;
e[u].emplace_back(v,w,h);
e[v].emplace_back(u,w,h);
}
pair<int,int> sh[k];
FOR(i,k){
scanf("%d %d",&sh[i].f,&sh[i].s);
}


sort(sh,sh+k);
int M=sh[0].s;
shoes.push_back(sh[0]);
for(int i=1;i<k;i++){if(sh[i].s>M){shoes.push_back(sh[i]);M=sh[i].s;}}
//for(auto i:shoes){printf("%d %d\n",i.f,i.s);}
f(0,shoes.size()-1);
if(ans!=INF)printf("%d",ans);
else printf("-1");

}
