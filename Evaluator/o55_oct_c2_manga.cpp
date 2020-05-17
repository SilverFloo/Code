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
const int INF=1e9;
vector<pair<int,ii>> e[50005];
int dist[50005];
int n,m,k;
int find(int x){
    priority_queue<ii,vector<ii>,greater<ii> >q;
    FOR1(i,n)dist[i]=INF;
    dist[1]=0;
    q.p(dist[1],1);
    while(!q.empty()){
        int l=q.top().f;
        int u=q.top().s;
        q.pop();
        if(l!=dist[u])continue;
        for(auto v:e[u]){
            if(v.f>x)break;
            if(dist[u]+v.s.s<dist[v.s.f]){
                dist[v.s.f]=dist[u]+v.s.s;
                q.p(dist[v.s.f],v.s.f);
            }
        }
    }
    return dist[n];
}
int main(){
    cin>>n>>m>>k;
    FOR1(i,m){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        e[a].pb(i,mp(b,c));
        e[b].pb(i,mp(a,c));
    }
    int ans=-1;
    int l=0,r=m;
    while(l<=r){
        int m=(l+r)/2;
        if(find(m)<=k){
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }
    printf("%d",ans);
}
