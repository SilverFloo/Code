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
ll gcd(ll a,ll b){
if(a%b==0)return b;
return gcd(b,a%b);
}
ll lcm(ll a,ll b){
if(a>b)return a*b/gcd(a,b);
else return a*b/gcd(b,a);
}
int main(){
    ll g=1;
    int n;
    cin>>n;
    FOR(i,n){
    ll a;
    scanf("%lld",&a);
    g=lcm(a,g);
    }
    printf("%lld",g);
}
