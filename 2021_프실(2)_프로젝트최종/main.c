#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int main() {
    int choice = 0;
    time_t t_ALL = time(NULL);

    while (choice != 3) {
        system("cls");
        printf("★★★★★★★★★★★★★★★★★★★★★★★\n");
        printf("%s ", ctime(&t_ALL));
        printf("무엇을 할까요?\n");
        printf("1.캘린더\n");
        printf("2.주간목표\n");
        printf("3.종료\n>>");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1: calenderRun(); break;
        case 2: GoalRun(); break;
        case 3: break;
        default:
            printf("잘못된 입력입니다.\n\n");
        }

    }

    printf("★★★★★★★★★★★★★★★★★★★★★★★\n");
    printf("프로그램을 종료합니다..\n");

}
