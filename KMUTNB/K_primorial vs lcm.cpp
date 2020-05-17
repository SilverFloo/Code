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
const int MAX=1e7+5;
const int INF=1e9+7;
bool isp[MAX];
vector<int> prime;
int lg(double base, double x) {
    return (int)floor(log(x) / log(base));
}
int main(){
    for(int i=2;i<MAX;i++){
    if(!isp[i]){
    prime.pb(i);
    for(int j=i+i;j<MAX;j+=i){
    isp[j]=1;
    }
    }
    }
    int q;
    scanf("%d",&q);
    while(q--){
    long long a,ans=1;
    scanf("%lld",&a);
    int s=sqrt(a);
        for(auto i:prime){
        if(i>s)break;
            int xx=lg(i,a);
           FOR(j,xx-1)ans*=i,ans%=INF;
        }
    printf("%lld\n",ans);
    }
}
