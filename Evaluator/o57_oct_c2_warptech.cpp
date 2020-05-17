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
typedef struct edge{
    int u,v,w;
    edge(int u,int v,int w):u(u),v(v),w(w){}
    bool operator < (const edge &ot) const{
        return w<ot.w;
    }
}edge;
int par[5005];
int root(int i){
    while(i!=par[par[i]]){
        par[i]=par[par[i]];
        i=par[par[i]];
    }
    return i;
}
vector<edge> e;
vector<ii> query;
int ans[5005];
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    FOR(i,m){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        e.pb(a,b,c);
    }
    FOR(i,n)par[i]=i;
    sort(all(e));
    FOR(i,q){
        int a;
        scanf("%d",&a);
        query.pb(a,i);
    }
    sort(all(query),greater<ii>());
    int pos=0;
    int cnt=n;
    for(auto i:e){
        if(root(i.u)!=root(i.v)){
            par[root(i.u)]=root(i.v);
            cnt--;
            while(pos<query.size()&&query[pos].f==cnt){
                ans[query[pos].s]=i.w;
                pos++;
            }
        }
    }
    for(int i=0;i<q;i++){
        printf("%d\n",ans[i]);
    }


}
