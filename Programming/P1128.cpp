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
    int val[n];
    FOR(i,n)scanf("%d",&val[i]);
    ll p=2,x=1;
    ll ans=0;

    for(int i=n-1;i>=0;i--){
        ans+=val[i]*x;
        ans%=2553;
    x+=p;
    x%=2553;
    p++;
    }
   printf("%lld",ans);

}
