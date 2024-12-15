#ifndef REMINDER_H
#define REMINDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_STR_LEN 100
struct Node {
        char reminder[MAX_STR_LEN]; /* data stored in the node */
        struct Node* next; /* Pointer to the next node */
};

struct Month{
	int month_idx;
	int month_days;
	int start_day;
	struct Node* reminderNodes[31];
	bool reminders[31]; 
};
extern struct Month November; 
/*
Takes a reminder string and a day number and inserts the reminder into the calendar.
Also, sets the reminder flag to true for that day.
 */
void insert_to_calendar(int day, const char* value) ;

/*
Takes a char array and its length and reads a reminder from the user.
Returns the day number.
 */
int read_reminder(char *str, int n) ;

const char* get_weekday_name(int day_index);
/*
Prints the calendar and the reminders for each day.	
 */
void print_calendar(void);

void initializeMonth(void);
#endif
