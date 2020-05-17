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
int t[100005];
int main(){
    int n,p;
    int ans=0;
    cin>>n>>p;
    for(int i=0;i<n;i++)scanf("%d",&t[i]);
    int l=0,r=2e9;
    while(l<=r){
        int m=(l+r)/2;
        ll cnt=0;
        for(int i=0;i<n;i++){
            cnt+=(ll)m/t[i]+1;
        }
        //printf("%d %d\n",m,cnt);
        if(cnt>=p)r=m-1,ans=m;
        else l=m+1;
    }
    printf("%d",ans);
}
