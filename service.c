#include <stdio.h>
#include <string.h>
#include "service.h"

int canDeleteService(Appointment* head, int serviceId) {
    Appointment* temp = head;

    while (temp != NULL) {
        if (temp->serviceId == serviceId && temp->isPaid == 1 && temp->isFuture == 1) {
            return 0;
        }
        temp = temp->next;
    }

    return 1;
}

void addService(Service services[], int* count, int id, char name[], float price) {
    if (*count >= MAX_SERVICES) {
        return;
    }

    services[*count].id = id;
    strcpy(services[*count].name, name);
    services[*count].price = price;

    (*count)++;
}

void deleteService(Service services[], int* count, int id, Appointment* appointments) {
    if (!canDeleteService(appointments, id)) {
        printf("Cannot delete service\n");
        return;
    }

    for (int i = 0; i < *count; i++) {
        if (services[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                services[j] = services[j + 1];
            }
            (*count)--;
            return;
        }
    }
}

void printServices(Service services[], int count) {
    if (count == 0) {
        printf("No services available\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d %s %.2f\n", services[i].id, services[i].name, services[i].price);
    }
}
