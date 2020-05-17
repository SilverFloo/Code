#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d>",a)
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
int tab[301][301];
int dp[301][301];

int main(){
    int n,m;
    cin>>m>>n;
    FOR(i,n){
        int a,b;
        cin>>a>>b;
        tab[a][b]++;
    }
    for(int l=1;l<=m;l++){
        for(int i=1;i<=m-l+1;i++){
            int j=i+l-1;
            for(int k=i;k<j;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
            dp[i][j]+=tab[i][j];
            //dp[i][j]=จำนวนงานที่เลือกได้มากที่สุดในช่อง i ถึง j
        }
    }
    printf("%d",n-dp[1][m]);
}
