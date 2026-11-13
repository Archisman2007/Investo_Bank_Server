#include <stdio.h>
#include <windows.h>


void DepositMoney(int accountNumber)
{
    FILE *fp, *temp;
    char line[200];

    int acc, type, pin;
    long long phone;
    float balance;
    char name[40], city[30];
    float depositAmount;
    printf("Enter amount to be deposited : ");
    scanf("%f",&depositAmount);
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
                balance += depositAmount;
                Sleep(500);
                printf("Deposit successful!\n");
                Sleep(600);
                printf("Available Balance: %.2f\n", balance);
                Sleep(600);
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