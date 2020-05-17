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
int main(){
    int n;
    cin>>n;
    int tab[n];
    FOR(i,n)scanf("%d",&tab[i]);
    ll ans=0;
    FOR(i,n)FOR(j,i){
        ans+=abs(tab[i]-tab[j]);
        ans%=49999;
    }
    if(n==2){printf("%lld",ans);return 0;}
    ll rans=0;
    FOR(i,n-2){
        rans+=ans;
        rans%=49999;
    }
    printf("%lld",rans);
}
