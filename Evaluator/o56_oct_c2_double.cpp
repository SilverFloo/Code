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
ll tab[200005];
int data[100005];
int main(){
    int n;
    cin>>n;
    FOR(i,n){
        scanf("%d",&data[i]);
    }
    for(int i=1;i<=n;i++){
        tab[i]=data[i-1];
        tab[i]+=tab[i-1];
    }
    ll x=tab[n];
    //printf("<%lld>",x);
    if(x%2==1){printf("NO");exit(0);}
    x/=2;
    for(int i=n+1;i<=n+n;i++){
        tab[i]=data[i-n-1];
        tab[i]+=tab[i-1];
    }
    for(int i=0;i<n;i++){
        if(binary_search(tab+i,tab+i+n,tab[i]+x)){
                //printf("%d//",tab[i]+x);
                if(i==0)printf("%d",lower_bound(tab+i,tab+i+n,tab[i]+x)-tab);
                else printf("%d %d",i,lower_bound(tab+i,tab+i+n,tab[i]+x)-tab);
            exit(0);
        }

    }
    printf("NO");
}
