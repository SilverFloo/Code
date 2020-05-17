#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9;
vector<int> e[100005];
vector<int> re[100005];
bool close[100005];
ii qu[200005];
int ans[200005];
bool st[100005],ed[100005];
void open(int u){
    st[u]=1;
    for(auto v:e[u])if(!close[v]&&st[v]==0){
        open(v);
    }
}
void ropen(int u){
    ed[u]=1;
    for(auto v:re[u])if(!close[v]&&ed[v]==0){
        ropen(v);
    }
}
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    FOR(i,m){
        int a,b;
        scanf("%d %d",&a,&b);
        e[a].pb(b);
        re[b].pb(a);
    }
    FOR(i,q){
        scanf("%d %d",&qu[i].f,&qu[i].s);
        if(qu[i].f==1)close[qu[i].s]=1;
    }
    st[1]=1;
    open(1);
    ed[n]=1;
    ropen(n);
    for(int i=q-1;i>=0;i--){
        if(qu[i].f==1){
            close[qu[i].s]=0;/*
            FOR1(j,n){
                printf("%d ",st[j]);
            }
            cout<<endl;*/

            int s=0;
            for(auto v:re[qu[i].s]){
                if(st[v]==1){s=1;break;}
            }
            if(s)open(qu[i].s);
            s=0;
            for(auto v:e[qu[i].s]){
                if(ed[v]==1){s=1;break;}
            }
            if(s)ropen(qu[i].s);
            ans[i]=-1;
        }
        else{
            if(st[qu[i].s]&&ed[qu[i].s])ans[i]=1;
            else ans[i]=0;
        }
    }
    for(int i=0;i<q;i++){
        if(ans[i]!=-1)printf("%d\n",ans[i]);
    }

}
