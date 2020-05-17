#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<long long,long long>
#define ll long long
using namespace std;
const int INF=1e9;
int cnt=0;
ll gcd(ll a,ll b){
if(a%b==0)return b;
a%=b;
return gcd(b,a);
}
ll lcm(ll a,ll b){
return a>b?a*b/gcd(a,b):a*b/gcd(b,a);
}
ii plu(ii a,ii b){
ii c;
c.s=lcm(a.s,b.s);
c.f=a.f*c.s/a.s+b.f*c.s/b.s;
return c;
}
ii low(ii a){
    if(a.f==0)return ii(0,1);
ll x=gcd(a.s,a.f);
a.s/=x;a.f/=x;
return a;
}
int main(){
    int  n;
    cin>>n;
    ii ans(0,1);
    FOR(i,n){
    ii a;
    char c;
    scanf("%lld%c%lld",&a.f,&c,&a.s);
    ans = plu(ans,a);
    ans=low(ans);
    }
    cnt=ceil((double)ans.f/ans.s);
    ans.f%=ans.s;
    ans=low(ans);
    if(ans.f==0)printf("%d\n0",cnt);
    else printf("%d\n%lld/%lld",cnt,ans.s-ans.f,ans.s);
}

