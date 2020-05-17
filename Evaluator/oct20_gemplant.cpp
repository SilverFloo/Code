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
const int MAX=200005;
int t[MAX];
void update(int x,int v){
    for(int i=x;i<MAX;i+=i&-i){
        t[i]+=v;
    }
}
int query(int x){
    if(x==0)return 0;
    int a=0;
    for(int i=x;i>0;i-=i&-i){
        a+=t[i];
    }
    return a;
}
int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,m){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a==1)update(c,b);
        else printf("%d\n",query(c)-query(b-1));
    }
}
