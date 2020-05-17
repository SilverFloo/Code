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
int cnt[(int)1e6+5];
int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    FOR(i,n)FOR(j,m)scanf("%d",&a[i][j]);
    FOR(i,n)sort(a[i],a[i]+m);
    FOR(i,m){
    int p,mx=0;
    FOR(j,n){
    if(a[j][i]>mx)mx=a[j][i],p=j;
    }
    cnt[p]++;
    }
    int mx=0,p;
    FOR(i,n){
    if(cnt[i]>mx)mx=cnt[i],p=i;
    }
    printf("%d",p+1);
}
