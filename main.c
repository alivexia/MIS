#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"

int main()
{
	int i;

	
	while (1) {
		show_welcome();
		printf("��������������>1��¼��ͼ����Ϣ\n");
		printf("��������������>2����ѯͼ����Ϣ\n");
		printf("��������������>3���޸�ͼ����Ϣ\n");
		printf("��������������>4��ɾ��ͼ����Ϣ\n");
		printf("��������������>5���˳�\n\n");
		printf("��������������>��������Ž���ѡ����һ��������");
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
				printf("��������������>�������������!!!\n\n");
				break;
			}
		}	
		show_welcome();
		printf("��������������>����1���²�ѯ\n");
		printf("��������������>�����\"1\"�˳�\n");
		printf("��������������>�����룺");
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