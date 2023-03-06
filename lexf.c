#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *fp;
    fp = fopen("words.txt", "r");
    char str[100];
    int i = 1;
    char words[100][100];
    words[0][0] = '\0';
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
    --i;
    do{
        pos = 0; 
        while(comb[pos] == i){
            comb[pos] = 0;
            ++pos;
        }

        ++comb[pos];
        // for(int j = 0; j < i; ++j) printf("%d", comb[j]); printf(" "); 
        for(int j = 0; j < i; ++j){
            printf("%s", words[comb[j]]);
        }
        printf("\n");
    }while(pos < i);
    return 0;
}