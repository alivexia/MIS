#include"function.h"
#include<stdio.h>
#include<stdlib.h>
void show_welcome()
{
	printf("———————————————————————————————————————————————————\n");
	printf("|                                                                                                    |\n");
	printf("|****************************************欢迎使用图书管理系统****************************************|\n");
	printf("|                                                                                                    |\n");
	printf("———————————————————————————————————————————————————\n\n");
}
void query_book()
{
	struct link *head, *pnew, *ptail;
	struct Book m;//配合文件指针完成链表数据的录入
	struct Book x;//存放客户输入的查询信息
	int flag, choice;//flag用来标记输入的内容是否被查询到
	FILE *fp;

	printf("小哥正在努力加载中...\n");//建立链表提示语^-^
	if ((fp = fopen("d:\\book.txt", "r")) == NULL)
	{
		printf("数据库打开失败!请查看D:book.txt文件是否存在!\n");
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
	system("cls");//以上代码在文件打开和关闭之间完成数据录入到链表中
	printf("****************************************欢迎使用图书查询功能****************************************\n\n");
	printf("\t\t\t1——按书ID查询\n\t");
	printf("\t\t2——按ISBN查询\n\t");
	printf("\t\t3——按书名查询\n\t");
	printf("\t\t4——按作者查询\n\t");
	printf("\t\t5——按分类查询\n\t");
	printf("\t\t6——按出版社查询\n\t");
	printf("\t\t7——返回主菜单\n\t");
	printf("\t\t0——退出程序\n\t");
	printf("为了数据安全，请以正确的方式退出程序!\n");
	while (1)
	{
		flag = 0;//每次查询都初始化
		printf("请输入代号:");
		scanf(" %d", &choice);
		switch (choice)
		{
		case 1:printf("请输入要查询的书ID:");
			scanf(" %d", &x.book_id);
			for (pnew = head; pnew != NULL; pnew = pnew->next)//遍历链表
			{
				if (pnew->b.book_id == x.book_id)
				{
					flag = 1;
					printf("书ID:%d\n书ISBN:%s\n书名:%s\n作者:%s\n分类号:%d\n价格:%.2f\n出版商:%s\n出版日期:%d-%d-%d\n存在状态号:%d\n\n"
						, pnew->b.book_id, pnew->b.isbn_id, pnew->b.name, pnew->b.author, pnew->b.category, pnew->b.price, pnew->b.press
						, pnew->b.press_data.year, pnew->b.press_data.month, pnew->b.press_data.day, pnew->b.exist);
				}
			}
			if (flag == 0)
				printf("你输入的书ID不存在!\n\n");
			break;
		case 2:printf("请输入要查询的ISBN号:");
			scanf(" %s", x.isbn_id);
			for (pnew = head; pnew != NULL; pnew = pnew->next)//遍历链表
			{
				if (strcmp(pnew->b.isbn_id, x.isbn_id) == 0)
				{
					flag = 1;
					printf("书ID:%d\n书ISBN:%s\n书名:%s\n作者:%s\n分类号:%d\n价格:%.2f\n出版商:%s\n出版日期:%d-%d-%d\n存在状态号:%d\n\n"
						, pnew->b.book_id, pnew->b.isbn_id, pnew->b.name, pnew->b.author, pnew->b.category, pnew->b.price, pnew->b.press
						, pnew->b.press_data.year, pnew->b.press_data.month, pnew->b.press_data.day, pnew->b.exist);
				}
			}
			if (flag == 0)
				printf("你输入的ISBN不存在!\n\n");
			break;
		case 3:printf("请输入要查询的书名:");
			scanf(" %s", x.name);
			for (pnew = head; pnew != NULL; pnew = pnew->next)
			{
				if (strcmp(pnew->b.name, x.name) == 0)
				{
					flag = 1;
					printf("书ID:%d\n书ISBN:%s\n书名:%s\n作者:%s\n分类号:%d\n价格:%.2f\n出版商:%s\n出版日期:%d-%d-%d\n存在状态号:%d\n\n"
						, pnew->b.book_id, pnew->b.isbn_id, pnew->b.name, pnew->b.author, pnew->b.category, pnew->b.price, pnew->b.press
						, pnew->b.press_data.year, pnew->b.press_data.month, pnew->b.press_data.day, pnew->b.exist);
				}
			}
			if (flag == 0)
				printf("你输入的书名不存在!\n\n");
			break;
		case 4:printf("请输入要查询的作者:");
			scanf(" %s", x.author);
			for (pnew = head; pnew != NULL; pnew = pnew->next)
			{
				if (strcmp(pnew->b.author, x.author) == 0)
				{
					flag = 1;
					printf("书ID:%d\n书ISBN:%s\n书名:%s\n作者:%s\n分类号:%d\n价格:%.2f\n出版商:%s\n出版日期:%d-%d-%d\n存在状态号:%d\n\n"
						, pnew->b.book_id, pnew->b.isbn_id, pnew->b.name, pnew->b.author, pnew->b.category, pnew->b.price, pnew->b.press
						, pnew->b.press_data.year, pnew->b.press_data.month, pnew->b.press_data.day, pnew->b.exist);
				}
			}
			if (flag == 0)
				printf("你输入的作者不存在!\n\n");
			break;
		case 5:printf("请输入要查询的分类号:");
			scanf(" %d", &x.category);
			for (pnew = head; pnew != NULL; pnew = pnew->next)
			{
				if (pnew->b.category == x.category)
				{
					flag = 1;
					printf("书ID:%d\n书ISBN:%s\n书名:%s\n作者:%s\n分类号:%d\n价格:%.2f\n出版商:%s\n出版日期:%d-%d-%d\n存在状态号:%d\n\n"
						, pnew->b.book_id, pnew->b.isbn_id, pnew->b.name, pnew->b.author, pnew->b.category, pnew->b.price, pnew->b.press
						, pnew->b.press_data.year, pnew->b.press_data.month, pnew->b.press_data.day, pnew->b.exist);
				}
			}
			if (flag == 0)
				printf("你输入的分类号不存在!\n\n");
			break;
		case 6:printf("请输入要查询的出版社:");
			scanf(" %s", x.press);
			for (pnew = head; pnew != NULL; pnew = pnew->next)
			{
				if (strcmp(pnew->b.press, x.press) == 0)
				{
					flag = 1;
					printf("书ID:%d\n书ISBN:%s\n书名:%s\n作者:%s\n分类号:%d\n价格:%.2f\n出版商:%s\n出版日期:%d-%d-%d\n存在状态号:%d\n\n"
						, pnew->b.book_id, pnew->b.isbn_id, pnew->b.name, pnew->b.author, pnew->b.category, pnew->b.price, pnew->b.press
						, pnew->b.press_data.year, pnew->b.press_data.month, pnew->b.press_data.day, pnew->b.exist);
				}
			}
			if (flag == 0)
				printf("你输入的出版社不存在!\n\n");
			break;
		case 7:for (pnew = head; pnew != NULL;)//遍历链表的同时释放内存
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
		default:printf("输入错误!请输入正确代号!\n\n");
		}
	}
}

void add_book()//录入图书信息	夏国超	   1、退出录入  2、继续录入
{
	FILE *fp1;
	struct Book m, n;
	int flag = 0,flag1=0;
	int i,j,times;
	
	system("cls");
	show_welcome();
	printf("****************************************欢迎使用图书管理系统录入功能****************************************\n\n");
	printf("———————>请输入将要录入书籍的数目：");
	scanf("%d", &times);
	system("cls");

	for (j = 0; j < times; j++)
	{
		show_welcome();
		printf("****************************************欢迎使用图书管理系统录入功能****************************************\n\n");
		printf("———————>已经成功输入%d本书。剩余%d本\n", j,times-j);
		if ((fp1 = fopen("d:\\book.txt", "a+")) == NULL)
		{
			printf("———————>文件打开失败，请联系管理员。");
			exit(0);
		}
		printf("———————>请输入需要添加书的ISBN号（13位纯数字）：");
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
			printf("———————>输入成功，请确认您输入的ISBN号为%s。\n", m.isbn_id);
		else
		{
			printf("———————>输入错误，请确认您输入的ISBN号为13位纯数字(请按Enter进入主菜单）。\n");
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
			printf("———————>录入一本ISBN号相同的图书，无需输入其余书本信息，系统自动分配书本ID。\n");
			fprintf(fp1, "%d\n%s\n%s\n%s\n%d\n%f\n%s\n%d-%d-%d\n%d\n",m.book_id, m.isbn_id, m.name, m.author, m.category, m.price, m.press, m.press_data.year, m.press_data.month, m.press_data.day, m.exist);
		}
		if (flag1 != 1)
		{
			printf("———————>请输入书名：");
			scanf("%s", m.name);
			printf("———————>请输入书的作者名：");
			scanf("%s", m.author);
			printf("———————>请输入的分类：");
			scanf("%d", &m.category);
			printf("———————>请输入书的价格：");
			scanf("%f", &m.price);
			printf("———————>请输入需要添加书的出版社名字：");
			scanf("%s", m.press);
			printf("———————>请输入书的出版日期（以xxxx-xx-xx形式输入）：");
			scanf("%d-%d-%d", &m.press_data.year, &m.press_data.month, &m.press_data.day);
			m.exist = 0;
			fprintf(fp1, "%d\n%s\n%s\n%s\n%d\n%f\n%s\n%d-%d-%d\n%d\n",m.book_id, m.isbn_id, m.name, m.author, m.category, m.price, m.press, m.press_data.year, m.press_data.month, m.press_data.day, m.exist);
		}
		fclose(fp1);
		i = 0;
		printf("———————>你成功录入了一本图书。\n");
		printf("      书本ID          ISBN           书名      作者      分类          价格           出版社       出版日期\n");
		printf("|%013d| |%s|       |%s|       |%s|       |%d|        |$%f|         |%s|       |%d-%d-%d|\n\n",m.book_id, m.isbn_id, m.name, m.author, m.category, m.price, m.press, m.press_data.year, m.press_data.month, m.press_data.day);
		system("pause");
		system("cls");
	}
}

void modify_book()
{
	FILE *fp1, *fp2;
	struct Book m;//文件数据复制的中间变量
	char n[14];
	int choice;
	int flag;//控制单个书目信息的输入，防止被修改书目信息的重复输入
	int f1 = 0, f2;

	while (1)
	{
		f1 = 0;//假设输入的ISBN不存在书库中
		system("cls");
		printf("************************欢迎使用图书修改功能****************************\n\n");
		if ((fp1 = fopen("d:\\book.txt", "r")) == NULL)
		{
			printf("数据库打开失败!请查看D:book.txt文件是否存在!\n");
			return;
		}
		if ((fp2 = fopen("d:\\Bufbook.txt", "w")) == NULL)
		{
			printf("创建文件失败!请检查内存是否已满!\n");
			return;
		}
		printf("请输入要修改书的ISBN:");
		scanf(" %s", n);
		while ((fscanf(fp1, "%d%s%s%s%d%f%s%d%d%d%d", &m.book_id, m.isbn_id, m.name, m.author, &m.category, &m.price, m.press, &m.press_data.year, &m.press_data.month, &m.press_data.day, &m.exist)) != EOF)
		{
			flag = 0;//假设目前读入的书目不是要修改的书目
			if (strcmp(n, m.isbn_id) == 0)
			{
				f1 = 1;//标记输入的ISBN存在书库中
				flag = 1;//标记当前书目为需要修改的书目
				printf("\t\t\t1——修改书名\n\t");
				printf("\t\t2——修改作者\n\t");
				printf("\t\t3——修改分类\n\t");
				printf("\t\t4——修改价格\n\t");
				printf("\t\t5——修改出版社\n\t");
				printf("\t\t6——修改出版时间\n\t");
				printf("\t\t0——修改完成\n");
				printf("为了数据安全，请以正确的方式退出程序!\n");
				while (1)
				{

					printf("请输入代号:");
					scanf(" %d", &choice);
					if (choice == 0)//输入当前被修改书目信息到指定文件
					{
						fprintf(fp2, "%d\n%s\n%s\n%s\n%d\n%.2f\n%s\n%d %d %d\n%d\n", m.book_id, m.isbn_id, m.name, m.author, m.category, m.price, m.press, m.press_data.year, m.press_data.month, m.press_data.day, m.exist);
						printf("修改完成！正在保存...\n");
						break;
					}
					switch (choice)
					{
					case 1:printf("请输入要修改的书名:"); scanf(" %s", m.name); printf("书名修改成功\n\n"); break;
					case 2:printf("请输入要修改的作者:"); scanf(" %s", m.author); printf("作者名修改成功\n\n"); break;
					case 3:printf("请输入要修改的类别:"); scanf(" %d", &m.category); printf("类别修改成功\n\n"); break;
					case 4:printf("请输入要修改的价格:"); scanf(" %f", &m.price); printf("价格修改成功\n\n"); break;
					case 5:printf("请输入要修改的出版社:"); scanf(" %s", m.press); printf("出版社修改成功\n\n"); break;
					case 6:printf("请输入要修改的出版日期:"); scanf(" %d%d%d", &m.press_data.year, &m.press_data.month, &m.press_data.day);
						printf("出版日期修改成功\n\n");
						break;
					default:printf("输入错误,请从此输入!\n\n");
					}
				}
			}
			if (flag == 0)//当前书目不是被修改书目则直接输出到另一个文件
				fprintf(fp2, "%d\n%s\n%s\n%s\n%d\n%.2f\n%s\n%d %d %d\n%d\n", m.book_id, m.isbn_id, m.name, m.author, m.category, m.price, m.press, m.press_data.year, m.press_data.month, m.press_data.day, m.exist);
		}
		if (f1 == 0)//输入的ISBN不存在书库中的提示语句
			printf("你输入的ISBN不存在该系统!\n\n");
		fclose(fp1);
		fclose(fp2);
		remove("d:\\book.txt");
		rename("d:\\Bufbook.txt", "d:\\book.txt");
		printf("是否继续修改？\n是——按1\n否——按任意键\n");
		scanf(" %d", &f2);
		if (f2 != 1)//判断是否再次进行图书修改功能
		{
			printf("你没有选择继续修改，正在返回主菜单...\n");
			system("pause");
			return;
		}
	}
}




void delete_book()//删除图书 吴龙
{

}