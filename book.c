#include "book.h"

void readBook(Book b){
    printf("%8s %13d %14s %10hd %hd %hd\n", b.name, b.studnetID, b.bookName, b.endYear, b.endMonth, b.endDay);    
}    
int createBook(Book *b){
    printf("�̸� : ");
    scanf("%s",b->name);
    printf("�й� : ");
    scanf("%d",&b->studnetID);
    printf("å �̸� : ");
    getchar();
    scanf("%[^\n]s",b->bookName);
    printf("�ݳ� �� ex)2001 01 01 : ");
    scanf ("%hd %hd %hd",&b->endYear, &b->endMonth, &b->endDay);
    return 1;
}
int updateBook(Book *b){
    printf("�̸� : ");
    scanf("%s",b->name);
    printf("�й� : ");
    scanf("%d",&b->studnetID);
    printf("å �̸� : ");
    getchar();
    scanf("%[^\n]s",b->bookName);
    printf("�ݳ� �� : ");
    scanf ("%hd %hd %hd",&b->endYear, &b->endMonth, &b->endDay);
    printf("���� ����!\n");
    return 1;
}
int deleteBook(Book *b){
    b->returningstate = 1;
    printf("�ݳ� �Ϸ�!\n");
    return 1;
}
void saveBook(Book *b[], int count){
    FILE *fp;
    FILE *s;
    fp = fopen("book.txt","wt");
    s = fopen("booklist.txt","wt");
    for(int i=0; i<count; i++){
        if(b[i]->returningstate == 1){
          fprintf(s,"%d %s",b[i]->returningstate,b[i]->bookName);
          continue;
        }
        fprintf(fp,"%s %d %hd %hd %s\n",b[i]->name,b[i]->studnetID,b[i]->endMonth,b[i]->endDay,b[i]->bookName);
        fprintf(s,"%d %s",b[i]->returningstate,b[i]->bookName);
    }
    fclose(fp);
    fclose(s);
    printf("=> �����! \n");
}
int loadBook(Book *b[], Library l[]){
    int i=0;
    FILE *fp;
    FILE *s;
    s = fopen("booklist.txt","rt");
    for(int j=0; j<30; j++){
	if(feof(s)) break;
	fscanf(s,"%d %[^\n]s",&l[j].returningstate,l[j].name);
    }
    fp = fopen("book.txt","rt");
    if(fp==NULL) return 0;
    for(; i<30; i++){
	b[i] = (Book *)malloc(sizeof(Book));
        if(feof(fp)) break;
        fscanf(fp, "%s %d %hd %hd",b[i]->name,&b[i]->studnetID,&b[i]->endMonth,&b[i]->endDay);
	fscanf(fp,"%[^\n]s",b[i]->bookName);
    }
    fclose(fp);
    return i-1;
}

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

int listBook(Book *b[], int count){
    printf("\nNo    Name      StudentID      Book Name       Due date\n");
    printf("===============================================================\n");
    for(int i=0; i<count; i++){
        if(b[i] == NULL){ // ������ ���� ó������
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
    scanf("%s", search);

    printf("\nNo    Name      StudentID      Book Name       state \n");
    printf("===============================================================\n");

    for(int i=0; i<count; i++){
        if(b[i] == NULL){
        continue;
        }
        if(strstr(b[i]->bookName, search)){

            printf("%2d ", i+1);
            if(b[i]->returningstate==1){
                printf("   %s      %d        %s        �뿩 ���� \n",b[i]->name,b[i]->studnetID,b[i]->bookName);
            }
            else{
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

    printf("���� ��¥ : %d %d %d\n", currentYear, currentMonth, currentDay);
    printf("\nNo    Name      StudentID      Book Name       Due date\n");
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

void recommendBook(Book *b){

}

