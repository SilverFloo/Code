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
const int MAX=1050;
int t[MAX][MAX];
void update(int x,int y,int v){
    for(int i=x;i<MAX;i+=i&-i){
        for(int j=y;j<MAX;j+=j&-j)t[i][j]+=v;
    }
}
int query(int x,int y){
    if(x==0||y==0)return 0;
    int ans=0;
    for(int i=x;i>0;i-=i&-i){
        for(int j=y;j>0;j-=j&-j)ans+=t[i][j];
    }
    return ans;
}
int main(){
    int n;
    while(1){
        int x;
        scanf("%d",&x);
        if(x==0){
            scanf("%d",&n);
        }
        if(x==1){
            int a,b,v;
            scanf("%d %d %d",&a,&b,&v);
            a++;b++;
            update(a,b,v);
        }
        if(x==2){
            int a,b,c,d;
            scanf("%d %d %d %d",&a,&b,&c,&d);
            a++;b++;c++;d++;
            printf("%d\n",query(c,d)-query(c,b-1)-query(a-1,d)+query(a-1,b-1));
        }
        if(x==3)exit(0);
    }
}
