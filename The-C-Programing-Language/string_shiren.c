#include <stdio.h>

//
// Created by unity on 2022/07/06.
//
int main(void){
    char input[26]="";
    printf("入力しなさい！：");
    scanf("%s",&input);
    getchar();
    //printf("%s\n",input);
    int condition=1;
    while (condition) {
        condition = 0;
        for (int i = 26; i >= 0; --i) {

            if (input[i]) {
                if (input[i] < input[i - 1]) {
                    char tmp = input[i];
                    input[i] = input[i - 1];
                    input[i - 1] = tmp;
                    condition = 1;
                }
            }
        }
    }
    printf("%s",input);

}