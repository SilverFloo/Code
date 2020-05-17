#include<bits/stdc++.h>
using namespace std;
stack<int> a;
int main(){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
char s[10];
scanf("%s",s);
if(!strcmp(s,"push")){
int x;
scanf("%d",&x);
a.push(x);
}
else{
if(a.size()==0)printf("null\n");
else {printf("%d\n",a.top());a.pop();}

}
}

}
