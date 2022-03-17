
#include<stdio.h>
#include <string.h>
#define LEN sizeof(struct addritem)

void input();
void search();
void menu();
void del();
void update();


 struct addritem
{
	char name[10];
	char tel[11];
	char address[30];

}addrinfo[100];
int main(void)
{
	int n;
	menu();
	scanf("%d", &n);

	while (1)
	{
		if (n == 5)
		{
			printf("\n\n\n");
			printf("感谢您的使用，请按回车键退出此窗口！");
			printf("\n\n\n\n\n");
			break;
		}

		switch (n)
		{
		case 1:search(); break;
		case 2:input(); break;
		case 3:update(); break;
		case 4:del(); break;

		default:
			break;
		}
		
		menu();
		scanf("%d", &n);
	}

}
void menu()
{
	
	printf("1.查询联系人\n");
	printf("2.新增联系人\n");
	printf("3.修改联系人信息\n");
	printf("4.删除联系人信息\n");
	printf("5.退出\n");
	printf("\n\n\n");
	printf("您的选择是：");


	
	
}
void input()
{
	int i, count = 0;
	FILE* fp = fopen("data.txt", "a+");
	fseek(fp, 0, SEEK_SET);
	while (1)
	{
		
		
		if (fread(&addrinfo[count], LEN, 1, fp) == 1)
			count++;
		if (feof(fp))
			break;
	}
    if (count == 0)
			printf("目前储存联系人为空！");
	if (count == 100)
	{
		printf("当前联系人已满！");
	}
	else
	{

		fclose(fp);
		printf("请输入新增联系人信息\n");
		printf("请输入联系人姓名：\n");

		scanf("%s", &addrinfo[count].name);

		printf("请输入联系人电话：\n");

		scanf("%s", &addrinfo[count].tel);

		printf("请输入联系人地址：\n");

		scanf("%s", &addrinfo[count].address);
		fp = fopen("data.txt", "w");
		for (i = 0; i <= count; i++)
		{
			fwrite(&addrinfo[i], LEN, 1, fp);

		}

		printf("新增联系人已添加成功！\n");
		fclose(fp);

		memset(addrinfo, 0, sizeof(struct addritem) * 100);
	}
}

void search()
{
	int i, count = 0;
	char name[10];
	FILE* fp = fopen("data.txt", "r");
	fseek(fp, 0, SEEK_SET);
	while (1)
	{
		

		if (fread(&addrinfo[count], LEN, 1, fp) == 1)
			count++;
		if (feof(fp))
			break;
	}
	if (count == 0)
		printf("目前储存联系人为空！\n");
	fclose(fp);
	printf("请输入您要查找的联系人姓名：\n");
	scanf("%s", &name);

	for (i = 0; i < count; i++)
	{
		if (strcmp(name, addrinfo[i].name) == 0)
		{
			printf("%s\n", addrinfo[i].name);
			printf("%s\n", addrinfo[i].tel);
			printf("%s\n", addrinfo[i].address);
		}

	}
	if (i == count)
		printf("您输入的联系人不存在！");
	memset(addrinfo, 0, sizeof(struct addritem) * 100);

}
void update()
{
	int i,j, count = 0;
	char name[10];
	FILE* fp = fopen("data.txt", "r");
	fseek(fp, 0, SEEK_SET);
	while (1)
	{
		

		if (fread(&addrinfo[count], LEN, 1, fp) == 1)
			count++;
		if (feof(fp))
			break;
	}
	if (count == 0)
		printf("目前储存联系人为空！\n");
	fclose(fp);
	printf("请输入您要修改的联系人姓名：");
	scanf("%s", &name, 10);
	for (i = 0; i < count; i++)
	{
		if (strcmp(name, addrinfo[i].name) == 0)
		{
			printf("已找到您要修改的联系人！请输入相对应的信息进行修改！\n");
			printf("请输入联系人姓名：\n");

			scanf("%s", &addrinfo[i].name);

			printf("请输入联系人电话：\n");

			scanf("%s", &addrinfo[i].tel);

			printf("请输入联系人地址：\n");

			scanf("%s", &addrinfo[i].address);

		}
		
	}
    if (count == i)
			printf("您想要修改的联系人不存在！");
	fp = fopen("data.txt", "w");
	for (j = 0; j < count; j++)
	{
		fwrite(&addrinfo[j], LEN, 1, fp);
	}
	fclose(fp);
	printf("联系人修改成功！");
	memset(addrinfo, 0, sizeof(struct addritem) * 100);
}
void del()
{
	int i, j,n, count = 0;
	char name[10];
	FILE* fp = fopen("data.txt", "r");
	fseek(fp, 0, SEEK_SET);
	while (1)
	{
		

		if (fread(&addrinfo[count], LEN, 1, fp) == 1)
			count++;
		if (feof(fp))
			break;
	}
	if (count == 0)
		printf("目前储存联系人为空！\n");
	fclose(fp);
	printf("请输入您要删除的联系人姓名：");
	scanf("%s", &name);
	for (i = 0; i < count; i++)
	{
		if (strcmp(name, addrinfo[i].name) == 0)
		{
			printf("已找到您要删除的联系人！\n");
			printf("%s\n", addrinfo[i].name);
			printf("%s\n", addrinfo[i].tel);
			printf("%s\n", addrinfo[i].address);
			for (j = i; j < count; j++)
			{
				addrinfo[j] = addrinfo[j + 1];
			}
			count--;

		}

	}

	if (count == i)
		printf("您想要修改的联系人不存在！");
	fp = fopen("data.txt", "w");
	for (n = 0; n < count; n++)
	{
		fwrite(&addrinfo[n], LEN, 1, fp);
	}
	fclose(fp);
	printf("该联系人已成功删除！");
	memset(addrinfo, 0, sizeof(struct addritem) * 100);
}



































