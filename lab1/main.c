#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#include <string.h>

FILE* lottery_txt;
FILE* binfile;
FILE* operator_id;
static int currentCount;
/*
    operator_id = fopen("operator_id.txt", "wb+");
    int people;
    scanf ("%d", &people);
    int people_ID[1];
    people_ID[0] = people;
    fwrite(operator_id, sizeof(int), 1, operator_id);
    fread()
*/
void countTimes(){
    int read[1];
    int write[1];    
    if((binfile = fopen("binfile.txt", "r")) == NULL){
        binfile = fopen("binfile.txt", "wb+");
        write[0] = 1;       
        fwrite(write, sizeof(int), 1, binfile);
    }
    else{
        binfile = fopen("binfile.txt", "rb+");
        fseek(binfile, 0, SEEK_SET);
        fread(read, sizeof(int), 1, binfile);
        fclose(binfile);    
        write[0] = read[0] + 1;
        binfile = fopen("binfile.txt", "wb+");
        fwrite(write, sizeof(int), 1, binfile);
    }
    fclose(binfile);
    currentCount = write[0];
}  

void get_6_RandNum(){
    int r[12];
    int i = 0, j, box;
    while(i<=5){
        box = rand()%69+1;
        for(j = 0; j < i; j++){
            if(box == r[j])break;
        }
        if(j == i){
            r[i] = box;
            i++;
        }
    }
    for (int a = 0; a < 6; ++a) {
        for (int b = 0; b < a; ++b) {
              if (r[b] > r[a]) {
            int temp = r[b];
            r[b] = r[a];
            r[a] = temp;
            }    
           }
    }
    r[6] = rand()%10+1;//special number
    for(j = 0; j <= 6; j++){
        fprintf(lottery_txt,"%02d ",r[j]);
    }
}
void Delay(unsigned int secs){
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);
}

int main(){
    int a, i, p;
    char currentName[80];
    int people_ID[1];//
    int read_people[1];//
    printf("welcome to the lottery machine(?)\nhow many lottery you wanna buy:");
    scanf("%d", &i);
    for(int t = 1; t <= 3; t++){
        Delay(1);
        printf(".");
    }
    Delay(1);
    printf("\noutput you %d set(s) of lottery to lotto.txt\n", i);
    printf("請輸入操作人員ID：(0~5)：");//
    int people;//
    scanf ("%d", &people);//
    people =people_ID[0] ;//
    fwrite(operator_ID, sizeof(int), 1, operator_id);//
    srand(time(NULL));
    countTimes();
    sprintf(currentName, "lotto[%04d].txt", currentCount);
    lottery_txt = fopen(currentName,"w+");
    time_t now;
    time(&now);
    char* dt = ctime(&now);
    dt[strlen(dt)-1]=0;
    fprintf(lottery_txt,"========= lotto649 =========\n= %s =\n", dt);
    fprintf(lottery_txt,"========+ No.%05d +========\n", currentCount);
    for(a = 1; a <= i; a++){
        fprintf(lottery_txt,"= [%d]:", a);
        get_6_RandNum();
        fprintf(lottery_txt,"=\n");
    }
    p = fread (read_people, sizeof(int), 1, operator_id);//
    for(; a <= 5; a++)fprintf(lottery_txt,"= [%d]:== == == == == == == =\n", a);
    fprintf(lottery_txt, "========* Op.%05d *========", operator_id[0]);//
    fprintf(lottery_txt,"========= csie@CGU =========\n");
    fclose(lottery_txt);
}



