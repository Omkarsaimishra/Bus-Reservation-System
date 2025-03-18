#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define HLINE "================================================================"
#define VLINE "||                                                              ||"
#define CLEAR system("cls")

char ch[10][130] = {"Mo Bus route number 19","OSRTC","op travels","Mo Bus route number 18","Shiv Shakti Transport","Mo Bus route number 17 ac"};
char name[32][100] = {'\0'};
char number[32][2] = {'\0'};
int num1[32] = {0};
int trno;

// Function prototypes
void printHeader();
void bus();
void name_number(int booking, char numstr[100], int booked_seats);
void booking();
int read_number(int trno);
void read_name(int trno);
void status();
void status_1(int trno);
void cancle();
void login();
void printBoxedText(char* text);
void seatGrid();
void printMainMenu();
void printExitScreen();
void printBusStatusHeader();

// Graphical elements
void printHeader() {
    CLEAR;
    printf("\n\n%s\n", HLINE);
    printf("||                BUS RESERVATION SYSTEM                      ||\n");
    printf("%s\n\n", HLINE);
}

void printBoxedText(char* text) {
    printf("||  %-60s  ||\n", text);
}

void seatGrid() {
    printf("\n");
    printf("       =======================     =======================\n");
    printf("       | 1 | 2 | 3 | 4 |         | 5 | 6 | 7 | 8 |       \n");
    printf("       =======================     =======================\n");
    printf("       | 9 |10 |11 |12 |         |13 |14 |15 |16 |       \n");
    printf("       =======================     =======================\n");
    printf("       |17 |18 |19 |20 |         |21 |22 |23 |24 |       \n");
    printf("       =======================     =======================\n");
    printf("       |25 |26 |27 |28 |         |29 |30 |31 |32 |       \n");
    printf("       =======================     =======================\n\n");
}

void login() {
    char uname[10];
    char pword[10];
    char c;
    int i = 0;

    do {
        printHeader();
        printf("||                   LOGIN PAGE                            ||\n");
        printf("%s\n", HLINE);
        printf("||                   -----------                          ||\n");
        printf("||                  ENTER USERNAME:                        ||\n");
        printf("||                  > ");
        scanf("%9s", uname);
        printf("||                  ENTER PASSWORD:                        ||\n");
        printf("||                  > ");

        i = 0;
        while(i < 9) {
            c = getch();
            if(c == '\r') break;
            pword[i++] = c;
            printf("*");
        }
        pword[i] = '\0';

        if(strcmp(uname,"user") == 0 && strcmp(pword,"pass") == 0) {
            printf("\n%s\n", HLINE);
            printf("||                LOGIN SUCCESSFUL!                         ||\n");
            printf("%s\n", HLINE);
            printf("\nPress any key to continue...");
            getch();
            break;
        } else {
            printf("\n%s\n", HLINE);
            printf("||              INVALID CREDENTIALS!                        ||\n");
            printf("%s\n", HLINE);
            printf("Press any key to try again...");
            getch();
        }
    } while(1);
}

void printMainMenu() {
    printHeader();
    printf("||                     MAIN MENU                            ||\n");
    printf("%s\n", HLINE);
    printBoxedText("1. View Bus List");
    printBoxedText("2. Book Tickets");
    printBoxedText("3. Cancel Booking");
    printBoxedText("4. Bus Status Board");
    printBoxedText("5. Exit");
    printf("%s\n", HLINE);
    printf("\nEnter your choice: ");
}

void bus() {
    printHeader();
    printf("||                    AVAILABLE BUSES                       ||\n");
    printf("%s\n", HLINE);
    for(int i = 0; i < 5; i++) {
        printf("||  %d. %-55s||\n", i+1, ch[i]);
    }
    printf("%s\n", HLINE);
    printf("\nPress any key to return to main menu...");
    getch();
}

void booking() {
    int i=0;
    char numstr[100];
    
    printHeader();
    printf("||                    TICKET BOOKING                         ||\n");
    printf("%s\n\n", HLINE);
    bus();
    printf("\nEnter the Bus number: ");
    scanf("%d",&trno);

    printHeader();
    printf("||                  SELECT YOUR SEATS                        ||\n");
    printf("%s\n\n", HLINE);
    status_1(trno);

    int booked_seats = read_number(trno);
    int available_seats = 32 - booked_seats;
    
    if(available_seats <= 0) {
        printHeader();
        printf("||              NO SEATS AVAILABLE!                          ||\n");
        printf("%s\n", HLINE);
        getch();
        return;
    }

    printf("\n\n\tAvailable Seats: %d\n", available_seats);
    printf("\tNumber of Tickets: ");
    int booking;
    scanf("%d",&booking);

    if(booking > available_seats) {
        printHeader();
        printf("||          NOT ENOUGH SEATS AVAILABLE!                    ||\n");
        printf("%s\n", HLINE);
        getch();
        return;
    }

    itoa(trno,numstr,10);
    name_number(booking, numstr, booked_seats);
    
    printHeader();
    printf("||                    PAYMENT DETAILS                         ||\n");
    printf("%s\n", HLINE);
    printf("\tTotal Amount: Rs.%d\n", 200*booking);
    printf("%s\n", HLINE);
    printf("\nPress any key to confirm payment...");
    getch();
}

