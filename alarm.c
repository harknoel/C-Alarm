#include <stdio.h>
#include <time.h>
#include <windows.h>
int main(void)
{
    printf("Started\n");

    while(1)
    {
        // time_t is a double data type.
        time_t today = time(NULL);                          // Number of secs since Epoch (July 1, 1970).
        struct tm *local_time = localtime(&today);          // Assigns secs into a time and date format in the struct tm.

        if((local_time->tm_min == 24 || local_time->tm_min == 59) && local_time->tm_sec == 0)    // Since local_time is a pointer itself, and to access the tm_min struct we use ->.
        {
            printf("Alarmed on: %s", asctime(local_time));                                      // The purpose of asctime() function is to get all the data assigned to tm (a struct that assigns seconds into months, etc.)
            for(int i = 0; i < 10; i++)
            {
                printf("%d\n", i);
                MessageBeep(MB_ICONINFORMATION);            // Microsoft default beep.        
                Sleep(1000);                                // 1 seconds is equivalen to 1000 milliseconds.
            }   
        }
    }


    return 0;
}

