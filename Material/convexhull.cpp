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
ii p0;
int turn(ii p0,ii p1,ii p2){
    return (p1.f-p0.f)*(p2.s-p0.s)-(p2.f-p0.f)*(p1.s-p0.s);
}
int dist(ii a,ii b){
    return (a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s);
}
int cmp(ii p1,ii p2){
    int x = turn(p0,p1,p2);
    if(x==0){
        return dist(p0,p1)<dist(p0,p2);
    }
    else
        return x>0;
}
ii p[10005];
vector<ii> s;
int main(){
    int n;
    cin>>n;
    FOR(i,n)scanf("%d %d",&p[i].f,&p[i].s);
    sort(p,p+n);
    p0=p[0];
    sort(p+1,p+n,cmp);
    s.pb(p[0]);
    s.pb(p[1]);
    int ptr=1;
    for(int i=2;i<n;i++){
        while(ptr>=1&&turn(s[ptr-1],s[ptr],p[i])<=0){
            s.pop_back();
            ptr--;
        }
        s.pb(p[i]);
        ptr++;
    }
    printf("//ans//\n");
        for(auto i:s)printf("%d %d\n",i.f,i.s);

}

/*
8
0 0
1 0
1 1
2 1
0 1
2 2
0 -1
0 2



9
0 0
0 1
1 0
-1 0
0 -1
1 1
-1 1
1 -1
-1 -1
*/
