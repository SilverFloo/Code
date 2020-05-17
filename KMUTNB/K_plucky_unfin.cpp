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
const int INF=2e9+5;
const ll LINF=2e18+5;
vector<ii> tab[10][10][2];
stuct pos{
int a,b,c,d;
}
int x[100005];
cmp1(pos a,pos b){
return pos a
}
int main(){
    int r,c,n,m;
    cin>>r>>c>>n>>m;
    FOR(i,n){scanf("%d %d %d %d",&x.a,&x.b,&x.c,&x.d);}
    sort(x,x+n,cmp1);
    FOR(i,n){
    for(int j=x[i].a;j<x[i].b;j++)tab[i][j].pb(x[i].c,x[i].d);
    }
    sort(x,x+n,cmp2);
    FOR(i,n){
    for(int j=x[i].a;j<x[i].b;j++)tab[i][j].pb(x[i].c,x[i].d);
    }


}
