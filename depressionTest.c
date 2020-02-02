#include <stdio.h>
#define char_size 256
int averageScore(int scores[], int arr_size)
{
    int total = 0;

    for (size_t i = 0; i < arr_size; i++)
    {
        total += scores[i];
    }
    return total;
}

void main()
{
    // initialize
    char user_name[char_size], user_gender[1];
    int user_age;

    int scores[] = {0};
    char questions[][char_size] = {"test1: ", "test2: ", "test3: ", "test4: ", "test5: "};

    int questions_arr_size = sizeof(questions) / sizeof(questions[0]);

    // Gather user informations
    printf("Please enter your name: ");
    scanf("%s", user_name);

    printf("Please enter your gender: m/f");
    scanf("%s", user_gender);

    printf("Please enter your age: ");
    scanf("%o", user_age);

    // Test start
    for (int i = 0; i < questions_arr_size; i++)
    {
        printf("%s\n", questions[i]);

        // get user input and store in scores[i]
    }

    // Process data
    int score_arr_size = sizeof(scores) / sizeof(int);
    int average = averageScore(scores, score_arr_size);

    // Output results

    // retest
}
