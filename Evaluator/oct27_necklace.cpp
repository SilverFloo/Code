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
int bf[300005],nx[300005],tail[300005];
int main(){
    int n;
    cin>>n;
    FOR1(i,n)tail[i]=i;
    FOR(i,n-1){
        int a,b;
        scanf("%d %d",&b,&a);
        bf[b]=a;
        if(nx[a]!=0){
                int p=tail[b];
                while(tail[p]!=p)p=tail[p];
                nx[p]=nx[a];}
        else tail[a]=tail[b];
        nx[a]=b;
    }
    int pos=-1;
    for(int i=1;i<=n;i++)if(bf[i]==0)pos=i;
    while(pos!=0){
        printf("%d ",pos);
        pos=nx[pos];
    }
}
/*

5
4 5
3 4
2 1
5 1
1 5 4 2

5 4 3
1 2
1 5 4 3 2


*/
