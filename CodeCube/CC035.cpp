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
const int MAX=1e5+5;
vector<int> e[MAX];
bool visit[MAX];
int val[MAX];
vector<int> ti[MAX];

int main(){
    int n,m,k;
    cin>>n>>m>>k;k--;
    FOR(i,n)scanf("%d",&val[i]);
    FOR(i,m){
    int a,b;
    scanf("%d %d",&a,&b);a--;b--;
    e[a].pb(b);
    e[b].pb(a);
    }
    queue<ii> q;
    q.p(k,0);
    visit[k]=1;
    while(!q.empty()){
    int u=q.front().f;
    int t=q.front().s;
    q.pop();
    ti[t].pb(u);
    for(auto v:e[u]){
    if(!visit[v]){visit[v]=1;q.p(v,t+1);}
    }
    }
    priority_queue<int> x;
    ll ans=0;
    FOR(i,n)if(!visit[i])x.p(val[i]);
    for(int i=n;i>0;i--){
            //printf("%d",x.size());
    for(auto j:ti[i])x.p(val[j]);
    if(!x.empty()&&x.top()>0){ans+=x.top();x.pop();}
    }
    printf("%lld",ans);
}
