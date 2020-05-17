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
int main(){
    int n,q;
    cin>>n>>q;
    int tab[n];
    FOR(i,n)scanf("%d",&tab[i]);
    while(q--){
    int l,x,r;
    scanf("%d %d",&l,&x);
    l--;
    r=l+x-1;
    while(l<r){
            //printf("%d %d\n",l%n,r%n);
    swap(tab[l%n],tab[r%n]);
    l++;r--;
    }
    }
    FOR(i,n)printf("%d ",tab[i]);
}
