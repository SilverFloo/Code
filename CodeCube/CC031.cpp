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
ll a[10005];
int main(){
    int n;
    cin>>n;

    a[0]=1;
    a[1]=1;
    for(int i=2;i<=n;i++){
    for(int j=0;j<i;j++){
    a[i]+=a[j]*a[i-j-1];
    a[i]%= 909091;
    }
    }
    printf("%lld",a[n]);
}
