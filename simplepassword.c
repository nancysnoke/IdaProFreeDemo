#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool VerifyPassword();

int main() {
    bool verified;

    printf("Enter password => ");
    verified = VerifyPassword();
    if (verified) {
        printf("You got it!\n Congratulations.\n");
    } else {
        printf("Wrong Try again some other time!\n");
    }
      
    return 0;
}

bool VerifyPassword() {
    char myPassword[16];
    
    scanf("%s", myPassword);
    printf("Got [%s]\n", myPassword);
    if (strcmp(myPassword, "harvey") == 0) 
        return true;
    else
        return false;
}
