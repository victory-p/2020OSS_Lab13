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
		if(menu < 0 || menu > 6) printf("\n 항목이 없습니다\n 다시 입력하세요\n"); 
		if(menu == 1){
			#ifdef DEBUG
			printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
			#endif
			listPhoneNum(slist,curcount);
		}
		if(menu == 2){
			#ifdef DEBUG
			printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
			#endif
			count+=createPhonenum(&slist[curcount++]);
		}
		if(menu == 3){
			#ifdef DEBUG
			printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
			#endif
			int no=selectDataNo(slist,curcount);
			if(no ==0){
				printf("=>취소됨!\n");
				continue;
			}
			#ifdef DEBUG
			printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
			#endif
			updatePhoneNum(&slist[no-1]);
		}
		if(menu == 4){
			#ifdef DEBUG
                        printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
                        #endif
			int no=selectDataNo(slist,curcount);
			if(no==0){
				printf("=>취소됨!\n");
				continue;
			}
			int deleteok;
			printf("정말로 삭제하시겠습니까?(삭제:1)");
			scanf("%d",&deleteok);
			if(deleteok==1){
				#ifdef DEBUG
                        	printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
                        	#endif
				if(deletePhoneNum(&slist[no-1])) count--;
			}
		}
		if(menu == 5){
			#ifdef DEBUG
                        printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
                        #endif
			saveData(slist, curcount);
		}
		if(menu == 6){
			#ifdef DEBUG
                        printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
                        #endif
			int num =selectSearch();
			if(num==0){
				printf("=>취소됨!\n");
				continue;
			}
			#ifdef DEBUG
                        printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
                        #endif
			search(slist,curcount,num);
		}
		if(menu == 0){
			printf("=>종료됨!\n");
			break;
		}
	}
return 0;	
}
