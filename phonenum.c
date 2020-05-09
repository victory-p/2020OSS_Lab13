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
	printf("=> 추가 완료\n");

	return 1;
}

void readPhonenum(PhoneNum p){
	if(p.phonenum[0] == '-') return;
	printf(" %s / %s / %s / %d%d월 %d%d일 / %s\n", p.name, p.phonenum, p.relation, p.birth[0]-'0',p.birth[1]-'0',p.birth[2]-'0',p.birth[3]-'0',p.address);
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
        printf("=> 수정 완료\n");

        return 1;
}

int deletePhoneNum(PhoneNum *p){
	p->phonenum[0] = '-';
	printf("=> 삭제 완료\n");

	return 1;
}

int selectMenu(){
	int menu;
	printf("\n============Phone Book=============\n");
	printf("1. 연락처 조회\n");
	printf("2. 연락처 추가\n");
	printf("3. 연락처 수정\n");
	printf("4. 연락처 삭제\n");
	printf("5. 데이터 저장\n");
	printf("6. 연락처 검색\n");
	printf("0. 종료\n\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d",&menu);
	return menu;
}
void listPhoneNum(PhoneNum *p,int count){
	printf("No / Name / Phonenum / Relation / Birth / Address\n");
	printf("============================================\n");
	for(int i=0; i<count; i++){
		if(p[i].phonenum[0] != '-'){
		printf("%2d", i +1);
		readPhonenum(p[i]);
		}
	}
}

int selectDataNo(PhoneNum *p, int count){
	int num;
	listPhoneNum(p, count);
	printf("=> 선택할 데이터 번호는?(취소 : 0) ");
	scanf("%d", &num);

	return num;
}

void saveData(PhoneNum p[], int count){
	FILE *fp;
	fp=fopen("Phonebook.txt","wt");
	for(int i=0;i<count; i++){
		if(p[i].phonenum[0] != '-') fprintf(fp,"%s %s %s %s %s\n", p[i].name, p[i].phonenum, p[i].relation, p[i].birth, p[i].address);
	}	
	fclose(fp);
	printf("=> 저장 완료\n");
}
int loadData(PhoneNum p[]){
	int count=0;
	FILE *fp;
	fp=fopen("Phonebook.txt","rt");
	if(fp == NULL){
		printf("=> 파일 없음\n");
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

void searchName(PhoneNum *p, int count){//이름 검색 함수
	int scount = 0;
	char search[10];
	printf("=> 검색할 이름 입력 : ");
	scanf("%s", search);
	printf("No / Name / Phonenum / Relation / Birth / Address\n");
	printf("============================================\n");
	for(int i=0; i<count; i++){
		if(p[i].phonenum[0] != '-'){
			if(strstr(p[i].name, search)){
				printf("%d", i+1);
				readPhonenum(p[i]);
				scount++;
			}
		}
	}
	if(scount==0) printf("=> 검색된 데이터 없음! \n");
}
//void searchPhonenum(PhoneNum *p, int count){};//전화 번호  검색 함수
//void searchrelation(PhoneNum *p, int count){};//관계  검색 함수
void searchBirth(PhoneNum *p, int count){//생일 검색 함수
	int scount =0;
	char search[20];
	printf("=> 검색할 생일 입력 : ");
	scanf("%s",search);
	printf("No / Name / Phonenum / Relation / Birth / Address\n");
	printf("============================================\n");
	for(int i=0; i<count; i++){
		if(p[i].phonenum[0] != '-'){
			if(strstr(p[i].birth,search)){
				printf("%d",i+1);
				readPhonenum(p[i]);
				scount++;
			}
		}
	}
	if(scount==0) printf("=> 검색된 데이터 없음! \n");
}

void searchAddress(PhoneNum *p, int count){//주소  검색 함수
	int scount =0;
	char search[100];
	printf("=> 검색할 주소 입력 : ");
	scanf("%s",search);
	printf("No / Name / Phonenum / Relation / Birth / Address\n");
	printf("============================================\n");
	for(int i=0; i<count; i++){
		if(p[i].phonenum[0] != '-'){
			if(strstr(p[i].address,search)){
				printf("%d",i+1);
				readPhonenum(p[i]);
				scount++;
			}
		}
	}
	if(scount==0) printf("=> 검색된 데이터 없음! \n");
}

void search(PhoneNum *p, int count,int num){
	switch(num){
		case 1: printf("1번\n"); break;
		case 2: printf("2번\n");break;
		case 3: printf("3번\n");break;
		case 4: searchBirth(p, count);break;
		case 5: searchAddress(p, count);break;
		default : break;
	}
}	
int selectSearch(){
	int menu;
	printf("\n========검색 항목=========\n");
	printf("1. 이름\n");
	printf("2. 전화번호\n");
	printf("3. 그룹\n");
	printf("4. 생일\n");
	printf("5. 주소\n");
	printf("=> 검색할 항목은? ");
	scanf("%d",&menu);
	return menu;
}
