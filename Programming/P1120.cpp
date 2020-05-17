#include<stdio.h>
using namespace std;
int data[1000005];
int main(){

for(int i=1;i<1000001;i++){
for(int j=i;j<1000001;j+=i){data[j]++;}
}
int q;
scanf("%d",&q);
while(q--){
int a,b,x;
int c=0;
scanf("%d %d %d",&a,&b,&x);
while(a<=b){
if(data[a]==x)c++;a++;
}printf("%d\n",c);
}
}
