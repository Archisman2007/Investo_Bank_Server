#include <stdio.h>
#include "AccountDetails.h"

void CopyToFile()
{
    FILE *fp = fopen("Accounts.csv", "a");
    if (fp == NULL)
    {
        printf("Error opening file !!!!!\n");
        return;
    }
    fprintf(fp, "%d,%s,%lld,%s,%d,%d,%.2f\n",
            account[i].account_number,
            account[i].customer_name,
            account[i].phone_number,
            account[i].city,
            account[i].account_type,
            account[i].pin,
            account[i].balance);
    fclose(fp);
}