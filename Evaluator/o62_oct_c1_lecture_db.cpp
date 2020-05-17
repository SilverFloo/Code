#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9+5;
int room[100005];
ll t[100005];
vector<ii> e[305];
ll dist[305][305];
void d(int st){
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.p(0,st);
    while(!q.empty()){
        ll l=q.top().f;
        ll u=q.top().s;
        q.pop();
        if(l!=dist[st][u])continue;
        for(auto v:e[u]){
            if(dist[st][u]+v.s<dist[st][v.f]){
                dist[st][v.f]=dist[st][u]+(ll)v.s;
                q.p(dist[st][v.f],v.f);
            }
        }
    }

}
int main(){
    freopen("inputt.txt","r",stdin);
      int c,n,m;
    cin>>c>>n>>m;
    FOR(i,c)scanf("%d",&room[i]);
    FOR(i,c)scanf("%lld",&t[i]);
    FOR1(i,n)FOR1(j,n)dist[i][j]=i==j?0:INF;
    FOR(i,m){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        e[a].pb(b,c);
        e[b].pb(a,c);
    }
    FOR1(i,n)d(i);
    ll l=0,r=1e9;
    ll ans=-1;
    while(l<=r){
        ll m =(l+r)/2;
        ll left = t[0];
        int ch=0;
        for(int i=1;i<c;i++){
            left+=t[i];
            left-=m*dist[room[i]][room[i-1]];
            if(left<0){ch=1;break;}
            left=min(left,t[i]);
        }
        if(ch==1){
            r=m-1;
        }
        else {
            l=m+1;
            ans=m;
        }
    }
    printf("%lld",ans);

}
