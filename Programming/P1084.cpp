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
    ll x,y,k;
    scanf("%lld %lld %lld",&x,&y,&k);
    ll cnt=0;
    for(ll i=5;i<=x-1;i*=5){
        cnt+=(x-1)/i;
        cnt%=k;
    }
    ll ans=0;
    for(int i=x;i<=y;i++){
    int aa=i;
    while(aa%5==0){cnt++;aa/=5;}
    ans+=cnt;
    ans%=k;
    }
    printf("%lld",ans);
}
