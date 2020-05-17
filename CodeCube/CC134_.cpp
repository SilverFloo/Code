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
int a[30][2],b[30][2];
int main(){
    int n,m;
    cin>>n;
    FOR(i,n){
    int x;
    scanf("%d",&x);
    FOR(j,27){
        a[j][x%2]++;
        x/=2;
    }
    }
    cin>>m;
    FOR(i,m){
    int x;
    scanf("%d",&x);
    FOR(j,27){
        b[j][x%2]++;
        x/=2;
    }
    }
    ll ans=0;
    FOR(i,27){
       // printf("%d %d//",bb[i][0],bb[i][1]);
    ans+=(ll)(1<<i)*(ll)((ll)(a[i][0]*b[i][1])+(ll)(a[i][1]*b[i][0]));
    }
    printf("%lld",ans);
}
