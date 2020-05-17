#include<bits/stdc++.h>
main(){
char s[105];
scanf("%s",s);
int x=0,y=0;
for(int i=0;i<strlen(s);i++){
switch(s[i]){
case 'N':x++;break;
case 'S':x--;break;
case 'E':y++;break;
case 'W':y--;break;
case 'Z':x=0;y=0;break;
}
}
printf("%d %d",y,x);

}
