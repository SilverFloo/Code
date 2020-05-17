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
int tab[10005];
int main(){
    int n,k;    cin>>n>>k;
    int l=0,r=2e9;
    FOR(i,n){scanf("%d",&tab[i]);l=max(l,tab[i]);}

    int ans=-1;
    while(l<=r){
        int cnt=1;
        int tmp=0;
        int m=(l+r)/2;
        for(int i=0;i<n;i++){
            if(tmp+tab[i]<=m)tmp+=tab[i];
            else tmp=tab[i],cnt++;
        }
        //printf("%d %d>",m,cnt);
        if(cnt>=k){
            if(cnt==k)ans=m;
            l=m+1;
        }
        else r=m-1;
    }
    if(ans==-1)printf("IMPOSSIBLE");
    else printf("%d",ans);
}
