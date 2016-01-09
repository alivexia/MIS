#include"function.h"
#include<stdio.h>
#include<stdlib.h>
void show_welcome()
{
	printf("������������������������������������������������������������������������������������������������������\n");
	printf("|                                                                                                    |\n");
	printf("|****************************************��ӭʹ��ͼ�����ϵͳ****************************************|\n");
	printf("|                                                                                                    |\n");
	printf("������������������������������������������������������������������������������������������������������\n\n");
}
void query_book()
{
	struct link *head, *pnew, *ptail;
	struct Book m;//����ļ�ָ������������ݵ�¼��
	struct Book x;//��ſͻ�����Ĳ�ѯ��Ϣ
	int flag, choice;//flag�����������������Ƿ񱻲�ѯ��
	FILE *fp;

	printf("С������Ŭ��������...\n");//����������ʾ��^-^
	if ((fp = fopen("d:\\book.txt", "r")) == NULL)
	{
		printf("���ݿ��ʧ��!��鿴D:book.txt�ļ��Ƿ����!\n");
		return;
	}
	pnew = (struct link *)malloc(sizeof(struct link));
	head = ptail = pnew;
	while ((fscanf(fp, "%d%s%s%s%d%f%s%d%d%d%d", &m.book_id, m.isbn_id, m.name, m.author, &m.category, &m.price, m.press, &m.press_data.year, &m.press_data.month, &m.press_data.day, &m.exist)) != EOF)
	{
		pnew->b = m;
		ptail = pnew;
		ptail->next = (struct link *)malloc(sizeof(struct link));
		pnew = ptail->next;

	}
	free(pnew);
	ptail->next = NULL;
	fclose(fp);
	system("cls");//���ϴ������ļ��򿪺͹ر�֮���������¼�뵽������
	printf("****************************************��ӭʹ��ͼ���ѯ����****************************************\n\n");
	printf("\t\t\t1��������ID��ѯ\n\t");
	printf("\t\t2������ISBN��ѯ\n\t");
	printf("\t\t3������������ѯ\n\t");
	printf("\t\t4���������߲�ѯ\n\t");
	printf("\t\t5�����������ѯ\n\t");
	printf("\t\t6�������������ѯ\n\t");
	printf("\t\t7�����������˵�\n\t");
	printf("\t\t0�����˳�����\n\t");
	printf("Ϊ�����ݰ�ȫ��������ȷ�ķ�ʽ�˳�����!\n");
	while (1)
	{
		flag = 0;//ÿ�β�ѯ����ʼ��
		printf("���������:");
		scanf(" %d", &choice);
		switch (choice)
		{
		case 1:printf("������Ҫ��ѯ����ID:");
			scanf(" %d", &x.book_id);
			for (pnew = head; pnew != NULL; pnew = pnew->next)//��������
			{
				if (pnew->b.book_id == x.book_id)
				{
					flag = 1;
					printf("��ID:%d\n��ISBN:%s\n����:%s\n����:%s\n�����:%d\n�۸�:%.2f\n������:%s\n��������:%d-%d-%d\n����״̬��:%d\n\n"
						, pnew->b.book_id, pnew->b.isbn_id, pnew->b.name, pnew->b.author, pnew->b.category, pnew->b.price, pnew->b.press
						, pnew->b.press_data.year, pnew->b.press_data.month, pnew->b.press_data.day, pnew->b.exist);
				}
			}
			if (flag == 0)
				printf("���������ID������!\n\n");
			break;
		case 2:printf("������Ҫ��ѯ��ISBN��:");
			scanf(" %s", x.isbn_id);
			for (pnew = head; pnew != NULL; pnew = pnew->next)//��������
			{
				if (strcmp(pnew->b.isbn_id, x.isbn_id) == 0)
				{
					flag = 1;
					printf("��ID:%d\n��ISBN:%s\n����:%s\n����:%s\n�����:%d\n�۸�:%.2f\n������:%s\n��������:%d-%d-%d\n����״̬��:%d\n\n"
						, pnew->b.book_id, pnew->b.isbn_id, pnew->b.name, pnew->b.author, pnew->b.category, pnew->b.price, pnew->b.press
						, pnew->b.press_data.year, pnew->b.press_data.month, pnew->b.press_data.day, pnew->b.exist);
				}
			}
			if (flag == 0)
				printf("�������ISBN������!\n\n");
			break;
		case 3:printf("������Ҫ��ѯ������:");
			scanf(" %s", x.name);
			for (pnew = head; pnew != NULL; pnew = pnew->next)
			{
				if (strcmp(pnew->b.name, x.name) == 0)
				{
					flag = 1;
					printf("��ID:%d\n��ISBN:%s\n����:%s\n����:%s\n�����:%d\n�۸�:%.2f\n������:%s\n��������:%d-%d-%d\n����״̬��:%d\n\n"
						, pnew->b.book_id, pnew->b.isbn_id, pnew->b.name, pnew->b.author, pnew->b.category, pnew->b.price, pnew->b.press
						, pnew->b.press_data.year, pnew->b.press_data.month, pnew->b.press_data.day, pnew->b.exist);
				}
			}
			if (flag == 0)
				printf("�����������������!\n\n");
			break;
		case 4:printf("������Ҫ��ѯ������:");
			scanf(" %s", x.author);
			for (pnew = head; pnew != NULL; pnew = pnew->next)
			{
				if (strcmp(pnew->b.author, x.author) == 0)
				{
					flag = 1;
					printf("��ID:%d\n��ISBN:%s\n����:%s\n����:%s\n�����:%d\n�۸�:%.2f\n������:%s\n��������:%d-%d-%d\n����״̬��:%d\n\n"
						, pnew->b.book_id, pnew->b.isbn_id, pnew->b.name, pnew->b.author, pnew->b.category, pnew->b.price, pnew->b.press
						, pnew->b.press_data.year, pnew->b.press_data.month, pnew->b.press_data.day, pnew->b.exist);
				}
			}
			if (flag == 0)
				printf("����������߲�����!\n\n");
			break;
		case 5:printf("������Ҫ��ѯ�ķ����:");
			scanf(" %d", &x.category);
			for (pnew = head; pnew != NULL; pnew = pnew->next)
			{
				if (pnew->b.category == x.category)
				{
					flag = 1;
					printf("��ID:%d\n��ISBN:%s\n����:%s\n����:%s\n�����:%d\n�۸�:%.2f\n������:%s\n��������:%d-%d-%d\n����״̬��:%d\n\n"
						, pnew->b.book_id, pnew->b.isbn_id, pnew->b.name, pnew->b.author, pnew->b.category, pnew->b.price, pnew->b.press
						, pnew->b.press_data.year, pnew->b.press_data.month, pnew->b.press_data.day, pnew->b.exist);
				}
			}
			if (flag == 0)
				printf("������ķ���Ų�����!\n\n");
			break;
		case 6:printf("������Ҫ��ѯ�ĳ�����:");
			scanf(" %s", x.press);
			for (pnew = head; pnew != NULL; pnew = pnew->next)
			{
				if (strcmp(pnew->b.press, x.press) == 0)
				{
					flag = 1;
					printf("��ID:%d\n��ISBN:%s\n����:%s\n����:%s\n�����:%d\n�۸�:%.2f\n������:%s\n��������:%d-%d-%d\n����״̬��:%d\n\n"
						, pnew->b.book_id, pnew->b.isbn_id, pnew->b.name, pnew->b.author, pnew->b.category, pnew->b.price, pnew->b.press
						, pnew->b.press_data.year, pnew->b.press_data.month, pnew->b.press_data.day, pnew->b.exist);
				}
			}
			if (flag == 0)
				printf("������ĳ����粻����!\n\n");
			break;
		case 7:for (pnew = head; pnew != NULL;)//���������ͬʱ�ͷ��ڴ�
		{
			ptail = pnew->next;
			free(pnew);
			pnew = ptail;
		}
			   return;
		case 0:for (pnew = head; pnew != NULL;)
		{
			ptail = pnew->next;
			free(pnew);
			pnew = ptail;
		}
			   exit(0);
		default:printf("�������!��������ȷ����!\n\n");
		}
	}
}

