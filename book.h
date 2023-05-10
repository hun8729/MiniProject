#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


typedef struct{
    char name[20]; // 본인 이름
    int studnetID; // 본인 학번
    char bookName[20]; // 책 이름
    char returningstate; //반납 유무 1이면 반납 0이면 아직 대여중
    short int endYear; //반납 년도
    short int endMonth; // 반납 달
    short int endDay; // 반납 날짜
}Book; //구조체
typedef struct{
	char name[20];
	int returningstate;
}Library;

int createBook(Book *b); //대출 목록에 추가
void readBook(Book b);   //책 하나의 대출 정보 출력
int updateBook(Book *b); //대출 정보 수정
int deleteBook(Book *b); //대출 목록에서 삭제(반납하기)

void saveBook(Book *b[], int count); //데이터를 파일에 저장
int loadBook(Book *b[], Library l[]);             //파일의 데이터 불러오기

int selectMenu();        //메뉴 선택하는 함수
int selectNum(Book *b[], int count); //리스트 번호 선택
int listBook(Book *b[], int count);  //대여한 책 리스트 블러오기

void searchName(Book *b[], int count);    //본인 이름 검색
void searchBook(Book *b[], int count);    //책 이름 검색
void showOverdue(Book *b[], int count); //반납 날이 지난 책 조회
void recommendBook(Book *b);    // 랜덤으로 대출 중이 아닌 책을 추천 해주는 기능
