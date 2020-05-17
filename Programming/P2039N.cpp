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
vector<int> e[100005];
int pr[100005];
int lv[100005];
priority_queue<int,vector<int>,greater<int>> q[100005];
int n, m;
ll ans = 0;
void dfs(int u,int parent){
    if(e[u].size() == 0){
        ans = max(ans,(ll)lv[u]);
        q[parent].p(pr[u]);
        return ;
    }

    for(auto v : e[u]){
        dfs(v,u);
    }
    int now = m;
    int cnt = 0;
    q[u].p(pr[u]);
    while(!q[u].empty()){
        if(now - q[u].top() >= 0) {
            now -= q[u].top();
            q[parent].p(q[u].top());
            q[u].pop();
            cnt++;
        }
        else break;
    }
    //if(now-pr[u] >= 0) cnt++;
    //printf("/%d %d %d %d\n",u,cnt,lv[u],now);
    ans = max(ans, (ll)cnt*lv[u]);
    //return x;
}
int main(){
    cin>>n>>m;
    int st=-1;
    for(int i = 1; i <= n; i++){
        int b;
        scanf("%d %d %d", &b, &pr[i], &lv[i]);
        if(b == 0) st = i;
        else e[b].pb(i);
    }
    dfs(st,0);
    printf("%lld", ans);
}
