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
#define iii pair<int,ii>
#define ll long long
using namespace std;
const int INF=2e9+5;
ll dist[100005][2];
vector<ii> e[100005];
int main(){
    ll sum=0;
    int n,m;
    cin>>n>>m;
    int st,ed;
    cin>>st>>ed;
    FOR(i,m){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        sum+=(ll)c;
        e[a].pb(b,c);
        e[b].pb(a,c);
    }
    FOR(i,n)dist[i][0]=INF,dist[i][1]=INF;
    priority_queue<iii,vector<iii>,greater<iii>> q;
    dist[st][0]=0;
    q.p(0,mp(st,0));
    while(!q.empty()){
        int l=q.top().f;
        int u=q.top().s.f;
        int w=q.top().s.s;
        q.pop();
        if(dist[u][w]!=l)continue;
        for(auto v:e[u]){
            if((ll)dist[u][w]+v.s<dist[v.f][w]){
                dist[v.f][w]=(ll)dist[u][w]+v.s;
                q.p(dist[v.f][w],mp(v.f,w));
            }
            if(w==0){
                if(dist[u][0]<dist[v.f][1]){
                dist[v.f][1]=dist[u][0];
                q.p(dist[v.f][1],mp(v.f,1));
            }
            }

        }

    }
    printf("%lld",sum-dist[ed][1]);

}
