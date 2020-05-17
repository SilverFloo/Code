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
int st[5][100005];
int val[100005];
vector<int> edge[100005];
bool visit[100005];
int ans=-1;
void dfs(int u){
    visit[u]=1;
    int mx11=-1,mx12=-1,mx21=-1,mx22=-1,mx31=-1,mx32=-1,p1,p3;
    st[0][u]=val[u];
    for(auto v:edge[u]){
        if(!visit[v]){
                dfs(v);
            FOR1(i,4)st[i][u]=max(st[i][u],st[i-1][v]);
            if(st[0][v]>=mx11){
                mx12=mx11;
                mx11=st[0][v];
                p1=v;
            }
            if(st[2][v]>=mx31){
                mx32=mx31;
                mx31=st[2][v];
                p3=v;
            }
            if(st[1][v]>=mx21){
                mx22=mx21;
                mx21=st[1][v];
            }
        }
        ans=max(ans,st[4][u]+st[0][u]);
        if(mx11!=-1&&mx31!=-1){
            if(p1!=p3)ans=max(ans,mx11+mx31);
            else{
                if(mx12!=-1){
                    ans=max(ans,mx12+mx31);
                }
                if(mx32!=-1){
                    ans=max(ans,mx32+mx11);
                }
            }
        }
        if(mx21!=-1&&mx22!=-1)ans=max(ans,mx21+mx22);
    }
    //printf("%d->%d %d %d %d %d(%d)\n",u,st[0][u],st[1][u],st[2][u],st[3][u],st[4][u],ans);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        FOR1(i,n)FOR(j,5)st[j][i]=-INF;
        FOR1(i,n)edge[i].clear(),visit[i]=0;
        FOR1(i,n)scanf("%d",&val[i]);
        FOR(i,n-1){
            int a,b;
            scanf("%d %d",&a,&b);
            edge[a].pb(b);
            edge[b].pb(a);
        }
        ans=-1;
        dfs(1);
        printf("%d\n",ans);
    }
}
