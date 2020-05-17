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
const int MAX=1e6+5;
int fenwick[MAX][3];
int v[MAX];
void update(int v,int x,int val){
    for(int i=x;i<=MAX;i+=i&-i){
        fenwick[i][v]+=val;
    }
}
int query(int v,int x){
    int sum=0;
    for(int i=x;i>=1;i-=i&-i){
        sum+=fenwick[i][v];
    }
    return sum;
}
int main(){
    int n,q;
    cin>>n>>q;
    FOR1(i,n){
        update((i-1)%3,i,1);
        v[i]=(i-1)%3;
    }
    while(q--){
    int x;
    scanf("%d",&x);
    if(x==1){
        int p;char c;
        scanf("%d %c",&p,&c);
        update(v[p],p,-1);
        if(c=='R')update(0,p,1),v[p]=0;
        else if(c=='G')update(1,p,1),v[p]=1;
        else update(2,p,1),v[p]=2;

    }
    else{
        int l,r;
        scanf("%d %d",&l,&r);
        int a=query(0,r)-query(0,l-1);
        int b=query(1,r)-query(1,l-1);
        int c=query(2,r)-query(2,l-1);
        //printf("%d %d %d ",a,b,c);
        if(a>b&&a>c)printf("R\n");
        else if(b>a&&b>c)printf("G\n");
        else if(c>a&&c>b)printf("B\n");
        else printf("None\n");
    }
    }

}
