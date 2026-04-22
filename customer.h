#ifndef CUSTOMER_H
#define CUSTOMER_H

typedef struct Customer {
    int id;
    char name[50];
    char phone[15];
    struct Customer* next;
} Customer;

Customer* addCustomer(Customer* head, int id, char name[], char phone[]);
Customer* findCustomer(Customer* head, int id);
void printCustomers(Customer* head);
void freeCustomers(Customer* head);

#endif
