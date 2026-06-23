#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "email.h"
#include "database.h"

/* -------------------------------- */
/* EMAIL VALIDATION                */
/* -------------------------------- */

int isValidEmail(const char *email)
{
    const char *at = strchr(email, '@');
    const char *dot = strrchr(email, '.');

    if (!at || !dot)
        return 0;

    if (at > dot)
        return 0;

    if (at == email)
        return 0;

    if (*(dot + 1) == '\0')
        return 0;

    return 1;
}

/* -------------------------------- */
/* ADD NODE TO LINKED LIST         */
/* -------------------------------- */

void addEmailNode(
    LinkedList *list,
    Email *email
)
{
    if(list->head == NULL)
    {
        list->head = email;
        return;
    }

    Email *temp = list->head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = email;
}

/* -------------------------------- */
/* DISPLAY EMAILS                  */
/* -------------------------------- */

void displayEmails(
    LinkedList *list
)
{
    if(list->head == NULL)
    {
        printf("\nNo Emails Found.\n");
        return;
    }

    Email *temp = list->head;

    while(temp != NULL)
    {
        printf("\n=========================================\n");

        printf("ID          : %d\n",
               temp->id);

        printf("Sender      : %s\n",
               temp->sender);

        printf("Receiver    : %s\n",
               temp->receiver);

        printf("Subject     : %s\n",
               temp->subject);

        printf("Content     : %s\n",
               temp->content);

        printf("Folder      : %s\n",
               temp->folder);

        printf("Category    : %s\n",
               temp->category);

        printf("Priority    : ");

        switch(temp->priority)
        {
            case 1:
                printf("LOW\n");
                break;

            case 2:
                printf("MEDIUM\n");
                break;

            case 3:
                printf("HIGH\n");
                break;

            default:
                printf("UNKNOWN\n");
        }

        printf("Starred     : %s\n",
               temp->isStarred ? "YES" : "NO");

        printf("Created At  : %s\n",
               temp->createdAt);

        printf("=========================================\n");

        temp = temp->next;
    }
}

/* -------------------------------- */
/* COMPOSE EMAIL                   */
/* -------------------------------- */

void composeEmail()
{
    char sender[MAX_EMAIL];
    char receiver[MAX_EMAIL];

    char subject[MAX_SUBJECT];
    char content[MAX_CONTENT];

    int priority;

    int choice;

    char category[MAX_CATEGORY];

    printf("\n========== COMPOSE EMAIL ==========\n");

    printf("Sender Email : ");
    fgets(sender, MAX_EMAIL, stdin);
    sender[strcspn(sender,"\n")] = '\0';

    if(!isValidEmail(sender))
    {
        printf("Invalid Sender Email\n");
        return;
    }

    printf("Receiver Email : ");
    fgets(receiver, MAX_EMAIL, stdin);
    receiver[strcspn(receiver,"\n")] = '\0';

    if(!isValidEmail(receiver))
    {
        printf("Invalid Receiver Email\n");
        return;
    }

    printf("Subject : ");
    fgets(subject, MAX_SUBJECT, stdin);
    subject[strcspn(subject,"\n")] = '\0';

    printf("Content : ");
    fgets(content, MAX_CONTENT, stdin);
    content[strcspn(content,"\n")] = '\0';

    printf("\nChoose Category\n");

    printf("1. Personal\n");
    printf("2. Work\n");
    printf("3. College\n");
    printf("4. Important\n");

    printf("Choice : ");
    scanf("%d",&choice);

    getchar();

    switch(choice)
    {
        case 1:
            strcpy(category,"PERSONAL");
            break;

        case 2:
            strcpy(category,"WORK");
            break;

        case 3:
            strcpy(category,"COLLEGE");
            break;

        case 4:
            strcpy(category,"IMPORTANT");
            break;

        default:
            strcpy(category,"PERSONAL");
    }

    printf("\nPriority\n");

    printf("1. Low\n");
    printf("2. Medium\n");
    printf("3. High\n");

    printf("Enter Priority : ");
    scanf("%d",&priority);

    getchar();

    printf("\n");

    printf("1. Send Email\n");
    printf("2. Save Draft\n");

    printf("Choice : ");
    scanf("%d",&choice);

    getchar();

    if(choice == 1)
    {
        insertEmail(
            sender,
            receiver,
            subject,
            content,
            "SENT",
            category,
            priority,
            0
        );

        printf("\nEmail Sent Successfully\n");
    }
    else
    {
        insertEmail(
            sender,
            receiver,
            subject,
            content,
            "DRAFT",
            category,
            priority,
            0
        );

        printf("\nDraft Saved Successfully\n");
    }
}