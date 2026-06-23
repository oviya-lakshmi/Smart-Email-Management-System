#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sqlite3.h"
#include "database.h"

static sqlite3 *db = NULL;

/* ------------------------------------------------ */
/* DATABASE INIT                                    */
/* ------------------------------------------------ */

void initDatabase()
{
    char *errMsg = NULL;

    if(sqlite3_open("database/emails.db", &db))
    {
        printf("Cannot Open Database\n");
        return;
    }

    char *sql =
    "CREATE TABLE IF NOT EXISTS Emails("
    "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
    "Sender TEXT,"
    "Receiver TEXT,"
    "Subject TEXT,"
    "Content TEXT,"
    "Folder TEXT,"
    "Category TEXT,"
    "Priority INTEGER,"
    "IsStarred INTEGER,"
    "CreatedAt TEXT"
    ");";

    if(sqlite3_exec(db, sql, 0, 0, &errMsg)!=SQLITE_OK)
    {
        printf("SQL Error : %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    printf("Database Initialized Successfully\n");
}

/* ------------------------------------------------ */
/* INSERT EMAIL                                     */
/* ------------------------------------------------ */

void insertEmail(
    char *sender,
    char *receiver,
    char *subject,
    char *content,
    char *folder,
    char *category,
    int priority,
    int isStarred
)
{
    char sql[5000];

    time_t now = time(NULL);

    char date[100];

    strftime(
        date,
        sizeof(date),
        "%Y-%m-%d %H:%M:%S",
        localtime(&now)
    );

    sprintf(
        sql,
        "INSERT INTO Emails "
        "(Sender,Receiver,Subject,Content,"
        "Folder,Category,Priority,"
        "IsStarred,CreatedAt)"
        " VALUES('%s','%s','%s','%s',"
        "'%s','%s',%d,%d,'%s');",

        sender,
        receiver,
        subject,
        content,
        folder,
        category,
        priority,
        isStarred,
        date
    );

    char *errMsg = NULL;

    if(sqlite3_exec(
        db,
        sql,
        0,
        0,
        &errMsg
    ) != SQLITE_OK)
    {
        printf("Insert Error : %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

/* ------------------------------------------------ */
/* CALLBACK FOR LOADING                             */
/* ------------------------------------------------ */

static int loadCallback(
    void *data,
    int argc,
    char **argv,
    char **colNames
)
{
    LinkedList *list =
        (LinkedList *)data;

    Email *email =
        (Email*)malloc(sizeof(Email));

    email->id =
        atoi(argv[0]);

    strcpy(email->sender, argv[1]);
    strcpy(email->receiver, argv[2]);
    strcpy(email->subject, argv[3]);
    strcpy(email->content, argv[4]);
    strcpy(email->folder, argv[5]);
    strcpy(email->category, argv[6]);

    email->priority =
        atoi(argv[7]);

    email->isStarred =
        atoi(argv[8]);

    strcpy(email->createdAt,
           argv[9]);

    email->next = NULL;

    addEmailNode(
        list,
        email
    );

    return 0;
}

/* ------------------------------------------------ */
/* LOAD BY FOLDER                                   */
/* ------------------------------------------------ */

void loadEmailsByFolder(
    LinkedList *list,
    const char *folder
)
{
    char sql[500];

    sprintf(
        sql,
        "SELECT * FROM Emails "
        "WHERE Folder='%s';",
        folder
    );

    sqlite3_exec(
        db,
        sql,
        loadCallback,
        list,
        NULL
    );
}

/* ------------------------------------------------ */
/* STAR EMAIL                                       */
/* ------------------------------------------------ */

void starEmail(
    int emailId
)
{
    char sql[300];

    sprintf(
        sql,
        "UPDATE Emails "
        "SET IsStarred=1 "
        "WHERE ID=%d;",
        emailId
    );

    sqlite3_exec(
        db,
        sql,
        NULL,
        NULL,
        NULL
    );

    printf(
        "Email Starred Successfully\n"
    );
}

/* ------------------------------------------------ */
/* MOVE TO TRASH                                    */
/* ------------------------------------------------ */

void moveToTrash(
    int emailId
)
{
    char sql[300];

    sprintf(
        sql,
        "UPDATE Emails "
        "SET Folder='TRASH' "
        "WHERE ID=%d;",
        emailId
    );

    sqlite3_exec(
        db,
        sql,
        NULL,
        NULL,
        NULL
    );

    printf(
        "Moved To Trash\n"
    );
}

/* ------------------------------------------------ */
/* RESTORE EMAIL                                    */
/* ------------------------------------------------ */

void restoreEmail(
    int emailId
)
{
    char sql[300];

    sprintf(
        sql,
        "UPDATE Emails "
        "SET Folder='INBOX' "
        "WHERE ID=%d;",
        emailId
    );

    sqlite3_exec(
        db,
        sql,
        NULL,
        NULL,
        NULL
    );

    printf(
        "Email Restored\n"
    );
}

/* ------------------------------------------------ */
/* SEARCH CALLBACK                                  */
/* ------------------------------------------------ */

static int searchCallback(
    void *data,
    int argc,
    char **argv,
    char **azColName
)
{
    printf(
        "\n---------------------------------\n"
    );

    printf(
        "ID : %s\n",
        argv[0]
    );

    printf(
        "Subject : %s\n",
        argv[3]
    );

    printf(
        "Sender : %s\n",
        argv[1]
    );

    printf(
        "Folder : %s\n",
        argv[5]
    );

    return 0;
}

/* ------------------------------------------------ */
/* SEARCH EMAIL                                     */
/* ------------------------------------------------ */

void searchEmailsDB(
    const char *keyword
)
{
    char sql[1000];

    sprintf(
        sql,
        "SELECT * FROM Emails "
        "WHERE Subject LIKE '%%%s%%' "
        "OR Content LIKE '%%%s%%';",
        keyword,
        keyword
    );

    sqlite3_exec(
        db,
        sql,
        searchCallback,
        NULL,
        NULL
    );
}

/* ------------------------------------------------ */
/* ANALYTICS CALLBACK                               */
/* ------------------------------------------------ */

static int analyticsCallback(
    void *data,
    int argc,
    char **argv,
    char **azColName
)
{
    printf(
        "%s : %s\n",
        argv[0],
        argv[1]
    );

    return 0;
}

/* ------------------------------------------------ */
/* DASHBOARD                                        */
/* ------------------------------------------------ */

void analyticsDashboard()
{
    printf(
        "\n========== DASHBOARD ==========\n"
    );

    sqlite3_exec(
        db,
        "SELECT Folder,COUNT(*) "
        "FROM Emails "
        "GROUP BY Folder;",
        analyticsCallback,
        NULL,
        NULL
    );
}
void resetDatabase()
{
    sqlite3_exec(
        db,
        "DELETE FROM Emails;",
        NULL,
        NULL,
        NULL
    );

    printf("Database Reset Successfully\n");
}
void loadDemoData()
{
    insertEmail(
        "principal@college.edu",
        "student@college.edu",
        "Semester Results Published",
        "Results have been published on portal.",
        "INBOX",
        "COLLEGE",
        3,
        1
    );

    insertEmail(
        "placement@college.edu",
        "student@college.edu",
        "Amazon Interview Round",
        "Interview scheduled for Monday.",
        "INBOX",
        "COLLEGE",
        3,
        1
    );

    insertEmail(
        "hr@company.com",
        "student@college.edu",
        "Internship Offer",
        "Congratulations on your selection.",
        "INBOX",
        "WORK",
        3,
        0
    );

    insertEmail(
        "friend@gmail.com",
        "student@college.edu",
        "Weekend Trip",
       "Weekend trip planning.",
        "INBOX",
        "PERSONAL",
        1,
        0
    );

    insertEmail(
        "bank@axis.com",
        "student@college.edu",
        "Monthly Statement",
        "Your monthly statement is attached.",
        "INBOX",
        "IMPORTANT",
        2,
        1
    );

    insertEmail(
        "student@college.edu",
        "placement@college.edu",
        "Resume Submission",
        "Attached my latest resume.",
        "SENT",
        "COLLEGE",
        2,
        0
    );

    insertEmail(
        "student@college.edu",
        "hr@company.com",
        "Interview Confirmation",
        "I confirm my availability.",
        "SENT",
        "WORK",
        2,
        0
    );

    insertEmail(
        "student@college.edu",
        "friend@gmail.com",
        "Trip Details",
        "Sharing the itinerary.",
        "SENT",
        "PERSONAL",
        1,
        0
    );

    insertEmail(
        "student@college.edu",
        "manager@company.com",
        "Project Update",
        "Current project status attached.",
        "DRAFT",
        "WORK",
        2,
        0
    );

    insertEmail(
        "student@college.edu",
        "faculty@college.edu",
        "Leave Request",
        "Requesting leave for two days.",
        "DRAFT",
        "COLLEGE",
        1,
        0
    );

    insertEmail(
        "lottery@fake.com",
        "student@college.edu",
        "You Won 1 Crore",
        "Claim your prize immediately.",
        "TRASH",
        "IMPORTANT",
        3,
        0
    );

    insertEmail(
        "spam@offers.com",
        "student@college.edu",
        "Free Money Offer",
        "Click here to claim reward.",
        "TRASH",
        "IMPORTANT",
        3,
        0
    );

    printf(
        "\nDemo Data Loaded Successfully\n"
    );
}
/* ------------------------------------------------ */
/* STARRED EMAILS                                   */
/* ------------------------------------------------ */

void viewStarredEmails(
    LinkedList *list
)
{
    sqlite3_exec(
        db,
        "SELECT * FROM Emails "
        "WHERE IsStarred=1;",
        loadCallback,
        list,
        NULL
    );
}