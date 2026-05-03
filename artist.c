// artist.c
#include "artist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addArtist(struct Artist** head, int id, const char* name, int infoType, const char* info) {
   struct Artist* newArtist = (struct Artist*)malloc(sizeof(struct Artist));
    
   newArtist->id = id;
   strcpy(newArtist->name, name);
   newArtist->infoType = infoType;
   if (infoType == 1) strcpy(newArtist->info.phone, info);
   else if (infoType == 2) strcpy(newArtist->info.nationalId, info);
   else strcpy(newArtist->info.address, info);
   newArtist->next = *head;
   *head = newArtist;
    
}

void deleteArtist(struct Artist** head, int id) {
   struct Artist* current = *head;
   struct Artist* prev = NULL;
   while (current != NULL ) {
      if (current->id == id) {
         if (prev != NULL) 
            prev->next = current->next;
         else 
            *head = current->next;
         free(current);
         printf("Artist deleted.\n");
         return ; 
      }
      prev = current;
      current = current->next;
   }
   printf(" artist not found.\n");            

}

struct Artist* findArtist(struct Artist* head, int id) {
   while (head != NULL) {
      if (head->id == id) 
         return head;
      else
         head = head->next;
   }
   return NULL;
}

void printArtists(struct Artist* head) {
   if (head == NULL) {
      printf("list of artists is empty.\n");
      return;
   }
    
   printf("\n*** Artist List ***\n");
   while (head != NULL) {
      printf("ID: %d | Name: %s | ", head->id, head->name);
      if (head->infoType == 1) printf("Phone: %s\n", head->info.phone);
      else 
         if (head->infoType == 2) printf("National ID: %s\n", head->info.nationalId);
         else 
            printf("Address: %s\n", head->info.address);
      head = head->next;
   }
}
//=========================================
void freeArtists(struct Artist* head) {
   struct Artist* temp;
   while (head != NULL ) {
      temp = head;
      head = head->next;
      free(temp);
   }
}

void saveArtists(struct Artist* head, const char* filename) {
   FILE* file = fopen(filename, "w");
   if (file == NULL) 
      return;
    
   while (head != NULL) {
      fprintf(file, "%d|%s|%d|", head->id, head->name, head->infoType);
      if (head->infoType == 1) fprintf(file, "%s\n", head->info.phone);
      else if (head->infoType == 2) fprintf(file, "%s\n", head->info.nationalId);
      else fprintf(file, "%s\n", head->info.address);
      head = head->next;
   }
   fclose(file);
}

void loadArtists(struct Artist** head, const char* filename) {
   FILE* file = fopen(filename, "r");
   if (!file) 
      return;
   int id, infoType;
   char name[50], info[100];
   while (fscanf(file, "%d|%[^|]|%d|%[^\n]\n", &id, name, &infoType, info) == 4) {
      addArtist(head, id, name, infoType, info);
   }
   fclose(file);
}
