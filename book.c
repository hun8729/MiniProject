#include "book.h"

void readBook(Book b){
    printf("%7s%13d%14s%14hd %hd %hd\n", b.name, b.studnetID, b.bookName, b.endYear, b.endMonth, b.endDay);    
}
int timeCal(Book *b){ //현재 날짜와 입력된 날짜 차이 계산
  time_t currentTime = time(NULL);
    struct tm *currentDate = localtime(&currentTime);

    struct tm enteredDate = {0};
    enteredDate.tm_mday = b->endDay;
    enteredDate.tm_mon = b->endMonth - 1;
    enteredDate.tm_year = b->endYear - 1900;


    time_t currentTimestamp = mktime(currentDate);
    time_t enteredTimestamp = mktime(&enteredDate);

    double secondsDiff = difftime(enteredTimestamp, currentTimestamp);
    double daysDiff = secondsDiff / (60 * 60 * 24);

    if (daysDiff >= 30 || daysDiff < 0 || b->endDay < 0 || b->endDay > 32) {
      printf("반납일을 잘못 입력하였습니다.(현재 날짜보다 많으며 30일 이내)\n");
      return 1;
    }else {
      return 0;
    }
}
int createBook(Book *b, Library *l[]){
    printf("이름 : ");
    scanf("%s",b->name);
    printf("학번 : ");
    scanf("%d",&b->studnetID);
    printf("책 이름 : ");
    getchar();
    scanf("%[^\n]s",b->bookName);
    
    while(1){
      printf("반납일 ex)2001 01 01 : ");
      scanf ("%hd %hd %hd",&b->endYear, &b->endMonth, &b->endDay);
      if(timeCal(b) == 0){
        break;
      }
    }
    
    b->returningstate=0;
    for(int i = 0; l[i]->name; i++){  //반납리스트에 빌리려하는 책이 있다면 반납리스트에서 지우기
        if(l[i]->name == b->bookName){
            free(l[i]);
            l[i] == NULL;
        }
    }
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
    while(1){
      printf("반납일 ex)2001 01 01 : ");
      scanf ("%hd %hd %hd",&b->endYear, &b->endMonth, &b->endDay);
      if(timeCal(b) == 0){
        break;
      }
    }
    printf("수정 성공!\n");
    return 1;
}
int deleteBook(Book *b, Library *l){
    b->returningstate = 1;
    strcpy(l->name,b->bookName);
    printf("반납 완료!\n");
    return 1;
}

void saveBook(Book *b[],Library *l[], int count, int booknum){
    FILE *fp;
    FILE *s;
    fp = fopen("book.txt","wt");
    s = fopen("booklist.txt","wt");
    for(int i=0; i<count; i++){     //대여리스트(book.txt)에 저장
      fprintf(fp,"%hd %s %d %hd %hd %hd%s\n",b[i]->returningstate,b[i]->name,b[i]->studnetID,b[i]->endYear,b[i]->endMonth,b[i]->endDay,b[i]->bookName);
    }
  for(int i=0; i<booknum; i++){
    int re=0;
    if(l[i]==NULL) break;
    for(int j=0; j<=count; j++){
      if(b[j]==NULL) break;
    }
    fprintf(s,"%s\n",l[i]->name); //반납리스트(booklist.txt)에 저장
  }
    fclose(fp);
    fclose(s);
    printf("=> 저장됨! \n");
}
int loadBook(Book *b[]){    //대여리스트 불러오기
    int i=0;
    FILE *fp;
    fp = fopen("book.txt","rt");
    if(fp==NULL) return 0;
    for(; i<30; i++){
      if(feof(fp)) break;
      b[i] = (Book *)malloc(sizeof(Book));
      fscanf(fp, "%hd %s %d %hd %hd %hd",&b[i]->returningstate,b[i]->name,&b[i]->studnetID,&b[i]->endYear,&b[i]->endMonth,&b[i]->endDay);
      fscanf(fp,"%[^\n]s",b[i]->bookName);
    }
    fclose(fp);
    return i-1;
}
int loadBookList(Library *l[]){ //반납리스트 불러오기
  int i=0;
  FILE *s;
  s = fopen("booklist.txt","rt");
  if(s==NULL) return 0;
  for(; i<100; i++){
    if(feof(s)) break;
    l[i] = (Library *)malloc(sizeof(Library));
    fgets(l[i]->name, sizeof(l[i]->name), s);
    l[i]->name[strcspn(l[i]->name, "\n")] = '\0';
  }
  fclose(s);
  return i-1;
}
