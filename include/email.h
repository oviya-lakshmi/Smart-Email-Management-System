#ifndef EMAIL_H
#define EMAIL_H

#define MAX_EMAIL 100
#define MAX_SUBJECT 200
#define MAX_CONTENT 1000
#define MAX_CATEGORY 50
#define MAX_DATE 50

typedef struct Email
{
    int id;

    char sender[MAX_EMAIL];
    char receiver[MAX_EMAIL];

    char subject[MAX_SUBJECT];
    char content[MAX_CONTENT];

    char folder[20];
    char category[MAX_CATEGORY];

    int priority;
    int isStarred;

    char createdAt[MAX_DATE];

    struct Email *next;

} Email;

typedef struct LinkedList
{
    Email *head;

} LinkedList;

/*
Folders

INBOX
SENT
DRAFT
TRASH
*/

int isValidEmail(const char *email);

void composeEmail();

void displayEmails(
    LinkedList *list
);

void addEmailNode(
    LinkedList *list,
    Email *email
);

#endif