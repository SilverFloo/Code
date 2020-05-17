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
int tab[500005];
int main(){
    int n,k;
    cin>>n>>k;
    FOR(i,n)scanf("%d",&tab[i]);
    int l=1;int r=5e6;
    int ans=INF;
    while(l<=r){
        int m=(l+r)/2;
        int cnt=0;
        FOR(i,n)cnt+=ceil(float(tab[i])/m);
        //printf("<%d->%d>",m,cnt);
        if(cnt<=k)ans=min(ans,m),r=m-1;
        else l=m+1;
    }
    printf("%d",ans);


}
