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
const ll LINF=1e18;
ll tab[100005];
int main(){
    int n;
    cin>>n;
    FOR1(i,n){
    ll a,b;
    scanf("%lld %lld",&a,&b);
    tab[i]=(ll)b-2*a;
    }

    sort(tab+1,tab+n+1,greater<ll>());
    FOR1(i,n)tab[i]+=tab[i-1];
    ll ans=-LINF;
    FOR(i,n+1){
    ans=max(ans,tab[i]-(ll)(n-i)*(n-i));
    }
    printf("%lld",ans);

}
