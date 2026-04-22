// artist.h
#ifndef ARTIST_H
#define ARTIST_H

typedef union {
    char phone[20];
    char nationalId[20];
    char address[100];
} ArtistInfo;

 struct Artist {
    int id;
    char name[50];
    int infoType;
    ArtistInfo info;
    struct Artist* next;
} ;

void addArtist(struct Artist** head, int id, const char* name, int infoType, const char* info);
void deleteArtist(struct Artist** head, int id );
struct Artist* findArtist(struct Artist* head, int id);
void printArtists(struct Artist* head);
//////
void freeArtists(struct Artist* head);
void saveArtists(struct Artist* head, const char* filename);
void loadArtists(struct Artist** head, const char* filename);

#endif
