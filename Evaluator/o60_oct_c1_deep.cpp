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
int l[200005],r[200005];
int found[200005];
vector<int> line[200005];
void dfs(int u){
    //printf("%d ",u);
    if(l[u]==-1&&r[u]==-1)return;
    if(l[u]!=-1&&r[u]!=-1){
        dfs(l[u]);
        dfs(r[u]);
    }
    else{
        int walk=u;
        while(1){
            if(l[walk]==-1&&r[walk]==-1)break;
            if(l[walk]!=-1&&r[walk]!=-1)break;
            if(l[walk]!=-1)walk=l[walk];
            else walk=r[walk];
            line[u].pb(walk);
        }
        dfs(walk);
    }
}

int s,a,b;
int dir() {
 int res = ((s & 8) >> 3);
 s = (s * a + b) % 40507;
 return res;
}
void go(int u,int lv){
    //printf("%d %d/",u,lv);
    if(l[u]==-1&&r[u]==-1){printf("%d\n",u);return;}
    if(lv==0){printf("%d\n",u);return;}
    if(l[u]!=-1&&r[u]!=-1){
        if(!dir()){go(l[u],lv-1);}
        else go(r[u],lv-1);
    }
    else{
        if(lv>line[u].size()){
                //printf("aa");
            go(line[u][line[u].size()-1],lv-line[u].size());
        }
        else go(line[u][lv-1],0);
    }
}
int main(){
    int n,q;
    cin>>n>>q;
    FOR(i,n){
        scanf("%d %d",&l[i],&r[i]);
        found[l[i]]=1;
        found[r[i]]=1;
    }
    int root;
    FOR(i,n)if(found[i]==0){root=i;break;}
    dfs(root);
    while(q--){
        int lv;
        scanf("%d %d %d %d",&lv,&s,&a,&b);
        go(root,lv);
    }
}
