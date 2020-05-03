#include <stdio.h>
#include "phonenum.h"

int main(){
	PhoneNum slist[1024];
	int curcount=0;
	int count=0;
	int menu;

		
	while(1){
		printf("입력하세요: ");
		scanf("%d",&menu);
		if(menu == 0)break;
		if(menu == 1){
			readPhonenum(slist[0]);
			printf("1번\n");
		}
		if(menu == 2){
			count+=createPhonenum(&slist[curcount++]);
		}
	}
return 0;	
}
