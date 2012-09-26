#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool VerifyPassword();

int main() {
    bool verified;

    printf("Enter the super secret code => ");
    verified = VerifyPassword();
    if (verified) {
        printf("The super secret code is safe with you\n Congratulations.\n");
    } else {
        printf("Hmmm .... Its fairly simple you shouldn't have this much trouble \n");
    }
      
    return 0;
}

bool VerifyPassword() {
    char myPassword[16];
    
    scanf("%s", myPassword);
    printf("Got [%s]\n", myPassword);

    if (strlen(myPassword) != 4)
        return false;

    if (myPassword[0] != 'X')
        return false;
 
    if (!isdigit(myPassword[1]))
        return false;

    if (!isdigit(myPassword[2]))
        return false;

    if (!isdigit(myPassword[3]))
        return false;

    int num1 = myPassword[1] - '0';
    int num2 = myPassword[2] - '0';
    int num3 = myPassword[3] - '0';
    int value = num1 + num2 + num3 + 5;

    if (value == 17)
        return true;
    else
        return false;    

}
