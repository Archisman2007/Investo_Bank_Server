#include<stdio.h>
#include <windows.h>



int CheckBalance(int accountNumber)
{
    FILE *fp;
    char line[200];
    int Acc_Num;
    float bal;

    fp = fopen("accounts.csv", "r");

    if (fp == NULL){
        printf("File opening failed!\n");
        return 0;
    }

    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%d,%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%f" , &Acc_Num, &bal) == 2)
        {
            if (Acc_Num == accountNumber)
            {
                Sleep(500);
                printf("Current balance is           : %.2f\n\n",bal);
                fclose(fp);  
                return 1;
            }
        }
    }

    fclose(fp);


    return 0;
}