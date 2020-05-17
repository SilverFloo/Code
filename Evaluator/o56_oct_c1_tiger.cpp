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
ii f[1005];
int x[1000005];
int cal(ii a,ii b){
return abs(a.f-b.f)+abs(a.s-b.s);
}
int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,n)scanf("%d %d",&f[i].f,&f[i].s);
    FOR(i,m){
        ii a;
        int ans=INF;
        scanf("%d %d",&a.f,&a.s);
        FOR(j,n){
            ans=min(ans,cal(a,f[j]));
        }
        x[ans]++;
    }
    int mx=0;
    FOR(i,1000005){
        mx=max(mx,x[i]);
    }
    printf("%d",mx);
}
