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
int tab[2][130];
int tmp[130];
int main(){
    int t;
    cin>>t;
    while(t--){ int ans=0;

    int n,m;
    cin>>n>>m;
    int now=0,prev=1; FOR(i,129)tab[prev][i]=0;
    FOR(i,n){
        int a;
        scanf("%d",&a);
        FOR(i,129){
        tab[now][i]=tab[prev][i^a];
        }
        tab[now][a]++;
        for(int j=m;j<129;j++){ans+=tab[now][j];}
        FOR(i,20)printf("%d ",tab[now][i]);
        printf("\n");
        swap(now,prev);
    }
    printf("%d\n",ans);
    }
}
