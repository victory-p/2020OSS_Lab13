#include <stdio.h>
#include "phonenum.h"

int main(){
	PhoneNum slist[1024];
	int curcount=0;
	int count=0;
	int menu;

	curcount = loadData(slist);
	count=curcount;		
	while(1){
		menu=selectMenu();
		if(menu < 1 || menu > 9)break;
		if(menu == 1){
			readPhonenum(slist[0]);
			readPhonenum(slist[1]);
			readPhonenum(slist[2]);
		}
		if(menu == 2){
			count+=createPhonenum(&slist[curcount++]);
		}
		if(menu == 5){
			saveData(slist, count);
		}
		if(menu == 0){
			break;
		}
	}
return 0;	
}
