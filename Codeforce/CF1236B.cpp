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
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
ll mod = 1e9+7;
int main(){
    int n,m;
    cin>>n>>m;
    ll ans=1;
   ll two = 2;
    while(m!=0){
        if(m%2){
            ans*=two;
            ans%=mod;
        }
        two*=two;
        two%=mod;
        m>>=1;
    }
    ans--;
    ans=(ans+mod)%mod;
    ll aans=1;
    while(n!=0){
        if(n%2){
            aans*=ans;
            aans%=mod;
        }
        ans*=ans;
        ans%=mod;
        n>>=1;
    }
    printf("%lld",aans);

}
