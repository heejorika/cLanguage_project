#include<windows.h>
#include<stdio.h>
#include<string.h>

typedef struct node {
    int number;              //목표 번호
    int type[3];                //목표 타입
    char task[50];           //목표 내용
    int achievementRate;     //달성율
    struct node* link;
}node;
count = 0;  //전체 목표 개수
node* head = NULL;

//주간 목표 및 달성율 보기
void achievementLook() {
    if (head == NULL) { printf("출력할 목표가 없습니다.\n"); return; }
    

    node* n = head;   //순회할 노드 
    printf("---------------목표목록 및 달성율---------------\n");
    while (n != NULL) {
        if (n != NULL) {
            printf("%d. %s %d %% 달성\n", n->number, n->task, n->achievementRate);
            n = n->link;
        }
    }
    int key = _getch();
    if (key=='r'){ system("cls"); }
}

//주간 목표 추가 
void insert() {
    node* p = (node*)malloc(sizeof(node));     //노드 생성
    printf("-------------------목표타입---------------------\n");
    printf("1. T/F\n");
    printf("2. 횟수\n");
    printf("3. 매일\n");
    printf("------------------------------------------------\n");
    scanf_s("%d", &p->type[0]);

    printf("목표>> ");
    scanf_s("%s", p->task, 50);

    if (p->type[0] == 2) {
        printf("몇 회 실행?>> ");
        scanf_s("%d", &p->type[1]);
        p->type[2] = 0;
    }
    else if (p->type[0] == 3) {
        p->type[1] = 7;
        p->type[2] = 0;
    }

    count++;
    p->number = count;
    p->achievementRate = 0;
    p->link = NULL;

    if (head == NULL) {    //노드 연결
        head = p;
    }
    else {
        node* n = head;
        while (n->link != NULL) n = n->link;
        n->link = p;
    }
    printf("★추가 완료★★\n");
    int key = _getch();
    if (key == 'r') { system("cls"); }
}

//주간 목표 삭제
void delete() {
    if (count == 0) { printf("목표가 없습니다!"); return; }
    node* n = head;   //순회할 노드 
    node* np = NULL;
    int c = 0;

    //모든 노드 보여주기
    achievementLook();

    //삭제할 노드 탐색
    while (1) {
        printf("삭제할 목표 번호>> ");
        scanf_s("%d", &c);
        if (c > count) printf("잘못된 입력\n");
        else break;
    }

    //노드 삭제
    while (n != NULL) {
        if (n->number == c) {
            if (np == NULL) {         //첫번째 노드가 삭제할 노드
                head = n->link;
                break;
            }
            else {
                np->link = n->link;
                break;
            }
        }
        else {
            np = n;
            n = n->link;
        }
    }

    node* n2 = n->link;  //번호 -1
    if (n2 != NULL) {
        //기존의 목표들 번호-1
        while (n2 != NULL) {
            n2->number--;
            n2 = n2->link;
        }
    }

    printf("★삭제 완료★\n"); count--;
    int key = _getch();
    if (key == 'r') { system("cls"); }
}


//주간 목표 달성율 체크
void achievementCheck() {
    achievementLook();
    int choice = count + 1;
    node* p = head;

    while (choice > count) {
        printf("체크할 목표 번호 선택>> ");
        scanf_s("%d", &choice);
    }

    while (p->number != choice && p != NULL) p = p->link;

    int num = 0;
    if (p->type[0] == 1) { //T/F
        printf("목표 <%s>를 성취하셨나요?\n1.yes\n2.no\n", p->task);
        scanf_s("%d", &num);
        if (num == 1) {
            p->achievementRate = 100;
            printf("★목표를 달성했습니다!!★\n\n");
        }
    }
    else if (p->type[0] == 2) {  //횟수
        if (p->type[1] == p->type[2]) {
            p->achievementRate = 100;
            printf("★목표를 달성했습니다!!★\n\n");
        }
        else {
            p->type[2] = p->type[2] + 1;
            p->achievementRate = (int)((100 / p->type[1]) * p->type[2]);
            printf("달성율 %d %% 오늘도 고생 많았습니다.\n\n", p->achievementRate);
        }
    }
    else {   //매일
        if (p->type[2] == 7) {
            p->achievementRate = 100;
            printf("★목표를 달성했습니다!★\n\n");
        }
        else {
            p->type[2] = (p->type[2] + 1);
            p->achievementRate = (int)((100 / p->type[1]) * p->type[2]);
            printf("달성율 %d %% 오늘도 고생 많았습니다.\n\n", p->achievementRate);
        }
    }
    int key = _getch();
    if (key == 'r') { system("cls"); }
}

void edit() {
    if (count == 0) { printf("수정할 목표가 없습니다!"); return; }
    int c = 0;
    achievementLook();  //모든 노드 보여주기
    node* p = head;

     //수정할 노드 탐색
    while (1) {
        printf("수정할 목표 번호>> ");
        scanf_s("%d", &c);
        if (c > count) printf("잘못된 입력\n");
        else break;
    }

    //노드 수정
    while (p != NULL) {
        if (p->number == c) {   // 수정할 노드 탐색 성공
            printf("-------------------목표타입---------------------\n");
            printf("1. T/F\n");
            printf("2. 횟수\n");
            printf("3. 매일\n");
            printf("------------------------------------------------\n");
            scanf_s("%d", &p->type[0]);

            printf("목표>> ");
            scanf_s("%s", p->task, 50);

            if (p->type[0] == 2) {
                printf("몇 회 실행?>> ");
                scanf_s("%d", &p->type[1]);
                p->type[2] = 0;
            }
            else if (p->type[0] == 3) {
                p->type[1] = 7;
                p->type[2] = 0;
            }
            break;
        }else {
            p = p->link;
        }
    }

    printf("★수정 완료★\n");
    int key = _getch();
    if (key == 'r') { system("cls"); }
}

void GoalRun() {
    int choice = 0;

    while (choice != 6) {
        system("cls");
        printf("------------------------------------------------\n");
        printf("1. 주간 목표 추가\n");
        printf("2. 주간 목표 수정\n");
        printf("3. 주간 목표 삭제\n");
        printf("4. 주간 목표 달성율 체크\n");
        printf("5. 주간 목표 및 달성율 보기\n");
        printf("6. 주간 목표 나가기\n");
        printf("------------------------------------------------\n>> ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: insert(); break;
        case 2: edit(); break;
        case 3: delete(); break;
        case 4: achievementCheck(); break;
        case 5: achievementLook(); break;
        case 6: break;
        default:
            printf("잘못된 입력입니다.\n");
        }
    }
}