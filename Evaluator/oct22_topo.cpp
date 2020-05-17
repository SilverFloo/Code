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
int deg[100005];
vector<int> edge[100005];
int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,m){
        int a,b;
        scanf("%d %d",&a,&b);
        edge[a].pb(b);
        deg[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0)q.p(i);
    }
    int cnt=n;
    vector<int> ans;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ans.pb(u);
        cnt--;
        for(auto v:edge[u]){
            deg[v]--;
            if(deg[v]==0)q.p(v);
        }
    }
    if(cnt!=0)printf("no");
    else for(auto i:ans)printf("%d\n",i);
}
