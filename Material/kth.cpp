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
int t1[100005];
int t2[100005];
int query(int a,int b,int c,int d,int k){
    //printf("%d %d %d %d %d\n",a,b,c,d,k);
    int m1=(b-a)/2;
    int m2=(d-c)/2;
    if(a==b)return t2[c+k-1];
    if(c==d)return t1[a+k-1];
    if(m1+m2+2<=k){
        if(t1[a+m1]<t2[c+m2])return query(a+m1+1,b,c,d,k-m1-1);
        else return query(a,b,c+m2+1,d,k-m2-1);
    }
    else {
        if(t1[a+m1]<t2[c+m2])return query(a,b,c,c+m2,k);
        return query(a,a+m1,c,d,k);
    }
}
int check(int a,int b,int c,int d,int k){

    int ans=-1;
    int p1=a,p2=c;
    for(int i=0;i<k;i++){
        if(p1>b)ans=t2[p2],p2++;
        else if(p2>d)ans=t1[p1],p1++;
        else if(t1[p1]<t2[p2])ans=t1[p1],p1++;
        else ans=t2[p2],p2++;
    }
    return ans;
}
int main(){
   // rf();
    int n,q;
    cin>>n>>q;
    FOR(i,n)scanf("%d",&t1[i]);
    FOR(i,n)scanf("%d",&t2[i]);
    while(q--){
        int a,b,c,d,k;
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        k++;
        int x=query(a,b+1,c,d+1,k);
        printf("%d\n",x);
    //check
        //int y=check(a,b,c,d,k);
        //if(x!=y)exit(1);
    }
}
