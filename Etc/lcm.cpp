#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
if(a%b==0)return b;
return gcd(b,a%b);
}
long long unsigned lcm(int a,int b){
return (long long unsigned)b/gcd(a,b)*a;
}
int main(){
int a,b;
scanf("%d %d",&a,&b);
if(a>b)printf("%llu",lcm(a,b));
else printf("%llu",lcm(b,a));

}
