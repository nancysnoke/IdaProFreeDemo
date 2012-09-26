#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool VerifyPassword();
bool VerifyZeroAndFour(char chOne, char chTwo);
int GetNum1(char chOne, char chTwo, char chThree);
int GetNum2(char chOne, char chTwo);
bool VerifyNumbers(int num1, int num2, char chOne);

int main() {
    bool verified;

    printf("Enter the password => ");
    verified = VerifyPassword();
    if (verified) {
        printf("Wow! You got it again!\n Congratulations.\n");
    } else {
        printf("Wrong!! Try again some other time!\n");
    }
      
    return 0;
}

bool VerifyPassword() {
    char myPassword[16];
    int num1= 0; 
    int num2= 0; 
  
    scanf("%s", myPassword);

    if (strlen(myPassword)!=8) 
        return false;

    if (VerifyZeroAndFour(myPassword[0], myPassword[4])) {
        num1 = GetNum1(myPassword[1], myPassword[2], myPassword[3]);
        num2 = GetNum2(myPassword[5], myPassword[6]);
        if (num1 == -1 || num2 == -1) {
            return false;
        } else {
            if (VerifyNumbers(num1, num2, myPassword[7])) {
                return true;
            } else {
                return false;     
            }
        }
    } else {
        return false;
    }
}


bool VerifyZeroAndFour(char chOne, char chTwo) {
    bool verifiedChars = false;

    if (chOne == 'X' && chTwo == 'K')
        verifiedChars = true;

    if (chOne == 'B' && chTwo == 'R')
        verifiedChars = true;

    if (chOne == 'D' && chTwo == 'W')
        verifiedChars = true;

    if (chOne == 'Q' && chTwo == 'A')
        verifiedChars = true;

    if (chOne == 'V' && chTwo == 'J')
        verifiedChars = true;

    return verifiedChars;
}


int GetNum1(char chOne, char chTwo, char chThree) {
    if (!isdigit(chOne))
        return -1;
    if (!isdigit(chTwo))
        return -1;   
    if (!isdigit(chThree))
        return -1;   

    int num1 = chOne - '0';
    int num2 = chTwo - '0';
    int num3 = chThree - '0';

    int value = (num1 + num2) % num3;

    return value;

}


int GetNum2(char chOne, char chTwo) {
    if (!isdigit(chOne))
        return -1;
    if (!isdigit(chTwo))
        return -1;   

    int num1 = chOne - '0';
    int num2 = chTwo - '0';

    int value = (num1 + num2);

    return value;

}

bool VerifyNumbers(int num1, int num2, char chOne) {
    if (!isdigit(chOne)) 
        return false;
    
    int myNum = chOne - '0';
    
    int value = (num1 * num2) % myNum;

    if (value == 3)
        return true;
    else 
       return false; 
}
