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
const int INF=1e9;
priority_queue<int,vector<int>,greater<int>> s;
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    s.p(0);
    ll ans=0;
    if(n==1){
        printf("%d",min(a,b));
        return 0;
    }
    while(s.size()!=n){
        int x=s.top();
        s.pop();
        ans+=x+a+b;
        s.p(x+a);
        s.p(x+b);
    }
    printf("%lld",ans);
}
