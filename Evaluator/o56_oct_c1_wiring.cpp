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
bool visit[100005];
vector<int> edge[100005];
int st=0;
void dfs(int u,int par){
    //printf("%d->",u);
    if(visit[u]){st=1;return;}
    visit[u]=1;
    for(auto i:edge[u])if(i!=par)dfs(i,u);
}
int main(){
    int x;
    cin>>x;
    while(x--){

        int n;
        int m[100005];
        cin>>n;
        FOR1(i,n)visit[i]=0,edge[i].clear();
        st=0;
        FOR1(i,n){
            int a;
            scanf("%d",&a);
            if(a!=0)m[a]=i;
        }
        FOR1(i,n){
            int a;
            scanf("%d",&a);
            if(a==0)continue;
            edge[m[a]].pb(i);
            edge[i].pb(m[a]);
        }

        FOR1(i,n){
            if(!visit[i]&&!edge[i].empty()){
                dfs(i,i);
                if(st)break;
            }
        }
        if(!st)printf("YES\n");
        else printf("NO\n");
    }
}
