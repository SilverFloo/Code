#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=b-1;i>=a;i--)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
using namespace std;
const int MAX=1e9+7;
unsigned long long fib[32][2][2];
void mul(unsigned long long a[2][2],unsigned long long b[2][2],unsigned long long c[2][2]){
    int xx[2][2];
    xx[0][0]=a[0][0]*b[0][0]%MAX+a[1][0]*b[0][1]%MAX;
    xx[0][1]=a[0][0]*b[0][1]%MAX+a[0][1]*b[1][1]%MAX;
    xx[1][0]=a[1][0]*b[0][0]%MAX+a[1][1]*b[1][0]%MAX;
    xx[1][1]=a[1][0]*b[0][1]%MAX+a[1][1]*b[1][1]%MAX;
    FOR(i,0,2)FOR(j,0,2)c[i][j]=xx[i][j]%MAX;
}
int main(){
    fib[0][0][0]=1;
    fib[0][0][1]=1;
    fib[0][1][0]=1;
    fib[0][1][1]=0;
    int n;
    scanf("%d",&n);
    for(int i=1;i<32;i++){
        mul(fib[i-1],fib[i-1],fib[i]);
    }
    unsigned long long ans[2][2]={1,0,0,1};
    int c=0;
    while(n>0){
        if(n%2)mul(ans,fib[c],ans);
        c++;n>>=1;
    }
    printf("%llu",ans[0][1]);
}
