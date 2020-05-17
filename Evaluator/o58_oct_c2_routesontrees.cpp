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
int dist[100005][10];
vector<ii> edge[100005];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    FOR(i,m){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        edge[a].pb(b,c);
    }
    FOR1(i,n)FOR(j,k+1)dist[i][j]=INF;
    dist[1][0]=0;
    priority_queue<pair<int,ii>,vector<pair<int,ii>>,greater<pair<int,ii>>> q;
    q.p(0,mp(1,0));
    while(!q.empty()){
        int l=q.top().f;
        int u=q.top().s.f;
        int st=q.top().s.s;
        q.pop();
        if(dist[u][st]!=l)continue;
        //printf("%d %d/",u,st);
        if(u==n){
            printf("%d",l); return 0;
        }
        for(auto v:edge[u]){
            if(v.s<-100){
                if(st>=k)continue;
                if(dist[v.f][st+1]>dist[u][st]){
                    dist[v.f][st+1]=dist[u][st];
                    q.p(dist[v.f][st+1],mp(v.f,st+1));
                }
            }
            else if(v.s<=0){
                if(dist[v.f][st]>dist[u][st]){
                    dist[v.f][st]=dist[u][st];
                    q.p(dist[v.f][st],mp(v.f,st));
                }
            }
            else{
                if(dist[v.f][st]>dist[u][st]+v.s){
                    dist[v.f][st]=dist[u][st]+v.s;
                    q.p(dist[v.f][st],mp(v.f,st));
                }
            }
        }
    }
    printf("-1");
}
