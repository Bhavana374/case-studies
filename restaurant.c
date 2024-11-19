#include <stdio.h>
#include <string.h>

#define MAX_TABLES 10
#define NAME_LENGTH 50

// Structure to hold reservation information
typedef struct {
    int tableNumber;
    char name[NAME_LENGTH];
    char surname[NAME_LENGTH];
    int isReserved;
} Table;

// Function to display available tables
void displayTables(Table tables[], int totalTables) {
    printf("\nAvailable tables:\n");
    int i;
    for (i = 0; i < totalTables; i++) {
        if (!tables[i].isReserved) {
            printf("Table %d is available\n", tables[i].tableNumber);
        }
    }
}

// Function to reserve a table
void reserveTable(Table tables[], int totalTables) {
    int tableNumber;
    char name[NAME_LENGTH], surname[NAME_LENGTH];

    printf("Enter the table number you want to reserve: ");
    scanf("%d", &tableNumber);

    // Check if the table number is valid
    if (tableNumber < 1 || tableNumber > totalTables) {
        printf("Invalid table number!\n");
        return;
    }

    // Check if the table is already reserved
    if (tables[tableNumber - 1].isReserved) {
        printf("Table %d is already reserved!\n", tableNumber);
        return;
    }

    // Get the name and surname of the customer
    printf("Enter your first name: ");
    scanf("%s", name);
    printf("Enter your surname: ");
    scanf("%s", surname);

    // Reserve the table
    tables[tableNumber - 1].isReserved = 1;
    strcpy(tables[tableNumber - 1].name, name);
    strcpy(tables[tableNumber - 1].surname, surname);
    printf("Table %d reserved successfully for %s %s.\n", tableNumber, name, surname);
}

// Function to cancel a reservation
void cancelReservation(Table tables[], int totalTables) {
    int tableNumber;

    printf("Enter the table number you want to cancel the reservation for: ");
    scanf("%d", &tableNumber);

    // Check if the table number is valid
    if (tableNumber < 1 || tableNumber > totalTables) {
        printf("Invalid table number!\n");
        return;
    }

    // Check if the table is reserved
    if (!tables[tableNumber - 1].isReserved) {
        printf("Table %d is not reserved.\n", tableNumber);
        return;
    }

    // Cancel the reservation
    tables[tableNumber - 1].isReserved = 0;
    printf("Reservation for table %d canceled successfully.\n", tableNumber);
}

// Main function
int main() {
    Table tables[MAX_TABLES];

    // Initialize all tables as not reserved
    int i;
    for (i = 0; i < MAX_TABLES; i++) {
        tables[i].tableNumber = i + 1;
        tables[i].isReserved = 0;
    }

    int choice;

    while (1) {
        printf("\nRestaurant Table Reservation System\n");
        printf("1. Display available tables\n");
        printf("2. Reserve a table\n");
        printf("3. Cancel a reservation\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTables(tables, MAX_TABLES);
                break;
            case 2:
                reserveTable(tables, MAX_TABLES);
                break;
            case 3:
                cancelReservation(tables, MAX_TABLES);
                break;
            case 4:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

