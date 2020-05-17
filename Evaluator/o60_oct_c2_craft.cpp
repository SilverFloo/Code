#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
int c[25];
ll ans=0;
void find(int l,int w){
    if(l==1){
        ans+=w;
        return;
    }
    int x = w*2+1-c[l-1];
    if(x<2){
        printf("-1");
        exit(0);
    }
    find(l-1,x/2);
    find(l-1,(x+1)/2);
}
int main(){
    int l,w;
    cin>>l>>w;
    FOR1(i,l-1)scanf("%d",&c[i]);
    find(l,w);
    printf("%lld",ans);
}
