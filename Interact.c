#include "Interact.h"
#include "reminder.h"


void readingFromFile(void) {
    FILE *file = fopen("reminders.txt", "r");  // Open the file in read mode
    if (file == NULL) {
        printf("Failed to open file for reading.\n");
        return;
    }
    char line[MAX_STR_LEN];
    char reminder[MAX_STR_LEN];
    int day;
    while (fgets(line, sizeof(line), file) != NULL)   {
	 if (sscanf(line, "%d %[^\n]", &day, reminder) == 2) {

		insert_to_calendar(day, reminder);

        } else {
		continue;
	}
    }

    fclose(file);  
}

/*
*/
void writingToFile(void) {
    FILE* file = fopen("reminders.txt", "w");  // Open the file in write mode
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }

    // Iterate through all the days and write the reminders to the file
    for (int i = 0; i < November.month_days; i++) {  // Use the actual number of days in the month
        if (November.reminderNodes[i] != NULL) {    // Check if there are reminders for the day
            struct Node* current = November.reminderNodes[i];  // Get linked list for the day
            while (current != NULL) {
                // Write day and reminder exactly as entered
                fprintf(file, "%d %s\n", i + 1, current->reminder);
                current = current->next;  // Move to the next reminder in the list
            }
        }
    }

    fclose(file);  // Close the file after writing
    printf("Reminders saved successfully to reminders.txt.\n");
}

