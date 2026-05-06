#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "customer.h"
#include "artist.h"
#include "service.h"
#include "appointment.h"

int isValidDate(int year, int month, int day);
int isInFuture(int year, int month, int day);

int main() {

    Customer* customers = NULL;
    Artist* artists = NULL;
    Service services[MAX_SERVICES];
    int serviceCount = 0;
    Appointment* appointments = NULL;

    loadCustomers(&customers, "customers.txt");
    loadArtists(&artists, "artists.txt");
    loadServices(services, &serviceCount, "services.txt");
    loadAppointments(&appointments, "appointments.txt",
        customers, artists, services, serviceCount);

    int choice;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Add Customer\n");
        printf("2. Add Artist\n");
        printf("3. Add Service\n");
        printf("4. Make Appointment\n");
        printf("5. Cancel Appointment\n");
        printf("6. Delete Service\n");
        printf("7. Print Customers\n");
        printf("8. Print Services\n");
        printf("9. Save & Exit\n");

        scanf("%d", &choice);

        switch (choice) {

        case 1: {
            int id;
            char name[50], phone[15];

            scanf("%d", &id);
            getchar();

            fgets(name, 50, stdin);
            name[strcspn(name, "\n")] = 0;

            scanf("%s", phone);

            customers = addCustomer(customers, id, name, phone);
            break;
        }

        case 4: {
            int custId, artId, servId, y, m, d, h;

            scanf("%d", &custId);
            Customer* cust = findCustomer(customers, custId);
            if (!cust) break;

            scanf("%d", &artId);
            Artist* art = findArtist(artists, artId);
            if (!art) break;

            scanf("%d", &servId);

            Service* serv = NULL;
            for (int i = 0; i < serviceCount; i++)
                if (services[i].id == servId)
                    serv = &services[i];

            if (!serv) break;

            scanf("%d %d %d", &y, &m, &d);
            scanf("%d", &h);

            int id = (appointments == NULL) ? 1 : appointments->id + 1;

            makeAppointment(&appointments, id, cust, art, serv,
                y, (Month)m, d, h);
            break;
        }

        case 9:
            saveCustomers(customers, "customers.txt");
            saveArtists(artists, "artists.txt");
            saveServices(services, serviceCount, "services.txt");
            saveAppointments(appointments, "appointments.txt");
            break;
        }

    } while (choice != 9);

    freeCustomers(customers);
    freeArtists(artists);
    freeAppointments(appointments);

    return 0;
}