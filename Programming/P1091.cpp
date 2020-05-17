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
const int MAX=3e5+5;
vector<int> e[MAX];
int dist[MAX];
int main(){
int n;
cin>>n;
    FOR(i,n-1){
    int a,b;
    scanf("%d %d",&a,&b);
    if(a>b)swap(a,b);
    e[a].pb(b);
    }
    int ans=0;
    FOR1(i,n){
    for(auto j:e[i])if(dist[j]<dist[i]+1)dist[j]=dist[i]+1;
    ans=max(ans,dist[i]);
    }
    printf("%d",ans+1);
}
