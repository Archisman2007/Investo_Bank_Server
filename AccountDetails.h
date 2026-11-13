#ifndef ACCOUNTDETAILS_H
#define ACCOUNTDETAILS_H

struct AccountDetails
{
    int account_number;
    char customer_name[40];
    long long phone_number;
    char city[30];
    int account_type;
    int pin;
    float balance;
};

extern struct AccountDetails account[1000];
extern int i;

#endif