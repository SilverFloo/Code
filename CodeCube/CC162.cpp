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
long long tab[100005];
int num[100005];
int main(){
    int q;
    cin>>q;
    while(q--){
    int n;
    cin>>n;int ch=0;
    FOR1(i,n)scanf("%d",&num[i]);
    sort(num+1,num+n+1,greater<int>());
    tab[0]=0;
    FOR1(i,n)tab[i]=(ll)tab[i-1]+(ll)num[i];
    if(tab[n]%2==1){printf("No\n");continue;}
    FOR1(i,n){
    int l=i+1,r=n;
    int p=-1;
    while(l<=r){
    int mid=(l+r)/2;
    //printf("%d %d",mid,i);
    if(num[mid]>i)l=mid+1,p=mid;
    else r=mid-1;
    }

    ll rr=(ll)i*(i-1);

    if(p==-1){
    rr+=(ll)tab[n]-(ll)tab[i];
    }
    else rr+=(ll)(p-i)*(i)+(ll)tab[n]-(ll)tab[p];
    //printf("%d",(p-i)*(i));
    //printf("%lld<%d> %lld\n",rr,p,tab[i]);
    if(tab[i]>rr){printf("No\n");ch=1;break;}
    }
    if(!ch)printf("Yes\n");
    }
}
