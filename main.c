#include <stdio.h>
#include "phonenum.h"

int main(){
	PhoneNum slist[1024];
	int curcount=0;
	int count=0;
	int menu;

	count = loadData(slist);
	curcount=count;		
	while(1){
		menu=selectMenu();
		if(menu < 1 || menu > 9)break;
		if(menu == 1){
			listPhoneNum(slist,curcount);
		}
		if(menu == 2){
			count+=createPhonenum(&slist[curcount++]);
		}
		if(menu == 3){
			int no=selectDataNo(slist,curcount);
			if(no ==0){
				printf("=>취소됨!\n");
				continue;
			}
			updatePhoneNum(&slist[no-1]);
		}
		if(menu == 4){
			int no=selectDataNo(slist,curcount);
			if(no==0){
				printf("=>취소됨!\n");
				continue;
			}
			int deleteok;
			printf("정말로 삭제하시겠습니까?(삭제:1)");
			scanf("%d",&deleteok);
			if(deleteok==1){
				if(deletePhoneNum(&slist[no-1])) count--;
			}
		}
		if(menu == 5){
			saveData(slist, curcount);
		}
		if(menu == 6){
			int num =0;
			printf("어떤 것을 검색하고 싶으십니까? : ");
			scanf("%d",&num);
			if(num==0){
				printf("=>취소됨!\n");
				continue;
			}
			switch(num){
				case 1 :
					searchBirth(slist,curcount);
					break;
			}	
		}
		if(menu == 0){
			break;
		}
	}
return 0;	
}
