#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define NAME_LEN 100
#define NUM_GRADES 13

int main() {
    char names[MAX_STUDENTS][NAME_LEN];
    double averages[MAX_STUDENTS];
    int count = 0;

    while (scanf("%s", names[count]) == 1) {
        int sum = 0;
        for (int i = 0; i < NUM_GRADES; i++) {
            int grade;
            if (scanf("%d", &grade) != 1) return 1;
            sum += grade;
        }
        averages[count] = sum / (double)NUM_GRADES;
        count++;
    }

    int best_index = 0;
    for (int i = 1; i < count; i++) {
        if (averages[i] > averages[best_index]) {
            best_index = i;
        }
    }

    int min1 = -1, min2 = -1;
    for (int i = 0; i < count; i++) {
        if (i == best_index) continue;
        if (min1 == -1 || averages[i] < averages[min1]) {
            min2 = min1;
            min1 = i;
        } else if (min2 == -1 || averages[i] < averages[min2]) {
            min2 = i;
        }
    }

    printf("%s\n", names[best_index]);

    names[min1][0] = toupper(names[min1][0]);
    names[min2][0] = toupper(names[min2][0]);

    printf("%s\n", names[min1]);
    printf("%s\n", names[min2]);

    return 0;
}


