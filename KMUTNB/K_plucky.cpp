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
vector<ii> tab1[12][12];
vector<ii> tab2[12][12];
int size[12][12];
bool cmp(ii a,ii b){
return a.s>b.s;
}
int main(){
        int r,c,n,m;
        cin>>r>>c>>n>>m;
        FOR(i,n){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        tab1[b][d].pb(a,c);
        tab2[b][d].pb(a,c);
        }
        FOR1(i,10)FOR1(j,10)sort(all(tab1[i][j])),size[i][j]=tab1[i][j].size();
        FOR1(i,10)FOR1(j,10)sort(all(tab2[i][j]),cmp);
        FOR(i,m){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        int ans=0;
        for(int i=b;i<=d;i++){
        for(int j=i;j<=d;j++){
        int low=size[i][j];
        int up=-1;
        int l=0;r=size[i][j]-1;
        while(l<=r){
        int mid=(l+r)/2;
        printf("<%d> ",mid);
        if(tab1[i][j][mid].f>=c)up=mid,r=mid-1;
        else l=mid+1;
        }
        l=0;r=size[i][j]-1;
        while(l<=r){
        int mid=(l+r)/2;
        if(tab2[i][j][mid].s<a)low=mid,l=mid+1;
        else r=mid-1;
        }
        printf("%d %d->",up,low);
        ans+=low-up;
        }
        }

        printf("%d\n",ans);
        }
}/*
100 1 2 3
2 1 5 1
3 1 20 1
1 1 2 1
5 1 30 1
30 1 40 1

*/
