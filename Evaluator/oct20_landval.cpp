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
        int a;
        scanf("%d",&a);
        if(a==1){
            int b,c,d;
            scanf("%d %d %d",&b,&c,&d);
            update(b,d);
            update(c+1,-d);
        }
        if(a==2){
            int b;
            scanf("%d",&b);
            printf("%d\n",query(b));
        }
    }
}
