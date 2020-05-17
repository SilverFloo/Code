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
ll tab[1000005];
int main(){
    int n,m;
    cin>>n>>m;
    FOR1(i,n)scanf("%lld",&tab[i]),tab[i]+=tab[i-1];
    ll mn=1e18;
    ll ans=-1e18;
    for(int i=m;i<=n;i++){
           // printf("%lld\n",tab[]);
    mn=min(mn,tab[i-m]);
    ans=max(ans,tab[i]-mn);
    }
    printf("%lld",ans);
}

