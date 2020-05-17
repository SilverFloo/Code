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
int a[700005];
ii b[700005];
int ans[700005];
int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,n){
        scanf("%d",&a[i]);
    }
    FOR(i,m){
        scanf("%d",&b[i].f);
        b[i].s=i;
    }
    sort(a,a+n);
    sort(b,b+m);
    int cnt=b[0].f;
    int pos=0;
    FOR(i,m){
        while(pos<n&&cnt>=a[pos]){
            pos++;
            cnt++;
        }
        ans[b[i].s]=cnt;
        cnt+=b[i+1].f-b[i].f;
    }
    FOR(i,m)printf("%d ",ans[i]);
}
