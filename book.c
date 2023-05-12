#include "book.h"

void readBook(Book b){
    printf("%8s %13d %14s %10hd %hd %hd\n", b.name, b.studnetID, b.bookName, b.endYear, b.endMonth, b.endDay);    
}    
int createBook(Book *b){
    printf("�� : ");
    scanf("%s",b->name);
    printf("�� : ");
    scanf("%d",&b->studnetID);
    printf("� �� : ");
    getchar();
    scanf("%[^\n]s",b->bookName);
    printf("�� � ex)2001 01 01 : ");
    scanf ("%hd %hd %hd",&b->endYear, &b->endMonth, &b->endDay);
    return 1;
}
int updateBook(Book *b){
    printf("�� : ");
    scanf("%s",b->name);
    printf("�� : ");
    scanf("%d",&b->studnetID);
    printf("� �� : ");
    getchar();
    scanf("%[^\n]s",b->bookName);
    printf("�� � : ");
    scanf ("%hd %hd %hd",&b->endYear, &b->endMonth, &b->endDay);
    printf("�� ��!\n");
    return 1;
}
int deleteBook(Book *b){
    b->returningstate = 1;
    printf("�� ��!\n");
    return 1;
}
void saveBook(Book *b[], int count){
    FILE *fp;
    FILE *s;
    fp = fopen("book.txt","wt");
    s = fopen("booklist.txt","wt");
    for(int i=0; i<count; i++){
        if(b[i]->returningstate == 1){
          fprintf(s,"%d %s",b[i]->returningstate,b[i]->bookName);
          continue;
        }
        fprintf(fp,"%s %d %hd %hd %hd %s\n",b[i]->name,b[i]->studnetID,b[i]->endYear,b[i]->endMonth,b[i]->endDay,b[i]->bookName);
        fprintf(s,"%d %s",b[i]->returningstate,b[i]->bookName);
    }
    fclose(fp);
    fclose(s);
    printf("=> ���! \n");
}
int loadBook(Book *b[], Library l[]){
    int i=0;
    FILE *fp;
    FILE *s;
    s = fopen("booklist.txt","rt");
    for(int j=0; j<30; j++){
	if(feof(s)) break;
	fscanf(s,"%d %[^\n]s",&l[j].returningstate,l[j].name);
    }
    fp = fopen("book.txt","rt");
    if(fp==NULL) return 0;
    for(; i<30; i++){
	b[i] = (Book *)malloc(sizeof(Book));
        if(feof(fp)) break;
        fscanf(fp, "%s %d %hd %hd %hd",b[i]->name,&b[i]->studnetID,&b[i]->endYear,&b[i]->endMonth,&b[i]->endDay);
	fscanf(fp,"%[^\n]s",b[i]->bookName);
    }
    fclose(fp);
    return i-1;
}

