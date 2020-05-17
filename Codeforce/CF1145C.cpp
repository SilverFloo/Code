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
    if(n==0)printf("15");
    else if(n==1)printf("14");
    else if(n==2)printf("12");
    else if(n==3)printf("13");
    else if(n==4)printf("8");
    else if(n==5)printf("9");
    else if(n==6)printf("10");
    else if(n==7)printf("11");
    else if(n==8)printf("0");
    else if(n==9)printf("1");
    else if(n==10)printf("2");
    else if(n==11)printf("3");
    else if(n==12)printf("4");
    else if(n==13)printf("5");
    else if(n==14)printf("6");
    else if(n==15)printf("7");
    else exit(1);
}
