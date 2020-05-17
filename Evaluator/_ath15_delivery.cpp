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
int w[100005],c[100005];
int st[100005];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int l=0,r=100000000;
        FOR(i,n){
            scanf("%d",&w[i]);scanf("%d",&c[i]);
            l=max(l,w[i]);
        }
        int ans=-1;
        while(l<=r){
            FOR(i,n)st[i]=0;
            int m=(l+r)/2;
            int cnt=1,val=0;
            for(int i=0;i<n;i++){
                if(st[c[i]]==cnt||val+w[i]>m){
                    cnt++;
                    val=w[i];
                }
                else val+=w[i];
                st[c[i]]=cnt;
               //printf("<%d %d>",i,cnt);
            }
           //printf("///%d->%d/// ",m,cnt,st[1]);
            if(cnt==k){ans=m;r=m-1;}
            else if(cnt<k){r=m-1;}
            else l=m+1;
        }
       printf("%d\n",ans);



    }
}
