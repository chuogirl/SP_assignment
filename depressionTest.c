#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define char_size 256

int menu()
{
    char user_choice[256];

    printf("\nMenu: \n1. Start Testing \ntype q to quit.\n:");
    scanf("%s", user_choice);
    // Start
    if (strcmp(user_choice, "1") == 0)
    {

        // name accept 256 char
        char user_name[char_size], user_gender[1], user_age[3];
        printf("\nPlease enter your name: \n:");
        scanf("%s", user_name);

        // age shall larger than 0, preventing entering words as well using atoi
        while (atoi(user_age) <= 0)
        {
            printf("\nPlease enter your age in number: \n:");
            scanf("%s", user_age);
        }

        // gender only accept character m or f
        while (!(strcmp(user_gender, "m") == 0 ||
                 strcmp(user_gender, "f") == 0 ||
                 strcmp(user_gender, "M") == 0 ||
                 strcmp(user_gender, "F") == 0))
        {
            printf("\nPlease enter your gender only character m/f:\n:");
            scanf("%s", user_gender);
        }

        // Test
        int average = depressionTest(user_gender);
        // output
        outputResults(average);
        // reset the program
        menu();
    }
    // quit
    else if (strcmp(user_choice, "q") == 0)
    {
        exit(0);
    }
    else
    {
        printf("Invalid option, please enter again: \n:");
        menu();
    }
}

int depressionTest(char user_gender[])
{
    int scores[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char questions[][char_size] = {
        "test1: ",
        "test2: ",
        "test3: ",
        "test4: ",
        "test5: ",
        "test6: ",
        "test7: ",
        "test8: ",
        "test9: ",
        "test10: ",
        "test11: ",
        "test12: ",
        "test13: ",
        "test14: ",
        "test15: ",
        "test16: ",
        "test17: ",
        "test18: ",
        "test19: ",
        "test20: ",
    };

    int questions_arr_size = sizeof(questions) / sizeof(questions[0]);

    printf("\nTest start, in this test, \nwe personalized the test based on your gender, \nto gain the most from this test, please answer the question as intuitive as possible.\n");
    sleep(2);

    // Test start
    for (int i = 0; i < questions_arr_size; i++)
    {
        char temp_score[] = {"0"};
        printf("\n%s\n", questions[i]);
        sleep(1);
        while (!(strcmp(temp_score, "1") == 0 ||
                 strcmp(temp_score, "2") == 0 ||
                 strcmp(temp_score, "3") == 0 ||
                 strcmp(temp_score, "4") == 0))
        {
            printf("\nPlease choose an option by entering the number 1 to 4:\n");
            printf("1. Not at all\t2. Somewhat\n3. Moderately\t4. Very much\ntype q to exit\n:");
            scanf("%s", temp_score);

            if (strcmp(temp_score, "q") == 0 || strcmp(temp_score, "q") == 0)
            {
                exit(0);
            }
        }

        scores[i] = atoi(temp_score);
        printf("%o", scores[i]);
    }

    // Process data
    int scores_arr_size = sizeof(scores) / sizeof(int);
    int average = averageScore(scores, scores_arr_size);
    return average;
}

int outputResults(int average)
{
    printf("\nAverage scores: %o\n", average);
}

int averageScore(int scores[], int arr_size)
{
    int total = 0;

    for (size_t i = 0; i < arr_size; i++)
    {
        total += scores[i];
    }
    return total / arr_size;
}

void main()
{
    // Menu
    menu();
}
