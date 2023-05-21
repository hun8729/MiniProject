#include "manager.h"

int selectMenu(){        //선택 메뉴
    int menu;
    printf("\n===도서 대출/반납 메뉴\n");
    printf("1. 대출 현황 조회\n");  //조회
    printf("2. 도서 대출\n");       //추가
    printf("3. 대출 현황 수정\n");  //수정
    printf("4. 도서 반납\n");       //삭제
    printf("5. 파일 저장하기\n");
    printf("6. 도서 이름 검색\n"); 
    printf("7. 대출자 이름 검색\n");
    printf("8. 대출 미납자\n");
    printf("9. 오늘의 책\n");       //대출 중이 아닌 책들 중 하나 추천
    printf("0. 종료\n");
    printf("원하는 메뉴는? :");
    scanf("%d", &menu);

    return menu;
}

void listBook(Book *b[], int count){
    printf("\nNo    Name      StudentID      Book Name       Due date\n");
    printf("===============================================================\n");
    for(int i=0; i<count; i++){
        if(b[i] == NULL||b[i]->returningstate==1){ // 없으면 루프 처음으로
            continue;
        }
        printf("%2d ", i+1);
        readBook(*b[i]);
    }
    printf("\n");
}
int selectNum(Book *b[], int count){ //선택한 메뉴 취소 or 번호 선택
    int num;
    listBook(b, count);
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &num);
    return num;
}
void searchName(Book *b[], int count){
    int scnt=0;
    int sID;

    printf("검색할 본인 학번은? ");
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
    printf("\n===검색된 데이터 없음===\n");
    }
    printf("\n");
}
void searchBook(Book *b[], int count){
    int scnt=0;
    char search[20];

    printf("검색할 책의 이름은? ");
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
                printf("   %s      %d        %s        대여 중 \n",b[i]->name,b[i]->studnetID,b[i]->bookName);
                printf("반납 예정 일은 %hd년 %hd월 %hd일입니다!\n",b[i]->endYear, b[i]->endMonth,b[i]->endDay);
            }
            scnt++;
        }
    }
    if(scnt == 0){
        printf("\n===검색된 데이터 없음===\n");
    }
    printf("\n");
}

void showOverdue(Book *b[], int count){     //반납일자가 지난 책 리스트
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    int currentYear = localTime->tm_year + 1900;
    int currentMonth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;
    int scnt=0;

    printf("\n현재 날짜 : %d %d %d\n", currentYear, currentMonth, currentDay);
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
        printf("\n===검색된 데이터 없음===\n");
    }
}

void recommendBook(Library *l[], int booknum){
    int randomNumber;
    srand(time(NULL));
    while (1){ //반납된 책 중에서 추천
        if(booknum == 0){
            printf("책이 없습니다.\n");
            break;
        }
        randomNumber = rand() % booknum; // 1에서 count 사이의 랜덤한 번호 선택
        if(l[randomNumber]){
            printf("오늘은 '%s'을(를) 읽어보는 것이 어떤가요?\n", l[randomNumber]->name);
            break;
        }   
    }
}