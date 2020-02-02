#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// These headers is for exit(0), took Unix OS into consideration.
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define char_size 256

/** A function to display menu page
This is a function to let user choose whether to take the test (or retest as after the test complete it will return to this page) or quit the program
*/
int menu()
{
    char user_choice[256];
    printf("________                                            .__               \n");
    printf("\\______ \\   ____ _____________   ____   ______ _____|__| ____   ____  \n");
    printf(" |    |  \\_/ __ \\\\____ \\_  __ \\_/ __ \\ /  ___//  ___/  |/  _ \\ /    \\ \n");
    printf(" |    `   \\  ___/|  |_> >  | \\/\\  ___/ \\___ \\ \\___ \\|  (  <_> )   |  \\ \n");
    printf("/_______  /\\___  >   __/|__|    \\___  >____  >____  >__|\\____/|___|  /\n");
    printf("        \\/     \\/|__|               \\/     \\/     \\/               \\/ \n");
    printf("___________              __                                           \n");
    printf("\\__    ___/___   _______/  |_                                         \n");
    printf("  |    |_/ __ \\ /  ___/\\   __\\                                        \n");
    printf("  |    |\\  ___/ \\___ \\  |  |                                          \n");
    printf("  |____| \\___  >____  > |__|                                          \n");
    printf("             \\/     \\/                                                \n");

    printf("\nMenu: \n1. Start Testing \ntype q to quit.\n:");
    scanf("%s", user_choice);

    /** Menu options
    1 = Start test
    q = quit
    other = call menu() again recursively
    */
    // Start
    if (strcmp(user_choice, "1") == 0)
    {
        // name accept 256 char
        char user_name, user_gender, user_age;
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
    char questions_m[][char_size] = {
        "test1: m",
        "test2: m",
        "test3: m",
        "test4: m",
        "test5: m",
        "test6: m",
        "test7: m",
        "test8: m",
        "test9: m",
        "test10: m",
        "test11: m",
        "test12: m",
        "test13: m",
        "test14: m",
        "test15: m",
        "test16: m",
        "test17: m",
        "test18: m",
        "test19: m",
        "test20: m",
    };
    char questions_f[][char_size] = {
        "test1: f",
        "test2: f",
        "test3: f",
        "test4: f",
        "test5: f",
        "test6: f",
        "test7: f",
        "test8: f",
        "test9: f",
        "test10: f",
        "test11: f",
        "test12: f",
        "test13: f",
        "test14: f",
        "test15: f",
        "test16: f",
        "test17: f",
        "test18: f",
        "test19: f",
        "test20: f",
    };

    int questions_arr_size = sizeof(questions_m) / sizeof(questions_m[0]);

    printf("\nTest start, in this test, \nwe personalized the test based on your gender, \nto gain the most from this test, please answer the question as intuitive as possible.\n");
    sleep(2);

    // Test start
    for (int i = 0; i < questions_arr_size; i++)
    {
        char temp_score[] = {"0"};
        // if user is male, use questions_m question set, else questions_f
        if (strcmp(user_gender, "m") == 0)
        {
            printf("\n\n%s\n", questions_m[i]);
        }
        else
        {
            printf("\n\n%s\n", questions_f[i]);
        }

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

        // store the user choice to the respective scores array item
        scores[i] = atoi(temp_score);
    }

    // Process data
    int scores_arr_size = sizeof(scores) / sizeof(int);
    int average = averageScore(scores, scores_arr_size);
    return average;
}

int outputResults(int average)
{
    printf("\nAverage scores: %o\n", average);
    // output results based on average score
    switch (average)
    {
    case 1:
        printf("BAD BAD");
        break;
    case 2:
        printf("NOT BAD");
        break;
    case 3:
        printf("GOOD");
        break;
    case 4:
        printf("VERY GOOD");
        break;
    default:
        break;
    }
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
    // Display Menu Page()
    menu();
}
