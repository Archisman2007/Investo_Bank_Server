#include <Stdio.h>
#include <windows.h>

int CheckBalance(int accountNumber);
void WithdrawMoney(int accountNumber);
void DepositMoney(int accountNumber);
void DisplayAccountDetails(int accountNumber);


int Acc_Num;




int ViewExistingAccount()
{
    printf("--------------------------------------------------------------------------\n");
    printf("Enter Your Account Number    : ");
    int counter = 0;
    scanf("%d", &Acc_Num);
    printf("\n");
    while (counter != 1)
    {
        int returned_value = CheckAccountNumber(Acc_Num);
        if (returned_value != 1)
        {
            printf("Account number does not exist!!! \nTry again with a valid account number\n");
            printf("Enter Your Account Number    : ");
            scanf("%d", &Acc_Num);
            printf("\n");
        }
        else
            counter = 1;
    }
    printf("Enter Your PIN               : ");
    int pin;
    scanf("%d", &pin);
    printf("\n");
    counter = 0;
    int pincount=0;
    while (counter != 1)
    {
        int returned_value = CheckPin(pin);
        if (returned_value != 1)
        {
            pincount++;
            if(pincount<=3)
            {
                printf("Wrong Pin!!!\nTry again with a valid Pin\n");
                printf("Enter Your PIN               : ");
                scanf("%d", &pin);
                printf("\n");
            }
            else
            {
                printf("Maximum attempts exceeded!!!\n");
                printf("--------------------------------------------------------------------------\n");
                Sleep(1000);
                return 1;
            }
        }
        else
        {
            counter = 1;
            printf("Pin Matched\n");
            Sleep(800);
            printf("Logging In.......\n");
            Sleep(400);
        }
    }
    printf("");
    printf("");

    return 0;
}




int saved_acc_no;
int CheckAccountNumber(int acc_no)
{
    FILE *fp;
    char line[200];

    fp = fopen("accounts.csv", "r");

    if (fp == NULL)
        return 0;

    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%d", &saved_acc_no) == 1)
        {
            if (saved_acc_no == acc_no)
            {
                saved_acc_no = acc_no;
                fclose(fp);
                return 1;
            }
        }
    }

    fclose(fp);
    return 0;
}





int CheckPin(int pin)
{
    FILE *fp;
    int saved_pin, saved_account_num;
    char line[200];

    fp = fopen("accounts.csv", "r");

    if (fp == NULL)
        return 0;

    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%d,%*[^,],%*[^,],%*[^,],%*[^,],%d",
                   &saved_account_num, &saved_pin) == 2)
        {
            if (Acc_Num == saved_account_num && pin == saved_pin)
            {
                fclose(fp);
                return 1;
            }
        }
    }

    fclose(fp);
    return 0;
}






int AccountFunction()
{
    printf("\n");
    printf("--------------------------------------------------------------------------\n");
    printf("                                   🏦                                   \n");
    printf("                             Investio Bank                              \n");
    printf("                        ~~~Account Dashboard~~~                         \n");
AccountDashboard:
    printf("--------------------------------------------------------------------------\n");
    printf("Press 1 : Check Balance \t Press 4 : Account Details\n");
    printf("Press 2 : Withdraw Money \t Press 5 : Logout\n");
    printf("Press 3 : Deposit Money \t \n");
    printf("--------------------------------------------------------------------------\n");
    printf("\nEnter your choice : ");
    int choice2;
    scanf("%d", &choice2);
    printf("\n--------------------------------------------------------------------------\n");
    getchar();
    printf("\n");
    printf("");

    switch(choice2)
    {
        case 1:
        {
            CheckBalance(saved_acc_no);
            goto AccountDashboard;
        break;
        }
        case 2:
            WithdrawMoney(saved_acc_no);
            goto AccountDashboard;
        break;
        case 3:
            DepositMoney(saved_acc_no);
            goto AccountDashboard;
        break;
        case 4:
            DisplayAccountDetails(saved_acc_no);
            goto AccountDashboard;
        break;
        case 5:
        Sleep(300);
            printf("Logging Out!!!\n");
            printf("--------------------------------------------------------------------------\n");
            Sleep(500);
        break;
        default:
            printf("Enter a valid choice and try again!!!\n");
            goto AccountDashboard;

    }

    return 0;
}




void Finalmain()
{
    int pin_entered;
    pin_entered=ViewExistingAccount();
    if(pin_entered == 1)
        return;
    else
        AccountFunction();
}