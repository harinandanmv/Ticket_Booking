#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLS 5
#define MAX_WAITLIST 10
#define MAX_USERS 3

char usernames[MAX_USERS][30] = {"user1", "user2", "user3"};
char passwords[MAX_USERS][20] = {"pass1", "pass2", "pass3"};

char seats[ROWS][COLS][30];
char waitlist[MAX_WAITLIST][30];
int waitlistSize = 0;

char currentUser[30];

void initializeSeats() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            strcpy(seats[i][j], "EMPTY");
        }
    }
}

int isWaitlistFull() {
    return waitlistSize >= MAX_WAITLIST;
}

void addToWaitlist(char name[]) {
    if (!isWaitlistFull()) {
        strcpy(waitlist[waitlistSize], name);
        waitlistSize++;
        printf("%s added to the waitlist.\n", name);
    } else {
        printf("Waitlist is full. Cannot add %s.\n", name);
    }
}

void displaySeats() {
    int i, j;
    printf("\nCurrent Seating Arrangement:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("[%s] ", seats[i][j]);
        }
        printf("\n");
    }
}

void displayWaitlist() {
    int i;
    if (waitlistSize == 0) {
        printf("Waitlist is empty.\n");
    } else {
        printf("\nCurrent Waitlist:\n");
        for (i = 0; i < waitlistSize; i++) {
            printf("%d. %s\n", i + 1, waitlist[i]);
        }
    }
}

int login() {
    char username[30], password[20];
    int i;
    printf("Enter username: ");
    scanf(" %[^\n]", username);
    printf("Enter password: ");
    scanf(" %[^\n]", password);

    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(username, usernames[i]) == 0 && strcmp(password, passwords[i]) == 0) {
            strcpy(currentUser, username);
            printf("Login successful. Welcome, %s!\n", currentUser);
            return 1;
        }
    }

    printf("Invalid username or password.\n");
    return 0;
}

void bookTicket() {
    char name[30];
    int row, col;
    int i, j;
    int seatBooked = 0;

    printf("Enter your name: ");
    scanf(" %[^\n]", name);

    while (!seatBooked) {
        printf("Enter row number (1 to %d): ", ROWS);
        scanf("%d", &row);

        printf("Enter column number (1 to %d): ", COLS);
        scanf("%d", &col);

        if (row < 1 || row > ROWS || col < 1 || col > COLS) {
            printf("Invalid seat position.\n");
            continue;
        }

        if (strcmp(seats[row - 1][col - 1], "EMPTY") == 0) {
            strcpy(seats[row - 1][col - 1], name);
            printf("Seat booked for %s at Row %d, Column %d.\n", name, row, col);
            seatBooked = 1;
        } else {
            printf("Seat is already booked.\n");
            int foundEmpty = 0;
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    if (strcmp(seats[i][j], "EMPTY") == 0) {
                        foundEmpty = 1;
                        break;
                    }
                }
                if (foundEmpty) break;
            }
            if (foundEmpty) {
                printf("Other seats are available. Please choose a different seat.\n");
            } else {
                printf("No seats available. Adding %s to waitlist.\n", name);
                addToWaitlist(name);
                seatBooked = 1;
            }
        }
    }
}

void cancelTicket() {
    char name[30];
    int numSeats, i, j;
    int hasBookings = 0;

    printf("Enter your name for cancellation: ");
    scanf(" %[^\n]", name);

    printf("Seats booked under your name:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (strcmp(seats[i][j], name) == 0) {
                printf("Row %d, Column %d\n", i + 1, j + 1);
                hasBookings = 1;
            }
        }
    }

    if (!hasBookings) {
        printf("No bookings found under your name.\n");
        return;
    }

    printf("How many seats do you want to cancel? ");
    scanf("%d", &numSeats);

    for (i = 0; i < numSeats; i++) {
        int row, col;
        printf("Enter seat %d to cancel (row column): ", i + 1);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > ROWS || col < 1 || col > COLS) {
            printf("Invalid seat position.\n");
            continue;
        }

        if (strcmp(seats[row - 1][col - 1], name) == 0) {
            printf("Cancelling seat at Row %d, Column %d.\n", row, col);
            strcpy(seats[row - 1][col - 1], "EMPTY");

            if (waitlistSize > 0) {
                strcpy(seats[row - 1][col - 1], waitlist[0]);
                printf("%s moved from waitlist to Row %d, Column %d.\n", waitlist[0], row, col);

                for (j = 1; j < waitlistSize; j++) {
                    strcpy(waitlist[j - 1], waitlist[j]);
                }
                waitlistSize--;
            }
        } else {
            printf("Seat at Row %d, Column %d is not booked under your name.\n", row, col);
        }
    }
}

int main() {
    int choice;
    initializeSeats();

    if (!login()) {
        printf("Exiting program.\n");
        return 0;
    }

    do {
        printf("\n--- Theater Booking Menu ---\n");
        printf("1. Book a Ticket\n");
        printf("2. Cancel a Ticket\n");
        printf("3. Display Seating Arrangement\n");
        printf("4. Display Waitlist\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                cancelTicket();
                break;
            case 3:
                displaySeats();
                break;
            case 4:
                displayWaitlist();
                break;
            case 5:
                printf("Thank you for using the booking system!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}