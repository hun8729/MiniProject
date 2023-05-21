#define SIZE 30
#include "manager.h"


int main(void){
  Book *b[SIZE];
  Library *l[100];
  int booknum=0;
  int index=0, count=0, menu;
  count = loadBook(b);        //�뿩����Ʈ�� ������ ����
  booknum = loadBookList(l);  //�ݳ�����Ʈ�� ������ ����
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
        if(modif==0){
          printf("��� ��!\n");
          continue;
        }
        updateBook(b[modif-1]);
        for(int i = 0; i < booknum; i++){
          if(strcmp(b[modif-1]->bookName, l[i]->name) == 0){
            if(l[i]->name){
              for(int j = i; j < booknum; j++){
                if(l[j+1]){
                strcpy(l[j]->name, l[j+1]->name);
                }
              }
              booknum--;
              break;
            }
          }
        }
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
               l[booknum] = (Library *)malloc(sizeof(Library));
                if(deleteBook(b[delete-1],l[booknum])){
                    count--;
                    booknum++;
                }
            }         
        }
        }
    else if(menu == 5){
      saveBook(b,l ,index,booknum);
    }else if(menu == 6){
      searchBook(b, index);
    }else if(menu == 7){
      searchName(b, index);
    }

    else if(menu == 8){
      showOverdue(b, index);
    }
    else if(menu == 9){
      recommendBook(l, booknum);
    }
  }
  printf("�����!\n");
  return 0;
}