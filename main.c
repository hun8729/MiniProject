#define SIZE 30
#include "manager.h"


int main(void){
  Book *b[SIZE];
  Library *l[100];
  int booknum = 0;
  int index=0, count=0, menu;
  count = loadBook(b);
  booknum = loadBookList(l);
  index = count;
  if(count!=0){
        printf("=> 로딩 성공!\n");
       }else{
         printf("=> 파일 없음\n");
    }
  while(1){
    menu = selectMenu();
    if(menu == 0) break;
    if(menu == 1){
      if(count<=0){
        printf("데이터가 없ㅅ브니다.\n");
      }else{
        listBook(b, index);
      }
      }
    else if(menu == 2){
      b[index] = (Book *)malloc(sizeof(Book));
      count += createBook(b[index], l);
      index++;
    }
    else if(menu == 3){
      int modif=0;
      if(count<=0){
                printf("데이터가 없습니다.\n");
            }else{
            modif = selectNum(b, index);
        if(modif<0){
          printf("취소 됨!\n");
          continue;
        }
        updateBook(b[modif-1]);
    }
    }
    else if(menu == 4){
      int delete;
            int again;
            if(count<=0){
                printf("데이터가 없ㅅ브니다.\n");
            }else{
            delete = selectNum(b, index);
            if(delete<=0){
                printf("취소됨!\n");
                continue;
            }
            printf("정말로 반납하시겠습니까?(삭제 :1) ");
            scanf("%d",&again);
            if(again==1){
		l[booknum] = (Library *)malloc(sizeof(Library));
                if(deleteBook(b[delete-1],l[booknum])){
		    booknum++;
                    count--;
                }
            }         
        }
        }
    else if(menu == 5){
      saveBook(b, index);
    }else if(menu == 6){
      searchBook(b, index);
    }else if(menu == 7){
      searchName(b, index);
    }

    else if(menu == 8){
      showOverdue(b, index);
    }
    else if(menu == 9){
      recommendBook(l);
    }
  }
  printf("종료됨!\n");
  return 0;
}
