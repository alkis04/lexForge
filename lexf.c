#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *fp;
    fp = fopen("words.txt", "r");
    char str[100];
    int i = 0;
    char words[100][100];
    while(fgets(str, 100, fp) != NULL){
        sscanf(str, "%s", words[i]);
        ++i; 
    }
    fclose(fp);

    // for(int j = 0; j < i; ++j){
        // printf("%s\n", words[j]);
    // }

    int comb[i]; 
    for(int j = 0; j < i; ++j){
        comb[j] = 0;
    }
    int pos = 0; 
    while(1){
        while(comb[pos] == i){
            comb[pos] = 0;
            ++pos;
            ++comb[pos];
            if(pos > i) goto end;
        }
        pos = 0;



        ++comb[pos]; 
        for(int j = 0; j < i; ++j){
            printf("%d", comb[j]);
        }
        printf("\n");
        getchar();
    }
    end:
    return 0;
}