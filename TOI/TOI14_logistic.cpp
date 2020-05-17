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
typedef struct node{
    int u,w,f,c;
    bool operator > (const node &ot)const{
        return w<ot.w;
    }
    node(int u,int w,int f,int c):u(u),w(w),f(f),c(c){}
}node;
int dist[105][105][2];
int price[105];
vector<pair<int,int>> edge[105];
int main(){
    int s,d,F;
    cin>>s>>d>>F;
    FOR(i,n)scanf("%d",&price[i]);
    int m;
    FOR(i,m){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    e[a].pb(b,c);
    e[b].pb(a,c);
    }
    priority_queue<node> q;
    q.pb(s,0,0,0);
    while(!q.empty()){
        int u=q.top().u;
        int w=q.top().w;
        int f=q.top().f;
        int c=q.top().c;

        if(c==0){
            if(dist[u][F][1]>w){
                dist[u][F][1]=w;
                q.pb(u,F,w,1);
            }
        }
        if(f<F){
            if(dist[u][f+1][c] > w+price[u]){
                dist[u][f+1][c] = w+price[u];
            }
        }
        for(auto v : edge[u]){
            if(v.s<=f){

            }
        }
    }
}
