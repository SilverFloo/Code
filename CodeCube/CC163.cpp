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
int tab[(int)1e5+5];
int main(){
    int n,k,a;
    cin>>n>>k;
    int mx=0,mn=INF;
    FOR(i,n){scanf("%d",&a);tab[a]++;
    mx=max(mx,a);
    mn=min(mn,a);
    }
    int cnt=0;
    while(mx-mn>k){
    a=min(tab[mx],tab[mn]);
    cnt+=a;
    tab[mx]-=a;
    tab[mx-1]+=a;
    if(tab[mx]==0)mx--;
    tab[mn]-=a;
    tab[mn+1]+=a;
    if(tab[mn]==0)mn++;
    }
    printf("%d",cnt);
}
