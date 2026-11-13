#include <stdio.h>
#include <string.h>
#include <windows.h>
void CopyToFile();

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

struct AccountDetails account[1000];
int i = 0;
int next_account_number;

int CreateNewAccount()
{

    printf("--------------------------------------------------------------------------");
    printf("\nEnter Customer name                         : ");
    scanf(" "); // removing buffer
    fgets(account[i].customer_name, sizeof(account[i].customer_name), stdin);
    account[i].customer_name[strcspn(account[i].customer_name, "\n")] = '\0';
    printf("\nEnter Customer Phone Number                 : ");
    scanf("%lld", &account[i].phone_number);
    getchar(); // rectifying string buffering
    printf("\nEnter Customer city                         : ");
    fgets(account[i].city, sizeof(account[i].city), stdin);
    account[i].city[strcspn(account[i].city, "\n")] = '\0';
    printf("\nEnter account type (1.Savings   2.Current)  : ");
    scanf("%d", &account[i].account_type);
    printf("\nEnter a PIN for your account (1000-9999)    : ");
    int PIN;
    do
    {
        scanf("%d", &PIN);
        if (PIN < 1000 || PIN > 9999) // checking for pin to be 4 digit if not then re entering
            printf("\nPin Should be in between 1000 and 9999 : ");
        else
            account[i].pin = PIN;
    } while (PIN < 1000 || PIN > 9999);
    printf("--------------------------------------------------------------------------\n");

    return 0;
}

int GetNextAccountNumber()
{
    FILE *fp;
    int acc_no, last_acc_no = 999;
    char line[200];

    fp = fopen("accounts.csv", "r");

    if (fp == NULL)
        return 1000;

    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%d", &acc_no) == 1)
        {
            if (acc_no > last_acc_no)
                last_acc_no = acc_no;
        }
    }

    fclose(fp);
    return last_acc_no + 1;
}

int GeneratingAccountNumber()
{
    // generates account number as 1000 then 1001 then 1002........
    next_account_number = GetNextAccountNumber();
    account[i].account_number = next_account_number;
    printf("Creating Account....\n");
    Sleep(400);
    printf("Your Account Number is : %d \n", account[i].account_number);
    return 0;
}

int AddingBalance()
{
    printf("\nEnter amount of money you want to deposit(minimum Rs.3000) : ");
    getchar(); // rectifying string buffering
    do
    {
        scanf("%f", &account[i].balance);
        if (account[i].balance < 3000)
            printf("\nEnter amount greater than or equal to Rs.3000 : ");
    } while (account[i].balance < 3000);
    printf("\nUpdated Balance : %.2f ", account[i].balance);
    printf("\n--------------------------------------------------------------------------\n");
    return 0;
}

void CreateNewAccountFinal()
{
    CreateNewAccount();
    GeneratingAccountNumber();
    AddingBalance();
    CopyToFile(); // uses the copy to file to save the data in csv file...
    i++;
}

// void main()
//{
//     CreateNewAccountFinal();
// }