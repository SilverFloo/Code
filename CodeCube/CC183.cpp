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
const int MAX=2e5+5;
int fenwick[MAX];
int val[MAX];
int n;


void update(int p,int v){
    for(int i=p;i<=n;i+=i&(-i)){
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

    cin>>n;
    FOR1(i,n){
    scanf("%d",&val[i]);
    update(i,1);
    }
    FOR(i,n){
    int x;
    scanf("%d",&x);
    int l=1,r=n;int p=-1;
    while(l<=r){
        int mid=(l+r)/2;
        int v=query(mid);
       // printf("%d->%d/",mid,v);
        if(v==x)p=mid;
        if(v>=x)r=mid-1;
        else l=mid+1;
    }
    //FOR1(j,n)printf("%d ",query(j));
    printf("%d\n",val[p]);
    update(p,-1);
    }
}





