#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<(a);i++)
#define f first
#define s second
using namespace std;
typedef struct edge{
int v,w,h;
edge(int v,int w,int h):v(v),w(w),h(h);
}edge;
vector<edge> e[(int)1e5+5];
vector< pair<int,int> > shoes;
find(int l,int r){
int m=(l+r)/2;
int dp
priority_queue< pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;
pq.push_back(0,0);
while(!pq.empty()){
int u=pq.


}
}
int main(){
int n,m,k,t;
scanf("%d %d %d %d",&n,&m,&k,&t);
FOR(i,n){
int u,v,w,h;
scanf("%d %d %d %d",u,v,w,h);
u--;v--;
e[u].emplace_back(v,w,h);
e[v].emplace_back(u,w,h);
}
pair<int,int> sh[k];
FOR(i,k){
scanf("%d %d",sh[i].f,sh[i].s);
}
sort(sh,sh+k);
int M=sh[0].s;
shoes.push_back(sh[0]);
for(int i=1;i<k;i++){if(sh[i]>M){shoes.push_back(sh[i]);M=sh[i].s;}}
find(0,shoes.size()-1);

}
