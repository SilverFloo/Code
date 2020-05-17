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
ii q[50005];
int l[100005];
int main(){
    int n,m;
    int ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%d %d",&q[i].f,&q[i].s);
    }
    for(int i=0;i<m;i++)scanf("%d",&l[i]);
    sort(l,l+m);
    FOR(i,n){
        ans+=lower_bound(l,l+m,q[i].s)-upper_bound(l,l+m,q[i].f);
        ans%=2007;
    }
    printf("%d",ans);
}
