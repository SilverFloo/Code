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
int cnt[1000005];
int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,n){
    int x;
    scanf("%d",&x);
    cnt[x]++;
    }
    ll ans=0;
    FOR(i,m/2+1){
    if(i==(m+1)/2&&cnt[i]>0)ans+=(ll)(cnt[i]*(cnt[i]-1))/2;
    else ans+=(ll)cnt[i]*cnt[m-i];
    }
    printf("%lld",ans);

}
