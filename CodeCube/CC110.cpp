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
double dist(ii a,ii b){
return sqrt((double)(a.f-b.f)*(a.f-b.f)+(double)(a.s-b.s)*(a.s-b.s));
}
int main(){
    int n,m;
    cin>>n>>m;
    ii a[n],b[m];
    FOR(i,n){
    scanf("%d %d",&a[i].f,&a[i].s);
    }
    FOR(i,m){
    scanf("%d %d",&b[i].f,&b[i].s);
    }
    double mx=0;
    FOR(i,n){
    double mn=4e9;
    FOR(j,m){
    mn=min(mn,dist(a[i],b[j]));
    }
    mx=max(mx,mn);
    }
    printf("%.4f",mx);
}
