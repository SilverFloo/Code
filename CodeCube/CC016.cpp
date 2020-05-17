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
    int tab[2*n];
    FOR(i,2*n)scanf("%d",&tab[i]);
    sort(tab,tab+2*n);
    ll ans=0;
    FOR(i,n){
    ans+=(ll)tab[i]*tab[2*n-i-1];
    }
    printf("%lld",ans);
}
