//
// Created by unity on 2022/06/29.
//
#include<stdio.h>
int UltraTen(int v){
    int r=1;
    for (int i = 0; i < v; ++i) {
        r*=10;
    }
    return r;
}
//MEMO DO NOT USE GOTO
int main(void) {
    int n=3245;
    int degits=0;
    for (int i = 0; n> UltraTen(i); ++i) {
        degits++;
    }
    printf("%d\n",degits);
    char results[10]="";


    for (int i = 0; i < degits; ++i) {
        results[degits-i-1]='0'+(n%10);
        n-=n%10;
        n/=10;
    }
    printf("%s\n",results);
    /*




    for (int i = 0; n>=0; ++i) {
        printf("%s\n",result);
        result[i]='0'+(n%10);
        n-=n%10;
        n/=10;
    }


    printf("%s\n",result);
*/
    /*
    for (int k = 0; a[k]!=0; ++k) {
        printf("%c",a[k]);
    }*/

    return 0;
}


