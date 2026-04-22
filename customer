#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"

Customer* addCustomer(Customer* head, int id, char name[], char phone[]) {
    Customer* newNode = (Customer*)malloc(sizeof(Customer));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }

    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Customer* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

Customer* findCustomer(Customer* head, int id) {
    Customer* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

void printCustomers(Customer* head) {
    Customer* temp = head;

    if (temp == NULL) {
        printf("No customers found\n");
        return;
    }

    while (temp != NULL) {
        printf("%d %s %s\n", temp->id, temp->name, temp->phone);
        temp = temp->next;
    }
}

void freeCustomers(Customer* head) {
    Customer* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
