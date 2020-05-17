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
int a[(int)1e5+5],b[(int)1e5+5];
int main(){
    int n;
    cin>>n;
    FOR(i,n)scanf("%d",&a[i]);
    FOR(i,n)scanf("%d",&b[i]);
    int k;
    cin>>k;
    int l=0,r=2e6;
    int ans=-1;
    while(l<=r){
    int m=(l+r)/2;
    //printf("%d ",m);
    ll cnt=k;
    FOR(i,n){
    if((ll)a[i]*m>(ll)b[i]){
    cnt-=(ll)a[i]*m-b[i];
    if(cnt<0)break;
    }
    }
    if(cnt>=0)l=m+1,ans=m;
    else r=m-1;
    }
    printf("%d",ans);
}
/*
1
1000000
1000000
0
*/
