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
int lis[1000005];
int M=0;
int n;
int bs(int l,int r,int val){
    if(l<r){
        int mid=(l+r)/2;
        if(lis[mid]==val)return mid;
        else if(lis[mid]<val)return bs(mid+1,r,val);
        else return bs(l,mid-1,val);
    }
if(lis[l]<val)return l;
else if(l==0)return -1;
return l-1;
}

int main(){
  scanf("%d",&n);
    for(int i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    if(M==0){lis[0]=a;M++;}
    else{
        int x=bs(0,M-1,a);
        while(lis[x]==lis[x+1])x++;
        lis[x+1]=a;
        if(x+1>=M)M++;
    }}
    printf("%d\n",M);
}
