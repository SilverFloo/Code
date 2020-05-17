#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
double tab[20][20];
double dp[(1<<20)+5];
vector<int> x[21];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)scanf("%lf",&tab[i][j]);
    }
    FOR(i,1<<n){
        int j=i;
        int cnt=0;
        while(j!=0){
            if(j%2)cnt++;
            j/=2;
        }
        x[cnt].pb(i);
    }
    dp[0]=1;
    FOR1(i,n){
        for(auto j:x[i]){
            for(int k=0;k<n;k++){
                if(j&(1<<k)){
                    if(dp[j]==0||(dp[j]<dp[j&(~(1<<k))]*tab[k][i-1]/100))dp[j]=dp[j&(~(1<<k))]*tab[k][i-1]/100;
                }
            }
        }
    }
    printf("%f",dp[(1<<n)-1]*100);
}
