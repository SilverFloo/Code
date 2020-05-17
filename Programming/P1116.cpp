#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
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
int tab[(int)1e6+5];
int main(){
    double ans=0;
    int n;
    cin>>n;
    int mx=0;
    FOR(i,0,n){
            scanf("%d",&tab[i]);
            if(i&&tab[i]<tab[i-1]){
                ans=max(ans,(double)(mx-tab[i])/2);
            }
            mx=max(mx,tab[i]);
    }
    printf("%.6f",ans);
}
