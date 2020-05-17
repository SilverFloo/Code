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
using namespace std;
const int INF=1e9;
ii card[45];
long long c1[1<<20+5],c2[1<<20+5];
bool find(int l,int r,int val){
if(l>r)return 0;
int mid=(l+r)/2;
if()


}
int main(){
    int n;
    cin>>n;
    FOR(i,n)scanf("%d %d",&card[i].f,&card[i].s);
    for(int i=0;i<1<<n/2;i++){
        int x=i;
        for(int j=0;j<n/2;j++){
            if(x%2)c1[i]+=card[j].f;
            else c1[i]-=card[j].s;
            x>>=1;
        }
        printf("%d ",c1[i]);
    }

    for(int i=0;i<1<<(int)ceil((float)n/2);i++){
        int x=i;
        FOR(j,ceil((float)n/2)){
            if(x%2)c2[i]+=card[n/2+j].f;
            else c2[i]-=card[n/2+j].s;
            x>>=1;
        }
        printf("%d ",c2[i]);
    }
    FOR(i,1<<n/2){
    if(find(0,1<<(int)ceil((float)n/2)),c1[i])return 0;
    }
    printf("-1");
}
