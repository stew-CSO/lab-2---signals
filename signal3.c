/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

volatile int alarm_count = 0;       // To count the number of SIGALRM signals
time_t program_start_time; // To store the program start time

void sigalrm_handler(int signum)
{ // SIGALRM handler
    alarm_count++;
}

void sigint_handler(int signum)
{ // SIGINT handler (CTRL-C)
    time_t program_end_time;
    double execution_time;

    program_end_time = time(NULL);
    execution_time = difftime(program_end_time, program_start_time);

    printf("\nTotal alarms occurred: %d\n", alarm_count);
    printf("Program executed for %.0lf seconds.\n", execution_time);
    exit(0);
}

int main(int argc, char *argv[])
{
    struct sigaction sa;

    // Register SIGALRM handler
    sa.sa_handler = sigalrm_handler;
    sigaction(SIGALRM, &sa, NULL);

    // Register SIGINT handler
    signal(SIGINT, sigint_handler);

    // Set up the timer to send SIGALRM every 1 second
    alarm(1); // Schedule a SIGALRM for 1 second
    program_start_time = time(NULL); // Record program start time

    while (1)
    {
        // Wait for signals
        pause();
    }

    return 0; // This is never reached
}
