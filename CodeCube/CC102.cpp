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
int fenwick[(int)1e6+5];



void update(int p,int v){
    for(int i=p;i<1e6+5;i+=i&(-i)){
        fenwick[i]+=v;
    }
}
int query(int p){
    int sum=0;
    for(int i=p;i>0;i-=i&(-i)){
        sum+=fenwick[i];
    }
    return sum;
}
int main(){
    int p,n;
    cin>>n>>p;
    while(p--){
    int a,k,d,q;
    scanf("%d%d%d%d",&a,&k,&d,&q);
    int l=a-k,r=a+k;

    update(max(1,l),d);
    update(min(n+1,r+1),-d);

    if(l<=0){
        update(n+l,d);
        update(n+1,-d);
    }
    if(r>n){
        update(1,d);
        update(r-n+1,-d);
    }
   // FOR1(i,n)printf("%d ",query(i));
    while(q--){
    int x;
    scanf("%d",&x);
    printf("%d ",max(10000-query(x),0));
    }printf("\n");
    }
}
