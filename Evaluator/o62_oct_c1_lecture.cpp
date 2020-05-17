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

    ll ans=-1;
    ll l=1,r=1e15;
    while(l<=r){
        ll m=(l+r)/2;
        int ch=0;
        ll left=t[0];
        //printf("<%d %d %d> ",l,m,r);
        for(int i=1;i<c;i++){
            left+=t[i];
            left-=m*dist[room[i-1]][room[i]];
          //  printf("//%d %lld//",e[room[i-1]][room[i]],left);
            if(left<=0){ch=1;break;}
            left=min(left,t[i]);
        }
       // cout<<endl;
        if(ch==0){
            ans=m;
            l=m+1;
        }
        else {
            r=m-1;
        }
    }
    printf("%lld",ans);
}
