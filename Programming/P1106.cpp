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
int t[200005];
int n,k;
void update(int p,int v){
    for(int i=p;i<200005;i+=i&-i)t[i]+=v;
}
int query(int p){
    int ans=0;
    for(int i=p;i>0;i-=i&-i)ans+=t[i];
    return ans;
}
int find(int x){
    int l=1,r=n;
    int ans=-1;
    while(l<=r){
        int m=(l+r)/2;
        //printf("%d->%d\n",m,query(m));
        if(query(m)==x){ans=m;r=m-1;}
        else if(query(m)>x)r=m-1;
        else l=m+1;
    }
    return ans;
}
int main(){
    cin>>n>>k;
    FOR1(i,n)update(i,1);
    for(int i=n;i>1;i--){
        k=(k-1)%i+1;
        int x=find(k);
       // printf("%d %d\n",k,x);
        update(x,-1);
        k+=x-1;
    }
    printf("%d",find(1));
}
