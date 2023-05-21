#define SIZE 30
#define BOOKCOUNT 100
#include "manager.h"


int main(void){
  Book *b[SIZE];
  Library *l[BOOKCOUNT];
  int booknum=0;
  int index=0, count=0, menu;
  count = loadBook(b);        //????ó¨Î¶¨Ïä§?ä∏?ùò ?ç∞?ù¥?Ñ∞ Í∞úÏàò
  booknum = loadBookList(l);  //Î∞òÎÇ©Î¶¨Ïä§?ä∏?ùò ?ç∞?ù¥?Ñ∞ Í∞úÏàò
  index = count;
  if(count!=0){
        printf("=> Î°úÎî© ?Ñ±Í≥?!\n");
       }else{
         printf("=> ?åå?ùº ?óÜ?ùå\n");
    }
  while(1){
    menu = selectMenu();
    if(menu == 0) break;
    if(menu == 1){
      if(count<=0){
        printf("?ç∞?ù¥?Ñ∞Í∞? ?óÜ?äµ?ãà?ã§.\n");
      }else{
        listBook(b, index);
      }
      }
    else if(menu == 2){
      b[index] = (Book *)malloc(sizeof(Book));
      count += createBook(b[index], l);
      for(int i = 0; i < booknum; i++){
          if(strcmp(b[index]->bookName, l[i]->name) == 0){
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
      index++;
    }
    else if(menu == 3){
      int modif=0;
      if(count<=0){
                printf("?ç∞?ù¥?Ñ∞Í∞? ?óÜ?äµ?ãà?ã§.\n");
            }else{
            modif = selectNum(b, index);
        if(modif==0){
          printf("Ï∑®ÏÜå ?ê®!\n");
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
                printf("?ç∞?ù¥?Ñ∞Í∞? ?óÜ?äµ?ãà?ã§.\n");
            }else{
            delete = selectNum(b, index);
            if(delete<=0){
                printf("Ï∑®ÏÜå?ê®!\n");
                continue;
            }
            printf("?†ïÎßêÎ°ú Î∞òÎÇ©?ïò?ãúÍ≤†Ïäµ?ãàÍπ??(?Ç≠?†ú :1) ");
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
  printf("Ï¢ÖÎ£å?ê®!\n");
  return 0;
}
