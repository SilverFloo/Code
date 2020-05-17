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
int dp[(int)1e6+5];
const int INF=1e9;
int main(){
    int n;
    cin>>n;
    FOR1(i,n){
    int a;
    scanf("%1d",&a);
    if(a==0)dp[i]=dp[i-1]-1;
    else dp[i]=dp[i-1]+1;
    }
    sort(dp,dp+n+1);
    int ans=0;
    int cnt=1;
    dp[n+1]=INF;
    FOR(i,n+1){
        if(dp[i]==dp[i+1]){cnt++;}
        else{
              //  printf("%d :%d \n",dp[i],cnt);
            ans+=(cnt)*(cnt-1)/2%10007;
            ans%=10007;
            cnt=1;
        }
    }
    printf("%d",ans);
}
