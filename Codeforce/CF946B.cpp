#include<bits/stdc++.h>
using namespace std;
long long a,b;
void find(){
if(a==0||b==0)return;
else if(a>=2*b){a=a%(2*b);find();}
else if(b>=2*a){b=b%(2*a);find();}
}
int main(){
scanf("%lld %lld",&a,&b);
find();
printf("%lld %lld",a,b);
}
