#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
#define pb emplace_back
#define p emplace
#define all(x) x.begin(),x.end()
#define ii pair<int,int>
#define ll long long
#define f first
#define s second
using namespace std;
vector<int> e[20005];
int deg[20005];
vector<int> child[20005];
int ans[20005];
struct x{
    int a,b,c;
    x(int a,int b,int c):a(a),b(b),c(c){}
};
vector<x> t1,t2,t3;
int par[20005];
int root(int i){
   while(par[par[i]]!=i){
    par[i]=par[par[i]];
    i=par[par[i]];
   }
   return i;
}

int main(){
    int n,w;
    cin>>n>>w;
    FOR1(i,n)par[i]=i;
    FOR(i,w){
        int t,a,b,c;
        scanf("%d %d %d %d",&t,&a,&b,&c);
        if(t==1){
           t1.pb(a,b,c);
        }
        if(t==2){
            t2.pb(a,b,c);
        }
        if(t==3){
            t3.pb(a,b,c);
        }
    }
    for(auto i:t3){
        par[root(i.b)]=root(i.a);
        par[root(i.c)]=root(i.a);
    }
    FOR1(i,n){
        child[root(i)].pb(i);
    }
    for(auto i:t2){
        e[root(i.a)].pb(root(i.b));
        e[root(i.a)].pb(root(i.c));
    }
    for(auto i:t1){
        e[root(i.b)].pb(root(i.a));
        e[root(i.c)].pb(root(i.a));
    }


    int st=-1;
    FOR1(i,n)sort(all(e[i]));
    FOR1(i,n){
        for(int j=0;j<e[i].size();j++){
            if(j>0&&e[i][j]==e[i][j-1])continue;
            deg[e[i][j]]++;
           // printf("<%d>",e[i][j]);
        }
    }
    //FOR1(i,n)printf("%d/",deg[i]);
    FOR1(i,n)if(deg[i]==0&&root(i)==i)st=i;
   // printf("<%d>",st);
    queue<int> q;
    q.p(st);
    int cnt=0;
    while(!q.empty()){

        int u=q.front(); //printf("%d",u);
        q.pop();
        for(int i=0;i<e[u].size();i++){
            if(i>0&&e[u][i]==e[u][i-1])continue;
            deg[e[u][i]]--;
            if(deg[e[u][i]]==0)q.p(e[u][i]);
        }
        ans[cnt]=u;
        cnt++;
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++){
        sort(all(child[ans[i]]));
        printf("%d ",child[ans[i]].size());
        for(auto j:child[ans[i]])printf("%d ",j);
        printf("\n");
    }
}
/*
30 min 20%
15 min 100%
->fix line 59,60 i.a to root(i.a)
*/
