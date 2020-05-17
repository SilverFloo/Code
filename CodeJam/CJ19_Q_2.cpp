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
int ans[105];
int main(){
    int ca;
    cin>>ca;
    FOR(j,ca){
    int n,l;
    map<int,int> m;
    cin>>n>>l;
    int a,b;
    scanf("%d %d",&a,&b);
    int c=__gcd(a,b);
    ans[0]=a/c;
    ans[1]=c;
    ans[2]=b/c;
    m[ans[0]]=1;
    m[ans[1]]=1;
    m[ans[2]]=1;
    c=b/c;
    for(int i=2;i<l;i++){
        //printf("%d->",i);
        scanf("%d",&b);
      //  printf("%d->%d/ ",b,c);
        ans[i+1]=b/c;
        c=b/c;
        m[ans[i+1]]=1;
    }
  //  FOR(i,l+1)printf("%d ",ans[i]);
    int ptr=0;
    for(auto &i:m)i.s=ptr++;
    printf("Case #%d: ",j+1);
    FOR(i,l+1)printf("%c",m[ans[i]]+'A');
    printf("\n");
    }
}
