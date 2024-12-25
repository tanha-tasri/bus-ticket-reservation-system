#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 5
#define MAX_SEATS 40

typedef struct {
    int bus_id;
    char route[50];
    float price;
    int seats[MAX_SEATS];
} Bus;

Bus buses[MAX_BUSES];
int num_buses = 0;

void initialize_buses() {
    // Initialize some buses with routes and prices
    strcpy(buses[0].route, "City A to City B");
    buses[0].bus_id = 1;
    buses[0].price = 50.0;
    memset(buses[0].seats, 0, sizeof(buses[0].seats));

    strcpy(buses[1].route, "City C to City D");
    buses[1].bus_id = 2;
    buses[1].price = 75.0;
    memset(buses[1].seats, 0, sizeof(buses[1].seats));

    num_buses = 2;
}

void show_buses() {
    printf("Available Bus Routes:\n");
    for (int i = 0; i < num_buses; i++) {
        printf("Bus ID: %d | Route: %s | Price: $%.2f\n", buses[i].bus_id, buses[i].route, buses[i].price);
    }
}

void show_available_seats(int bus_id) {
    printf("Available seats for Bus ID %d:\n", bus_id);
    for (int i = 0; i < MAX_SEATS; i++) {
        if (buses[bus_id - 1].seats[i] == 0) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

void book_seats(int bus_id) {
    int num_seats, seat_number;
    float total_price = 0.0;

    printf("How many seats would you like to book? ");
    scanf("%d", &num_seats);

    for (int i = 0; i < num_seats; i++) {
        printf("Enter seat number to book (1-%d): ", MAX_SEATS);
        scanf("%d", &seat_number);

        if (seat_number < 1 || seat_number > MAX_SEATS) {
            printf("Invalid seat number. Try again.\n");
            i--;
            continue;
        }

        if (buses[bus_id - 1].seats[seat_number - 1] == 0) {
            buses[bus_id - 1].seats[seat_number - 1] = 1;
            total_price += buses[bus_id - 1].price;
            printf("Seat %d booked successfully.\n", seat_number);
        } else {
            printf("Seat %d is already booked. Choose another seat.\n", seat_number);
            i--;
        }
    }

    printf("Total price: $%.2f\n", total_price);
    printf("Payment successful. Booking confirmed!\n");
}

int main() {
    int choice, bus_id;

    initialize_buses();

    while (1) {
        printf("\nBus Ticket Reservation System\n");
        printf("1. Show Available Buses\n");
        printf("2. Show Available Seats\n");
        printf("3. Book Seats\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                show_buses();
                break;

            case 2:
                printf("Enter Bus ID to view available seats: ");
                scanf("%d", &bus_id);
                if (bus_id < 1 || bus_id > num_buses) {
                    printf("Invalid Bus ID.\n");
                } else {
                    show_available_seats(bus_id);
                }
                break;

            case 3:
                printf("Enter Bus ID to book seats: ");
                scanf("%d", &bus_id);
                if (bus_id < 1 || bus_id > num_buses) {
                    printf("Invalid Bus ID.\n");
                } else {
                    book_seats(bus_id);
                }
                break;

            case 4:
                printf("Exiting the system. Thank you!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

