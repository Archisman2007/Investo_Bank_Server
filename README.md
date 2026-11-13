# Investo_Bank_Server
This is a basic c project...

## Concepts used in this project : 
1. Array
2. String
3. Structure
4. Switch case
5. Files(creation,checking,reading,re-writing at a desired position,comaring multiple values)
6. Calling method of one file into another
7. Header file use
8. Pointer and '&'

## What we can do :
Here we can create a bank account with the necessary details which will provide a account number and the user have to set a pin....We can view existing account by logging in by providing the users account number and pin. 1st it checks whether the account number exists or not if it exists then the program will ask for the pin(user have 3 tries to enter the pin correctly, if user fails to do so then it will get back to the welcome menu)....after logging in(if account number and its corresponding pin matched) the user is taken to the account dashboard where the user can check his/her balance, withdraw money, deposit money, view account details and logout....for withdrawing money the program check whether user has more than the amount he/she wants to withdraw....After logging out the server goes back to the welcome menu.

## Programming language used :
1. C programming language

## How to run the code :

The following code was tested using MinGW compiler( https://sourceforge.net/projects/mingw/ ) ....one must have the compiler installed and setup before running the code.

1. Download all the codes from here and store it in a file
2. open that file and navigate to the address bar
3. clear the address and type 'cmd'(which will open the command prompt)
4. type 'gcc *.c -o BankSystem.exe'(which will compile all .c files at once)
5. then type '.\BankSystem'(which will run the code for bank server)


## "C is a hard language....but practice makes it easier😎"
