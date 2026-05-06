//Appointment.h
#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "customer.h"
#include "artist.h"
#include "service.h"

typedef enum { JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC } Month;

typedef struct Appointment {
    int id;

    Customer* customer;
    Artist* artist;
    Service* service;

    int serviceId;
    int isPaid;
    int isFuture;

    struct {
        int year;
        Month month;
        int day;
    } date;

    int hour;

    struct Appointment* next;
} Appointment;

void makeAppointment(Appointment** head, int id,
    Customer* customer, Artist* artist,
    Service* service,
    int year, Month month, int day, int hr);

int cancelAppointment(Appointment** head, int id);

void editAppointment(Appointment* appointment,
    Artist* newArtist, Service* newService,
    int newYear, Month newMonth, int newDay, int hr,
    Appointment* allAppointments);

void freeAppointments(Appointment* head);

void saveAppointments(Appointment* head, const char* filename);

void loadAppointments(Appointment** head, const char* filename,
    Customer* customers, Artist* artists,
    Service services[], int serviceCount);

#endif