void add_book()//¼��ͼ����Ϣ	�Ĺ���	   1���˳�¼��  2������¼��
{
	FILE *fp1;
	struct Book m, n;
	int flag = 0,flag1=0;
	int i,j,times;
	
	system("cls");
	show_welcome();
	printf("****************************************��ӭʹ��ͼ�����ϵͳ¼�빦��****************************************\n\n");
	printf("��������������>�����뽫Ҫ¼���鼮����Ŀ��");
	scanf("%d", &times);
	system("cls");

	for (j = 0; j < times; j++)
	{
		show_welcome();
		printf("****************************************��ӭʹ��ͼ�����ϵͳ¼�빦��****************************************\n\n");
		printf("��������������>�Ѿ��ɹ�����%d���顣ʣ��%d��\n", j,times-j);
		if ((fp1 = fopen("d:\\book.txt", "a+")) == NULL)
		{
			printf("��������������>�ļ���ʧ�ܣ�����ϵ����Ա��");
			exit(0);
		}
		printf("��������������>��������Ҫ������ISBN�ţ�13λ�����֣���");
		scanf(" %s", m.isbn_id);
		for (i = 0; m.isbn_id[i] != '\0'; i++)
			if (m.isbn_id[i] >= '0' || m.isbn_id[i] <= '9')
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		if (flag == 1 && i == 13)
			printf("��������������>����ɹ�����ȷ���������ISBN��Ϊ%s��\n", m.isbn_id);
		else
		{
			printf("��������������>���������ȷ���������ISBN��Ϊ13λ������(�밴Enter�������˵�����\n");
			system("pause");
			system("cls");
			return;
		}
		flag = 0;
		while (fscanf(fp1, "%d", &n.book_id)!=EOF)
		{
			fscanf(fp1, "  %s", n.isbn_id);
		   	for (i = 0; i < 13; i++)
				if (m.isbn_id[i] == n.isbn_id[i])
					flag = 1;
				else
				{
					flag = 0;
					break;
				}
			m.book_id = n.book_id + 1;
			if (flag == 1 && i == 13)
			{
				fscanf(fp1, " %s %s %d %f %s %d-%d-%d %d", m.name, m.author, &m.category, &m.price, m.press, &m.press_data.year, &m.press_data.month, &m.press_data.day, &m.exist);
				flag1 = 1;
				continue;
			}
			fscanf(fp1, " %s %s %d %f %s %d-%d-%d %d",n.name, n.author, &n.category, &n.price, n.press, &n.press_data.year, &n.press_data.month, &n.press_data.day, &n.exist);	
		}
		if (flag1==1)
		{
			printf("��������������>¼��һ��ISBN����ͬ��ͼ�飬�������������鱾��Ϣ��ϵͳ�Զ������鱾ID��\n");
			fprintf(fp1, "%d\n%s\n%s\n%s\n%d\n%f\n%s\n%d-%d-%d\n%d\n",m.book_id, m.isbn_id, m.name, m.author, m.category, m.price, m.press, m.press_data.year, m.press_data.month, m.press_data.day, m.exist);
		}
		if (flag1 != 1)
		{
			printf("��������������>������������");
			scanf("%s", m.name);
			printf("��������������>�����������������");
			scanf("%s", m.author);
			printf("��������������>������ķ��ࣺ");
			scanf("%d", &m.category);
			printf("��������������>��������ļ۸�");
			scanf("%f", &m.price);
			printf("��������������>��������Ҫ�����ĳ��������֣�");
			scanf("%s", m.press);
			printf("��������������>��������ĳ������ڣ���xxxx-xx-xx��ʽ���룩��");
			scanf("%d-%d-%d", &m.press_data.year, &m.press_data.month, &m.press_data.day);
			m.exist = 0;
			fprintf(fp1, "%d\n%s\n%s\n%s\n%d\n%f\n%s\n%d-%d-%d\n%d\n",m.book_id, m.isbn_id, m.name, m.author, m.category, m.price, m.press, m.press_data.year, m.press_data.month, m.press_data.day, m.exist);
		}
		fclose(fp1);
		i = 0;
		printf("��������������>��ɹ�¼����һ��ͼ�顣\n");
		printf("      �鱾ID          ISBN           ����      ����      ����          �۸�           ������       ��������\n");
		printf("|%013d| |%s|       |%s|       |%s|       |%d|        |$%f|         |%s|       |%d-%d-%d|\n\n",m.book_id, m.isbn_id, m.name, m.author, m.category, m.price, m.press, m.press_data.year, m.press_data.month, m.press_data.day);
		system("pause");
		system("cls");
	}
}

