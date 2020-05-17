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
int tab[105],e[105],v[105];
int main(){
    int n;
    cin>>n;
    FOR(i,n){
    scanf("%d",&tab[i]);
    }
    for(int i=2*n-1;i>=n;i--)scanf("%d",&tab[i]);
    FOR(i,2*n){
    if(e[i]==-1)continue;
    for(int j=i+1;j<2*n;j++){
    if(tab[i]==tab[j]){
    e[i]=j;
    e[j]=-1;
    v[j]=-1;
    }
    }
    }
    int ans=0;
    FOR(i,2*n){
    if(e[i]==-1)continue;
    int a=1;
    for(int j=0;j<i;j++){
        if(e[j]<i||(i<e[j]&&e[i]<e[j])){
            a=max(a,v[j]+1);
        }
    }
    v[i]=a;
    ans=max(ans,v[i]);
    }
    printf("%d",ans);

}
