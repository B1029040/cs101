#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void print_number(int random, int i, FILE *fp) {
    int lotto[6] = {0};
    int special;
    int number;
    random += i;
    fprintf(fp, "[%d]：", i);
    srand(random);
    for(int k=0; k<6; k++) {
        number = rand()%69+1;
        lotto[k] = number;
        for(int m=0; m<k; m++) {
            if(lotto[k] == lotto[m]) {
                k-=1;
                break;
            }
        }
    }
    for(int a=0; a<5; a++) {
        for(int b=a+1; b<6; b++) {
            if(lotto[a]>lotto[b]) {
                int temp;
                temp = lotto[a];
                lotto[a] = lotto[b];
                lotto[b] = temp;
            }
        }
    }
    for(int k=0; k<6; k++) {
        fprintf(fp, "%02d ", lotto[k]);    
    }
    special = random %10+1;
    fprintf(fp, "%02d\n", special);
}

void print_nothing(int i, FILE *fp) {
    fprintf(fp, "[%d]：", i);
    for(int k=1; k<=7; k++) {
        fprintf(fp, "-- ");   
    }
    fprintf(fp, "\n");
}

int main() {
    FILE *fp;
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    int n, random;
    //n = 5;
    scanf("%d", &n);
    while(n>0) {
        if(n>5) {
        printf("請再輸入一遍(1~5張)：");
        scanf("%d", &n);
        } else {
            break;
        }   
    }
    fp = fopen("lotto.txt","w+");
    fprintf(fp, "========= lotto649 =========\n");
    time_t curtime;
    time(&curtime);
    char* tmstr = ctime(&curtime);
    size_t length = strlen(tmstr);
    tmstr[length-1] = '\0';
    fprintf(fp, "= %s =\n", tmstr);
    srand((unsigned) time(NULL));
    random = rand();
    for(int i=1; i<=5; i++) {
        if(i<=n) {
            print_number(random, i, fp);
        } else {
            print_nothing(i,fp);
        }    
    }
    fprintf(fp, "========= csie@CGU =========");
    fclose(fp);
    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt", n);
    
    
    return 0;
}