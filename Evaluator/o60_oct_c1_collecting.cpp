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
int dist[50005][35];
int lv[50005];
vector<ii> edge[50005];
priority_queue<pair<int,ii>,vector<pair<int,ii>>,greater<pair<int,ii>>> q;
void add(int a,int b,int c){
    q.p(a,mp(b,c));
}
int main(){
    int n,m,l;
    cin>>n>>m>>l;
    int st,ed;
    cin>>st>>ed;
    FOR1(i,n){
        scanf("%d",&lv[i]);
    }
    FOR(i,m){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        edge[a].pb(b,c);
    }
    FOR1(i,n)FOR(j,l+1)dist[i][j]=INF;
    dist[st][0]=0;
    add(0,st,0);
    while(!q.empty()){
        int u=q.top().s.f;
        int st=q.top().s.s;
        int l=q.top().f;
        q.pop();
        if(l!=dist[u][st])continue;
        //printf("%d %d/",u,st);
        for(auto v:edge[u]){
            int newlv;
            if(lv[v.f]==st+1)newlv=st+1;
            else newlv=st;
            if(dist[v.f][newlv]>l+v.s){
                dist[v.f][newlv]=l+v.s;
                add(dist[v.f][newlv],v.f,newlv);
            }
        }
    }
    printf("%d",dist[ed][l]);
}
