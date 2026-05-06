//Appointment.c
#include <stdio.h>
#include <stdlib.h>
#include "appointment.h"

extern int isInFuture(int, int, int);

void makeAppointment(Appointment** head, int id,
    Customer* customer, Artist* artist,
    Service* service,
    int year, Month month, int day, int hr) {

    Appointment* newApp = malloc(sizeof(Appointment));

    newApp->id = id;
    newApp->customer = customer;
    newApp->artist = artist;
    newApp->service = service;

    newApp->serviceId = service->id;
    newApp->isPaid = 0;
    newApp->isFuture = isInFuture(year, month, day);

    newApp->date.year = year;
    newApp->date.month = month;
    newApp->date.day = day;
    newApp->hour = hr;

    newApp->next = *head;
    *head = newApp;
}

int cancelAppointment(Appointment** head, int id) {
    Appointment *cur = *head, *prev = NULL;

    while (cur) {
        if (cur->id == id) {
            if (cur->isPaid) return 0;

            if (prev) prev->next = cur->next;
            else *head = cur->next;

            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}