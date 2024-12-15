#include "reminder.h"
#include "Interact.h"
#include <signal.h>
#include <stdbool.h>
#include <time.h>

struct Month November; 
struct Month month;

void handle_signal(int signal) {
	printf("\nProgram terminated...\n");
	writingToFile() ;
	printf("Writing to file...\n");
	exit (0);
}
int main() {

    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);
    signal(SIGSEGV, handle_signal);    
    initializeMonth();
    

    November.start_day = month.start_day;
    November.month_days = month.month_days;

    for (int i = 0; i < November.month_days; i++) {
        November.reminders[i] = false;
	November.reminderNodes[i] = NULL;
    }
    readingFromFile();
    char str[MAX_STR_LEN];
    int day;
    int v = true;
    //While loop to read user input, until the user enters 0 to quit
    while (v) {
        printf("\nEnter day and reminder (0 to quit): ");
        day = read_reminder(str, MAX_STR_LEN);
        if (day == 0) {
            v = false;
        } else {
            insert_to_calendar(day, str);
            print_calendar();
        }
    }
    writingToFile();
 
    return 0;
}
void initializeMonth(void) {
 time_t now = time(NULL);
 struct tm *t = localtime(&now);
 month.month_idx = t->tm_mon;

 t->tm_mday = 1;
 mktime(t);
 month.start_day = t->tm_wday;

 month.month_days = t->tm_mday;
 while (t->tm_mon == month.month_idx){
 month.month_days = t->tm_mday;
 t->tm_mday++;
 mktime(t);
 }
}

