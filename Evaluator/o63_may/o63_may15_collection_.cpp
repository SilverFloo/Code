#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("_working/input.in","r",stdin)
#define pf() freopen("_working/output.out","w+",stdout)
using namespace std;
const ll INF=1e18;
ll val[100005];
vector<int> e[100005];
int par[100005];
pair<ll,ll> dp[100005];
map<int,int> mp[100005];
class segtree{
    pair<ll,ll>* t;
    int n;
    public : 
        void init(int x){
            n=x;
            t=(pair<ll,ll>*)malloc(((n+1)*sizeof(pair<ll,ll>))<<2);
            FOR1(i,n<<2)t[i]={-INF,-INF};
        }
        pair<ll,ll> getmax(pair<ll,ll> a,pair<ll,ll> b){
            pair<ll,ll> tmp;
            if(a.f>b.f){
                tmp.s = max(a.s,b.f);
            }
            else{
                tmp.s = max(a.f,b.s);
            }
            tmp.f = max(a.f,b.f);
            return tmp;
        }
        void update(int x,ll v,int p,int l ,int r){
            if(l==r){
                t[p].f=v;
                return;
            }
            int m=(l+r)/2;
            if(x<=m)update(x,v,p<<1,l,m);
            else update(x,v,p<<1|1,m+1,r);
            t[p] = getmax(t[p<<1],t[p<<1|1]);
        }
        pair<ll,ll> query(){
            return t[1];
        }
};
segtree treef[100005],trees[100005];
void dfs(int u){
    for(auto v:e[u]){
        if(v!=par[u]){
            par[v]=u;
            dfs(v);
        }
    }
}
void init(int u){
    pair<ll,ll> mx={0,0};
    treef[u].init(e[u].size()-1);
    trees[u].init(e[u].size()-1);
    int ptr=0;
    for(auto v:e[u]){
        if(v!=par[u]){
            init(v);
            mp[u][v]=ptr++;
            treef[u].update(mp[u][v],dp[v].f,1,0,e[u].size()-1);
            trees[u].update(mp[u][v],dp[v].s,1,0,e[u].size()-1);
        }
    }
    if(e[u].size()>1){
        mx = treef[u].query();
        mx.f=max(mx.f,0LL);
        mx.s=max(mx.s,0LL);
        dp[u].s = max(trees[u].query().f,mx.f+mx.s+val[u]);
        dp[u].f = mx.f+val[u];
    }
    else{
        dp[u].f = val[u];
        dp[u].s = val[u];
    }
    //printf("<%d %lld %lld>",u+1,dp[u].f,dp[u].s);
}
void change(int u,int bf=-1){
    if(u==-1)return;
    pair<ll,ll> mx={0,0};
    if(bf!=-1){
        treef[u].update(mp[u][bf],dp[bf].f,1,0,e[u].size()-1);
        trees[u].update(mp[u][bf],dp[bf].s,1,0,e[u].size()-1);
    }
    if(e[u].size()>1){
        mx = treef[u].query();
        mx.f=max(mx.f,0LL);
        mx.s=max(mx.s,0LL);
        dp[u].s = max(trees[u].query().f,mx.f+mx.s+val[u]);
        dp[u].f = mx.f+val[u];
    }
    else{
        dp[u].f = val[u];
        dp[u].s = val[u];
    }
    //printf("<%d %lld %lld>",u+1,dp[u].f,dp[u].s);
    change(par[u],u);
}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        scanf("%lld",&val[i]);
        dp[i]={-INF,-INF};
    }
    FOR(i,n-1){
        int a,b;
        scanf("%d %d",&a,&b);
        e[a-1].pb(b-1);
        e[b-1].pb(a-1);
    }
    e[0].pb(-1);
    par[0]=-1;
    dfs(0);
    init(0);
    printf("%lld\n",max(dp[0].f,dp[0].s));
    FOR(i,q){
        int a; ll b;
        scanf("%d %lld",&a,&b);
        a--;
        val[a]=b;
        change(a);
        printf("%lld\n",max(dp[0].f,dp[0].s));
    }
}