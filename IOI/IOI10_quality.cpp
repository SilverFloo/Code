//#include "quality.h"
#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_bajck
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("_working/input.in","r",stdin)
#define pf() freopen("_working/output.out","w+",stdout)
using namespace std;
const int INF=1e9;
int tab[3005][3005];
int dp[3005][3005];
int rectangle(int n,int m,int a,int b,int x[3001][3001]){
    //rf();
    //int n,m,a,b;
    //cin>>n>>m>>a>>b;
    FOR1(i,n)FOR1(j,m)tab[i][j]=x[i-1][j-1];
    int l = 1, r = n*m;
    int ans=-1;
    while(l<=r){
       // printf("<%d %d>\n",l,r);
        int mid = (l+r)/2;
        FOR1(i,n)FOR1(j,m){
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(tab[i][j]<=mid?1:0);
        }
        int ch=0;
        for(int i=a;i<=n;i++){
            for(int j=b;j<=m;j++){
                int x = dp[i][j]-dp[i-a][j]-dp[i][j-b]+dp[i-a][j-b];
                //printf("%d ",x);
                if(x>=((a*b+1)/2)){
                    ch=1;break;
                }
                if(ch)break;
            }
        }
        if(ch)ans=mid,r=mid-1;
        else l=mid+1;
    }
    return ans;
}