#include <stdio.h>
#include <string.h>

#include "search.h"
#include "database.h"

void searchEmails(
    const char *keyword
)
{
    if(keyword == NULL)
    {
        printf("Invalid Search Keyword\n");
        return;
    }

    if(strlen(keyword) == 0)
    {
        printf("Search Keyword Cannot Be Empty\n");
        return;
    }

    searchEmailsDB(keyword);
}