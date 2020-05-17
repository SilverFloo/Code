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
const int MAX=1e3+5;
vector<ii> e[MAX];
int dist1[MAX];
int dist2[MAX];
int visit[MAX];
void dijk(int st,int dist[]){
    FOR(i,MAX)dist[i]=INF,visit[i]=0;
    dist[st]=0;
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.p(0,st);//printf("\n");
    while(!q.empty()){
        int u=q.top().s;
        int t=q.top().f;
        q.pop();
        if(t==dist[u]&&!visit[u]){
               // printf("%d>",u);
            visit[u]=1;
            for(auto v:e[u]){
                if(dist[v.f]>dist[u]+v.s){
                    dist[v.f]=dist[u]+v.s;
                    q.p(dist[v.f],v.f);
                }
            }
        }
    }
}
int main(){
    int n,m,st,ed,k1,k2,k3,k4;
    cin>>n>>m>>st>>ed>>k1>>k2>>k3>>k4;
    FOR(i,m){
    int a,b,w;
    scanf("%d %d %d",&a,&b,&w);
    e[a].pb(b,w);
    }
    dijk(st,dist1);
    dijk(ed,dist2);
    //FOR(i,n)printf("%d ",dist1[i]);printf("\n");
   // FOR(i,n)printf("%d ",dist2[i]);
    int mn=dist1[ed];
    if(dist1[k1]<=k4){
        mn=min(mn,dist1[k1]+dist2[k2]+k3);
    }
    printf("%d",mn);
}