void name_number(int booking, char numstr[100], int booked_seats) {
    char tempstr[100], tempstr1[20] = "status", tempstr2[20] = "number";
    FILE *a, *b;
    int current_seats[32] = {0};
    int current_count = 0;

    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);
    a = fopen(tempstr1, "a");
    b = fopen(tempstr2, "a");

    for(int i = 0; i < booking; i++) {
        int seat_number;
        while(1) {
            printHeader();
            printf("||                  PASSENGER DETAILS %02d                      ||\n", i+1);
            printf("%s\n", HLINE);
            seatGrid();
            printf("\tSeat Number: ");
            scanf("%d", &seat_number);

            if(seat_number < 1 || seat_number > 32) {
                printf("\nInvalid seat number. Please choose between 1 and 32.\n");
                printf("Press any key to continue...");
                getch();
                continue;
            }

            int is_booked = 0;
            // Check existing bookings
            for(int j = 0; j < booked_seats; j++) {
                if(num1[j] == seat_number) {
                    is_booked = 1;
                    break;
                }
            }
            // Check current session
            for(int j = 0; j < current_count; j++) {
                if(current_seats[j] == seat_number) {
                    is_booked = 1;
                    break;
                }
            }

            if(is_booked) {
                printf("\nSeat %d is already booked. Please choose another seat.\n", seat_number);
                printf("Press any key to continue...");
                getch();
            } else {
                current_seats[current_count++] = seat_number;
                break;
            }
        }

        printf("\tPassenger Name: ");
        scanf("%s", name[seat_number - 1]);
        fprintf(a, "%s ", name[seat_number - 1]);
        fprintf(b, "%d ", seat_number);
    }
    fclose(a);
    fclose(b);
}

int read_number(int trno) {
    char tempstr2[20] = "number";
    FILE *a;
    char numstr[100];
    int i = 0, j = 0;

    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr2, numstr);
    a = fopen(tempstr2, "r");

    if (a == NULL) {
        return 0;
    }

    while(fscanf(a, "%d", &num1[i]) != EOF) {
        i++;
    }
    fclose(a);
    return i;
}

void read_name(int trno) {
    char tempstr1[20] = "status";
    FILE *b;
    char numstr[100];
    int i = 0, j = 0;

    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    b = fopen(tempstr1, "r");

    if (b == NULL) {
        return;
    }

    while(fscanf(b, "%s", name[i]) != EOF) {
        i++;
    }
    fclose(b);
}

void status() {
    printHeader();
    printf("||                  BUS STATUS BOARD                         ||\n");
    printf("%s\n", HLINE);
    int trno;
    printf("\tEnter Bus Number: ");
    scanf("%d",&trno);
    status_1(trno);
    printf("\nPress any key to continue...");
    getch();
}

void status_1(int trno) {
    int j = read_number(trno);
    read_name(trno);
    char tempname[33][10] = {"Empty"};

    printHeader();
    printf("||                  SEAT AVAILABILITY                        ||\n");
    printf("%s\n", HLINE);
    printf("\tBus Number: %d (%s)\n\n", trno, ch[trno-1]);

    // Create tempname array with passenger names
    for(int i = 0; i < j; i++) {
        if(num1[i] > 0 && num1[i] <= 32) {
            strcpy(tempname[num1[i]], name[i]);
        }
    }

    // Display seats in grid format
    for(int i = 0; i < 32; i += 8) {
        // First section
        for(int s = i; s < i+4; s++) {
            printf(" %2d.%-8s", s+1, tempname[s+1]);
        }
        printf("     |     ");
        // Second section
        for(int s = i+4; s < i+8; s++) {
            printf(" %2d.%-8s", s+1, tempname[s+1]);
        }
        printf("\n");
    }

    int available = 0;
    for(int i = 1; i <= 32; i++) {
        if(strcmp(tempname[i], "Empty") == 0) available++;
    }

    printf("\n%s\n", HLINE);
    printf("||               Available Seats: %-2d                     ||\n", available);
    printf("%s\n", HLINE);
    printf("\nPress any key to continue...");
    getch();
}

void cancle() {
    printHeader();
    printf("||                  CANCEL BOOKING                           ||\n");
    printf("%s\n", HLINE);
    int seat_no;
    printf("\tEnter Bus Number: ");
    scanf("%d",&trno);
    printf("\tEnter Seat Number: ");
    scanf("%d",&seat_no);
    
    char numstr[100], tempstr2[20] = "number", tempstr1[20] = "status";
    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);
    
    int booked_seats = read_number(trno);
    read_name(trno);
    
    FILE *a, *b;
    a = fopen(tempstr1, "w");
    b = fopen(tempstr2, "w");
    
    for(int i = 0; i < booked_seats; i++) {
        if(num1[i] != seat_no) {
            fprintf(b, "%d ", num1[i]);
            fprintf(a, "%s ", name[i]);
        }
    }
    fclose(a);
    fclose(b);
    
    printHeader();
    printf("||               CANCELLATION SUCCESSFUL                     ||\n");
    printf("%s\n", HLINE);
    printf("\tRefund Amount: Rs.200\n");
    printf("%s\n", HLINE);
    printf("\nPress any key to continue...");
    getch();
}

int main() {
    login();
    int choice;
    
    do {
        printMainMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: bus(); break;
            case 2: booking(); break;
            case 3: cancle(); break;
            case 4: status(); break;
            case 5: 
                printHeader();
                printf("||         THANK YOU FOR USING OUR SYSTEM!               ||\n");
                printf("%s\n", HLINE);
                exit(0);
            default:
                printHeader();
                printf("||              INVALID CHOICE!                         ||\n");
                printf("%s\n", HLINE);
                printf("Press any key to continue...");
                getch();
        }
    } while(1);

    return 0;
}