
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
char* dateArr[15] = { "��", "��", "ȭ", "��", "��", "��", "��" };
node* arr[7] = { NULL };  //���� �迭

void LookAll() {
    printf("<�̹��� ����>  ");
    if (Taskcount == 0) { printf("������ �����ϴ�!\n"); return; }
    printf("\n");
    for (int i = 0; i < 7; i++) {
        printf("__________________%s����__________________\n", dateArr[i]);
        node* p = arr[i];
        while (p != NULL) {
            printf("%2d�� %2d�� :  %s\n", p->hour, p->min, p->task);
            p = p->link;
        }
        printf("\n");
    }
    int key = _getch();
    if (key == 'r') { system("cls"); }
}

void calenderInsert(int day) {
    node* n = (node*)malloc(sizeof(node));
    printf("�ð�>> "); scanf_s("%d", &n->hour);
    printf("��>> "); scanf_s("%d", &n->min);
    printf("�� ��>> "); scanf_s("%s", n->task, 100);
    n->link = NULL;

    if (arr[day] == NULL) {
        arr[day] = n;
    }
    else {
        node* p = arr[day];
        while (p->link != NULL) p = p->link;
        p->link = n;
    }

    printf("���߰� �Ϸ��\n\n"); Taskcount++;
    int key = _getch();
    if (key == 'r') { system("cls"); }
}

void calenderUpdate(int day) {
    node* p = arr[day];
    if (p == NULL) {
        printf("%s������ ������ �����ϴ�.\n\n", dateArr[day]);
        return;
    }
    LookAll();
    node* p2 = arr[day];
    int choice = 100, count = 0;
    printf("__________________%s����__________________\n", dateArr[day]);
    while (p != NULL) {
        printf("%d. %2d�� %2d�� :  %s\n", count, p->hour, p->min, p->task);
        p = p->link;
        count++;
    }
    while (choice >= count) {
        printf("������ ���� ����>> ");
        scanf_s("%d", &choice);
    }
    if (choice != 0) {
        for (int i = 0; i < count - 1; i++) p2 = p2->link;
    }

    printf("�ð�>> "); scanf_s("%d", &p2->hour);
    printf("��>> "); scanf_s("%d", &p2->min);
    printf("�� ��>> "); scanf_s("%s", p2->task, 100);

    printf("�ڼ����Ϸ��\n\n");
    int key = _getch();
    if (key == 'r') { system("cls"); }
}

void nowTask(int day, int h) {
    printf("���� �� �� : ");
    node* p = arr[day];
    if (p != NULL) {
        while (p != NULL) {
            if (p->hour == h) {
                printf("%s\n", p->task); return;
            }
            else { p = p->link; }
        }
    }
    printf("���� �� ���� �����ϴ�.\n");
    int key = _getch();
    if (key == 'r') { system("cls"); }
}

void calenderDelete(int day) {
    int choice = 100, count = 0;
    node* parent = NULL;
    node* child = arr[day];
    node* p = arr[day];

    printf("__________________%s����__________________\n", dateArr[day]);
    while (p != NULL) {
        printf("%d. %2d�� %2d�� :  %s\n", count, p->hour, p->min, p->task);
        p = p->link;
        count++;
    }

    while (choice >= count) {
        printf("������ ���� ����>> ");
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

    printf("�ڻ��� �Ϸ��\n\n"); Taskcount--;
    int key = _getch();
    if (key == 'r') { system("cls"); }
}

void calenderRun() {
    struct tm* t;  //�ð��� ��
    const time_t date = time(NULL);
    t = localtime(&date);
    time_t t_ALL = time(NULL);

    int choice = 0, day = 7;

    while (choice != 5) {
        system("cls");
        printf("%s ", ctime(&t_ALL));
        nowTask(t->tm_wday, t->tm_hour);
        printf("---------------------�� ��----------------------\n");
        printf("1. Ķ���� �߰�\n");
        printf("2. Ķ���� ����\n");
        printf("3. Ķ���� ����\n");
        printf("4. Ķ���� ����\n");
        printf("5. Ķ���� ����\n");
        printf("------------------------------------------------\n>> ");
        scanf_s("%d", &choice);
        if (choice != 5 && choice != 4) {
            while (day > 6) {
                printf("���� ����>> ");
                printf("(0) �Ͽ��� (1) ������ (2) ȭ����\n(3) ������ (4) ����� (5) �ݿ��� (6) �����\n");
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
            printf("�߸��� �Է��Դϴ�.\n\n");
        }
        day = 7;
    }

    printf("\n\n");
}
