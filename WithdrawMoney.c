#include <stdio.h>
#include <windows.h>


void WithdrawMoney(int accountNumber)
{
    FILE *fp, *temp;
    char line[200];

    int acc, type, pin;
    long long phone;
    float balance;
    char name[40], city[30];
    float withdrawAmount;
    printf("Enter amount                 : ");
    scanf("%f",&withdrawAmount);
    printf("\n");
    fp = fopen("accounts.csv", "r");
    temp = fopen("tem.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("File opening failed!\n");
        return;
    }

    while (fgets(line, sizeof(line), fp))
    {
        sscanf(line, "%d,%39[^,],%lld,%29[^,],%d,%d,%f",
               &acc, name, &phone, city,
               &type, &pin, &balance);

        if (acc == accountNumber)
        {
            if (balance >= withdrawAmount)
            {
                balance -= withdrawAmount;
                Sleep(500);
                printf("Withdrawal successful!\n");
                Sleep(600);
                printf("Remaining Balance: %.2f\n", balance);
                Sleep(600);
            }
            else
            {
                printf("Insufficient Balance!\n");
            }
        }

        fprintf(temp, "%d,%s,%lld,%s,%d,%d,%.2f\n",
                acc, name, phone, city,
                type, pin, balance);
    }

    fclose(fp);
    fclose(temp);

    remove("accounts.csv");
    rename("tem.txt", "accounts.csv");
}