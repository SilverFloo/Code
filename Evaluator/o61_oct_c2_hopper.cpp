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
int val[3005];
ii d[3005];
int cnt[3005];
int main(){
    int n,k;
    cin>>n>>k;
    FOR(i,n){
        scanf("%d",&val[i]);
        d[i].f=val[i];
        d[i].s=i;
    }
    sort(d,d+n);
    int ans=INF;
    int l=0,r=n;
    while(l<=r){
        int ch=0;
        int m=(l+r)/2;
        //printf("\n%d : ",m);
        FOR(i,n)cnt[i]=0;
        for(int i=0;i<n;i++){
            int p=d[i].s;
            if(cnt[p]==k)ch=1;
           // printf("%d ",cnt[p]);
            for(int j=1;j<=m;j++){
                if(val[(p+j)%n]>val[p])cnt[(p+j)%n]=max(cnt[(p+j)%n],cnt[p]+1);
            }
        }
        if(ch)ans=min(ans,m);
        if(ch)r=m-1;
        else l=m+1;
    }
    printf("%d",ans);
}
