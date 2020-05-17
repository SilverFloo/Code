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
int tab[200005];
int dp[200005];
int n;
int main(){
    cin>>n;
    FOR(i,n)scanf("%d",&tab[i]);
    int ans=0;
    FOR(i,n){
        if(ans==0){
        ans++;
        dp[0]=tab[i];
        continue;
        }
        int l=0,r=ans-1;
        int p=-1;
        while(l<=r){
            int m=(l+r)/2;
            if(tab[i]>dp[m])p=m,l=m+1;
            else r=m-1;
        }
        p++;
        dp[p]=tab[i];
        if(p==ans)ans++;
    }

    printf("%d",ans);
}
