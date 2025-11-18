#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    float avg;
};

int main() {
    struct Student s[50], temp;
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter name, roll no, avg marks of student %d: ", i + 1);
        scanf("%s %d %f", s[i].name, &s[i].roll, &s[i].avg);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(s[j].avg < s[j + 1].avg) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted in descending order of avg marks:\n");
    for(i = 0; i < n; i++)
        printf("%s\t%d\t%.2f\n", s[i].name, s[i].roll, s[i].avg);

    return 0;
}
