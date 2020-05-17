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
    int n,k;int mx=0;
    cin>>n>>k;
    int tab[n];
    int ch=1;
    FOR(i,n){scanf("%d",&tab[i]);mx=max(tab[i],mx);}

    for(int i=mx;i<1e9;i++){
    int t=1,l=0;
    FOR(j,n){

    if(l+tab[j]>i){l=tab[j];t++;}
    else {l+=tab[j];}
    if(t>k)break;
    // printf("<%d %d>",l,t);
    }
    //printf("%d",t);
    if(t<=k){printf("%d",i);exit(0);}
    }
}
