//
// Created by unity on 2022/07/06.
//

#include<stdio.h>

int main() {
    char sentence[1000];
    //="Lorem ipsum dolor sit amet"
    int length;
    printf("文を入れようね{1000文字まで(絵文字は入れないでください)}:");
    for (length = 0; sentence[length-1] != '\n'; ++length) {
        scanf("%c", &sentence[length]);
    }



    int maxWordCount = 1;
    int maxWordLength = 0;
    {
        int tmpWL = 0;
        for (int i = 0; sentence[i] != 0; ++i) {
            if (sentence[i] == ' ') {
                if (maxWordLength < tmpWL)maxWordLength = tmpWL;
                tmpWL = 0;
                maxWordCount++;
            } else tmpWL++;
        }
    }
    maxWordLength+=1;

    printf("単語数は %d 語\n", maxWordCount);
    char words[maxWordCount][maxWordLength];
    int wordsIndex = 0;

    int wordIndex = 0;
    for (int i = 0; sentence[i] != 0&&sentence[i]!='\n'; ++i) {
        if (sentence[i] == ' ') {

            for (; wordIndex < maxWordLength; wordIndex++) {
                words[wordsIndex][wordIndex] = 0;
            }
            wordsIndex++;
            wordIndex = 0;
            continue;
        }
        words[wordsIndex][wordIndex] = sentence[i];
        wordIndex++;

    }
    for (; wordIndex < maxWordLength; wordIndex++) {
        words[wordsIndex][wordIndex] = 0;
    }
    wordsIndex++;
    /*for (int i = 0; i < wordsIndex; ++i) {
        printf("単語:");
        printf("%s", words[i]);
        printf("\n");
    }*/


    //ここからオプション
    //1.辞書順ソート！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
    for (int index=0;index<maxWordLength;index++) {
        int needMoreSort = 1;
        while (needMoreSort) {
            needMoreSort = 0;
            for (int j = wordsIndex; j > 0; --j) {
                if (words[j][index] < words[j - 1][index]) {
                    char tmp = words[j][index];
                    words[j][index] = words[j - 1][index];
                    words[j - 1][index] = tmp;
                    needMoreSort = 1;
                }
            }
        }
    }
    for (int i = 0; i < wordsIndex; ++i) {
        printf("単語:");
        printf("%s", words[i]);
        printf("\n");
    }


}