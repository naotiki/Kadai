#include<stdio.h>

#define DEBUG_FLAG 0 //入力省略用 CHECK 消せ
#define FORCE_LOWER_CASE 1 //小文字を強制
#define MAX_SENTENCE_SIZE 1000 //最大文長
/*入力例
 * Lorem ipsum dolor sit amet
 * Lorem ipsum dolor sit amet.
 * Lorem ipsum dolor sit amet labore eirmod stet lorem accumsan. Ut sit eos eu clita ipsum sea nihil. Justo nonumy sea vero diam. Soluta nonummy dolore et et eos facilisis lorem.
 * */

//A -> aみたいな変換。対象じゃなきゃそのままreturn.
char toLowerCase(char value) {
    if (value <= 'Z' && value >= 'A' && FORCE_LOWER_CASE) {
        return 'a' + (value - 'A');
    } else return value;
}

//単語の区切り文字などの無視対象
int isSplitChar(char value) {
    int result = 0;
    char ignoreCharacter[] = {' ', ',', '.', '\n', '\0'};
    for (int i = 0; i < 5; ++i) {
        if (value == ignoreCharacter[i]) result = 1;
    }
    return result;
}

//CHECK 提出前に余分なコードは消せ！
int main() {
    char sentence[MAX_SENTENCE_SIZE]="";
    int length;
    //入力
    if (DEBUG_FLAG) {
        char testText[] = "Lorem ipsum dolor sit amet. What the FFFF.\n";
        for (length = 0; sentence[length - 1] != '\n'; ++length) {
            sentence[length] = testText[length];

        }
    } else {


        //CHECK 提出前にDebugを消せ！
        printf("まず文を入れましょう{%d文字まで(絵文字は入れないでください)}:", MAX_SENTENCE_SIZE);
        for (length = 0; sentence[length - 1] != '\n'; ++length) {
            scanf("%c", &sentence[length]);
        }

    }
    //末尾の改行を消す
    sentence[length - 1] = '\0';

    //単語数と単語の最大サイズを確認
    int maxWordsCount = 0;
    int maxWordLength = 0; //NULL文字の分
    {
        int tmpWL = 0;
        for (int i = 0; sentence[i] != '\0'; ++i) {
            tmpWL++;
            if (isSplitChar(sentence[i + 1])) {
                if (maxWordLength < tmpWL)maxWordLength = tmpWL;
                if (tmpWL != 0) {
                    maxWordsCount++;
                }
                tmpWL = 0;
                i++;
            }
        }

    }
    printf("単語数は %d 語\n", maxWordsCount);
    maxWordLength++;
    //配列作成
    char words[maxWordsCount][maxWordLength];
    int wordsIndex = 0;
    int wordIndex = 0;
    for (int i = 0; sentence[i] != '\0'; ++i) {
        if (!isSplitChar(sentence[i])) {
            words[wordsIndex][wordIndex] = toLowerCase(sentence[i]);
            wordIndex++;
        }
        if (isSplitChar(sentence[i + 1])) {
            if (wordIndex != 0) {
                for (; wordIndex < maxWordLength; wordIndex++) {
                    words[wordsIndex][wordIndex] = 0;
                }
                wordsIndex++;
            }
            wordIndex = 0;
            i++;
        }
    }






    //ここからオプション
    //1.アルファベット順ソート！
    for (int index = maxWordLength - 1; index >= 0; index--) {
        int needMoreSort = 1;
        while (needMoreSort) {
            needMoreSort = 0;
            for (int j = maxWordsCount - 1; j > 0; --j) {
                if (words[j][index] < words[j - 1][index]) {
                    for (int i = 0; i < maxWordLength; ++i) {
                        char tmp = words[j][i];
                        words[j][i] = words[j - 1][i];
                        words[j - 1][i] = tmp;
                    }
                    needMoreSort = 1;
                }
            }
        }
    }
    //2.


    //出力
    for (int i = 0; i < wordsIndex; ++i) {
        printf("単語:");
        for (int j = 0; j < maxWordLength; ++j) {
            printf("%c", words[i][j]);
        }
        printf("\n");
    }
}