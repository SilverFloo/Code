#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
#define pb emplace_back
#define p emplace
#define all(x) x.begin(),x.end()
#define ii pair<int,int>
#define ll long long
#define f first
#define s second
using namespace std;
ii p1[100005];
ii p2[100005];
vector<ii> cv1,cv2;
ii x1,x2;
double m(ii a,ii b){
    if(a==b)return -2e9;
    if(a.f==b.f)return a.s>b.s?1e9:1e9;
    return (double)(a.s-b.s)/(double)(a.f-b.f);
}
bool cmp1(ii a,ii b){
    if(m(x1,a)==m(x1,b))return a.f-x1.f>b.f-x1.f;
    return m(x1,a)<m(x1,b);
}
bool cmp2(ii a,ii b){
    return m(x2,a)<m(x2,b);
}
int main(){
    x1.f=2e9;
    x2.f=2e9;
    int n1,n2;
    cin>>n1>>n2;
    FOR(i,n1){scanf("%d %d",&p1[i].f,&p1[i].s);if(p1[i].f<x1.f)x1=p1[i];}
    FOR(i,n2){scanf("%d %d",&p2[i].f,&p2[i].s);if(p2[i].f<x2.f)x2=p2[i];}
    sort(p1,p1+n1,cmp1);
    sort(p2,p2+n2,cmp2);
    int sz=0;
    for(int i=0;i<n1;i++){
            if(sz>1)printf("%f//",m(p1[i],cv1[sz-1])-m(cv1[sz-1],cv1[sz-2]));
            //if(cv)
            while(sz>1&&m(p1[i],cv1[sz-1])-m(cv1[sz-1],cv1[sz-2])>0){
                cv1.pop_back();
                sz--;
            }
            sz++;
            cv1.pb(p1[i]);
            for(auto i:cv1)printf("%d %d//",i.f,i.s);
            cout<<endl;
           // printf("%f ",m(p1[i-1],p1[i]));
        //if(m(p1[i-1],p1[i])<m(p1[i],p1[i+1]))printf("ee");
    }

    FOR(i,n1){
        printf("%d %d\n",p1[i].f,p1[i].s);
    }

}
/*
???min 0%
WTF convex hall
*/
/*

5 4
0 0
0 2
2 2
2 0
1 1

-1 -1
-1 1
1 1
1 -1


5 4
-1 0
0 -1
0 1
1 0
0 0

-1 -1
-1 1
1 1
1 -1


*/
