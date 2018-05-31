#include <stdio.h>
#include <stdint.h>

struct time
{
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
};
typedef struct time time_t;

int main (void) 
{
    time_t currentTime;

    printf("Location of hours: %p\nLocation of seconds: %p\nLocation of seconds: %p\n", &(currentTime.hours), &(currentTime.minutes), &(currentTime.seconds));

    time_t copyTime;
    copyTime = currentTime;

    printf("Location of copy-hours: %p\nLocation of copy-minutes: %p\nLocation of copy-seconds: %p\n", &(copyTime.hours), &(copyTime.minutes),&(copyTime.seconds));

    return 0;
}

// Conclusion: Memory seems to be allocated in succession for variables in structs.
