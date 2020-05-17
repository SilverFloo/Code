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
int main(){
    int t;
    cin>>t;
    ll M;
    scanf("%lld",&M);
    FOR(i,t-1){
    ll x;
    scanf("%lld",&x);
    M=gcd(max(M,x),min(M,x));
    }
    int cnt=0;
    for(int i=1;i<=sqrt(M);i++){
        if(M%i==0)cnt+=2;
    }
    if(M%(ll)sqrt(M)==0)cnt--;
    printf("%d",cnt);
}
