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
#define iii pair<int,ii>
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
int v[17];
vector<ii> edge[17];
int e[205][205];
int dist[17][(1<<15)+5];
int main(){
   // rf();
    int n,m,k;
    cin>>n>>m>>k;
    FOR(i,k){
        scanf("%d",&v[i]);
    }
    FOR(i,m){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        e[u][v]=w;
        e[v][u]=w;
    }
    FOR1(k,n){
        FOR1(i,n){
            FOR1(j,n){
                if(e[i][k]!=0&&e[k][j]!=0){
                    if(e[i][j]!=0)e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
                    else e[i][j]=e[i][k]+e[k][j];
                }
            }
        }
    }/*
    FOR1(i,n){
        FOR1(j,n)printf("%d ",e[i][j]);
        cout<<endl;
    }*/
    FOR(i,k){
        FOR(j,k){
            if(e[v[i]][v[j]]!=0)edge[i].pb(j,e[v[i]][v[j]]);
        }
    }
    FOR(i,k)FOR(j,1<<k)dist[i][j]=INF;
    priority_queue<iii,vector<iii>,greater<iii>> q;
    FOR(i,k){
        dist[i][1<<i]=e[1][v[i]];
        q.p(dist[i][1<<i],mp(i,1<<i));
    }
    while(!q.empty()){
        int l=q.top().f;
        int u=q.top().s.f;
        int st=q.top().s.s;
        q.pop();
        //printf(">>%d %d->%d\n",u,st,l);
        if(dist[u][st]!=l)continue;
        //printf(">>%d %d->%d\n",u,st,l);
        for(auto v:edge[u]){
            int tmp = st|(1<<v.f);
            if(dist[v.f][tmp]>dist[u][st]+v.s){
                dist[v.f][tmp]=dist[u][st]+v.s;
                q.p(dist[v.f][tmp],mp(v.f,tmp));
            }
        }
    }
    int ans=1e9;
    FOR(i,k){
        if(dist[i][(1<<k)-1]+e[n][v[i]]<ans)ans=dist[i][(1<<k)-1]+e[n][v[i]];
    }
    printf("%d",ans);

}
