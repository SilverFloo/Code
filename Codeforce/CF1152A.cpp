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
using namespace std;
const int INF=1e9;
int main(){
    int n,m;
    cin>>n>>m;
    int a=0,b=0;
    FOR(i,n){
        int x;
        scanf("%d",&x);
        if(x%2)a++;
        else b++;
    }
    int ans=0;
    FOR(i,m){
        int x;
        scanf("%d",&x);
        if(x%2){
            if(b>0)b--,ans++;
        }
        else{
            if(a>0)a--,ans++;
        }
    }
    printf("%d",ans);
}
