#define SIZE 30
#include "manager.h"


int main(void){
  Book *b[SIZE];
  Library *l[SIZE];
  int index=0, count=0, menu;
  count = loadBook(b,l);
  index = count;
  if(count!=0){
        printf("=> �ε� ����!\n");
       }else{
         printf("=> ���� ����\n");
    }
  while(1){
    menu = selectMenu();
    if(menu == 0) break;
    if(menu == 1){
      if(count<=0){
        printf("�����Ͱ� �����ϴ�.\n");
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
                printf("�����Ͱ� �����ϴ�.\n");
            }else{
            modif = selectNum(b, index);
        if(modif<0){
          printf("��� ��!\n");
          continue;
        }
        updateBook(b[modif-1]);
    }
    }
    else if(menu == 4){
      int delete;
            int again;
            if(count<=0){
                printf("�����Ͱ� �����ϴ�.\n");
            }else{
            delete = selectNum(b, index);
            if(delete<=0){
                printf("��ҵ�!\n");
                continue;
            }
            printf("������ �ݳ��Ͻðڽ��ϱ�?(���� :1) ");
            scanf("%d",&again);
            if(again==1){
                if(deleteBook(b[delete-1])){
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
  printf("�����!\n");
  return 0;
}
