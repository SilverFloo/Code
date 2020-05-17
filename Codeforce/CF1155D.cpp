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
using namespace std;
const int INF=1e9;
ll tab[300005];
ll sum[300005];
ll lr[300005];
ll rl[300005];
ll ans[300005];
int main(){
    int n,m;
    cin>>n>>m;
    FOR1(i,n)scanf("%lld",&tab[i]);
    FOR1(i,n)sum[i]=sum[i-1]+tab[i];
    ll mn=0;
    ll mx=max((ll)0,sum[n]);
    FOR1(i,n){
        lr[i]=max(sum[i]-mn,(ll)0);
        mn=min(mn,sum[i]);
    }
    for(int i=n;i>0;i--)sum[i]=tab[i]+sum[i+1];
    mn=0;
    for(int i=n;i>0;i--){
        rl[i]=max(sum[i]-mn,(ll)0);
        mn=min(mn,sum[i]);
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+tab[i]*m;
    }
    mn=0;

    for(int i=1;i<=n;i++){
        ans[i]=max(rl[i+1]+sum[i]-mn,(ll)0);
        mn=min(mn,sum[i]-lr[i]);
        mx=max(mx,ans[i]);
        //printf("%lld ",ans[i]);
    }
    printf("%lld",mx);

}
