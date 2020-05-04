#include <stdio.h>
#include <string.h>
#include "phonenum.h"

int createPhonenum(PhoneNum *p){
	printf("- 이름 : ");
	scanf("%s", p->name);
	printf("- 전화번호 : ");
	scanf("%s", p->phonenum);
	printf("- 관계 : ");
	scanf("%s", p->relation);
	printf("- 생일(MMDD) : ");
	scanf("%s",p->birth);
	printf("- 주소 : ");
	getchar();
	scanf("%[^\n]s", p->address);
	printf(">>추가 완료<<\n");

	return 1;
}

void readPhonenum(PhoneNum p){
	if(p.phonenum[0] == '-') return;

	printf("%s %s %s %s %s\n", p.name, p.phonenum, p.relation, p.birth, p.address);
}

int updatePhoneNum(PhoneNum *p){
        printf("- 이름 : ");
        scanf("%s", p->name);
        printf("- 전화번호 : ");
        scanf("%s", p->phonenum);
        printf("- 관계 : ");
        scanf("%s", p->relation);
        printf("- 생일(MMDD) : ");
        scanf("%s",p->birth);
        printf("- 주소 : ");
        getchar();
        scanf("%[^\n]s", p->address);
        printf(">>수정 완료<<\n");

        return 1;
}

int deletePhoneNum(PhoneNum *p){
	p->phonenum[0] = '-';
	printf(">>삭제 완료<<\n");

	return 1;
}

int selectMenu(){
	int menu;
	printf("\n============Phone Book=============\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 데이터 저장\n");
	printf("6. 검색\n");
	printf("0. 종료\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d",&menu);
	return menu;
}
void listPhoneNum(PhoneNum *p,int count){
	printf("Name / Phonenum / Relation / Birth / Address\n");
	printf("============================================\n");
	for(int i=0; i<count; i++){
		if(p[i].phonenum == "-") continue;
		printf("%2d", i +1);
		readPhonenum(p[i]);
	}
}
//int selectDataNo(PhoneNum *p, int count){};

void saveData(PhoneNum p[], int count){
	FILE *fp;
	fp=fopen("Phonebook.txt","wt");
	for(int i=0;i<count; i++){
		if(p[i].phonenum != "-") fprintf(fp,"%s %s %s %s %s\n", p[i].name, p[i].phonenum, p[i].relation, p[i].birth, p[i].address);
	}	
	fclose(fp);
	printf("저장됨! \n");
}
int loadData(PhoneNum p[]){
	int count=0;
	FILE *fp;
	fp=fopen("Phonebook.txt","rt");
	if(fp == NULL){
		printf("파일 없음\n");
		return 0;
	}
	for( ; ; count++){
		fscanf(fp,"%s %s %s %s %[^\n]s\n", p[count].name, p[count].phonenum, p[count].relation, p[count].birth, p[count].address);
	if(feof(fp)) break;
	}
	fclose(fp);
	printf("=> 로딩 성공 \n");
	return count;
}

//void searchName(PhoneNum *p, int count){}; //이름 검색 함수
//void searchPhonenum(PhoneNum *p, int count){};//전화 번호  검색 함수
//void searchrelation(PhoneNum *p, int count){};//관계  검색 함수
//void searchBirth(PhoneNum *p, int count){};//생일 검색 함수
//void searchAddress(PhoneNum *p, int count){};//주소  검색 함수
	
