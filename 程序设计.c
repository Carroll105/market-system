#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define rec for(i=1;i<=n;i++)
#define LEN sizeof(struct list)
#define gets_s gets
int i = 0;
int dd[20], d1 = 0;
int nnp = 0, nnx = 0;
int search(), search2(), searchp;
int xg3();
int vip1(), vip2();
void nowtime();
float moneychange(float n);
float changemoney();
float e[50];
//����ͳһ���뺯�� 
struct fruit {
	char type[10];//����
	int selltype;//������ʽ 
	float per_price;//����
}b[5];//����ˮ���ṹ�� 
struct time {
	int ye;
	int mo;
	int md;
	int ho;
	int mi;
	int se;
};//����ʱ��ṹ�� 
struct time1 {
	int ye;
	int mo;
	int md;
	int ho;
	int mi;
	int se;
}tt[2];
struct money {
	int yuan;
	int jiao;
	int fen;
}money1;//Ǯ�ṹ�� 
struct vip_type {
	char name[5];
	float restmoney;
}vip[50];//vip�Ľṹ�� 
struct fruit1 {
	int type_numb;
	float fruitnum;
	float cost;
}c[5];//ˮ��������ʽ 
struct list {
	int num;//��ʶ��
	struct time ti;//����ʱ�䣨ϵͳʱ�䣩
	int pay_by; /* 1Ϊ�ֽ� 0Ϊ��Ա��*/
	int buynumber;//���������� 
	struct fruit1 c[5];//����ˮ����Ϣ 
	float allmoney; //�ܼ� 
	float change;//����
	float money_rec;//�տ�
	char id[5];//��Ա����
	float before;//���
	struct list *next;
}a[50];

