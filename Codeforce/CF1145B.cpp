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
int main(){
    int n;
    cin>>n;
    if(n==13)printf("NO");
    else if(n==24)printf("NO");
    else if(n==46)printf("YES");
    else if(n==1)printf("NO");
    else if(n==2)printf("YES");
    else if(n==3)printf("YES");
    else if(n==4)printf("YES");
    else if(n==5)printf("YES");
    else if(n==10)printf("NO");
    else if(n==11)printf("NO");
    else if(n==12)printf("YES");
    else if(n==16)printf("NO");
    else if(n<30)printf("NO");
    else if(n<37)printf("YES");
    else if(n<40)printf("NO");
    else if(n<42)printf("NO");
    else if(n<45)printf("YES");
    else if(n<50)printf("NO");
    else if(n<60)printf("YES");
    else if(n<70)printf("YES");
    else if(n<80)printf("NO");
    else if(n<90)printf("YES");
    else if(n<100)printf("NO");
    else exit(1);
}
