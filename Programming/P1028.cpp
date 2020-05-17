#include<bits/stdc++.h>
using namespace std;
int var[26];
main(){
while(1){
char c,a,b;
scanf(" %c",&c);
if(c=='!')break;scanf(" %c",&a);
if(c=='='){scanf("%d",&var[a-'A']);}
if(c=='#')printf("%d\n",var[a-'A']);
if(c=='+'){scanf(" %c",&b);var[a-'A']+=var[b-'A'];}
if(c=='-'){scanf(" %c",&b);var[a-'A']-=var[b-'A'];}
if(c=='*'){scanf(" %c",&b);var[a-'A']*=var[b-'A'];}
if(c=='/'){scanf(" %c",&b);var[a-'A']/=var[b-'A'];}
}

printf("!");

}
