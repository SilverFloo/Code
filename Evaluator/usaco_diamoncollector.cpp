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
int tab[50005],dp[50005];
int main(){
    int n,k;
    cin>>n>>k;
    FOR1(i,n){scanf("%d",&tab[i]);}
    sort(tab,tab+n);
    for(int i=2;i<=n;i++){
        if(tab[i]-tab[i-1]>=k)dp[i]=dp[i-1];
        else{
            dp[i]=max(dp[i-1],1+dp[i-2]);
        }
        printf("%d %d\n",tab[i],dp[i]);
    }
    printf("%d",dp[n]);
}
