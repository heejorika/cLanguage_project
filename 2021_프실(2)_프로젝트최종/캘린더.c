
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

typedef struct node {
    int hour;
    int min;
    char task[100];
    struct node* link;
}node;

int Taskcount = 0;
char* dateArr[15] = { "일", "월", "화", "수", "목", "금", "토" };
node* arr[7] = { NULL };  //요일 배열

void LookAll() {
    printf("<이번주 일정>  ");
    if (Taskcount == 0) { printf("일정이 없습니다!\n"); return; }
    printf("\n");
    for (int i = 0; i < 7; i++) {
        printf("__________________%s요일__________________\n", dateArr[i]);
        node* p = arr[i];
        while (p != NULL) {
            printf("%2d시 %2d분 :  %s\n", p->hour, p->min, p->task);
            p = p->link;
        }
        printf("\n");
    }
    int key = _getch();
    if (key == 'r') { system("cls"); }
}

void calenderInsert(int day) {
    node* n = (node*)malloc(sizeof(node));
    printf("시간>> "); scanf_s("%d", &n->hour);
    printf("분>> "); scanf_s("%d", &n->min);
    printf("할 일>> "); scanf_s("%s", n->task, 100);
    n->link = NULL;

    if (arr[day] == NULL) {
        arr[day] = n;
    }
    else {
        node* p = arr[day];
        while (p->link != NULL) p = p->link;
        p->link = n;
    }

    printf("★추가 완료★\n\n"); Taskcount++;
    int key = _getch();
    if (key == 'r') { system("cls"); }
}

void calenderUpdate(int day) {
    node* p = arr[day];
    if (p == NULL) {
        printf("%s요일의 일정이 없습니다.\n\n", dateArr[day]);
        return;
    }
    LookAll();
    node* p2 = arr[day];
    int choice = 100, count = 0;
    printf("__________________%s요일__________________\n", dateArr[day]);
    while (p != NULL) {
        printf("%d. %2d시 %2d분 :  %s\n", count, p->hour, p->min, p->task);
        p = p->link;
        count++;
    }
    while (choice >= count) {
        printf("수정할 일정 선택>> ");
        scanf_s("%d", &choice);
    }
    if (choice != 0) {
        for (int i = 0; i < count - 1; i++) p2 = p2->link;
    }

    printf("시간>> "); scanf_s("%d", &p2->hour);
    printf("분>> "); scanf_s("%d", &p2->min);
    printf("할 일>> "); scanf_s("%s", p2->task, 100);

    printf("★수정완료★\n\n");
    int key = _getch();
    if (key == 'r') { system("cls"); }
}

void nowTask(int day, int h) {
    printf("현재 할 일 : ");
    node* p = arr[day];
    if (p != NULL) {
        while (p != NULL) {
            if (p->hour == h) {
                printf("%s\n", p->task); return;
            }
            else { p = p->link; }
        }
    }
    printf("현재 할 일이 없습니다.\n");
    int key = _getch();
    if (key == 'r') { system("cls"); }
}

void calenderDelete(int day) {
    int choice = 100, count = 0;
    node* parent = NULL;
    node* child = arr[day];
    node* p = arr[day];

    printf("__________________%s요일__________________\n", dateArr[day]);
    while (p != NULL) {
        printf("%d. %2d시 %2d분 :  %s\n", count, p->hour, p->min, p->task);
        p = p->link;
        count++;
    }

    while (choice >= count) {
        printf("삭제할 일정 선택>> ");
        scanf_s("%d", &choice);
    }

    if (choice == 0) {
        arr[day] = child->link; return;
    }
    else {
        for (int i = 0; i < choice; i++) {
            parent = child;
            child = child->link;
        }
        parent->link = child->link;
    }

    printf("★삭제 완료★\n\n"); Taskcount--;
    int key = _getch();
    if (key == 'r') { system("cls"); }
}

void calenderRun() {
    struct tm* t;  //시간과 분
    const time_t date = time(NULL);
    t = localtime(&date);
    time_t t_ALL = time(NULL);

    int choice = 0, day = 7;

    while (choice != 5) {
        system("cls");
        printf("%s ", ctime(&t_ALL));
        nowTask(t->tm_wday, t->tm_hour);
        printf("---------------------선 택----------------------\n");
        printf("1. 캘린더 추가\n");
        printf("2. 캘린더 수정\n");
        printf("3. 캘린더 삭제\n");
        printf("4. 캘린더 보기\n");
        printf("5. 캘린더 종료\n");
        printf("------------------------------------------------\n>> ");
        scanf_s("%d", &choice);
        if (choice != 5 && choice != 4) {
            while (day > 6) {
                printf("요일 선택>> ");
                printf("(0) 일요일 (1) 월요일 (2) 화요일\n(3) 수요일 (4) 목요일 (5) 금요일 (6) 토요일\n");
                scanf_s("%d", &day);
            }
        }

        switch (choice) {
        case 1: calenderInsert(day); break;
        case 2: calenderUpdate(day); break;
        case 3: calenderDelete(day); break;
        case 4: LookAll(); break;
        case 5: choice = 5; break;
        default:
            printf("잘못된 입력입니다.\n\n");
        }
        day = 7;
    }

    printf("\n\n");
}
