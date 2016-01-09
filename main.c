#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"

int main()
{
	int i;

	
	while (1) {
		show_welcome();
		printf("———————>1、录入图书信息\n");
		printf("———————>2、查询图书信息\n");
		printf("———————>3、修改图书信息\n");
		printf("———————>4、删除图书信息\n");
		printf("———————>5、退出\n\n");
		printf("———————>请输入序号进行选择下一步操作：");
		scanf("%d", &i);
		printf("\n");
		switch(i){
			case 1: {
				add_book();
				break;
			}
			case 2: {
				query_book();
				break;
			}
			case 3: {
				modify_book();
				break;
			}
			case 4: {
				//delete_book();
				break;
			}
			case 5: {
				printf("\n");
				show_welcome();
				exit(0);
			}
			default: {
				printf("———————>输入错误请重试!!!\n\n");
				break;
			}
		}	
		show_welcome();
		printf("———————>输入1重新查询\n");
		printf("———————>输入非\"1\"退出\n");
		printf("———————>请输入：");
		scanf("%d", &i);
		switch (i) {
		case 1: {
			system("cls");
			continue;
		}

		default: {
			printf("\n");
			show_welcome();
			exit(0);
		}
		}
	}
	return 0;
}