
#include <stdio.h>
#include<windows.h>

void DisplayAccountDetails(int accountNumber)
{
    FILE *fp;
    char line[200];

    int acc, type, pin;
    long long phone;
    float balance;

    char name[40], city[30];

    fp = fopen("accounts.csv", "r");

    if (fp == NULL)
    {
        printf("Unable to open accounts.csv!\n");
        return;
    }

    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%d,%39[^,],%lld,%29[^,],%d,%d,%f",
                   &acc, name, &phone, city,
                   &type, &pin, &balance) == 7)
        {
            if (acc == accountNumber)
            {
                printf("\n");
                printf("Account Number  : %d\n", acc);
                printf("Customer Name   : %s\n", name);
                printf("Phone Number    : %lld\n", phone);
                printf("City            : %s\n", city);

                printf("Account Type    : ");
                if (type == 1)
                    printf("Savings Account\n");
                else if (type == 2)
                    printf("Current Account\n");

                printf("Account Balance : Rs. %.2f\n", balance);
                Sleep(1000);
                
                printf("\n\n");

                fclose(fp);
                return;
            }
        }
    }

    printf("Account details not found!\n");

    fclose(fp);
}
