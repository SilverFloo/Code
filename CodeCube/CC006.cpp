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
ll tab[(int)1e6+5];
int main(){
    int n;
    cin>>n;
    ll sum=0;
    FOR1(i,n){
    scanf("%lld",&tab[i]);
    if(i%2)tab[i]=-tab[i];
    sum+=tab[i];
    tab[i]+=tab[i-1];
    }
    ll mn=0;
    ll ans=0;
    FOR1(i,n){
    ans=max(ans,tab[i]-mn);
    mn=min(mn,tab[i]);
    }
    printf("%lld",sum-ans-ans);
}


