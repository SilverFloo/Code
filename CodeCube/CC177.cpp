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
const int INF=1e9+7;
const int MAX=1e3+5;
int ans[MAX][MAX];
bool go[MAX][MAX];
int main(){
    int n,m;
    cin>>n>>m;
    FOR1(i,n)FOR1(j,m)scanf("%d",&go[i][j]);
    ans[1][1]=1;
    FOR1(i,n)FOR1(j,m)
    if(!go[i][j])ans[i][j]+=(ans[i-1][j]+ans[i][j-1])%INF;
    printf("%d",ans[n][m]);
}
