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
enum{l,o,v,e,lo,ov,ve,lov,ove,love};
ll dp[100005][10];
int main(){
    //rf();
    int n;
    cin>>n;
    FOR1(i,n){
        char c;
        scanf(" %c",&c);
        FOR(j,10)dp[i][j]=dp[i-1][j];
        switch(c){
            case 'L':dp[i][l]++;
                    break;
            case 'O':dp[i][o]++;
                    dp[i][lo]+=dp[i-1][l];
                    break;
            case 'V':dp[i][v]++;
                    dp[i][ov]+=dp[i-1][o];
                    dp[i][lov]+=dp[i-1][lo];
                    break;
            case 'E':dp[i][e]++;
                    dp[i][ve]+=dp[i-1][v];
                    dp[i][ove]+=dp[i-1][ov];
                    dp[i][love]+=dp[i-1][lov];
        }
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        scanf("%d %d",&a,&b);
        ll x[10]={};
        FOR(i,10)x[i]=dp[b][i]-dp[a-1][i];
        x[ve]-=dp[a-1][v]*x[e];
        x[ove]-=dp[a-1][o]*x[ve]+dp[a-1][ov]*x[e];
        x[love]-=dp[a-1][l]*x[ove]+dp[a-1][lo]*x[ve]+dp[a-1][lov]*x[e];
        printf("%lld\n",x[love]);
    }
}
