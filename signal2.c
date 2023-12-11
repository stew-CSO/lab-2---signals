/* signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile int handler_called = 0; // Global variable to indicate if the handler has been called

void handler(int signum)
{ // Signal handler
    printf("Hello World!\n");
    handler_called = 1; // Set the flag to indicate the handler has been called
    alarm(1); // Schedule a SIGALRM for 1 second
}

int main(int argc, char *argv[])
{
    signal(SIGALRM, handler); // Register handler to handle SIGALRM
    alarm(1); // Schedule a SIGALRM for 1 second

    while (1)
    {
        while (!handler_called)
        {
            // Busy wait for the signal handler to be called
        }

        printf("Turing was right!\n"); // Print this message after the handler is called
        handler_called = 0; // Reset the flag
    }

    return 0; // This is never reached
}
