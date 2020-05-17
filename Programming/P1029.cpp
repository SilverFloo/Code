#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
//#define p emplace
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    map<int,int> M;
    FOR(i,m){
    int a,b;
    scanf("%d %d",&a,&b);
    auto p=M.find(a);
    if(p==M.end()){
        M[a]=1;
    }
    else M.erase(p);
    b+=a;
    p=M.find(b);
    if(p==M.end()){
        M[b]=1;
    }
    else M.erase(p);

    }
    M[1]=1;
    M[n+1]=1;
    //for(auto i:M)printf("%d ",i.f);
    FOR(i,q){
//printf("in");
    int a;
    scanf("%d",&a);
    printf("%d\n",M.upper_bound(a)->f-(--M.upper_bound(a))->f);


    }
}
