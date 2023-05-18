#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
    char name[20]; // 본인 이름
    int studnetID; // 본인 학번
    char bookName[20]; // 책 이름
    short int returningstate; //반납 유무 1이면 반납 0이면 아직 대여중
    short int endYear; //반납 년도
    short int endMonth; // 반납 달
    short int endDay; // 반납 날짜
}Book; //구조체
typedef struct{
	char name[20];
	short int returningstate;
}Library;

int createBook(Book *b); //대출 목록에 추가
void readBook(Book b);   //책 하나의 대출 정보 출력
int updateBook(Book *b); //대출 정보 수정
int deleteBook(Book *b); //대출 목록에서 삭제(반납하기)

void saveBook(Book *b[], int count); //데이터를 파일에 저장
int loadBook(Book *b[], Library *l[]);             //파일의 데이터 불러오기
