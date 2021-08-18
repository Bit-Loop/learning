// itj aug/18/21
#include <stdio.h>

int main(void) {
    
	int dayOfWeek = 1;
	char days[8][10] = {
	    "", // place holder, wastes some space but arrays start at 0.
	    "Monday",
	    "Tuesday",
	    "Wednesday",
	    "Thursday",
	    "Friday",
	    "Saturday",
	    "Sunday"
	}; 
    // Test for all days in the week
    if (0 < dayOfWeek && dayOfWeek <= 7)
        printf("The day of the week is: %s\n", days[dayOfWeek]);
	return 0;
}