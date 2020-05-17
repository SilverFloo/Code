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
vector<int> x,y;
int main(){
    int s,n;
    cin>>s>>n;
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        x.pb(a);
        y.pb(b);
    }
    x.pb(0);x.pb(s);
    y.pb(0);y.pb(s);
    sort(all(x));
    sort(all(y));
    int ans1=0;
    for(int i=1;i<x.size();i++){
        ans1=max(ans1,x[i]-x[i-1]);
    }
    int ans2=0;
    for(int i=1;i<y.size();i++){
        ans2=max(ans2,y[i]-y[i-1]);
    }
    printf("%.3f",(double)min(ans1,ans2)/2);
}
