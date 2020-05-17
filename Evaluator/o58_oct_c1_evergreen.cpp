#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define st first
#define ed second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
int t[1005];
ll tri(int x){
    ll a=x/2;
    ll b=(x+1)/2;
    return a*(a+1)/2+b*(b+1)/2;
}
int main(){
    int n;ll k;
    int ans = -1;
    cin>>n>>k;
    FOR(i,n){
        scanf("%d",&t[i]);
    }
    sort(t,t+n);
    ll l=0,r=INF;
    while(l<=r){
        ll m=(l+r)/2;
        ll cnt = 0;
        for(int i=0;i<n;i++){
            cnt+=(m)*(m+1)/2;
            cnt+=(m+1)*(m+2)/2;
            if(i!=n-1&&t[i]+m>=t[i+1]-m){
                cnt-=tri(t[i]+m-(t[i+1]-m)+1);
            }
        }
        //cout<<cnt<<endl;
        if(cnt>=k){
            ans = m;
            r = m-1;
        }
        else l = m+1;
    }
if(ans==0)exit(1);
    printf("%d",ans);
}
