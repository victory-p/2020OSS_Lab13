#include <stdio.h>
#include <string.h>
#include "phonenum.h"

int createPhonenum(PhoneNum *p){
	printf("- 이름 : ");
	scanf("%s", p->name);
	printf("- 전화번호 : ");
	scanf("%s", p->phonenum);
	printf("- 관계 : ");
	scanf("%s", p->relative);
	printf("- 생일(MMDD) : ");
	scanf("%s", p->birth);
	printf("- 주소 : ");
	getchar();
	scanf("%[^\n]s", p->address);
	printf(">>추가 완료<<\n");

	return 1;
}
//void readPhonenum(PhoneNum p){};
//int updatePhoneNum(PhoneNum *p){};
//int deletePhoneNum(PhoneNum *p){};

//int selectMenu(){};
//void listPhoneNum(PhoneNum *p,int count){};
//int selectDataNo(PhoneNum *p, int count){};

//void saveData(PhoneNum p[], int count){};
//int loadData(PhoneNum p[]){};

//void searchName(PhoneNum *p, int count){}; //이름 검색 함수
//void searchPhonenum(PhoneNum *p, int count){};//전화 번호  검색 함수
//void searchRelative(PhoneNum *p, int count){};//관계  검색 함수
//void searchBirth(PhoneNum *p, int count){};//생일 검색 함수
//void searchAddress(PhoneNum *p, int count){};//주소  검색 함수
	
