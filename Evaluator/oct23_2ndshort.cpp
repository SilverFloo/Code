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
vector<ii> edge1[10005],edge2[10005];
int dist1[10005],dist2[10005];
int main(){
    int n,m;
    cin>>n>>m;
    int st,ed;
    cin>>st>>ed;
    FOR(i,m){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        edge1[a].pb(b,c);
        edge2[b].pb(a,c);
    }
    FOR1(i,n)dist1[i]=INF,dist2[i]=INF;
    dist1[st]=0;
    dist2[ed]=0;
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.p(0,st);
    while(!q.empty()){
        int l=q.top().f;
        int u=q.top().s;
        q.pop();
        if(dist1[u]!=l)continue;
        for(auto v:edge1[u]){
            if(dist1[v.f]>dist1[u]+v.s){
                dist1[v.f]=dist1[u]+v.s;
                q.p(dist1[v.f],v.f);
            }
        }
    }
    q.p(0,ed);
    while(!q.empty()){
        int l=q.top().f;
        int u=q.top().s;
        q.pop();
        if(dist2[u]!=l)continue;
        for(auto v:edge2[u]){
            if(dist2[v.f]>dist2[u]+v.s){
                dist2[v.f]=dist2[u]+v.s;
                q.p(dist2[v.f],v.f);
            }
        }
    }
    int ans=INF;
    FOR1(i,n){
        for(auto j:edge1[i]){
           // printf("%d %d %d %d %d\n",i,j.f,dist1[i],dist2[j.f],j.s);
            int x=dist1[i]+j.s+dist2[j.f];
            if(x!=dist1[ed])ans=min(ans,x);
        }
    }
    printf("%d",ans);
}
