#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e18;
int n,m,q;
double edge[205][205];
double dist[205];
double dijkstra(int st,int ed,double v,double c){
    FOR1(i,n)dist[i]=INF;
    dist[st]=0;
    priority_queue<pair<double,pair<double,int>>,vector<pair<double,pair<double,int>>>,greater<pair<double,pair<double,int>>>> q;
    q.p(0,mp(v,st));
    while(!q.empty()){
        double l = q.top().f;
        double x = q.top().s.f;
        int u = q.top().s.s;
        For(v,n){
            if(dist[v]>dist[u]+edge[u][v]/x&&x-edge[u][v]*c>0){
                dist[v]=dist[u]+edge[u][v]/x;
                q.p(dist[v],mp(x-edge[u][v]*c,v);
            }
        }
    }
    return dist[ed];
}
int main(){
    cin>>n>>m>>q;
    FOR1(i,n)FOR1(i,n)edge[i][j]=INF;
    FOR(i,m){
        int a,b;
        double c;
        scanf("%d %d %f",&a,&b,&c);
        if(edge[a][b]>c)edge[a][b]=c,edge[b][a]=c;
    }
    string s;
    while(q--){
        cin>>s;
        if(s=="travel"){
            int s,t;
            double v,c;
            scanf("%d %d %f %f",&a,&b,&c,&d);
            double x=dijkstra(a,b,c,d);
            if(x==INF)printf("IMPOSSIBLE\n");
            else printf("%f\n",x);
        }
        if(s=="destroy"){
            int x;
            cin>>x;
            FOR1(i,n)edge[x][i]=edge[i][x]=INF;
        }
        if(s=="add"){
            int x,y;
            cin>>x>>y;
            FOR(i,y){
                int a;
                double b;
                scanf("%d %f",&a,&b);
                edge[a][x]=edge[x][a]=min(edge[x][a],b);
            }
        }
    }
}
