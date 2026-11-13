#include <stdio.h>
void CreateNewAccountFinal();
void Finalmain();

int main()
{
    printf("--------------------------------------------------------------------------\n");
    printf("                                   🏦                                   \n");
    printf("                             Investio Bank                              \n");
    printf("                    ~~~Welcome To The Bank Server~~~                    \n");
    printf("--------------------------------------------------------------------------\n");
    toppage:
    printf("\n");
    printf("Press 1 : To create new Account\n");
    printf("Press 2 : To view existing Account\n");
    printf("Press 3 : To exit\n\n");
    printf("Enter your choise : ");
    int decide1;
    scanf("%d", &decide1);
    printf("\n");
    //printf("--------------------------------------------------------------------------\n");
    getchar();
    switch (decide1)
    {
    case 1:
        CreateNewAccountFinal();
        goto toppage;
        break;
    case 2:
        Finalmain();
        goto toppage;
        break;
    case 3:
        printf("\nThank You for choosing us!!! \nVisit Again\n");
        printf("--------------------------------------------------------------------------\n");
        return 0;
        break;
    default:
        printf("Enter a valid choice and try again!!!\n");
        printf("--------------------------------------------------------------------------\n");
        goto toppage;
    }

    return 0;
}