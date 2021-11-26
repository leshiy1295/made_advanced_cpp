#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 10; ++i) {
        printf("Time to fork\n");
        // check with output redirecting and with/without fflush(stdout)
        fork();
        printf("Hello world\n");
    }
    printf("Bye world\n");
    return 0;
}