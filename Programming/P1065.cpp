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
    int n,m;
    cin>>n>>m;
    pair<ii,ii> a[n];
    FOR(i,n){
    scanf("%d %d %d %d",&a[i].f.f,&a[i].s.s,&a[i].f.s,&a[i].s.f);
    }
    FOR(i,m){
    ii x,y;
    scanf("%d %d %d %d",&x.f,&y.s,&x.s,&y.f);
    int cnt=0;
    FOR(j,n){
    if(a[j].f.f>=x.s||a[j].f.s<=x.f){continue;}
    if(a[j].s.f>=y.s||a[j].s.s<=y.f){continue;}
    cnt++;
    }
    printf("%d\n",cnt);
    }
}
