#include <stdio.h>
#include <ctype.h>
#include <string.h>

char keywords[10][10] = {
    "int","float","char","return","void",
    "if","else","for","while","struct"
};

int isKeyword(char word[]) {
    for(int i=0;i<10;i++)
        if(strcmp(word, keywords[i]) == 0)
            return 1;
    return 0;
}

int main() {
    FILE *fp;
    char ch, word[20];
    int i = 0;

    fp = fopen("input.c", "r");

    printf("\nTOKENS\n\n");

    while((ch = fgetc(fp)) != EOF) {

        if(isspace(ch)) continue;

        if(isalpha(ch)) {
            i = 0;
            while(isalnum(ch)) {
                word[i++] = ch;
                ch = fgetc(fp);
            }
            word[i] = '\0';
            fseek(fp, -1, SEEK_CUR);

            if(isKeyword(word))
                printf("Keyword: %s\n", word);
            else
                printf("Identifier: %s\n", word);
        }

        else if(isdigit(ch)) {
            i = 0;
            while(isalnum(ch)) {
                word[i++] = ch;
                ch = fgetc(fp);
            }
            word[i] = '\0';
            fseek(fp, -1, SEEK_CUR);

            if(isdigit(word[strlen(word)-1]))
                printf("Constant: %s\n", word);
            else
                printf("Lexical Error: %s\n", word);
        }

        else {
            printf("Symbol: %c\n", ch);
        }
    }

    fclose(fp);
    return 0;
}