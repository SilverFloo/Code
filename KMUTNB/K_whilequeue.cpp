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
const int MAX=1e5;
int fenwick[MAX+5];
int num[MAX+5];
void update(int x,int v){
    for(int i=x;i<=MAX;i+=i&-i){
        fenwick[i]+=v;
    }
}
int query(int x){
int sum=0;
    for(int i=x;i>0;i-=i&-i){
        sum+=fenwick[i];
    }
    return sum;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
        scanf("%d",&num[i]);
        update(n-i+2,1);
        }
        int ans=0;
        for(int i=1;i<=n;i++) {
        int cost = query(num[i]);
        if(cost>2) {ans=-1; break;}
        ans+=cost; update(num[i]+1,-1);
        }
        if(ans==-1) printf("CHEAT\n");
        else printf("%d\n",ans);
    }
}
