#include<windows.h>
#include<stdio.h>
#include<string.h>

typedef struct node {
    int number;              //��ǥ ��ȣ
    int type[3];                //��ǥ Ÿ��
    char task[50];           //��ǥ ����
    int achievementRate;     //�޼���
    struct node* link;
}node;
count = 0;  //��ü ��ǥ ����
node* head = NULL;

//�ְ� ��ǥ �� �޼��� ����
void achievementLook() {
    if (head == NULL) { printf("����� ��ǥ�� �����ϴ�.\n"); return; }
    

    node* n = head;   //��ȸ�� ��� 
    printf("---------------��ǥ��� �� �޼���---------------\n");
    while (n != NULL) {
        if (n != NULL) {
            printf("%d. %s %d %% �޼�\n", n->number, n->task, n->achievementRate);
            n = n->link;
        }
    }
    int key = _getch();
    if (key=='r'){ system("cls"); }
}

//�ְ� ��ǥ �߰� 
void insert() {
    node* p = (node*)malloc(sizeof(node));     //��� ����
    printf("-------------------��ǥŸ��---------------------\n");
    printf("1. T/F\n");
    printf("2. Ƚ��\n");
    printf("3. ����\n");
    printf("------------------------------------------------\n");
    scanf_s("%d", &p->type[0]);

    printf("��ǥ>> ");
    scanf_s("%s", p->task, 50);

    if (p->type[0] == 2) {
        printf("�� ȸ ����?>> ");
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

    if (head == NULL) {    //��� ����
        head = p;
    }
    else {
        node* n = head;
        while (n->link != NULL) n = n->link;
        n->link = p;
    }
    printf("���߰� �Ϸ�ڡ�\n");
    int key = _getch();
    if (key == 'r') { system("cls"); }
}

//�ְ� ��ǥ ����
void delete() {
    if (count == 0) { printf("��ǥ�� �����ϴ�!"); return; }
    node* n = head;   //��ȸ�� ��� 
    node* np = NULL;
    int c = 0;

    //��� ��� �����ֱ�
    achievementLook();

    //������ ��� Ž��
    while (1) {
        printf("������ ��ǥ ��ȣ>> ");
        scanf_s("%d", &c);
        if (c > count) printf("�߸��� �Է�\n");
        else break;
    }

    //��� ����
    while (n != NULL) {
        if (n->number == c) {
            if (np == NULL) {         //ù��° ��尡 ������ ���
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

    node* n2 = n->link;  //��ȣ -1
    if (n2 != NULL) {
        //������ ��ǥ�� ��ȣ-1
        while (n2 != NULL) {
            n2->number--;
            n2 = n2->link;
        }
    }

    printf("�ڻ��� �Ϸ��\n"); count--;
    int key = _getch();
    if (key == 'r') { system("cls"); }
}


//�ְ� ��ǥ �޼��� üũ
void achievementCheck() {
    achievementLook();
    int choice = count + 1;
    node* p = head;

    while (choice > count) {
        printf("üũ�� ��ǥ ��ȣ ����>> ");
        scanf_s("%d", &choice);
    }

    while (p->number != choice && p != NULL) p = p->link;

    int num = 0;
    if (p->type[0] == 1) { //T/F
        printf("��ǥ <%s>�� �����ϼ̳���?\n1.yes\n2.no\n", p->task);
        scanf_s("%d", &num);
        if (num == 1) {
            p->achievementRate = 100;
            printf("�ڸ�ǥ�� �޼��߽��ϴ�!!��\n\n");
        }
    }
    else if (p->type[0] == 2) {  //Ƚ��
        if (p->type[1] == p->type[2]) {
            p->achievementRate = 100;
            printf("�ڸ�ǥ�� �޼��߽��ϴ�!!��\n\n");
        }
        else {
            p->type[2] = p->type[2] + 1;
            p->achievementRate = (int)((100 / p->type[1]) * p->type[2]);
            printf("�޼��� %d %% ���õ� ��� ���ҽ��ϴ�.\n\n", p->achievementRate);
        }
    }
    else {   //����
        if (p->type[2] == 7) {
            p->achievementRate = 100;
            printf("�ڸ�ǥ�� �޼��߽��ϴ�!��\n\n");
        }
        else {
            p->type[2] = (p->type[2] + 1);
            p->achievementRate = (int)((100 / p->type[1]) * p->type[2]);
            printf("�޼��� %d %% ���õ� ��� ���ҽ��ϴ�.\n\n", p->achievementRate);
        }
    }
    int key = _getch();
    if (key == 'r') { system("cls"); }
}

void edit() {
    if (count == 0) { printf("������ ��ǥ�� �����ϴ�!"); return; }
    int c = 0;
    achievementLook();  //��� ��� �����ֱ�
    node* p = head;

     //������ ��� Ž��
    while (1) {
        printf("������ ��ǥ ��ȣ>> ");
        scanf_s("%d", &c);
        if (c > count) printf("�߸��� �Է�\n");
        else break;
    }

    //��� ����
    while (p != NULL) {
        if (p->number == c) {   // ������ ��� Ž�� ����
            printf("-------------------��ǥŸ��---------------------\n");
            printf("1. T/F\n");
            printf("2. Ƚ��\n");
            printf("3. ����\n");
            printf("------------------------------------------------\n");
            scanf_s("%d", &p->type[0]);

            printf("��ǥ>> ");
            scanf_s("%s", p->task, 50);

            if (p->type[0] == 2) {
                printf("�� ȸ ����?>> ");
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

    printf("�ڼ��� �Ϸ��\n");
    int key = _getch();
    if (key == 'r') { system("cls"); }
}

void GoalRun() {
    int choice = 0;

    while (choice != 6) {
        system("cls");
        printf("------------------------------------------------\n");
        printf("1. �ְ� ��ǥ �߰�\n");
        printf("2. �ְ� ��ǥ ����\n");
        printf("3. �ְ� ��ǥ ����\n");
        printf("4. �ְ� ��ǥ �޼��� üũ\n");
        printf("5. �ְ� ��ǥ �� �޼��� ����\n");
        printf("6. �ְ� ��ǥ ������\n");
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
            printf("�߸��� �Է��Դϴ�.\n");
        }
    }
}