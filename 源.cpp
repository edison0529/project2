
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
			printf("��л����ʹ�ã��밴�س����˳��˴��ڣ�");
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
	
	printf("1.��ѯ��ϵ��\n");
	printf("2.������ϵ��\n");
	printf("3.�޸���ϵ����Ϣ\n");
	printf("4.ɾ����ϵ����Ϣ\n");
	printf("5.�˳�\n");
	printf("\n\n\n");
	printf("����ѡ���ǣ�");


	
	
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
			printf("Ŀǰ������ϵ��Ϊ�գ�");
	if (count == 100)
	{
		printf("��ǰ��ϵ��������");
	}
	else
	{

		fclose(fp);
		printf("������������ϵ����Ϣ\n");
		printf("��������ϵ��������\n");

		scanf("%s", &addrinfo[count].name);

		printf("��������ϵ�˵绰��\n");

		scanf("%s", &addrinfo[count].tel);

		printf("��������ϵ�˵�ַ��\n");

		scanf("%s", &addrinfo[count].address);
		fp = fopen("data.txt", "w");
		for (i = 0; i <= count; i++)
		{
			fwrite(&addrinfo[i], LEN, 1, fp);

		}

		printf("������ϵ������ӳɹ���\n");
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
		printf("Ŀǰ������ϵ��Ϊ�գ�\n");
	fclose(fp);
	printf("��������Ҫ���ҵ���ϵ��������\n");
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
		printf("���������ϵ�˲����ڣ�");
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
		printf("Ŀǰ������ϵ��Ϊ�գ�\n");
	fclose(fp);
	printf("��������Ҫ�޸ĵ���ϵ��������");
	scanf("%s", &name, 10);
	for (i = 0; i < count; i++)
	{
		if (strcmp(name, addrinfo[i].name) == 0)
		{
			printf("���ҵ���Ҫ�޸ĵ���ϵ�ˣ����������Ӧ����Ϣ�����޸ģ�\n");
			printf("��������ϵ��������\n");

			scanf("%s", &addrinfo[i].name);

			printf("��������ϵ�˵绰��\n");

			scanf("%s", &addrinfo[i].tel);

			printf("��������ϵ�˵�ַ��\n");

			scanf("%s", &addrinfo[i].address);

		}
		
	}
    if (count == i)
			printf("����Ҫ�޸ĵ���ϵ�˲����ڣ�");
	fp = fopen("data.txt", "w");
	for (j = 0; j < count; j++)
	{
		fwrite(&addrinfo[j], LEN, 1, fp);
	}
	fclose(fp);
	printf("��ϵ���޸ĳɹ���");
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
		printf("Ŀǰ������ϵ��Ϊ�գ�\n");
	fclose(fp);
	printf("��������Ҫɾ������ϵ��������");
	scanf("%s", &name);
	for (i = 0; i < count; i++)
	{
		if (strcmp(name, addrinfo[i].name) == 0)
		{
			printf("���ҵ���Ҫɾ������ϵ�ˣ�\n");
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
		printf("����Ҫ�޸ĵ���ϵ�˲����ڣ�");
	fp = fopen("data.txt", "w");
	for (n = 0; n < count; n++)
	{
		fwrite(&addrinfo[n], LEN, 1, fp);
	}
	fclose(fp);
	printf("����ϵ���ѳɹ�ɾ����");
	memset(addrinfo, 0, sizeof(struct addritem) * 100);
}



































