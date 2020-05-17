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
vector<int> lv[10005];
vector<int> e[100005];
int n,k,t;
int ans=-1;
bool have[100005];
bool visit[100005];
void make(int u){
    if(have[u])return;
    for(auto i:e[u]){
        if(!have[i]){
            if(visit[i]){printf("%d",ans);exit(0);}
            visit[i]=1;make(i);visit[i]=0;
        }
    }
    t--;
    have[u]=1;
}
int main(){
    cin>>n>>k>>t;
    FOR1(i,n){
        int l,p;
        scanf("%d %d",&l,&p);
        lv[l].pb(i);
        FOR(j,p){
        int a;
        scanf("%d",&a);
        e[i].pb(a);
        }
    }
    FOR1(i,k){
        for(auto j:lv[i]){
            visit[j]=1;
            make(j);
            visit[j]=0;
        }
        if(t<0){printf("%d",ans);return 0;}
        else ans=i;
    }
    printf("%d",ans);
}
