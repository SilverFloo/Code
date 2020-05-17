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
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
int a[20],b[20];
int main(){
    double ans=1e18;
    int n;
    cin>>n;

    FOR(i,n)scanf("%d",&a[i]);
    FOR(i,n)scanf("%d",&b[i]);
    for(int i=0;i<1<<n;i++){
        int ca=0,aa=0,cb=0,bb=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                ca++;
                aa+=a[j];
            }
            else{
                cb++;
                bb+=b[j];
            }
        }
        ans = min(ans,(double)aa*(100-ca)/100+(double)bb*(100-cb)/100);
      //  cout<<(double)aa*(100-ca)/100+(double)bb*(100-cb)/100<<endl;
    }
    printf("%.2f",ans);
}
