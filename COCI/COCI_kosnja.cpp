#include<bits/stdc++.h>
using namespace std;
main(){
int n;
scanf("%d",&n);
while(n--){
int i,j;
scanf("%d %d",&i,&j);
if(j<i)i=j;
if(i==1)printf("0\n");
if(i==2)printf("3\n");
if(i>=3)printf("%d\n",4+2*(i-3));
}

}
