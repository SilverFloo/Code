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
#define li pair<long long,int>
using namespace std;
const int INF=1e9;
li tab[(int)1e6+5];
int main(){
    int n,k;
    scanf("%d %d ",&n,&k);
    FOR1(i,n){
    char c;
    scanf(" %c",&c);
    if(c=='R')tab[i].f=k;
    else tab[i].f=-1;
    tab[i].f+=tab[i-1].f;
    tab[i].s=i;
    }
    sort(tab,tab+n+1);
    int st=0,ed=0;
    int ans=0;
    FOR1(i,n){
        if(tab[i].f!=tab[i-1].f){
            ans=max(ans,tab[ed].s-tab[st].s);
            st=i;ed=i;
        }
        else ed++;
    }
    printf("%d",ans);
}
