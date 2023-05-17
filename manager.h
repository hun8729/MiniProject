#include <time.h>
#include "book.h"

int selectMenu();        //메뉴 선택하는 함수
int selectNum(Book *b[], int count, Library *l[]); //리스트 번호 선택
void listBook(Book *b[], int count, Library *l[]);  //대여한 책 리스트 블러오기

void searchName(Book *b[], int count);    //본인 이름 검색
void searchBook(Book *b[], int count);    //책 이름 검색
void showOverdue(Book *b[], int count); //반납 날이 지난 책 조회
void recommendBook(Library *l[], int count);    // 랜덤으로 대출 중이 아닌 책을 추천 해주는 기능
