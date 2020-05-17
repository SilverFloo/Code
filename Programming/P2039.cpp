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
int n, m;
ll ans = 0;
vector<int> dfs(int u){
    if(e[u].size() == 0){
        ans = max(ans,(ll)lv[u]);
        vector<int> x;
        x.pb(pr[u]);
        return x;
    }
    priority_queue<int,vector<int>,greater<int>> q;
    for(auto v : e[u]){
        vector<int> x = dfs(v);
        for(auto i:x) q.p(i);
    }
    int now = m;
    int cnt = 0;
    vector<int> x;
    q.p(pr[u]);
    while(!q.empty()){
        if(now - q.top() >= 0) {
            now -= q.top();
            x.pb(q.top());
            q.pop();
            cnt++;
        }
        else break;
    }
    //if(now-pr[u] >= 0) cnt++;
    //printf("/%d %d %d %d\n",u,cnt,lv[u],now);
    ans = max(ans, (ll)cnt*lv[u]);
    return x;
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
    dfs(st);
    printf("%lld", ans);
}
