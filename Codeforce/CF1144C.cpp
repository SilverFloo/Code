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
int bucket[200005];
vector<int> a,b;
int main(){
    int n;
    cin>>n;
    FOR(i,n){
        int x;
        scanf("%d",&x);
        if(bucket[x]==0)a.pb(x),bucket[x]++;
        else if(bucket[x]==1)b.pb(x),bucket[x]++;
        else {printf("NO");return 0;}
    }
    sort(all(a));
    sort(all(b));
    printf("YES\n%d\n",a.size());
    for(int i=0;i<a.size();i++)printf("%d ",a[i]);
    printf("\n%d\n",b.size());
    for(int i=b.size()-1;i>=0;i--)printf("%d ",b[i]);
}
