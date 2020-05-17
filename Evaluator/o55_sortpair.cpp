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
ii x[100005];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d %d",&x[i].f,&x[i].s);
    sort(x,x+n);
    for(int i=0;i<n;i++)printf("%d %d\n",x[i].f,x[i].s);
}
