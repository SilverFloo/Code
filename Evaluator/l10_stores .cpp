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
int p1[20],p2[20];
int main(){
    int n;
    cin>>n;
    FOR(i,n)scanf("%d",&p1[i]);
    FOR(i,n)scanf("%d",&p2[i]);
    double ans=INF;
    for(int i=0;i<=1<<n;i++){
        int a=0,b=0,cnt=0;
        for(int j=0;j<n;j++){
            int st=(i>>j)%2;
            if(st==0)cnt++,a+=p1[j];
            else b+=p2[j];
        }
        ans=min(ans,a-(double)(a*cnt)/100+b-(double)(b*(n-cnt))/100);
    }
    printf("%.2f",ans);
}