void modify_book()
{
	FILE *fp1, *fp2;
	struct Book m;//�ļ����ݸ��Ƶ��м����
	char n[14];
	int choice;
	int flag;//���Ƶ�����Ŀ��Ϣ�����룬��ֹ���޸���Ŀ��Ϣ���ظ�����
	int f1 = 0, f2;

	while (1)
	{
		f1 = 0;//���������ISBN�����������
		system("cls");
		printf("************************��ӭʹ��ͼ���޸Ĺ���****************************\n\n");
		if ((fp1 = fopen("d:\\book.txt", "r")) == NULL)
		{
			printf("���ݿ��ʧ��!��鿴D:book.txt�ļ��Ƿ����!\n");
			return;
		}
		if ((fp2 = fopen("d:\\Bufbook.txt", "w")) == NULL)
		{
			printf("�����ļ�ʧ��!�����ڴ��Ƿ�����!\n");
			return;
		}
		printf("������Ҫ�޸����ISBN:");
		scanf(" %s", n);
		while ((fscanf(fp1, "%d%s%s%s%d%f%s%d%d%d%d", &m.book_id, m.isbn_id, m.name, m.author, &m.category, &m.price, m.press, &m.press_data.year, &m.press_data.month, &m.press_data.day, &m.exist)) != EOF)
		{
			flag = 0;//����Ŀǰ�������Ŀ����Ҫ�޸ĵ���Ŀ
			if (strcmp(n, m.isbn_id) == 0)
			{
				f1 = 1;//��������ISBN���������
				flag = 1;//��ǵ�ǰ��ĿΪ��Ҫ�޸ĵ���Ŀ
				printf("\t\t\t1�����޸�����\n\t");
				printf("\t\t2�����޸�����\n\t");
				printf("\t\t3�����޸ķ���\n\t");
				printf("\t\t4�����޸ļ۸�\n\t");
				printf("\t\t5�����޸ĳ�����\n\t");
				printf("\t\t6�����޸ĳ���ʱ��\n\t");
				printf("\t\t0�����޸����\n");
				printf("Ϊ�����ݰ�ȫ��������ȷ�ķ�ʽ�˳�����!\n");
				while (1)
				{

					printf("���������:");
					scanf(" %d", &choice);
					if (choice == 0)//���뵱ǰ���޸���Ŀ��Ϣ��ָ���ļ�
					{
						fprintf(fp2, "%d\n%s\n%s\n%s\n%d\n%.2f\n%s\n%d %d %d\n%d\n", m.book_id, m.isbn_id, m.name, m.author, m.category, m.price, m.press, m.press_data.year, m.press_data.month, m.press_data.day, m.exist);
						printf("�޸���ɣ����ڱ���...\n");
						break;
					}
					switch (choice)
					{
					case 1:printf("������Ҫ�޸ĵ�����:"); scanf(" %s", m.name); printf("�����޸ĳɹ�\n\n"); break;
					case 2:printf("������Ҫ�޸ĵ�����:"); scanf(" %s", m.author); printf("�������޸ĳɹ�\n\n"); break;
					case 3:printf("������Ҫ�޸ĵ����:"); scanf(" %d", &m.category); printf("����޸ĳɹ�\n\n"); break;
					case 4:printf("������Ҫ�޸ĵļ۸�:"); scanf(" %f", &m.price); printf("�۸��޸ĳɹ�\n\n"); break;
					case 5:printf("������Ҫ�޸ĵĳ�����:"); scanf(" %s", m.press); printf("�������޸ĳɹ�\n\n"); break;
					case 6:printf("������Ҫ�޸ĵĳ�������:"); scanf(" %d%d%d", &m.press_data.year, &m.press_data.month, &m.press_data.day);
						printf("���������޸ĳɹ�\n\n");
						break;
					default:printf("�������,��Ӵ�����!\n\n");
					}
				}
			}
			if (flag == 0)//��ǰ��Ŀ���Ǳ��޸���Ŀ��ֱ���������һ���ļ�
				fprintf(fp2, "%d\n%s\n%s\n%s\n%d\n%.2f\n%s\n%d %d %d\n%d\n", m.book_id, m.isbn_id, m.name, m.author, m.category, m.price, m.press, m.press_data.year, m.press_data.month, m.press_data.day, m.exist);
		}
		if (f1 == 0)//�����ISBN����������е���ʾ���
			printf("�������ISBN�����ڸ�ϵͳ!\n\n");
		fclose(fp1);
		fclose(fp2);
		remove("d:\\book.txt");
		rename("d:\\Bufbook.txt", "d:\\book.txt");
		printf("�Ƿ�����޸ģ�\n�ǡ�����1\n�񡪡��������\n");
		scanf(" %d", &f2);
		if (f2 != 1)//�ж��Ƿ��ٴν���ͼ���޸Ĺ���
		{
			printf("��û��ѡ������޸ģ����ڷ������˵�...\n");
			system("pause");
			return;
		}
	}
}




void delete_book()//ɾ��ͼ�� ����
{

}