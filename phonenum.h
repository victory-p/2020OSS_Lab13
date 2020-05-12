#include <stdio.h>

typedef struct{
	char name[10];
	char phonenum[12];
	char relation[10];
	char birth[5];
	char address [100];
} PhoneNum;

int createPhonenum(PhoneNum *p);
void readPhonenum(PhoneNum p);
int updatePhoneNum(PhoneNum *p);
int deletePhoneNum(PhoneNum *p);
int selectMenu();
int selectSearch();
void listPhoneNum(PhoneNum *p,int count);
int selectDataNo(PhoneNum *p, int count);
void saveData(PhoneNum p[], int count);
int loadData(PhoneNum p[]);
void searchName(PhoneNum *p, int count); //이름 검색 함수
void searchPhonenum(PhoneNum *p, int count);//전화 번호  검색 함수
void searchRelation(PhoneNum *p, int count);//관계  검색 함수
void searchBirth(PhoneNum *p, int count);//생일 검색 함수
void searchAddress(PhoneNum *p, int count);//주소  검색 함수
void search(PhoneNum *p, int count, int num);	
