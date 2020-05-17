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
int a[150005];
int main(){
    int n;
    cin>>n;
    FOR(i,n)scanf("%d",&a[i]);
    sort(a,a+n,greater<int>());
    int t=n/5;
    ll ans=0;
    for(int i=0;i<n;i++){
    ans+=(ll)a[i];
    if(t>0)t--,i++;
    }
    printf("%lld",ans);

}






