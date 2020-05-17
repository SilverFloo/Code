#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>

const int MAX = 1e5+5;
int lv[MAX],par[MAX],cost[MAX],val[MAX],deg[MAX];

int main(){
    int n,m;
    long long ans = 0;
    cin>>n>>m;
    for(int i = 0; i < n ; i++){
        scanf("%d %d %d", &par[i], &cost[i], &lv[i]);
        deg[par[i]]++;
    }
    priority_queue<ii, vector<ii>, greater<ii>> q;
    for(int i = 0; i < n ; i++){
        if(deg[i] == 0)q.push({cost[i], i});
    }
    while(!q.empty()){
        int u = q.top().second;

        q.pop();
        if(val[u]+cost[u] <= m) val[u] += cost[u];
        ans = max(ans, (long long)val[u]*lv[u]);
        if(val[par[u]]+cost[u] <= m) val[par[u]]+=cost[u];
        deg[par[u]]--;
        if(deg[par[u]] == 0 && par[u] != 0)q.push({val[par[u]], par[u]});
        printf("%d %d\n",u,val[u]);
    }
    printf("%lld", ans);
}
