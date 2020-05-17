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
int main(){
    int n;
    cin>>n;
    FOR(i,n){
        int a,b,c;
        cin>>a>>b>>c;
        int x=min(b,c/2);
        int ans=0;
        ans+= x+2*x;
        b-=x;
        c-=2*x;
        int y=min(a,b/2);
        ans+=y+y*2;
        printf("%d\n",ans);
    }

}
