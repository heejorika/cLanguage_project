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
        printf("�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
        printf("%s ", ctime(&t_ALL));
        printf("������ �ұ��?\n");
        printf("1.Ķ����\n");
        printf("2.�ְ���ǥ\n");
        printf("3.����\n>>");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1: calenderRun(); break;
        case 2: GoalRun(); break;
        case 3: break;
        default:
            printf("�߸��� �Է��Դϴ�.\n\n");
        }

    }

    printf("�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
    printf("���α׷��� �����մϴ�..\n");

}
