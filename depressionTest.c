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
    char questions_f[][char_size] = {
        "test1: I do things slowly. ",
        "test2: My future seems hopeless.",
        "test3: It is hard for me to concentrate on reading.",
        "test4: The pleasure and joy have gone out of my life.",
        "test5: I have difficulty making decisions.",
        "test6: I have lost interest in aspects of my life that used to be important to me.",
        "test7: I feel sad, blue and unhappy.",
        "test8: I am agitated and keep moving around.",
        "test9: I feel fatigued.",
        "test10: It takes great effort for me to do simple things.",
        "test11: I feel that I am a guilty person who deserves to be punished.",
        "test12: I feel like a failure.",
        "test13: I feel lifeless more dead than alive.",
        "test14: I’m getting too much, too little or not enough restful sleep.",
        "test15: I spend time thinking about HOW I might kill myself.",
        "test16: I feel trapped or caught.",
        "test17: I feel depressed even when good things happen to me.",
        "test18: Without trying to diet, I have lost or gained weight.",
        "test19: I feel have trouble concentrating.",
        "test20: I frequently feel like crying.",
    };
    char questions_m[][char_size] = {
        "test1: Have you dropped many of your activities and interests?",
        "test2: Do you feel that your life is empty?",
        "test3: Do you often get bored?",
        "test4: Are you bothered by thoughts you can’t get out of your head?",
        "test5: Are you afraid that something bad is going to happen to you?",
        "test6: Do you often get restless and fidgety?",
        "test7: Do you prefer to stay at home rather than go out and do things?",
        "test8: Do you frequently worry about the future?",
        "test9: Do you feel you have more problems with memory than most?",
        "test10: Do you feel downhearted and blue?",
        "test11: Do you feel pretty worthless the way you are now?",
        "test12: Do you worry a lot about the past?",
        "test13: Is it hard for you to get started on new projects?",
        "test14: Do you feel that your situation is hopeless?",
        "test15: Do you think that most people are better off than you are?",
        "test16: Do you frequently get upset over little things?",
        "test17: Do you prefer to avoid social occasions?",
        "test18: Do you often feel helpless?",
        "test19: I believe I cause problems for others.",
        "test20: I don’t have much of an appetite and eat less than usual.",
    };

    int questions_arr_size = sizeof(questions_m) / sizeof(questions_m[0]);

    printf("\nTest start, in this test, \nwe personalized the test based on your gender, \nto gain the most from this test, please answer the question as intuitive as possible.\n");
    sleep(2);

    // Test start
    for (int i = 0; i < questions_arr_size; i++)
    {
        char temp_score[] = {"0"};
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
        printf("No Depression Likely.\n\t You do not appear to be experiencing any depressive symptoms at this time.\n If this changes, you may need to seek further diagnosis and treatment.");
        break;
    case 2:
        printf("Borderline Depression.\n\t You appear to be experiencing some very mild depressive symptoms, many of which are commonly found amongst the general population, but border on the possibility of a depressive episode.\n It is unclear whether or not you suffer these problems severely enough to need to seek further diagnosis and treatment.");
        break;
    case 3:
        printf("Mild-Moderate Depression.\n\t You appear to be suffering from mild to moderate depressive symptoms commonly associated with depressive disorders.\n These symptoms appear to be causing you some noticeable signs of impairment and distress,\n and you would likely benefit from the attention of a trained mental health professional for further evaluation and a more accurate diagnosis.");
        break;
    case 4:
        printf("Severely Depressed.\n\t You appear to be suffering from severe depressive symptoms commonly associated with serious depressive disorders,\n such as major depressive disorder, bipolar disorder or dysthymia.\n These symptoms seem to be causing you some serious impairment and distress in your normal, everyday functioning.\n You would likely benefit from the immediate attention of your physician or a trained mental health professional for further evaluation\n and a more accurate diagnosis and treatment.");
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
    // Menu
    menu();
}
