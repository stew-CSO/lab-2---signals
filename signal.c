/* signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum)
{
    printf("Hello World!\n");
}

void int_handler(int signum)
{
    printf("\nTotal execution time: %d seconds\n", alarm(0));
    exit(0);
}

int main(int argc, char *argv[])
{
    signal(SIGALRM, handler);
    signal(SIGINT, int_handler);

    while (1)
    {
        alarm(1);
        pause();
        printf("Turing was Right!\n");
    }

    return 0;
}
