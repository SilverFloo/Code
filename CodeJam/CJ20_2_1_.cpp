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
#define rf() freopen("_working/input.in","r",stdin)
#define pf() freopen("_working/output.out","w+",stdout)
using namespace std;
double sum(double x){
    if(x>=2e9)return 4e18+10;
    return x*(x+1)/2;
}
double get(double x,double a){
    if(x>=2e9)return 4e18+10;
    return x*x+x*(a-1);
}
int main(){
    rf();pf();
    int t;
    cin>>t;
    FOR(k,t){
        double a,b;
        cin>>a>>b;
        double cnt=-1;
        int s=0;
        if(b>a){swap(a,b);s=1;}
        double l=0,r=a;
        while(l<=r){
            double m=floor((l+r)/2);
            if(a-sum(m)<=b)cnt=m,r=m-1;
            else l=m+1;
        }
        a-=sum(cnt);
        if(s==1)swap(a,b);

        s=0;
        if(b>a)swap(a,b),s=1;
        l=0,r=a;
        double xa=-1,xb=-1;
        while(l<=r){
            double m=floor((l+r)/2);
            if(a-get(m,cnt+1)>=0)xa=m,l=m+1;
            else r=m-1;
        }
        l=0,r=b;
        while(l<=r){
            double m=floor((l+r)/2);
            if(b-get(m,cnt+2)>=0)xb=m,l=m+1;
            else r=m-1;
        }

        a-=get(xa,cnt+1);
        b-=get(xb,cnt+2);
        if(s==1)swap(a,b);
        printf("Case #%d: %.0f %.0f %.0f\n",k+1,cnt+xa+xb,a,b);


    }
    
}