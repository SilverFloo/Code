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
vector<ii> e[100005];
bool visit[100005];
int val[100005];
int main(){
    int n,m;
    cin>>n>>m;

    FOR(i,n-1){
    int a,b,w;
    scanf("%d %d %d",&a,&b,&w);
    e[a].pb(b,w);
    e[b].pb(a,w);
    }
    queue<int> q;
    q.p(1);
    while(!q.empty()){
    int u=q.front();
    q.pop();
    visit[u]=1;
    for(auto v:e[u]){
    if(!visit[v.f]){val[v.f]=val[u]^v.s;q.p(v.f);}
    }
    }
    //FOR(i,n)printf("%d>",val[i]);
    FOR(i,m){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",val[a]^val[b]);
    }

}
