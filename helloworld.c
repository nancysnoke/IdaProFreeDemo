#include <stdlib.h>
#include <stdio.h>

void Test1(int var1);


int main() {
    int var1 = 93;
   
    printf("Hello World\n");
    Test1(var1);

    return 0;
}

void Test1(int var1) {
    char temp[] = "Interesting";

    if (var1 == 0) {
        printf("%s \n", temp);
    }
}
