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
vector<ii> st[100005];
vector<ii> ed[100005];
int cnt[200005];
int ans[100005];
int tab[100005];
map<int,int> M;
int main(){
    int n,q;
    cin>>n>>q;
    FOR1(i,n){
    scanf("%d",&tab[i]);
    M[tab[i]]=1;
    }
    int cc=0;
    FOR(i,q){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        st[a].pb(c,i);
        ed[b].pb(c,i);
        M[c]=1;
    }
    for(auto &i:M)i.s=cc++;
    FOR1(i,n){
    for(auto j:st[i]){
        ans[j.s]-=cnt[M[j.f]];
    }
    cnt[M[tab[i]]]++;
    for(auto j:ed[i]){
      ans[j.s]+=cnt[M[j.f]];
    }
    }
    FOR(i,q)printf("%d\n",ans[i]);

}
