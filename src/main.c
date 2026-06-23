#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "email.h"
#include "database.h"
#include "search.h"

void clearList(
    LinkedList *list
)
{
    Email *temp = list->head;

    while(temp != NULL)
    {
        Email *next = temp->next;

        free(temp);

        temp = next;
    }

    list->head = NULL;
}

int main()
{
    int choice;

    initDatabase();

    while(1)
    {
        printf("\n");
        printf("=========================================\n");
        printf(" SMART EMAIL MANAGEMENT SYSTEM v2.0\n");
        printf("=========================================\n");

        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. View Sent Emails\n");
        printf("4. View Drafts\n");
        printf("5. View Trash\n");
        printf("6. Star Email\n");
        printf("7. View Starred Emails\n");
        printf("8. Search Emails\n");
        printf("9. Delete Email\n");
        printf("10. Restore Email\n");
        printf("11. Analytics Dashboard\n");
        printf("12. Reset Database\n");
        printf("13. Load Demo Data\n");
        printf("14. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        getchar();

        switch(choice)
        {
            case 1:
            {
                composeEmail();
                break;
            }

            case 2:
            {
                LinkedList inbox;
                inbox.head = NULL;

                loadEmailsByFolder(
                    &inbox,
                    "INBOX"
                );

                displayEmails(
                    &inbox
                );

                clearList(
                    &inbox
                );

                break;
            }

            case 3:
            {
                LinkedList sent;
                sent.head = NULL;

                loadEmailsByFolder(
                    &sent,
                    "SENT"
                );

                displayEmails(
                    &sent
                );

                clearList(
                    &sent
                );

                break;
            }

            case 4:
            {
                LinkedList drafts;
                drafts.head = NULL;

                loadEmailsByFolder(
                    &drafts,
                    "DRAFT"
                );

                displayEmails(
                    &drafts
                );

                clearList(
                    &drafts
                );

                break;
            }

            case 5:
            {
                LinkedList trash;
                trash.head = NULL;

                loadEmailsByFolder(
                    &trash,
                    "TRASH"
                );

                displayEmails(
                    &trash
                );

                clearList(
                    &trash
                );

                break;
            }

            case 6:
            {
                int id;

                printf(
                    "Enter Email ID : "
                );

                scanf(
                    "%d",
                    &id
                );

                getchar();

                starEmail(id);

                break;
            }

            case 7:
            {
                LinkedList starred;

                starred.head = NULL;

                viewStarredEmails(
                    &starred
                );

                displayEmails(
                    &starred
                );

                clearList(
                    &starred
                );

                break;
            }

            case 8:
            {
                char keyword[200];

                printf(
                    "Enter Search Keyword : "
                );

                fgets(
                    keyword,
                    sizeof(keyword),
                    stdin
                );

                keyword[
                    strcspn(
                        keyword,
                        "\n"
                    )
                ] = '\0';

                searchEmailsDB(
                    keyword
                );

                break;
            }

            case 9:
            {
                int id;

                printf(
                    "Enter Email ID : "
                );

                scanf(
                    "%d",
                    &id
                );

                getchar();

                moveToTrash(
                    id
                );

                break;
            }

            case 10:
            {
                int id;

                printf(
                    "Enter Email ID : "
                );

                scanf(
                    "%d",
                    &id
                );

                getchar();

                restoreEmail(
                    id
                );

                break;
            }

            case 11:
            {
                analyticsDashboard();
                break;
            }

            case 12:
{
    resetDatabase();
    break;
}
            case 13:
{
    loadDemoData();
    break;
}
            case 14:
{
    printf("Thank You\n");
    return 0;
}

            default:
            {
                printf(
                    "\nInvalid Choice\n"
                );
            }
        }
    }

    return 0;
}