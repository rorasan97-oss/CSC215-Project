#ifndef SERVICE_H
#define SERVICE_H

#define MAX_SERVICES 10

typedef struct {
    int id;
    char name[50];
    float price;
} Service;

typedef struct Appointment {
    int serviceId;
    int isPaid;
    int isFuture;
    struct Appointment* next;
} Appointment;

int canDeleteService(Appointment* head, int serviceId);
void addService(Service services[], int* count, int id, char name[], float price);
void deleteService(Service services[], int* count, int id, Appointment* appointments);
void printServices(Service services[], int count);

#endif
