#ifndef DATABASE_H
#define DATABASE_H

#include "email.h"

void initDatabase();

void insertEmail(
    char *sender,
    char *receiver,
    char *subject,
    char *content,
    char *folder,
    char *category,
    int priority,
    int isStarred
);

void loadEmailsByFolder(
    LinkedList *list,
    const char *folder
);

void moveToTrash(
    int emailId
);

void restoreEmail(
    int emailId
);

void starEmail(
    int emailId
);

void viewStarredEmails(
    LinkedList *list
);
void loadDemoData();
void resetDatabase();
void searchEmailsDB(
    const char *keyword
);


void analyticsDashboard();

#endif