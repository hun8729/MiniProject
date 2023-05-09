#include "book.h"

void readBook(Book b){
    printf("%s    %d   %s  %hd %hd\n",b.name,b.studnetID,b.bookName,b.endMonth,b.endDay);    
}
int createBook(Book *b){
    printf("이름 : ");
    scanf("%s",b->name);
    printf("학번 : ");
    scanf("%d",&b->studnetID);
    printf("책 이름 : ");
    getchar();
    scanf("%[^\n]s",b->bookName);
    printf("반납 날 : ");
    scanf ("%hd %hd",&b->endMonth,&b->endDay);
    return 1;
}
int updateBook(Book *b){
    printf("이름 : ");
    scanf("%s",b->name);
    printf("학번 : ");
    scanf("%d",&b->studnetID);
    printf("책 이름 : ");
    getchar();
    scanf("%[^\n]s",b->bookName);
    printf("반납 날 : ");
    scanf ("%hd %hd",&b->endMonth,&b->endDay);
    printf("수정 성공!\n");
    return 1;
}
int deleteBook(Book *b){
    b->returningstate = 1;
    printf("반납 완료!\n");
    return 1;
}
void saveBook(Book *b[], int count){
    FILE *fp;
    FILE *s;
    fp = fopen("book.txt","wt");
    s = fopen("booklist.txt","wt");
    for(int i=0; i<count; i++){
        if(b[i]->returningstate == 1) continue;
        fprintf(fp,"%s %d %hd %hd %s\n",b[i]->name,b[i]->studnetID,b[i]->endMonth,b[i]->endDay,b[i]->bookName);
        fprintf(s,"%d %s",b[i]->returningstate,b[i]->bookName);
    }
    fclose(fp);
    fclose(s);
    printf("=> 저장됨! \n");
}
int loadBook(Book *b[]){
    int i=0;
    FILE *fp;
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

int selectMenu(){        //선택 메뉴
    int menu;
    printf("\n===도서 대출/반납 메뉴\n");
    printf("1. 대출 현황 조회\n");  //조회
    printf("2. 도서 대출/n");       //추가
    printf("3. 대출 현황 수정/n");  //수정
    printf("4. 도서 반납/n");       //삭제
    printf("5. 도서 이름 검색/n"); 
    printf("6. 대출자 이름 검색/n");
    printf("7. 대출 미납자/n");
    printf("8. 오늘의 책/n");       //대출 중이 아닌 책들 중 하나 추천
    printf("0. 종료 >> ");
    scanf("%d", &menu);

    return menu;
}

int selectNum(Book *b[], int count){ //선택한 메뉴 취소 or 번호 선택
    int num;
    listContact(b, count);
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &num);

    return num;
}

int listBook(Book *b[], int count){
    printf("\nNo    Name        StudentID       Book Name       Due date\n");
    printf("===============================================================\n");
    for(int i=0; i<count; i++){
        if(b[i] == NULL){ // 없으면 루프 처음으로
            continue;
        }
        printf("%2d ", i+1);
        readBook(*b[i]);
    }
    printf("\n");
}

void searchName(Book *b[], int count){
    int scnt=0;
    char search[20];

    printf("검색할 본인 이름은? ");
    scanf("%s", search);

    printf("\nNo    Name        StudentID       Book Name       Due date\n");
    printf("===============================================================\n");

    for(int i=0; i<count; i++){
        if(b[i] == NULL){
        continue;
        }
        if(strstr(b[i]->name, search)){
        printf("%2d ", i+1);
        readContact(*b[i]);
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
    scanf("%s", search);

    printf("\nNo    Name        StudentID       Book Name       Due date\n");
    printf("===============================================================\n");

    for(int i=0; i<count; i++){
        if(b[i] == NULL){
        continue;
        }
        if(strstr(b[i]->bookName, search)){
        printf("%2d ", i+1);
        readContact(*b[i]);
        scnt++;
        }
    }
    if(scnt == 0){
        printf("\n===검색된 데이터 없음===\n");
    }
    printf("\n");
}

void showOverdue(Book *b[], int count){
    
}

void recommendBook(Book *b){

}