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
int dp[2005];
bool rain[2005];
ii u[2000];
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    FOR(i,a){
        int x,y;
        cin>>x>>y;
        for(int j=x;j<=y;j++)rain[i]=1;
    }
    FOR(i,b){
        scanf("%d %d",&u[i].f,&u[i].s);
    }
    sort(u,u+b);
    FOR(i,n+1){
        if(rain[i]){


        }
        else{
            if(i!=0)dp[i]=dp[i-1];
        }
    }
}
