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
int coin[15];
int cnt[1000005],fo[1000005],type[1000005];
int ans[15];

int main(){
    int p,m,k;
    cin>>p>>m>>k;
    FOR(i,k)cin>>coin[i];
    for(int i=0;i<=m;i++){
        for(int j=0;j<k;j++){
            if(i+coin[j]>m)continue;
            if(cnt[i]+1<cnt[i+coin[j]]||cnt[i+coin[j]]==0){
                cnt[i+coin[j]]=cnt[i]+1;
                fo[i+coin[j]]=i;
                type[i+coin[j]]=j;
            }
        }
    }
    int mn=1e9,a=-1,b=-1;
    for(int i=p;i<=m;i++){
        if(cnt[i]+cnt[i-p]<mn){
            mn=cnt[i]+cnt[i-p];
            a=i;
            b=i-p;
        }
    }
    printf("%d %d\n",cnt[a],cnt[b]);
    int x=a;
    while(x!=0){
        ans[type[x]]++;
        x=fo[x];
    }
    FOR(i,k)printf("%d ",ans[i]),ans[i]=0;
    cout<<endl;
     x=b;
    while(x!=0){
        ans[type[x]]++;
        x=fo[x];
    }
    FOR(i,k)printf("%d ",ans[i]),ans[i]=0;
    cout<<endl;
}
