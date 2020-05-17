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
int al[(int)1e5+5];
int ar[(int)1e5+5];
int tab[(int)1e5+5];
int lis[(int)1e5+5];
int n;
int main(){
    cin>>n;
    FOR(i,n)scanf("%d",&tab[i]);
    int len=0;

    FOR(i,n){
    if(len==0)lis[0]=tab[i],len++;
    else{int l=0,r=len-1;
    int pos=-1;
    while(l<=r){
    int m=(l+r)/2;
    if(lis[m]<tab[i]){
    pos=m;
    l=m+1;
    }
    else r=m-1;
    }
    pos++;
    if(pos==len)len++;
    lis[pos]=tab[i];
    }
    //printf("%d ",len);
    al[i]=len;
    }

    len=0;
    for(int i=n-1;i>=0;i--){
    if(len==0)lis[0]=tab[i],len++;
    else{int l=0,r=len-1;
    int pos=-1;
    while(l<=r){
    int m=(l+r)/2;
    if(lis[m]<tab[i]){
    pos=m;
    l=m+1;
    }
    else r=m-1;
    }
    pos++;
    if(pos==len)len++;
    lis[pos]=tab[i];
    }
    //printf("%d ",len);
    ar[i]=len;
    }
    int ans=0;
    for(int i=0;i<n-1;i++){
           // printf("%d %d\n",al[i],ar[i+1]);
        ans=max(ans,al[i]+ar[i+1]);
    }
    printf("%d",ans);
}
