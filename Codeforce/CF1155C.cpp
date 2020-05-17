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
int main(){
    int n,m;
    cin>>n>>m;
    ll gcd;
    FOR(i,n){
        scanf("%lld",&tab[i]);
    }
    gcd=tab[1]-tab[0];
    for(int i=2;i<n;i++)gcd=__gcd(gcd,tab[i]-tab[i-1]);
    FOR(i,m){
        ll x;
        scanf("%lld",&x);
        if(gcd%x==0){printf("YES\n%lld %d",tab[0],i+1);return 0;}
    }
    printf("NO");

}
