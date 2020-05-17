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
int tab[(int)1e6+5];
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a,b;
    int pos=0;
    FOR(i,n){scanf("%d",&tab[i]);if(tab[i]==k)pos=i;}
    int cnt =0;
    int cz=0;
   for(int i=pos-1;i>=0;i--){
   if(tab[i]>k)cnt++;
   else cnt--;
   a.pb(cnt);
   if(cnt==0)cz++;
   //printf("%d ",cnt);
   }
   cnt=0;
    for(int i=pos+1;i<n;i++){
   if(tab[i]>k)cnt--;
   else cnt++;
   b.pb(cnt);
   if(cnt==0)cz++;
   //printf("%d ",cnt);
   }



    ll ans=0;
    sort(all(a));
    sort(all(b));
    int l=0,r=0;
    while(l<a.size()&&r<b.size()){
        //printf("%d %d->",l,r);
    if(a[l]==b[r]){
        int c1=1,c2=1;
        while(l<a.size()-1&&a[l+1]==a[l])c1++,l++;
        while(r<b.size()-1&&b[r+1]==b[r])c2++,r++;
        ans+=(ll)c1*c2;
        l++;r++;
    }
    else if(a[l]>b[r])r++;
    else l++;
    }
    printf("%lld",ans+cz+1);
}
