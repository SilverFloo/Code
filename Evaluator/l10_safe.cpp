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
int a[500005];
int main(){
    int n;
    cin>>n;
    FOR(i,n){scanf("%d %d",&a[i],&a[i]);
    if(i==0)printf("0\n");
    else {
        if(a[i]>a[i-1])printf("%d\n",a[i]-a[i-1]),a[i]=a[i-1];
        else printf("0\n");
    }
    }
}
