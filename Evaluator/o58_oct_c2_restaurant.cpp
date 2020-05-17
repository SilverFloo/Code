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
vector<pair<int,ii>> edge;
int con[305][305];
int di[305][305];
int main(){
    int n,q;
    cin>>n>>q;
    FOR1(i,n){
        FOR1(j,n){
            int x;
            scanf("%d",&x);
            if(i>j)edge.pb(x,mp(i,j));
        }
    }
    sort(all(edge));
    for(auto e:edge){
        int a=e.s.f;
        int b=e.s.s;
        int ch=0;
        for(int i=1;i<=n;i++){
            if(con[a][i]&&con[i][b]){ch=1;break;}
        }
        if(!ch){
            di[a][b]=1;
            di[b][a]=1;
        }
        con[a][b]=1;
        con[b][a]=1;
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(di[i][j]){cnt++;}
        }
        //printf("%d %d\n",i,cnt);

        if(cnt>2){
            printf("%d",i);
            if(q==2)printf("\n%d",cnt);
            break;
        }
    }
}