int answer(struct list card);
//������ʽ��ʾ���� 
int selltype1(struct fruit back)
{
	if (back.selltype == 1)
	{
		printf("����Ϊ��һ��  ");
		moneychange(back.per_price);
	}
	if (back.selltype == 2)
	{
		printf("����Ϊ��һ��  ");
		moneychange(back.per_price);
	}
	if (back.selltype == 3)
	{
		printf("����Ϊ��һ��  ");
		moneychange(back.per_price);
	}
	return 0;
}
//��ӹ�����Ϣ���� 
int xg1() {
	a[i].num = i + 1000;
	printf("�˵���Ϊ��%d\n", a[i].num);
	printf("����ʱ��\n");
	nowtime();
	printf("�����빺��ˮ��������\n");
	scanf("%d", &a[i].buynumber);
	if (a[i].buynumber>5) {
		printf("�����������ó�������,������ѡ��\n");
		return 0;
	}
	printf("1.%s\n2.%s\n3.%s\n4.%s\n5.%s\n", b[0].type, b[1].type, b[2].type, b[3].type, b[4].type);
	int i0 = 0;
	while (i0<a[i].buynumber)
	{
		printf("�����빺��ĵ�%d��ˮ��\n", i0 + 1);
		scanf("%d", &a[i].c[i0].type_numb);
		printf("\n");
		selltype1(b[i0]);
		printf("�����빺�������ˮ��������\n");
		scanf("%f", &a[i].c[i0].fruitnum);
		printf("��ˮ���ܼ�Ϊ\n");
		a[i].c[i0].cost = b[i0].per_price*a[i].c[i0].fruitnum;
		float kn = b[i0].per_price*a[i].c[i0].fruitnum;
		i0++;
		moneychange(kn);
	}
	a[i].allmoney = 0;
	int i1;
	for (i1 = 0; i1<a[i].buynumber; i1++)
	{
		a[i].allmoney = a[i].allmoney + a[i].c[i1].cost;
	}
	printf("\n");
	printf("����ˮ�����ܼ�Ϊ:\n");
	float kk = a[i].allmoney;
	moneychange(kk);
	printf("�����빺��ʽ(0Ϊ��Ա����1Ϊ�ֽ�)\n");
	scanf("%d", &a[i].pay_by);
	if (a[i].pay_by)
	{
		printf("�������տ�\n");
		a[i].money_rec = changemoney();
		if (a[i].money_rec>1000) {
			printf("�����޶�޷����ף�\n");
			int n = a[i].num - 1000;
			a[n].num = -1;
		}

		else {
			a[i].change = a[i].money_rec - kk;
			if (a[i].change<0)
			{
				a[i].change = -a[i].change;
				printf("���ν��׳��п��𣬿��ˣ�\n");
				moneychange(a[i].change);
				a[i].change = -a[i].change;
			}
			else
			{
				printf("����:\n");
				moneychange(a[i].change);
			}
		}
	}
	else
	{
		vip2();
	}
	printf("¼�����\n");
	printf("��������Լ���");
	getchar();
	getchar();
	i++;
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.��  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.��  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.ɾ  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.��          ��                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	return 5;
}
//�޸� ��Ϣ���� 
int xg2() {
	int j;
	printf("������Ҫ�޸ĵ���Ϣ��\n");
	int t;
	scanf("%d", &t);
	while (t<1000 || a[t - 1000].num == -1 || t >= i + 1000) {
		printf("�޸ĵ���Ϣ�����ڣ����������롣��������0�Խ����ù��ܡ�\n");
		printf("������Ҫ�޸ĵ���Ϣ��\n");
		scanf("%d", &t);
		if (t == 0) {
			printf("\n\n");
			printf("�������������빦�ܡ�\n");
			return 0;
		}

	}
	j = t - 1000;

	printf("����ʱ��\n");
	nowtime();
	printf("�����빺��ˮ��������\n");
	scanf("%d", &a[j].buynumber);
	printf("1.%s\n2.%s\n3.%s\n4.%s\n5.%s\n", b[0].type, b[1].type, b[2].type, b[3].type, b[4].type);
	int i0 = 0;
	while (i0<a[j].buynumber)
	{
		printf("�����빺��ĵ�%d��ˮ��", i0 + 1);
		scanf("%d", &a[j].c[i0].type_numb);
		printf("\n");
		selltype1(b[i0]);
		printf("�����빺�������ˮ��������\n");
		scanf("%f", &a[j].c[i0].fruitnum);
		printf("��ˮ���ܼ�Ϊ\n");
		a[j].c[i0].cost = b[i0].per_price*a[j].c[i0].fruitnum;
		float kn = b[i0].per_price*a[j].c[i0].fruitnum;
		i0++;
		moneychange(kn);
	}
	a[j].allmoney = 0;
	int i1;
	for (i1 = 0; i1<a[j].buynumber; i1++)
	{
		a[j].allmoney = a[j].allmoney + a[j].c[i1].cost;
	}
	printf("����ˮ�����ܼ�Ϊ:\n");
	float kk = a[j].allmoney;
	moneychange(kk);
	printf("�����빺��ʽ(0Ϊ��Ա����1Ϊ�ֽ�)\n");
	scanf("%d", &a[j].pay_by);
	if (a[j].pay_by)
	{
		printf("�������տ�\n");
		a[j].money_rec = changemoney();

		printf("����:\n");
		a[j].change = a[j].money_rec - kk;
		moneychange(a[j].change);
	}
	else
	{
		vip2();
	}

	printf("�޸����\n");
	printf("��������Լ���");
	getchar();
	getchar();
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.��  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.��  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.ɾ  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.��          ��                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	return 5;
}
//ɾ�� ��Ϣ���� 
int xg3() {
	int n = 0, j, p;
	printf("������Ҫɾ������Ϣ��\n");
	scanf("%d", &p);
	while (p<1000 || a[p - 1000].num == -1 || p >= i + 1000) {
		printf("�޸ĵ���Ϣ�����ڣ����������롣��������0�Խ����ù��ܡ�\n");
		printf("������Ҫ�޸ĵ���Ϣ��\n");
		scanf("%d", &p);
		if (p == 0) {
			printf("\n\n");
			printf("�������������빦�ܡ�\n");
			return 0;
		}

	}
	n = p - 1000;
	a[n].num = -1;
	printf("ɾ�����\n");
	printf("��������Լ���");
	getchar();
	getchar();
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.��  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.��  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.ɾ  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.��          ��                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	return 5;
}
int vip3();
int vip4();
//vip�ܺ��� 
int lvip() {
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.��  ��  Ա  ��                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.�� Ա �� �� ֵ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.   ��   ��                                          | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                                                                       | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	int i;
	scanf("%d", &i);
	if (i == 1)
		vip3();
	if (i == 2)
		vip4();
	if (i == 3)
	{
		{
			system("CLS");
			printf("\n\n\n");
			printf("           ____________________________________________________________________________________________\n");
			printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
			printf("          | ----------------------------------------------------------------------------------------- | \n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 1.��  ��  ��  Ϣ                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 2.��  ѯ  ��  Ϣ                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 3.��  ��  ��  Ϣ                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 4.  ��  Ա  ��                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | ----------------------------------------------------------------------------------------- |\n");
			printf("          |___________________________________________________________________________________________|\n");
			printf("���������蹦�����");
			return 0;
		}
	}
	return 0;
}
//vip��ѯ���� 
int vip1() {
	int n = 0;
	int i;
	FILE *kk = fopen("F:\\VIP1.txt", "r");
	while (!feof(kk))
	{
		fscanf(kk, "%s %f", vip[n].name, &vip[n].restmoney);
		n++;
	}
	char vipname[5];
	int j = 1;
	while (j == 1) {
		printf("�������Ա���ţ�\n");

		scanf("%s", vipname);
		int cc = 0;
		for (i = 0; i<n; i++)
		{
			if (strcmp(vipname, vip[i].name) == 0)
			{
				cc = 1;
				printf("��Ա����Ϊ��%s    \n���Ϊ��\n", vip[i].name);
				moneychange(vip[i].restmoney);
				printf("��Ա����������Ϊ:\n");
				moneychange(e[i] - vip[i].restmoney);
			}
		}
		if (cc == 0)
		{
			printf("�޸û�Ա����Ϣ����ѡ��0.���ء�1.�����������룡\n");
			scanf("%d", &j);
		}
		else
			j = 0;

	}
	printf("��������Է���\n");
	getchar();
	getchar();
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.��  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.��  ѯ  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.��  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.  ��  Ա  ��                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	printf("���������蹦�����");
	return 0;
}
//vip���Ѻ��� 
int vip2()
{
	int n = 0;
	int i2;
	FILE *kk = fopen("F:\\VIP1.txt", "r");
	while (!feof(kk))
	{
		fscanf(kk, "%s %f", vip[n].name, &vip[n].restmoney);
		n++;
	}
	char vipname[5];
	printf("�������Ա���ţ�\n");
	getchar();
	gets_s(vipname);
	int b = 0;
	for (i2 = 0; i2<n; i2++)
		if (strcmp(vipname, vip[i2].name) == 0)
		{
			printf("��Ա��ԭ���Ϊ:\n");
			strcpy(a[i].id, vip[i2].name);
			moneychange(vip[i2].restmoney);
			vip[i2].restmoney = vip[i2].restmoney - a[i2].allmoney;
			printf("��Ա�������Ϊ��\n");
			moneychange(vip[i2].restmoney);
			a[i].before = vip[i2].restmoney;
			b = 1;
		}
	if (b == 0) {
		printf("û�иû�Ա\n");
	}
	FILE *kp = fopen("F:\\VIP1.txt", "w");
	for (i2 = 0; i2<n; i2++)
	{
		fprintf(kp, "%s %f\n", vip[i2].name, vip[i2].restmoney);
	}
	fclose(kp);
	return 0;
}
//vip�쿨���� 
int vip3()
{
	char vip_name[5];
	int yy, bb, x;
	printf("�������Ƿ�쿨��(1.��   2.��)\n");
	scanf("%d", &yy);
	if (yy == 1)
	{
		printf("�������Ļ�Ա���ţ�\n");
		for (;;)
		{
			x = 1;
			scanf("%s", vip_name);
			int i = 0;
			for (; i < nnp; i++)
			{
				if (strcmp(vip[i].name, vip_name) == 0)
				{
					printf("��Ա�����ظ�,�������µĿ��ţ�\n");
					x = 0;
				}
			}
			if (x == 1) break;
		}
		strcpy(vip[nnp ].name, vip_name);
		printf("�����뽻�ѵĻ�Ա�����:\n");
		vip[nnp].restmoney = changemoney();
		nnp++;
		printf("�ɷѳɹ�");
		FILE *kp = fopen("F:\\VIP1.txt", "w");
		int i2;
		for (i2 = 0; i2<nnp; i2++)
		{
			fprintf(kp, "%s %f\n", vip[i2].name, vip[i2].restmoney);
		}
		fclose(kp);
		printf("��������Է���\n");
		getchar();
		getchar();
		system("CLS");
		printf("\n\n\n");
		printf("           ____________________________________________________________________________________________\n");
		printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
		printf("          | ----------------------------------------------------------------------------------------- | \n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 1.��  ��  ��  Ϣ                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 2.��  ѯ  ��  Ϣ                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 3.��  ��  ��  Ϣ                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 4.  ��  Ա  ��                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | ----------------------------------------------------------------------------------------- |\n");
		printf("          |___________________________________________________________________________________________|\n");
		printf("���������蹦�����");
		return 0;

	}
	if (yy == 2)
	{
		system("CLS");
		printf("\n\n\n");
		printf("           ____________________________________________________________________________________________\n");
		printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
		printf("          | ----------------------------------------------------------------------------------------- | \n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 1.��  ��  ��  Ϣ                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 2.��  ѯ  ��  Ϣ                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 3.��  ��  ��  Ϣ                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 4.  ��  Ա  ��                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | ----------------------------------------------------------------------------------------- |\n");
		printf("          |___________________________________________________________________________________________|\n");
		printf("���������蹦�����");
		return 0;
	}
}
//vip��ֵ���� 
int vip4()
{
	int n = 0;
	float vv;
	int i2;
	FILE *kk = fopen("F:\\VIP1.txt", "r");
	while (!feof(kk))
	{
		fscanf(kk, "%s %f", vip[n].name, &vip[n].restmoney);
		n++;
	}
	n--;
	char vipname[5];
	printf("�������Ա���ţ�\n");
	getchar();
	gets_s(vipname);
	int b = 0;
	for (i2 = 0; i2<n; i2++)
		if (strcmp(vipname, vip[i2].name) == 0)
		{
			printf("��Ա��ԭ���Ϊ:\n");
			strcpy(a[i].id, vip[i2].name);
			moneychange(vip[i2].restmoney);
			printf("�������ֵ����:\n");
			vv = changemoney();
			vip[i2].restmoney = vip[i2].restmoney + vv;
			e[i2]=vip[i2].restmoney;
			printf("��Ա�������Ϊ��\n");
			moneychange(vip[i2].restmoney);
			a[i].before = vip[i2].restmoney;
			b = 1;
		}
	if (b == 0) {
		printf("û�иû�Ա\n");
	}
	FILE *kp = fopen("F:\\VIP1.txt", "w");
	for (i2 = 0; i2<n; i2++)
	{
		fprintf(kp, "%s %.2lf\n", vip[i2].name, vip[i2].restmoney);
	}
	fclose(kp);
	printf("��������Է���\n");
	getchar();
	getchar();
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.��  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.��  ѯ  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.��  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.  ��  Ա  ��                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	printf("���������蹦�����");
	return 0;
}
//���ز�ѯ���� 
int search23() {
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.��  Ա  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.��  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.��  ��  ��  ��  ѯ                                  | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.��          ��                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	printf("���������蹦�����");
	return 0;
}
//������Ϣ������� 
int search22() {
	int mm;
	for (mm = 0; mm<i; mm++)
	{
		if (a[mm].num != -1)
			answer(a[mm]);
	}
	printf("��������Է���\n");
	getchar();
	getchar();
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.��  ��  ��  ѯ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.ȫ  ��  ��  ��                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.��          ��                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                                                                       | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	printf("���������蹦����ţ�\n");
	return 0;
}
//�˵��Ų�ѯ���� 
int search21() {
	int mn, v;
	printf("����������Ҫ��ѯ�Ĺ�����Ϣ���˵��ţ�\n");
	scanf("%d", &mn);
	v = mn - 1000;
	if (v<0 || a[v].num == -1 || v >= i)
	{
		printf("��Ǹ��δ�ܲ鵽����������Ϣ\n");
		printf("��������Է���\n");
		getchar();
		getchar();
		system("CLS");
		printf("\n\n\n");
		printf("           ____________________________________________________________________________________________\n");
		printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
		printf("          | ----------------------------------------------------------------------------------------- | \n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 1.��  ��  ��  ѯ                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 2.ȫ  ��  ��  ��                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 3.��          ��                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                                                                       | |\n");
		printf("          |                                                                                           |\n");
		printf("          | ----------------------------------------------------------------------------------------- |\n");
		printf("          |___________________________________________________________________________________________|\n");
		printf("���������蹦����ţ�\n");
		return 0;
	}
	else
	{
		answer(a[v]);
		printf("��������Է���\n");
		getchar();
		getchar();
		system("CLS");
		printf("\n\n\n");
		printf("           ____________________________________________________________________________________________\n");
		printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
		printf("          | ----------------------------------------------------------------------------------------- | \n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 1.��  ��  ��  ѯ                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 2.ȫ  ��  ��  ��                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 3.��          ��                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                                                                       | |\n");
		printf("          |                                                                                           |\n");
		printf("          | ----------------------------------------------------------------------------------------- |\n");
		printf("          |___________________________________________________________________________________________|\n");
		printf("���������蹦����ţ�\n");
	}
}
//�򵥲�ѯ�ܺ��� 
int search2() {
	int v, z;
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.��  ��  ��  ѯ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.ȫ  ��  ��  ��                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.��          ��                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                                                                       | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	printf("���������蹦����ţ�\n");
	v = 0;
	z = 1;
	while (1)
	{
		scanf("%d", &z);
		if (z == 1)
			search21();
		else if (z == 2)
			search22();
		else if (z == 3)
		{
			system("CLS");
			printf("\n\n\n");
			printf("           ____________________________________________________________________________________________\n");
			printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
			printf("          | ----------------------------------------------------------------------------------------- | \n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 1.��  ��  ��  Ϣ                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 2.��  ѯ  ��  Ϣ                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 3.��  ��  ��  Ϣ                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 4.  ��  Ա  ��                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | ----------------------------------------------------------------------------------------- |\n");
			printf("          |___________________________________________________________________________________________|\n");
			printf("���������蹦�����");
			return 0;
		}
		else
			printf("error\n");
	}
}
int search31();
int search32();
int search33();
//�����ѯ�ܺ��� 
int search3()
{
	while (1) {
		system("CLS");
		printf("\n\n\n");
		printf("           ____________________________________________________________________________________________\n");
		printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
		printf("          | ----------------------------------------------------------------------------------------- | \n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 1.��  ˮ  ��   ��  ��  ��  ѯ                         | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 2.��  ��  ��  ��  ��  ��  ѯ                          | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 3.��  ��  ��  ʱ  ��  ��  ѯ                          | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 4.��           ��                                     | |\n");
		printf("          |                                                                                           |\n");
		printf("          | ----------------------------------------------------------------------------------------- |\n");
		printf("          |___________________________________________________________________________________________|\n");
		printf("���������蹦�����");
		int i1;
		scanf("%d", &i1);
		if (i1 == 1)
			search31();
		else if (i1 == 2)
			search32();
		else if (i1 == 3)
			search33();
		else if (i1 == 4)
		{
			system("CLS");
			printf("\n\n\n");
			printf("           ____________________________________________________________________________________________\n");
			printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
			printf("          | ----------------------------------------------------------------------------------------- | \n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 1.��  ��  ��  Ϣ                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 2.��  ѯ  ��  Ϣ                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 3.��  ��  ��  Ϣ                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 4.  ��  Ա  ��                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | ----------------------------------------------------------------------------------------- |\n");
			printf("          |___________________________________________________________________________________________|\n");
			printf("���������蹦�����");
			return 4;
		}
		else
			printf("error\n");
	}

}
//ˮ�������ѯ���� 
int search31()
{
	printf("��������Ҫ��ѯ��ˮ�����ࣺ\n");
	printf("1. %s\n2. %s\n3. %s\n4. %s\n5. %s\n", b[0].type, b[1].type, b[2].type, b[3].type, b[4].type);
	int y;
	int i2, i3, i6;
	float i4 = 0, i5 = 0;
	scanf("%d", &i2);
	for (y = 0; y<i; y++)
		for (i3 = 0; i3<a[y].buynumber; i3++)
			if (a[y].c[i3].type_numb == i2) {
				i4 = i4 + a[y].c[i3].fruitnum;
				i5 = i5 + a[y].c[i3].cost;
			}
	printf("ˮ��Ŀǰ������������%.2f\n", i4);
	printf("ˮ��Ŀǰ�����ܽ��:\n");
	moneychange(i5);
	printf("��������Է���\n");
	getchar();
	getchar();
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.��  ˮ  ��   ��  ��  ��  ѯ                         | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.��  ��  ��  ��  ��  ��  ѯ                          | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.��  ��  ��  ʱ  ��  ��  ѯ                          | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.��           ��                                     | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	printf("���������蹦�����");
	return 0;
}
int printf1(struct list *head);
//������������������� 
int search32()
{
	int i7;
	int i8 = 0;
	float k1, k2;
	printf("��������Ҫ��ѯ�Ĺ��������������ޣ�\n");
	k1 = changemoney();
	printf("\n");
	k2 = changemoney();
	struct list *head = NULL;
	struct list *p1, *p2;
	p1 = p2 = (struct list*)malloc(LEN);
	for (i7 = 0; i7<i; i7++)
	{
		if (a[i7].allmoney >= k1 && a[i7].allmoney <= k2)//��Ҫ�õ�����ʵ��
		{
			i8++;
			if (i8 == 1)
			{
				p1 = (struct list *)malloc(LEN);
				p1 = &a[i7];
				p1->next = NULL;
				head = p1;
				p2 = p1;
			}
			else
			{

				p1 = (struct list *)malloc(LEN);
				p1 = &a[i7];
				p1->next = NULL;
				p2->next = p1;
				p2 = p1;
			}
		}
	}
	printf1(head);
	system("pause");
	return 0;
}
int search331();
int search332();
int search333();
//��ʱ���ѯ��������ʵ�� 
int search33()
{
	int i8;
	printf("��ѡ������Ҫ����������ʽ��ѯ��\n");
	printf("1.�迪ʼ�����ʱ�䡣2.ֻ�迪ʼʱ�䡣3.ֻ�����ʱ��\n");
	scanf("%d", &i8);
	if (i8 == 1)
		search331();//��Ҫ�õ��Ƚ�ʱ�亯������������ʵ��
	if (i8 == 2)
		search332();
	if (i8 == 3)
		search333();
	return 0;
}
//��ʼ����ʱ�亯�� 
int search331()
{
	int i7;
	int i8 = 0;
	printf("�����뿪ʼʱ�䣺\n");
	printf("Сʱ��");
	scanf("%d", &tt[0].ho);
	printf("���ӣ�");
	scanf("%d", &tt[0].mi);
	printf("�룺");
	scanf("%d", &tt[0].se);
	printf("���������ʱ�䣺\n");
	printf("Сʱ��");
	scanf("%d", &tt[1].ho);
	printf("���ӣ�");
	scanf("%d", &tt[1].mi);
	printf("�룺");
	scanf("%d", &tt[1].se);
	struct list *head = NULL;
	struct list *p1, *p2;
	p1 = p2 = (struct list*)malloc(LEN);
	for (i7 = 0; i7<i; i7++)
	{
		if (
			(
			((tt[1].ho >= a[i7].ti.ho)) ||
				((tt[1].ho >= a[i7].ti.ho) && (tt[1].mi >= a[i7].ti.mi)) ||
				((tt[1].ho >= a[i7].ti.ho) && (tt[1].mi >= a[i7].ti.mi) && (tt[1].se >= a[i7].ti.se))
				) &&
				(

			((tt[0].ho <= a[i7].ti.ho)) ||
					((tt[0].ho <= a[i7].ti.ho) && (tt[0].mi <= a[i7].ti.mi)) ||
					((tt[0].ho <= a[i7].ti.ho) && (tt[0].mi <= a[i7].ti.mi) && (tt[0].se <= a[i7].ti.se))
					)
			)//��Ҫ�õ�����ʵ��
		{
			i8++;
			if (i8 == 1)
			{
				p1 = (struct list *)malloc(LEN);
				p1 = &a[i7];
				p1->next = NULL;
				head = p1;
				p2 = p1;
			}
			else
			{

				p1 = (struct list *)malloc(LEN);
				p1 = &a[i7];
				p1->next = NULL;
				p2->next = p1;
				p2 = p1;
			}
		}
	}
	printf1(head);
	system("pause");
	return 0;
}
//��ʼʱ�亯�� 
int search332()
{
	int i7;
	int i8 = 0;
	printf("�����뿪ʼʱ�䣺\n");
	printf("Сʱ��");
	scanf("%d", &tt[0].ho);
	printf("���ӣ�");
	scanf("%d", &tt[0].mi);
	printf("�룺");
	scanf("%d", &tt[0].se);
	struct list *head = NULL;
	struct list *p1, *p2;
	p1 = p2 = (struct list*)malloc(LEN);
	for (i7 = 0; i7<i; i7++)
	{
		if (

			((tt[0].ho <= a[i7].ti.ho)) ||
			((tt[0].ho <= a[i7].ti.ho) && (tt[0].mi <= a[i7].ti.mi)) ||
			((tt[0].ho <= a[i7].ti.ho) && (tt[0].mi <= a[i7].ti.mi) && (tt[0].se <= a[i7].ti.se))
			)//��Ҫ�õ�����ʵ��(tt[0].md<=a[i7].ti.md)&&(tt[0].ho<=a[i7].ti.ho)&&(tt[0].mi<=a[i7].ti.mi)&&(tt[0].se<=a[i7].ti.se)
		{
			i8++;
			if (i8 == 1)
			{
				p1 = (struct list *)malloc(LEN);
				p1 = &a[i7];
				p1->next = NULL;
				head = p1;
				p2 = p1;
			}
			else
			{

				p1 = (struct list *)malloc(LEN);
				p1 = &a[i7];
				p1->next = NULL;
				p2->next = p1;
				p2 = p1;
			}
		}
	}
	printf1(head);
	system("pause");
	return 0;
}
//����ʱ�亯�� 
int search333()
{
	int i7;
	int i8 = 0;
	printf("���������ʱ�䣺\n");
	printf("Сʱ��");
	scanf("%d", &tt[1].ho);
	printf("���ӣ�");
	scanf("%d", &tt[1].mi);
	printf("�룺");
	scanf("%d", &tt[1].se);
	struct list *head = NULL;
	struct list *p1, *p2;
	p1 = p2 = (struct list*)malloc(LEN);
	for (i7 = 0; i7<i; i7++)
	{
		if (
			((tt[1].ho >= a[i7].ti.ho)) ||
			((tt[1].ho >= a[i7].ti.ho) && (tt[1].mi >= a[i7].ti.mi)) ||
			((tt[1].ho >= a[i7].ti.ho) && (tt[1].mi >= a[i7].ti.mi) && (tt[1].se >= a[i7].ti.se))
			)
		{
			i8++;
			if (i8 == 1)
			{
				p1 = (struct list *)malloc(LEN);
				p1 = &a[i7];
				p1->next = NULL;
				head = p1;
				p2 = p1;
			}
			else
			{

				p1 = (struct list *)malloc(LEN);
				p1 = &a[i7];
				p1->next = NULL;
				p2->next = p1;
				p2 = p1;
			}
		}
	}
	printf1(head);
	system("pause");
	return 0;
}
//��ӡ������� 
int answer(struct list card)
{
	printf("��ʶ��:%d\n", card.num);
	printf("����ʱ��:");
	printf("%d/%d/%d %d:%d:%d\n", card.ti.ye, card.ti.mo, card.ti.md, card.ti.ho, card.ti.mi, card.ti.se);
	int cn;
	for (cn = 0; cn<card.buynumber; cn++) {
		int kn = card.c[cn].type_numb - 1;
		printf("�������ࣺ");
		printf("%s", b[kn].type);
		printf("��������:%f\n", card.c[cn].fruitnum);
		printf("��ˮ���ܼ�:");
		moneychange(card.c[cn].cost);
		printf("���ι�����ܼ�Ϊ��");
		moneychange(card.allmoney);
		printf("֧����ʽ:%d\n", card.pay_by);
	}
	if (card.pay_by)
	{
		printf("�տ�:\n");
		moneychange(card.money_rec);
		printf("����:\n");
		moneychange(card.change);

	}
	else
	{
		printf("��Ա����:%s\n", card.id);
		printf("��Ա��ԭ���Ϊ��\n");
		moneychange(card.allmoney + card.before);
		printf("�����:\n");
		moneychange(card.before);
	}
	printf("\n");
	return 5;
}
//��ӡ����ṹ�庯�� 
int printf1(struct list *head)
{
	struct list *p;
	p = head;
	if (head != NULL)
		do {
			printf("��ʶ��:%d\n", p->num);
			printf("����ʱ��:");
			printf("%d/%d/%d %d:%d:%d\n", p->ti.ye, p->ti.mo, p->ti.md, p->ti.ho, p->ti.mi, p->ti.se);
			int cn;
			for (cn = 0; cn<p->buynumber; cn++) {
				int kn = p->c[cn].type_numb - 1;
				printf("�������ࣺ");
				printf("%s", b[kn].type);
				printf("��������:%f\n", p->c[cn].fruitnum);
				printf("��ˮ���ܼ�:");
				moneychange(p->c[cn].cost);
				printf("���ι�����ܼ�Ϊ��");
				moneychange(p->allmoney);
				printf("֧����ʽ:%d\n", p->pay_by);
			}
			if (p->pay_by)
			{
				printf("�տ�:\n");
				moneychange(p->money_rec);
				printf("����:\n");
				moneychange(p->change);

			}
			else
			{
				printf("��Ա����:%s\n", p->id);
				printf("��Ա��ԭ���Ϊ��\n");
				moneychange(p->allmoney + p->before);
				printf("�����:\n");
				moneychange(p->before);
			}
			printf("\n");
			p = p->next;
		} while (p != NULL);
		return 0;
}
//����ʱ�亯�� 
void nowtime()
{
	int n;
	int year, mon, day, hour, sec;
	time_t t;
	struct tm * lt;
	time(&t);//��ȡUnixʱ�����
	lt = localtime(&t);//תΪʱ��ṹ��
	printf("%d/%d/%d %d:%d:%d\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
	a[i].ti.ye = lt->tm_year + 1900;
	a[i].ti.mo = lt->tm_mon;
	a[i].ti.md = lt->tm_mday;
	a[i].ti.ho = lt->tm_hour;
	a[i].ti.mi = lt->tm_min;
	a[i].ti.se = lt->tm_sec;

}
//Ǯ�������ṹ�庯�� 
float moneychange(float n)
{
	int nn = n * 100;
	money1.yuan = nn / 100;
	money1.jiao = nn / 10 % 10;
	money1.fen = nn % 10;
	printf("Ԫ:%d  ", money1.yuan);
	printf("��:%d  ", money1.jiao);
	printf("��:%d  ", money1.fen);
	return 0;
}
//Ǯ�������ṹ�庯�� 
float changemoney()
{
	printf("Ԫ:");
	scanf("%d", &money1.yuan);
	//printf("\n");
	printf("��:");
	scanf("%d", &money1.jiao);
	while (money1.jiao >= 10) {
		printf("������һ��������9������\n");
		printf("��:");
		scanf("%d", &money1.jiao);
	}
	//printf("\n");
	printf("��:");
	scanf("%d", &money1.fen);
	while (money1.fen >= 10) {
		printf("������һ��������9������\n");
		printf("��:");
		scanf("%d", &money1.fen);
	}
	float money_nu;
	return money1.yuan * 1 + money1.jiao*0.1 + money1.fen*0.01;
}
//�ܲ�ѯ���� 
int search() {
	while (1)
	{
		system("CLS");
		printf("\n\n\n");
		printf("           ____________________________________________________________________________________________\n");
		printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
		printf("          | ----------------------------------------------------------------------------------------- | \n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 1.��  Ա  ��  Ϣ                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 2.��  ��  ��  Ϣ                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 3.��  ��  ��  ��  ѯ                                  | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 4.��          ��                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | ----------------------------------------------------------------------------------------- |\n");
		printf("          |___________________________________________________________________________________________|\n");
		printf("���������蹦�����");
		int n;
		scanf("%d", &n);
		if (n == 1)
			vip1();
		else if (n == 2)
			search2();
		else if (n == 3)
			search3();
		else if (n == 4)
		{
			system("CLS");
			printf("\n\n\n");
			printf("           ____________________________________________________________________________________________\n");
			printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
			printf("          | ----------------------------------------------------------------------------------------- | \n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 1.��  ��  ��  Ϣ                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 2.��  ѯ  ��  Ϣ                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 3.��  ��  ��  Ϣ                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 4.  ��  Ա  ��                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | ----------------------------------------------------------------------------------------- |\n");
			printf("          |___________________________________________________________________________________________|\n");
			printf("���������蹦�����\n");
			printf("����0�Խ���\n");
			return 4;
		}
		else
			printf("error");
	}
}
//�ܹ�����Ϣ���� 
int xg() {
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.��  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.��  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.ɾ  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.��          ��                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	int n;
	while (1) {
		printf("���������蹦�����");
		scanf("%d", &n);
		if (n == 1)
			xg1();
		else if (n == 2)
			xg2();
		else if (n == 3)
			xg3();
		else if (n == 4)
		{
			system("CLS");
			printf("\n\n\n");
			printf("           ____________________________________________________________________________________________\n");
			printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
			printf("          | ----------------------------------------------------------------------------------------- | \n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 1.��  ��  ��  Ϣ                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 2.��  ѯ  ��  Ϣ                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 3.��  ��  ��  Ϣ                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 4.  ��  Ա  ��                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | ----------------------------------------------------------------------------------------- |\n");
			printf("          |___________________________________________________________________________________________|\n");
			printf("���������蹦�����\n");
			printf("����0�Խ���\n");
			return 4;
		}
		else if (n == 5)
			continue;
		else
			printf("error");
	}
}
//������Ϣ���� 
void work() {
	int cp, i2, i1;
	FILE *fp = fopen("F:\\work.txt", "w");
	for (cp = 0; cp<i; cp++) {
		if (a[cp].pay_by == 1)
		{
			fprintf(fp, "%d  %d/%d/%d %d:%d:%d  %d %d %f %f %f\n", a[cp].num,
				a[cp].ti.ye, a[cp].ti.mo, a[cp].ti.md, a[cp].ti.ho, a[cp].ti.mi, a[cp].ti.se,
				a[cp].pay_by, a[cp].buynumber, a[cp].allmoney, a[cp].change, a[cp].money_rec);
			for (i1 = 0; i1<a[cp].buynumber; i1++)
			{
				fprintf(fp, "%d %d %f\n", a[cp].c[i1].fruitnum, a[cp].c[i1].type_numb, a[cp].c[i1].cost);
			}

		}
		if (a[cp].pay_by == 0)
		{
			fprintf(fp, "%d  %d/%d/%d %d:%d:%d  %d %d %f %s %f\n", a[cp].num,
				a[cp].ti.ye, a[cp].ti.mo, a[cp].ti.md, a[cp].ti.ho, a[cp].ti.mi, a[cp].ti.se,
				a[cp].pay_by, a[cp].buynumber, a[cp].allmoney, a[cp].id, a[cp].before);
			fprintf(fp, "%d %d %f\n", a[cp].c[i1].fruitnum, a[cp].c[i1].type_numb, a[cp].c[i1].cost);
		}
	}
	fclose(fp);
	FILE *kp = fopen("F:\\VIP1.txt", "w");
	for (i2 = 0; i2<nnp; i2++)
	{
		fprintf(kp, "%s %f\n", vip[i2].name, vip[i2].restmoney);
	}
	fclose(kp);
	printf("�������");
	printf("��������Է���\n");
	getchar();
	getchar();
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.��  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.��  ѯ  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.��  ��  ��  Ϣ                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.  ��  Ա  ��                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	printf("���������蹦�����\n");
	printf("����0�Խ���\n");

}
//������ 
int main()
{
	FILE *kj = fopen("F:\\VIP1.txt", "r");
	while (!feof(kj))
	{
		fscanf(kj, "%s %f", vip[nnp].name, &vip[nnp].restmoney);
		nnp++;
	}
	nnp--;
	for (nnx = 0; nnx < nnp; nnx++)
	{
		e[nnx] = vip[nnx].restmoney;
	}
	printf("\n");
	printf("\n");
	printf("			          *-----------��ӭʹ��ˮ�����й���ϵͳ-------------*				");
	printf("\n");
	system("pause");
	{system("CLS");
	printf("\n");
	printf("\n");
	printf("                                *------------------ˮ����Ϣ¼��------------------*                \n");
	int i;
	for (i = 0; i<5; i++)
	{
		char fruitname[10];
		printf("������ˮ�����ƣ�");
		if (i != 0)getchar();
		gets_s(b[i].type);
		printf("������ˮ��������ʽ����1.�2.�䣬3.��)\n");
		scanf("%d", &b[i].selltype);
		while (b[i].selltype>3) {
			printf("������������������¼��");
			printf("������ˮ��������ʽ����1.�2.�䣬3.��)\n");
			scanf("%d", &b[i].selltype);
		}
		printf("�����뵥�ۣ�\n");
		b[i].per_price = changemoney();
		printf("\n");
	}
	printf("				�����������ϵͳ					\n");
	getchar();
	}
	{
		system("CLS");
		printf("\n\n\n");
		printf("           ____________________________________________________________________________________________\n");
		printf("          |                                   ˮ�����й���ϵͳ                                        |\n");
		printf("          | ----------------------------------------------------------------------------------------- | \n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 1.��  ��  ��  Ϣ                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 2.��  ѯ  ��  Ϣ                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 3.��  ��  ��  Ϣ                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 4.  ��  Ա  ��                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | ----------------------------------------------------------------------------------------- |\n");
		printf("          |___________________________________________________________________________________________|\n");
		printf("���������蹦�����\n");
		printf("����0�Խ���\n");
		int n;
		while (1)
		{
			scanf("%d", &n);
			if (n == 0)
				break;
			else if (n == 1)
				xg();
			else if (n == 2)
				search();
			else if (n == 3)
				work();
			else if (n == 4)
				lvip();
			else
				printf("error");
		}
		printf("ллʹ��");
	}
}
