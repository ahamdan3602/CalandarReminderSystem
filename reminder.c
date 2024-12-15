#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "reminder.h"

//Insets a reminder on a specific dat in the calendar
void insert_to_calendar(int day, const char* value) // Day is the day of the month we want to insert, and value is the reminder to store for that day
{
	if (day < 1 || day > November.month_days) {
		printf("Invalid day:: The day must be >= 1 and <= 31 days \n");
		return;
	}

       	
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) {
		return;
	}
	strncpy(newNode->reminder, value, MAX_STR_LEN - 1);
	newNode->reminder[MAX_STR_LEN-1] = '\0';
	newNode->next = NULL;
	if (November.reminderNodes[day-1] == NULL) {
		November.reminderNodes[day-1] = newNode;
	} else {
		struct Node* curr = November.reminderNodes[day-1];
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
	November.reminders[day-1] = true;

}


int read_reminder(char *str, int n) 
{ 
    int day;
    scanf("%d", &day);
    if (day == 0) { // Reads a value from the user and assigns it to day. If day = 0, then simply return 0.
	    return 0;
    }
    getchar(); // Gets rid of the space character from the input buffer
    fgets(str, n, stdin); // Reads the reminder
    return day;
}

const char* get_weekday_name(int day_index) {
    const char* days_of_week[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return days_of_week[day_index % 7];
}
void print_calendar() {
    int y = 1;
    int c = 0;
    int dayReminders[31];
    int dayWeek = November.start_day+1; // Starting day of the month

    printf("\nSun Mon Tue Wed Thu Fri Sat\n");

    int week_day = November.start_day+1;
    for (int i = 1; i < week_day; i++) {
        printf("    ");
        }
    int daysCounter[31];
    int total_days = November.month_days;
    while (y <= total_days) {
        for (int i = week_day; i <= 7 && y <= total_days; i++) {
            if (November.reminders[y-1]) {
                dayReminders[c] = y;
                daysCounter[c++] = y;
                printf("(%2d)", y); // Print day with reminder in parentheses
            } else
                printf(" %2d", y); // Print day without reminder
            y++;
        }
        printf("\n");
        week_day = 1; // Reset for next week
    }
   int r = 1;
   if (c > 0) {
    printf("Reminders:\n");
    for (int i = 0; i < c; i++) {
        struct Node* current = November.reminderNodes[dayReminders[i] - 1];
        printf("%s %2d:\n", get_weekday_name(daysCounter[i]), dayReminders[i]);
        while (current != NULL) {
            printf("\t(%d) %s\n", r, current->reminder); // Print each reminder
            current = current->next;
            r++;
        }
    }
}


    printf("---------------------------\n");
}
