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
using namespace std;
const int INF=1e9;
int ch[305];
vector<int> e[305];
int d[305];
int cmp(int a,int b){
    return e[a].size()<e[b].size();
}
int main(){
    int n;
    cin>>n;
    FOR1(i,n){
        int x;
        scanf("%d",&x);
        d[i]=i;
        FOR(j,x){
            int a;
            scanf("%d",&a);
            ch[a]=1;
        }
        FOR1(j,n)if(!ch[j]&&j!=i)e[i].pb(j);
        else ch[j]=0;
    }
    sort(d+1,d+n+1,cmp);
    int cnt=0;
    FOR1(x,n){
        int i=d[x];
        //db(i);
        if(ch[i]==0){
           // db(i);
            cnt++;
            ch[i]=2;
            for(auto j:e[i])ch[j]=1;
        }
        if(cnt>=ceil((float)n/4)){
            printf("%d\n",cnt);
            FOR1(j,n)if(ch[j]==2)printf("%d ",j);
            return 0;
        }
    }


}
