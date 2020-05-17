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
int tab[1005][1005];
int val[1005][1005];
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,ii>> s;
    FOR(i,n){FOR(j,m){
        scanf("%d",&tab[i][j]);
        s.pb(tab[i][j],ii(i,j));
    }}
    int ans=0;
    sort(s.begin(),s.end(),greater<pair<int,ii>>());
    for(auto x:s){

    int i=x.s.f;
    int j=x.s.s;
    if(ans<val[i][j])ans=val[i][j];
        if(i>0)if(tab[i-1][j]<tab[i][j])val[i-1][j]=max(val[i-1][j],val[i][j]+1);
        if(i<n-1)if(tab[i+1][j]<tab[i][j])val[i+1][j]=max(val[i+1][j],val[i][j]+1);
        if(j<m-1)if(tab[i][j+1]<tab[i][j])val[i][j+1]=max(val[i][j+1],val[i][j]+1);
        if(j>0)if(tab[i][j-1]<tab[i][j])val[i][j-1]=max(val[i][j-1],val[i][j]+1);
    }
    printf("%d",ans+1);
}
