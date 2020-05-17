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
vector<int> ca[25];
int st[25],ed[25];
int find(int ff,int x){
int l=st[ff],r=ed[ff]-1;
int p=st[ff]-1;
while(l<=r){
    int mid=(l+r)/2;
    if(ca[ff][mid]<x)p=mid,l=mid+1;
    else r=mid-1;
}
return p-st[ff];
}
int main(){
    int n,q;
    cin>>n>>q;
    FOR1(i,n){
    scanf("%d",&ed[i]);
    FOR(j,ed[i]){
    int a;
    scanf("%d",&a);
    ca[i].pb(a);
    }
    sort(all(ca[i]));
    }
    while(q--){
    int a,b;
    scanf("%d%d",&a,&b);
    if(a==0){
    if(st[b]<ed[b])st[b]++;
    }
    else{
    int ans,pos=INF;
    FOR1(i,n){
    int x=find(i,b);
    if(x<pos)pos=x,ans=i;
    }
    ca[ans].insert(ca[ans].begin()+st[ans]+pos+1,b);
    ed[ans]++;
    printf("%d\n",ans);
    }//printf("%d %d//",st[1],ed[1]);
//for(int i=st[1];i<ed[1];i++)printf("%d ",ca[1][i]);
//printf("\n");
    }
}
