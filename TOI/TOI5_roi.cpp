#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
using namespace std;
const int INF=1e9;
const double e=2.71828182846;
double book(int i,int p){
double x=(double)((100 - (0.8569 * pow(e,(0.09*(p-100))))) * i ) / 100;
return x;
}

int main(){
int pcon=0;
cin>>pcon;
double mn=2e9;int a=2e9,b=2e9;
for(int i=1000;i<=15000;i+=500){
for(int p=74;p<=144;p++){
double sell=min((double)i,book(i,p))*p;
double pay=i*(100-(i-1000)/500)+pcon;
double adv=sell-pay;//printf("%.2lf %.2lf/",sell,adv);
if(adv>0&&adv<mn){mn=adv;a=i;b=p;}
//printf("%d %d %.2lf\n",i,p,adv);
}
}
printf("%d\n%d\n%.2lf",a,b,mn);
}
