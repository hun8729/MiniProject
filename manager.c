#include "manager.h"

int selectMenu(){        //���� �޴�
    int menu;
    printf("\n===���� ����/�ݳ� �޴�\n");
    printf("1. ���� ��Ȳ ��ȸ\n");  //��ȸ
    printf("2. ���� ����\n");       //�߰�
    printf("3. ���� ��Ȳ ����\n");  //����
    printf("4. ���� �ݳ�\n");       //����
    printf("5. ���� �����ϱ�\n");
    printf("6. ���� �̸� �˻�\n"); 
    printf("7. ������ �̸� �˻�\n");
    printf("8. ���� �̳���\n");
    printf("9. ������ å\n");       //���� ���� �ƴ� å�� �� �ϳ� ��õ
    printf("0. ����\n");
    printf("���ϴ� �޴���? :");
    scanf("%d", &menu);

    return menu;
}

void listBook(Book *b[], int count){
    printf("\nNo    Name      StudentID      Book Name       Due date\n");
    printf("===============================================================\n");
    for(int i=0; i<count; i++){
        if(b[i] == NULL||b[i]->returningstate==1){ // ������ ���� ó������
            continue;
        }
        printf("%2d ", i+1);
        readBook(*b[i]);
    }
    printf("\n");
}
int selectNum(Book *b[], int count){ //������ �޴� ��� or ��ȣ ����
    int num;
    listBook(b, count);
    printf("��ȣ�� (��� : 0)? ");
    scanf("%d", &num);
    return num;
}
void searchName(Book *b[], int count){
    int scnt=0;
    int sID;

    printf("�˻��� ���� �й���? ");
    scanf("%d", &sID);

    printf("\nNo    Name      StudentID      Book Name       Due date\n");
    printf("===============================================================\n");
    for(int i=0; i<count; i++){
        if(b[i] == NULL){
        continue;
        }
        if(b[i]->returningstate == 1){
          continue;
        }
        if(b[i]->studnetID == sID){
        printf("%2d ", i+1);
        readBook(*b[i]);
        scnt++;
        }
    }
    if(scnt == 0){
    printf("\n===�˻��� ������ ����===\n");
    }
    printf("\n");
}
void searchBook(Book *b[], int count){
    int scnt=0;
    char search[20];

    printf("�˻��� å�� �̸���? ");
    getchar();
    scanf("%[^\n]s", search);

    printf("\nNo    Name      StudentID      Book Name       state \n");
    printf("===============================================================\n");

    for(int i=0; i<count; i++){
        if(b[i] == NULL){
        continue;
        }
        if(b[i]->returningstate == 1){
          continue;
        }
        if(strstr(b[i]->bookName, search)){
            printf("%2d ", i+1);
            if(b[i]->returningstate==0){
                printf("   %s      %d        %s        �뿩 �� \n",b[i]->name,b[i]->studnetID,b[i]->bookName);
                printf("�ݳ� ���� ���� %hd�� %hd�� %hd���Դϴ�!\n",b[i]->endYear, b[i]->endMonth,b[i]->endDay);
            }
            scnt++;
        }
    }
    if(scnt == 0){
        printf("\n===�˻��� ������ ����===\n");
    }
    printf("\n");
}

void showOverdue(Book *b[], int count){     //�ݳ����ڰ� ���� å ����Ʈ
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    int currentYear = localTime->tm_year + 1900;
    int currentMonth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;
    int scnt=0;

    printf("\n���� ��¥ : %d %d %d\n", currentYear, currentMonth, currentDay);
    printf("\nNo    Name      StudentID      Book Name       Due date\n");
      printf("===============================================================\n");

    for(int i=0; i<count; i++){
        if(b[i] == NULL){
            continue;
        }
        if (currentYear > b[i]->endYear || (currentYear == b[i]->endYear && currentMonth > b[i]->endMonth) ||(currentYear == b[i]->endYear && currentMonth == b[i]->endMonth && currentDay > b[i]->endDay)) {
            printf("%2d ", i+1);
            readBook(*b[i]);
            scnt++;
        }
    }
    if(scnt == 0){
        printf("\n===�˻��� ������ ����===\n");
    }
}

void recommendBook(Library *l[], int booknum){
    int randomNumber;
    srand(time(NULL));
    while (1){ //�ݳ��� å �߿��� ��õ
        if(booknum == 0){
            printf("å�� �����ϴ�.\n");
            break;
        }
        randomNumber = rand() % booknum; // 1���� count ������ ������ ��ȣ ����
        if(l[randomNumber]){
            printf("������ '%s'��(��) �о�� ���� �����?\n", l[randomNumber]->name);
            break;
        }   
    }
}