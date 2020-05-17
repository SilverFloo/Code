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
const int MAX=1e5+5;
long long a[MAX],b[MAX];
int main(){
    int n,w,h;
    cin>>n>>w>>h;
    FOR1(i,n){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    FOR1(i,n){
        scanf("%lld",&b[i]);
        b[i]+=b[i-1];
    }
    ll mx1=0,mx2=0;
    for(int i=w;i<=n;i++){
        mx1=max(mx1,a[i]-a[i-w]);
    }
    for(int i=h;i<=n;i++){
        //printf("%lld>",b[i]-b[i-h]);
        mx2=max(mx2,b[i]-b[i-h]);
    }
    //printf("%lld %lld\n",mx1,mx2);
    ll ans1=mx1*h+mx2*w;
    printf("%lld",ans1);
}
