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
const ll INF=2e18;
vector<ii> e[80005];
map<int,int> po;
ll dist[80005][12];
typedef struct st{
    ll w;int u,b,p;
    st(ll w,int u,int b,int p):w(w),u(u),b(b),p(p){}
    bool operator < (const st &ot)const{
        return w>ot.w;
    }
}st;
int main(){
    int n,m,l,x;
    cin>>n>>m>>l>>x;
    FOR(i,m){
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        e[a].pb(b,w);
    }
    FOR1(i,l){
        int a;
        scanf("%d",&a);
        po[a]=i;
    }
    priority_queue<st> q;
    FOR1(i,n)FOR(k,x+2)dist[i][k]=INF;
    q.p(0,1,0,0);
    dist[1][0]=0;
    while(!q.empty()){
        ll w=q.top().w;
        int u=q.top().u;
        int bf=q.top().b;
        int p=q.top().p;
        q.pop();
        if(dist[u][p]!=w)continue;
        //printf("%d %lld %d %d\n",u,w,bf,p);
        if(u==n){printf("%lld",w);exit(0);}
        //if(po[u]!=0)printf("<%d>",bf);
        if(po[u]!=0&&po[u]!=bf&&p+1<=x){
            for(auto v:e[u]){
                if(dist[v.f][p+1]>(ll)dist[u][p]+(ll)v.s/(1<<(p+1))){
                    dist[v.f][p+1]=(ll)dist[u][p]+(ll)v.s/(1<<(p+1));
                    q.p(dist[v.f][p+1],v.f,po[u],p+1);
                }
            }
        }
        else{
            for(auto v:e[u]){
                if(dist[v.f][p]>(ll)dist[u][p]+(ll)v.s/(1<<p)){
                    dist[v.f][p]=(ll)dist[u][p]+(ll)v.s/(1<<p);
                    q.p(dist[v.f][p],v.f,bf,p);
                }
            }
        }
    }

}

