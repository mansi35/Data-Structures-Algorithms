#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]) {

    time_t seconds, diff;
    struct tm* current_time;
    struct timespec t = {1, 0};

    seconds = time(NULL);
    nanosleep(&t, NULL);

    while (difftime(seconds, time(NULL))) {
        seconds = time(NULL);
        current_time = localtime(&seconds);
        printf("%02d:%02d:%02d\n", current_time -> tm_hour,current_time -> tm_min, current_time -> tm_sec);
        nanosleep(&t, NULL);
    }
    return 0; 
}