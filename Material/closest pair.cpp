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
ii tab[100005];
ii check[100005];
double dist(ii a,ii b){
    return (double)sqrt((a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s));
}
ii re(ii a){
    return {a.s,a.f};
}
int main(){
    system ("start gen.exe")
    rf();
    int n;
    cin>>n;
    FOR(i,n){
        scanf("%d %d",&tab[i].f,&tab[i].s);
        check[i]=tab[i];
    }
    sort(tab,tab+n);
    double d = dist(tab[0],tab[1]);
    set<ii> s;
    s.insert(re(tab[0]));
    s.insert(re(tab[1]));
    int st=0;
    ii ans1=tab[0],ans2=tab[1];
    for(int i=2;i<n;i++){
           // printf("in");
        while(tab[st].f<tab[i].f-d){
            s.erase(re(tab[st]));
            st++;
        }
        for(auto j=s.lower_bound(mp(floor(tab[i].s-d),0));j!=s.upper_bound(mp(ceil(tab[i].s+d),0));j++){
           // printf("in");
            if(dist(tab[i],re(*j))<d)d=dist(tab[i],re(*j)),ans1=tab[i],ans2=re(*j);
        }
        s.insert(re(tab[i]));
    }
    int a=-1,b=-1;
    for(int i=0;i<n;i++){
        if(a==-1&&ans1==check[i])a=i;
        else if(ans2==check[i])b=i;
    }
    if(a<b)swap(a,b);
    printf("%d %d %f\n",b,a,d);

    double mn=1e9;
    FOR(i,n){
        for(int j=0;j<i;j++){
            if(dist(check[i],check[j])<mn){
                mn=dist(check[i],check[j]);
                a=i;b=j;
            }
        }
    }
    printf("%d %d %f",b,a,mn);
}
