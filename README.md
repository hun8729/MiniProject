# 📚 miniproject

## 📚 2023-1 OSS 팀 프로젝트
![istockphoto-1153884728-170667a](https://user-images.githubusercontent.com/130721702/236655140-bf8c71e0-d82a-4a1f-9273-a8ebbd1545a9.jpg)

## 📚 mini project 주제
* 혼자서 도서 대출 및 반납을 할 수 있는 프로그램

## 📚 mini project 소개
* 혼자 편하게 책을 빌리고 반납 할 수 있게 해주는 프로그램
* 학번과 이름을 통해서 간편하게 이용할 수 있습니다.

## 📚 대략 기능설명
* 도서 대출
* 도서 반납
* 반납 기간 연장
* 도서 검색
* 현재 상태 확인

## 📚 코드 및 기능
```C#
typedef struct{
    char name[20]; // 본인 이름
    int studnetID; // 본인 학번
    char bookName[20]; // 책 이름
    char returningstate; //반납 유무 1이면 반납 0이면 아직 대여중
    short int endMonth; // 반납 달
    short int endDay; // 반납 날
}Book; //구조체

int createBook(Book *b); //대출 목록에 추가
void readBook(Book b);   //책 하나의 대출 정보 출력
int updateBook(Book *b); //대출 정보 수정
int deleteBook(Book *b); //대출 목록에서 삭제

int selectMenu();        //메뉴 선택하는 함수
int selectNum(Book *b[], int count); //리스트 번호 선택

void saveBook(Book *b[], int count); //데이터를 파일에 저장
int loadBook(Book *b[]);             //파일의 데이터 불러오기
int listBook(Book *b[], int count);  //대여한 책 리스트 블러오기

void searchName(Book *b[], int count);    //본인 이름 검색
void searchBook(Book *b[], int count);    //책 이름 검색
void searchOverdue(Book *b[], int count); //반납 날이 지난 책 검색
void bestseller(Book *b[]);     //베스트셀러 책 출력
```



## 📚 개발환경 및 언어
<img src="https://img.shields.io/badge/C-A8B9CC?style=flat&logo=C&logoColor=white"/>
 <img src="https://img.shields.io/badge/Git-F05032?style=flat&logo=Git&logoColor=white"/>

## 📚 팀소개 및 팀원이 맡은 역할
팀원
박지훈 [hun8729 GITHUB LINK](https://github.com/hun8729)
 * Repo Owner
 * WIKI 관리
 * 

심성환 [hwan129 GITHUB LINK](https://github.com/hwan129)
 * Contributer
 * 
