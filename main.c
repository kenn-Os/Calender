#include <stdio.h>

#define TRUE 1
#define FALSE 0

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[] = {
    " ",
    "\n\n\nJanuary",
    "\n\n\nFebruary",
    "\n\n\nMarch",
    "\n\n\nApril",
    "\n\n\nMay",
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember"
};

int inputyear(void)
{
    int year;
    printf("Please enter a year (example: 1990): ");
    scanf("%d", &year);
    return year;
}

int determineleapyear(int year)
{
    if (year % 4 == FALSE && year % 100 != FALSE || year % 400 == FALSE)
    {
        days_in_month[2] = 29;
        return TRUE;
    }
    else
    {
        days_in_month[2] = 28;
        return FALSE;
    }
}
int determinedaycode(int year, int month, int day)
{
    int daycode;
    int d1, d2, d3;

    d1 = (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    d2 = (year - 1) % 7;
    d3 = 0;

    for (int i = 1; i < month; i++)
    {
        d3 += days_in_month[i];
    }

    daycode = (d1 + d2 + d3 + day) % 7;

    return daycode;
}

void calendar(int year, int daycode)
{
    int month, day;
    for (month = 1; month <= 12; month++)
    {
        printf("%s", months[month]);
        printf("\n\nSun Mon Tue Wed Thu Fri Sat\n");

        // Correct the position for the first date
        for (int space = 0; space < daycode; space++)
        {
            printf("    ");
        }

        // Print all the dates for one month
        for (day = 1; day <= days_in_month[month]; day++)
        {
            printf("%3d ", day);

            if (++daycode > 6)
            {
                printf("\n");
                daycode = 0;
            }
        }

        // Set position for the next month
        if (daycode != 0)
        {
            printf("\n");
        }
    }
}

int main(void)
{
    int year, daycode;
    year = inputyear();
    daycode = determinedaycode(year, 1, 1);
    determineleapyear(year);
    calendar(year, daycode);

    // Retrieve a specific month
    int month;
    printf("\nEnter the month number (1-12): ");
    scanf("%d", &month);

    if (month < 1 || month > 12)
    {
        printf("Invalid month number. Please enter a number between 1 and 12.\n");
        return 0;
    }

    printf("\n%s %d\n", months[month], year);
    printf("\nSun Mon Tue Wed Thu Fri Sat\n");

    int startDay = determinedaycode(year, month, 1);
    int maxDay = days_in_month[month];

    // Adjust the position for the first date
    for (int space = 0; space < startDay; space++)
    {
        printf("    ");
    }

    // Print all the dates for the specific month
    int day;
    for (day = 1; day <= maxDay; day++)
    {
        printf("%3d ", day);

        if (++startDay > 6)
        {
            printf("\n");
            startDay = 0;
        }
    }

    printf("\n");

    return 0;
}

// #include <stdio.h>

// #define TRUE 1
// #define FALSE 0

// int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// char *months[] = {
//     " ",
//     "\n\n\nJanuary",
//     "\n\n\nFebruary",
//     "\n\n\nMarch",
//     "\n\n\nApril",
//     "\n\n\nMay",
//     "\n\n\nJune",
//     "\n\n\nJuly",
//     "\n\n\nAugust",
//     "\n\n\nSeptember",
//     "\n\n\nOctober",
//     "\n\n\nNovember",
//     "\n\n\nDecember"
// };

// int inputyear(void)
// {
//     int year;
//     printf("Please enter a year (example: 1990): ");
//     scanf("%d", &year);
//     return year;
// }

// int determineleapyear(int year)
// {
//     if (year % 4 == FALSE && year % 100 != FALSE || year % 400 == FALSE)
//     {
//         days_in_month[2] = 29;
//         return TRUE;
//     }
//     else
//     {
//         days_in_month[2] = 28;
//         return FALSE;
//     }
// }

// int determinedaycode(int year, int month, int day)
// {
//     int daycode;
//     int d1, d2, d3;

//     d1 = (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
//     d2 = (year - 1) % 7;
//     d3 = 0;

//     for (int i = 1; i < month; i++)
//     {
//         d3 += days_in_month[i];
//     }

//     daycode = (d1 + d2 + d3 + day) % 7;

//     return daycode;
// }

// void calendar(int year, int daycode)
// {
//     int month, day;
//     for (month = 1; month <= 12; month++)
//     {
//         printf("%s", months[month]);
//         printf("\n\nSun Mon Tue Wed Thu Fri Sat\n");

//         // Correct the position for the first date
//         for (int space = 0; space < daycode; space++)
//         {
//             printf("    ");
//         }

//         // Print all the dates for one month
//         for (day = 1; day <= days_in_month[month]; day++)
//         {
//             printf("%3d ", day);

//             if (++daycode > 6)
//             {
//                 printf("\n");
//                 daycode = 0;
//             }
//         }

//         // Set position for the next month
//         if (daycode != 0)
//         {
//             printf("\n");
//         }
//     }
// }

// int main(void)
// {
//     int year, daycode;
//     char enterKey;

//     do {
//         year = inputyear();
//         daycode = determinedaycode(year, 1, 1);
//         determineleapyear(year);
//         calendar(year, daycode);

//         printf("\nPress Enter to restart the program or any other key to exit...");
//         enterKey = getchar();
//         while (getchar() != '\n');  // Clear the input buffer

//     } while (enterKey == '\n');

//     return 0;
// }
