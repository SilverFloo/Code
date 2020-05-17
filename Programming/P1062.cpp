#include<bits/stdc++.h>
using namespace std;
int main(){
int M,m;
scanf("%d%d",&M,&m);
char a[200],b[200],c[200];
scanf("%s %s %s",a,b,c);
for(int i=0;i<m;i++){
for(int j=0;j<M;j++){
char x[3];
x[0]=a[j];
x[1]=b[j];
x[2]=c[i];
sort(x,x+3);
c[i]=x[1];
}
}

printf("%s",c);

}
