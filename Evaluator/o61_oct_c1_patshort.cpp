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
pair<ii,ii> wp[105];
vector<ii> edge[105];
vector<ii> ex[105];
int dist[105];
int cost(ii a,ii b){
    int x=abs(a.f-b.f),y=abs(a.s-b.s);
    if(x>=y)return x;
    else return y+(y-x)%2;
}
int main(){
    int m,q;
    cin>>m>>q;
    FOR(i,m){
        scanf("%d %d %d %d",&wp[i].f.f,&wp[i].f.s,&wp[i].s.f,&wp[i].s.s);
    }
    FOR(i,m){
        FOR(j,m){
            if(i==j)continue;
            int a=min(cost(wp[i].f,wp[j].f),cost(wp[i].f,wp[j].s));
            a=min(a,cost(wp[i].s,wp[j].f));
            a=min(a,cost(wp[i].s,wp[j].s));
            edge[i].pb(j,a+1);
            edge[j].pb(i,a+1);
        }
    }
    while(q--){
        ii st,ed;
        scanf("%d %d %d %d",&st.f,&st.s,&ed.f,&ed.s);
        FOR(i,m){
            int a=min(cost(st,wp[i].f),cost(st,wp[i].s));
            ex[m].pb(i,a);
            a=min(cost(ed,wp[i].f),cost(ed,wp[i].s));
            ex[i].pb(m+1,a+1);
        }
        ex[m].pb(m+1,cost(st,ed));
        FOR(i,m+2)dist[i]=INF;
        dist[m]=0;
        priority_queue<ii,vector<ii>,greater<ii>> q;
        q.p(0,m);
        while(!q.empty()){
            int u=q.top().s;
            int l=q.top().f;
            q.pop();
            if(dist[u]!=l)continue;
            //printf("%d %d/",u,l);
            if(u==m+1)break;
            for(auto v:edge[u]){
                if(dist[v.f]>dist[u]+v.s){
                    dist[v.f]=dist[u]+v.s;
                    q.p(dist[v.f],v.f);
                }
            }
            for(auto v:ex[u]){
                if(dist[v.f]>dist[u]+v.s){
                    dist[v.f]=dist[u]+v.s;
                    q.p(dist[v.f],v.f);
                }
            }
        }
        printf("%d\n",dist[m+1]);
        FOR(i,m+2)ex[i].clear();
    }
}
/*
    idea : use warp gate as node then do dijkstra
    if dx >= dy  cost is dx
    if dx < dy co cost is dy+(dy-dx)%2

    30 min 100%
*/
