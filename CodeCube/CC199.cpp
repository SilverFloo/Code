#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
struct edge{
    int u,v,p;
    ll w;
};
bool cmp(edge a,edge b){
    return a.w>b.w;
}
int par[100005];
edge e[100005];
int root(int i){
    while(i!=par[par[i]]){
        par[i]=par[par[i]];
        i=par[par[i]];
    }
    return i;
}
vector<int> ans;
int main(){
    int n,m;
    cin>>n>>m;
    if(m==n-1){printf("-1");return 0;}
    FOR1(i,n)par[i]=i;
    FOR1(i,m){
        scanf("%d %d %lld",&e[i].u,&e[i].v,&e[i].w);
        e[i].p=i;
    }
    sort(e+1,e+m+1,cmp);
    int ch=1;
    ll cnt=0;
    int xx=0;
    int x;
    cin>>x;
    FOR1(i,m){
        if(root(e[i].u)!=root(e[i].v)){
            par[root(e[i].u)]=root(e[i].v);
            ans.pb(e[i].p);
            cnt+=e[i].w;
            xx++;
        }
        else{
            if(ch){
                ans.pb(e[i].p);
                cnt+=e[i].w;
                ch=0;
            }
        }
    }

    if(xx!=n-1){printf("-1");return 0;}
    printf("%lld\n",cnt);
    if(x==2)for(auto i:ans)printf("%d ",i);
}
