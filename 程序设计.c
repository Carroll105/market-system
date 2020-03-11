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
//程序统一量与函数 
struct fruit {
	char type[10];//种类
	int selltype;//出卖方式 
	float per_price;//单价
}b[5];//定义水果结构体 
struct time {
	int ye;
	int mo;
	int md;
	int ho;
	int mi;
	int se;
};//本地时间结构体 
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
}money1;//钱结构体 
struct vip_type {
	char name[5];
	float restmoney;
}vip[50];//vip的结构体 
struct fruit1 {
	int type_numb;
	float fruitnum;
	float cost;
}c[5];//水果出卖方式 
struct list {
	int num;//标识符
	struct time ti;//购买时间（系统时间）
	int pay_by; /* 1为现金 0为会员卡*/
	int buynumber;//购买种类数 
	struct fruit1 c[5];//购买水果信息 
	float allmoney; //总价 
	float change;//找零
	float money_rec;//收款
	char id[5];//会员卡号
	float before;//余额
	struct list *next;
}a[50];

int answer(struct list card);
//出卖方式显示函数 
int selltype1(struct fruit back)
{
	if (back.selltype == 1)
	{
		printf("单价为：一斤  ");
		moneychange(back.per_price);
	}
	if (back.selltype == 2)
	{
		printf("单价为：一箱  ");
		moneychange(back.per_price);
	}
	if (back.selltype == 3)
	{
		printf("单价为：一个  ");
		moneychange(back.per_price);
	}
	return 0;
}
//添加购物信息函数 
int xg1() {
	a[i].num = i + 1000;
	printf("账单号为：%d\n", a[i].num);
	printf("购买时间\n");
	nowtime();
	printf("请输入购买水果种类数\n");
	scanf("%d", &a[i].buynumber);
	if (a[i].buynumber>5) {
		printf("购买种数不得超过五种,请重新选择\n");
		return 0;
	}
	printf("1.%s\n2.%s\n3.%s\n4.%s\n5.%s\n", b[0].type, b[1].type, b[2].type, b[3].type, b[4].type);
	int i0 = 0;
	while (i0<a[i].buynumber)
	{
		printf("请输入购买的第%d种水果\n", i0 + 1);
		scanf("%d", &a[i].c[i0].type_numb);
		printf("\n");
		selltype1(b[i0]);
		printf("请输入购买的这种水果的数量\n");
		scanf("%f", &a[i].c[i0].fruitnum);
		printf("该水果总价为\n");
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
	printf("以上水果的总价为:\n");
	float kk = a[i].allmoney;
	moneychange(kk);
	printf("请输入购买方式(0为会员卡，1为现金)\n");
	scanf("%d", &a[i].pay_by);
	if (a[i].pay_by)
	{
		printf("请输入收款\n");
		a[i].money_rec = changemoney();
		if (a[i].money_rec>1000) {
			printf("超过限额，无法交易！\n");
			int n = a[i].num - 1000;
			a[n].num = -1;
		}

		else {
			a[i].change = a[i].money_rec - kk;
			if (a[i].change<0)
			{
				a[i].change = -a[i].change;
				printf("本次交易超市亏损，亏了：\n");
				moneychange(a[i].change);
				a[i].change = -a[i].change;
			}
			else
			{
				printf("找零:\n");
				moneychange(a[i].change);
			}
		}
	}
	else
	{
		vip2();
	}
	printf("录入完成\n");
	printf("摁任意键以继续");
	getchar();
	getchar();
	i++;
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   水果超市管理系统                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.增  加  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.修  改  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.删  除  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.返          回                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	return 5;
}
//修改 信息函数 
int xg2() {
	int j;
	printf("请输入要修改的信息号\n");
	int t;
	scanf("%d", &t);
	while (t<1000 || a[t - 1000].num == -1 || t >= i + 1000) {
		printf("修改的信息不存在，请重新输入。或者输入0以结束该功能。\n");
		printf("请输入要修改的信息号\n");
		scanf("%d", &t);
		if (t == 0) {
			printf("\n\n");
			printf("现在请重新输入功能。\n");
			return 0;
		}

	}
	j = t - 1000;

	printf("购买时间\n");
	nowtime();
	printf("请输入购买水果种类数\n");
	scanf("%d", &a[j].buynumber);
	printf("1.%s\n2.%s\n3.%s\n4.%s\n5.%s\n", b[0].type, b[1].type, b[2].type, b[3].type, b[4].type);
	int i0 = 0;
	while (i0<a[j].buynumber)
	{
		printf("请输入购买的第%d种水果", i0 + 1);
		scanf("%d", &a[j].c[i0].type_numb);
		printf("\n");
		selltype1(b[i0]);
		printf("请输入购买的这种水果的数量\n");
		scanf("%f", &a[j].c[i0].fruitnum);
		printf("该水果总价为\n");
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
	printf("以上水果的总价为:\n");
	float kk = a[j].allmoney;
	moneychange(kk);
	printf("请输入购买方式(0为会员卡，1为现金)\n");
	scanf("%d", &a[j].pay_by);
	if (a[j].pay_by)
	{
		printf("请输入收款\n");
		a[j].money_rec = changemoney();

		printf("找零:\n");
		a[j].change = a[j].money_rec - kk;
		moneychange(a[j].change);
	}
	else
	{
		vip2();
	}

	printf("修改完成\n");
	printf("摁任意键以继续");
	getchar();
	getchar();
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   水果超市管理系统                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.增  加  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.修  改  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.删  除  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.返          回                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	return 5;
}
//删除 信息函数 
int xg3() {
	int n = 0, j, p;
	printf("请输入要删除的信息号\n");
	scanf("%d", &p);
	while (p<1000 || a[p - 1000].num == -1 || p >= i + 1000) {
		printf("修改的信息不存在，请重新输入。或者输入0以结束该功能。\n");
		printf("请输入要修改的信息号\n");
		scanf("%d", &p);
		if (p == 0) {
			printf("\n\n");
			printf("现在请重新输入功能。\n");
			return 0;
		}

	}
	n = p - 1000;
	a[n].num = -1;
	printf("删除完成\n");
	printf("摁任意键以继续");
	getchar();
	getchar();
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   水果超市管理系统                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.增  加  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.修  改  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.删  除  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.返          回                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	return 5;
}
int vip3();
int vip4();
//vip总函数 
int lvip() {
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   水果超市管理系统                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.办  会  员  卡                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.会 员 卡 充 值                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.   返   回                                          | |\n");
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
			printf("          |                                   水果超市管理系统                                        |\n");
			printf("          | ----------------------------------------------------------------------------------------- | \n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 1.管  理  信  息                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 2.查  询  信  息                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 3.保  存  信  息                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 4.  会  员  卡                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | ----------------------------------------------------------------------------------------- |\n");
			printf("          |___________________________________________________________________________________________|\n");
			printf("请输入所需功能序号");
			return 0;
		}
	}
	return 0;
}
//vip查询函数 
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
		printf("请输入会员卡号：\n");

		scanf("%s", vipname);
		int cc = 0;
		for (i = 0; i<n; i++)
		{
			if (strcmp(vipname, vip[i].name) == 0)
			{
				cc = 1;
				printf("会员卡号为：%s    \n余额为：\n", vip[i].name);
				moneychange(vip[i].restmoney);
				printf("会员卡当日消费为:\n");
				moneychange(e[i] - vip[i].restmoney);
			}
		}
		if (cc == 0)
		{
			printf("无该会员卡信息，请选择0.返回。1.检查后重新输入！\n");
			scanf("%d", &j);
		}
		else
			j = 0;

	}
	printf("按任意键以返回\n");
	getchar();
	getchar();
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   水果超市管理系统                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.管  理  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.查  询  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.保  存  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.  会  员  卡                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	printf("请输入所需功能序号");
	return 0;
}
//vip消费函数 
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
	printf("请输入会员卡号：\n");
	getchar();
	gets_s(vipname);
	int b = 0;
	for (i2 = 0; i2<n; i2++)
		if (strcmp(vipname, vip[i2].name) == 0)
		{
			printf("会员卡原余额为:\n");
			strcpy(a[i].id, vip[i2].name);
			moneychange(vip[i2].restmoney);
			vip[i2].restmoney = vip[i2].restmoney - a[i2].allmoney;
			printf("会员卡现余额为：\n");
			moneychange(vip[i2].restmoney);
			a[i].before = vip[i2].restmoney;
			b = 1;
		}
	if (b == 0) {
		printf("没有该会员\n");
	}
	FILE *kp = fopen("F:\\VIP1.txt", "w");
	for (i2 = 0; i2<n; i2++)
	{
		fprintf(kp, "%s %f\n", vip[i2].name, vip[i2].restmoney);
	}
	fclose(kp);
	return 0;
}
//vip办卡函数 
int vip3()
{
	char vip_name[5];
	int yy, bb, x;
	printf("请问你是否办卡：(1.是   2.否)\n");
	scanf("%d", &yy);
	if (yy == 1)
	{
		printf("请输入办的会员卡号：\n");
		for (;;)
		{
			x = 1;
			scanf("%s", vip_name);
			int i = 0;
			for (; i < nnp; i++)
			{
				if (strcmp(vip[i].name, vip_name) == 0)
				{
					printf("会员卡号重复,请输入新的卡号：\n");
					x = 0;
				}
			}
			if (x == 1) break;
		}
		strcpy(vip[nnp ].name, vip_name);
		printf("请输入交费的会员卡金额:\n");
		vip[nnp].restmoney = changemoney();
		nnp++;
		printf("缴费成功");
		FILE *kp = fopen("F:\\VIP1.txt", "w");
		int i2;
		for (i2 = 0; i2<nnp; i2++)
		{
			fprintf(kp, "%s %f\n", vip[i2].name, vip[i2].restmoney);
		}
		fclose(kp);
		printf("按任意键以返回\n");
		getchar();
		getchar();
		system("CLS");
		printf("\n\n\n");
		printf("           ____________________________________________________________________________________________\n");
		printf("          |                                   水果超市管理系统                                        |\n");
		printf("          | ----------------------------------------------------------------------------------------- | \n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 1.管  理  信  息                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 2.查  询  信  息                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 3.保  存  信  息                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 4.  会  员  卡                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | ----------------------------------------------------------------------------------------- |\n");
		printf("          |___________________________________________________________________________________________|\n");
		printf("请输入所需功能序号");
		return 0;

	}
	if (yy == 2)
	{
		system("CLS");
		printf("\n\n\n");
		printf("           ____________________________________________________________________________________________\n");
		printf("          |                                   水果超市管理系统                                        |\n");
		printf("          | ----------------------------------------------------------------------------------------- | \n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 1.管  理  信  息                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 2.查  询  信  息                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 3.保  存  信  息                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 4.  会  员  卡                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | ----------------------------------------------------------------------------------------- |\n");
		printf("          |___________________________________________________________________________________________|\n");
		printf("请输入所需功能序号");
		return 0;
	}
}
//vip充值函数 
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
	printf("请输入会员卡号：\n");
	getchar();
	gets_s(vipname);
	int b = 0;
	for (i2 = 0; i2<n; i2++)
		if (strcmp(vipname, vip[i2].name) == 0)
		{
			printf("会员卡原余额为:\n");
			strcpy(a[i].id, vip[i2].name);
			moneychange(vip[i2].restmoney);
			printf("请输入充值费用:\n");
			vv = changemoney();
			vip[i2].restmoney = vip[i2].restmoney + vv;
			e[i2]=vip[i2].restmoney;
			printf("会员卡现余额为：\n");
			moneychange(vip[i2].restmoney);
			a[i].before = vip[i2].restmoney;
			b = 1;
		}
	if (b == 0) {
		printf("没有该会员\n");
	}
	FILE *kp = fopen("F:\\VIP1.txt", "w");
	for (i2 = 0; i2<n; i2++)
	{
		fprintf(kp, "%s %.2lf\n", vip[i2].name, vip[i2].restmoney);
	}
	fclose(kp);
	printf("按任意键以返回\n");
	getchar();
	getchar();
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   水果超市管理系统                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.管  理  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.查  询  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.保  存  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.  会  员  卡                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	printf("请输入所需功能序号");
	return 0;
}
//返回查询函数 
int search23() {
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   水果超市管理系统                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.会  员  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.购  买  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.按  条  件  查  询                                  | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.返          回                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	printf("请输入所需功能序号");
	return 0;
}
//所有信息输出函数 
int search22() {
	int mm;
	for (mm = 0; mm<i; mm++)
	{
		if (a[mm].num != -1)
			answer(a[mm]);
	}
	printf("按任意键以返回\n");
	getchar();
	getchar();
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   水果超市管理系统                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.逐  条  查  询                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.全  部  输  出                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.返          回                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                                                                       | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	printf("请输入所需功能序号：\n");
	return 0;
}
//账单号查询函数 
int search21() {
	int mn, v;
	printf("请输入您想要查询的购买信息的账单号：\n");
	scanf("%d", &mn);
	v = mn - 1000;
	if (v<0 || a[v].num == -1 || v >= i)
	{
		printf("抱歉，未能查到该条购买信息\n");
		printf("按任意键以返回\n");
		getchar();
		getchar();
		system("CLS");
		printf("\n\n\n");
		printf("           ____________________________________________________________________________________________\n");
		printf("          |                                   水果超市管理系统                                        |\n");
		printf("          | ----------------------------------------------------------------------------------------- | \n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 1.逐  条  查  询                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 2.全  部  输  出                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 3.返          回                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                                                                       | |\n");
		printf("          |                                                                                           |\n");
		printf("          | ----------------------------------------------------------------------------------------- |\n");
		printf("          |___________________________________________________________________________________________|\n");
		printf("请输入所需功能序号：\n");
		return 0;
	}
	else
	{
		answer(a[v]);
		printf("按任意键以返回\n");
		getchar();
		getchar();
		system("CLS");
		printf("\n\n\n");
		printf("           ____________________________________________________________________________________________\n");
		printf("          |                                   水果超市管理系统                                        |\n");
		printf("          | ----------------------------------------------------------------------------------------- | \n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 1.逐  条  查  询                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 2.全  部  输  出                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 3.返          回                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                                                                       | |\n");
		printf("          |                                                                                           |\n");
		printf("          | ----------------------------------------------------------------------------------------- |\n");
		printf("          |___________________________________________________________________________________________|\n");
		printf("请输入所需功能序号：\n");
	}
}
//简单查询总函数 
int search2() {
	int v, z;
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   水果超市管理系统                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.逐  条  查  询                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.全  部  输  出                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.返          回                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                                                                       | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	printf("请输入所需功能序号：\n");
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
			printf("          |                                   水果超市管理系统                                        |\n");
			printf("          | ----------------------------------------------------------------------------------------- | \n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 1.管  理  信  息                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 2.查  询  信  息                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 3.保  存  信  息                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 4.  会  员  卡                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | ----------------------------------------------------------------------------------------- |\n");
			printf("          |___________________________________________________________________________________________|\n");
			printf("请输入所需功能序号");
			return 0;
		}
		else
			printf("error\n");
	}
}
int search31();
int search32();
int search33();
//分类查询总函数 
int search3()
{
	while (1) {
		system("CLS");
		printf("\n\n\n");
		printf("           ____________________________________________________________________________________________\n");
		printf("          |                                   水果超市管理系统                                        |\n");
		printf("          | ----------------------------------------------------------------------------------------- | \n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 1.按  水  果   种  类  查  询                         | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 2.按  购  物  金  额  查  询                          | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 3.按  购  物  时  间  查  询                          | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 4.返           回                                     | |\n");
		printf("          |                                                                                           |\n");
		printf("          | ----------------------------------------------------------------------------------------- |\n");
		printf("          |___________________________________________________________________________________________|\n");
		printf("请输入所需功能序号");
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
			printf("          |                                   水果超市管理系统                                        |\n");
			printf("          | ----------------------------------------------------------------------------------------- | \n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 1.管  理  信  息                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 2.查  询  信  息                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 3.保  存  信  息                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 4.  会  员  卡                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | ----------------------------------------------------------------------------------------- |\n");
			printf("          |___________________________________________________________________________________________|\n");
			printf("请输入所需功能序号");
			return 4;
		}
		else
			printf("error\n");
	}

}
//水果种类查询函数 
int search31()
{
	printf("请输入您要查询的水果种类：\n");
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
	printf("水果目前总销售数量：%.2f\n", i4);
	printf("水果目前销售总金额:\n");
	moneychange(i5);
	printf("按任意键以返回\n");
	getchar();
	getchar();
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   水果超市管理系统                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.按  水  果   种  类  查  询                         | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.按  购  物  金  额  查  询                          | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.按  购  物  时  间  查  询                          | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.返           回                                     | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	printf("请输入所需功能序号");
	return 0;
}
int printf1(struct list *head);
//按购物金额链表检索函数 
int search32()
{
	int i7;
	int i8 = 0;
	float k1, k2;
	printf("请输入您要查询的购物金额下限与上限：\n");
	k1 = changemoney();
	printf("\n");
	k2 = changemoney();
	struct list *head = NULL;
	struct list *p1, *p2;
	p1 = p2 = (struct list*)malloc(LEN);
	for (i7 = 0; i7<i; i7++)
	{
		if (a[i7].allmoney >= k1 && a[i7].allmoney <= k2)//需要用到链表实现
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
//按时间查询函数链表实现 
int search33()
{
	int i8;
	printf("请选择您想要根据哪种形式查询：\n");
	printf("1.设开始与结束时间。2.只设开始时间。3.只设结束时间\n");
	scanf("%d", &i8);
	if (i8 == 1)
		search331();//需要用到比较时间函数，且用链表实现
	if (i8 == 2)
		search332();
	if (i8 == 3)
		search333();
	return 0;
}
//开始结束时间函数 
int search331()
{
	int i7;
	int i8 = 0;
	printf("请输入开始时间：\n");
	printf("小时：");
	scanf("%d", &tt[0].ho);
	printf("分钟：");
	scanf("%d", &tt[0].mi);
	printf("秒：");
	scanf("%d", &tt[0].se);
	printf("请输入结束时间：\n");
	printf("小时：");
	scanf("%d", &tt[1].ho);
	printf("分钟：");
	scanf("%d", &tt[1].mi);
	printf("秒：");
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
			)//需要用到链表实现
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
//开始时间函数 
int search332()
{
	int i7;
	int i8 = 0;
	printf("请输入开始时间：\n");
	printf("小时：");
	scanf("%d", &tt[0].ho);
	printf("分钟：");
	scanf("%d", &tt[0].mi);
	printf("秒：");
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
			)//需要用到链表实现(tt[0].md<=a[i7].ti.md)&&(tt[0].ho<=a[i7].ti.ho)&&(tt[0].mi<=a[i7].ti.mi)&&(tt[0].se<=a[i7].ti.se)
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
//结束时间函数 
int search333()
{
	int i7;
	int i8 = 0;
	printf("请输入结束时间：\n");
	printf("小时：");
	scanf("%d", &tt[1].ho);
	printf("分钟：");
	scanf("%d", &tt[1].mi);
	printf("秒：");
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
//打印输出函数 
int answer(struct list card)
{
	printf("标识符:%d\n", card.num);
	printf("购买时间:");
	printf("%d/%d/%d %d:%d:%d\n", card.ti.ye, card.ti.mo, card.ti.md, card.ti.ho, card.ti.mi, card.ti.se);
	int cn;
	for (cn = 0; cn<card.buynumber; cn++) {
		int kn = card.c[cn].type_numb - 1;
		printf("购买种类：");
		printf("%s", b[kn].type);
		printf("购买数量:%f\n", card.c[cn].fruitnum);
		printf("该水果总价:");
		moneychange(card.c[cn].cost);
		printf("本次购物的总价为：");
		moneychange(card.allmoney);
		printf("支付方式:%d\n", card.pay_by);
	}
	if (card.pay_by)
	{
		printf("收款:\n");
		moneychange(card.money_rec);
		printf("找零:\n");
		moneychange(card.change);

	}
	else
	{
		printf("会员卡号:%s\n", card.id);
		printf("会员卡原余额为：\n");
		moneychange(card.allmoney + card.before);
		printf("现余额:\n");
		moneychange(card.before);
	}
	printf("\n");
	return 5;
}
//打印输出结构体函数 
int printf1(struct list *head)
{
	struct list *p;
	p = head;
	if (head != NULL)
		do {
			printf("标识符:%d\n", p->num);
			printf("购买时间:");
			printf("%d/%d/%d %d:%d:%d\n", p->ti.ye, p->ti.mo, p->ti.md, p->ti.ho, p->ti.mi, p->ti.se);
			int cn;
			for (cn = 0; cn<p->buynumber; cn++) {
				int kn = p->c[cn].type_numb - 1;
				printf("购买种类：");
				printf("%s", b[kn].type);
				printf("购买数量:%f\n", p->c[cn].fruitnum);
				printf("该水果总价:");
				moneychange(p->c[cn].cost);
				printf("本次购物的总价为：");
				moneychange(p->allmoney);
				printf("支付方式:%d\n", p->pay_by);
			}
			if (p->pay_by)
			{
				printf("收款:\n");
				moneychange(p->money_rec);
				printf("找零:\n");
				moneychange(p->change);

			}
			else
			{
				printf("会员卡号:%s\n", p->id);
				printf("会员卡原余额为：\n");
				moneychange(p->allmoney + p->before);
				printf("现余额:\n");
				moneychange(p->before);
			}
			printf("\n");
			p = p->next;
		} while (p != NULL);
		return 0;
}
//本地时间函数 
void nowtime()
{
	int n;
	int year, mon, day, hour, sec;
	time_t t;
	struct tm * lt;
	time(&t);//获取Unix时间戳。
	lt = localtime(&t);//转为时间结构。
	printf("%d/%d/%d %d:%d:%d\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
	a[i].ti.ye = lt->tm_year + 1900;
	a[i].ti.mo = lt->tm_mon;
	a[i].ti.md = lt->tm_mday;
	a[i].ti.ho = lt->tm_hour;
	a[i].ti.mi = lt->tm_min;
	a[i].ti.se = lt->tm_sec;

}
//钱浮点数结构体函数 
float moneychange(float n)
{
	int nn = n * 100;
	money1.yuan = nn / 100;
	money1.jiao = nn / 10 % 10;
	money1.fen = nn % 10;
	printf("元:%d  ", money1.yuan);
	printf("角:%d  ", money1.jiao);
	printf("分:%d  ", money1.fen);
	return 0;
}
//钱浮点数结构体函数 
float changemoney()
{
	printf("元:");
	scanf("%d", &money1.yuan);
	//printf("\n");
	printf("角:");
	scanf("%d", &money1.jiao);
	while (money1.jiao >= 10) {
		printf("请输入一个不超过9的数字\n");
		printf("角:");
		scanf("%d", &money1.jiao);
	}
	//printf("\n");
	printf("分:");
	scanf("%d", &money1.fen);
	while (money1.fen >= 10) {
		printf("请输入一个不超过9的数字\n");
		printf("分:");
		scanf("%d", &money1.fen);
	}
	float money_nu;
	return money1.yuan * 1 + money1.jiao*0.1 + money1.fen*0.01;
}
//总查询函数 
int search() {
	while (1)
	{
		system("CLS");
		printf("\n\n\n");
		printf("           ____________________________________________________________________________________________\n");
		printf("          |                                   水果超市管理系统                                        |\n");
		printf("          | ----------------------------------------------------------------------------------------- | \n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 1.会  员  信  息                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 2.购  买  信  息                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 3.按  条  件  查  询                                  | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 4.返          回                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | ----------------------------------------------------------------------------------------- |\n");
		printf("          |___________________________________________________________________________________________|\n");
		printf("请输入所需功能序号");
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
			printf("          |                                   水果超市管理系统                                        |\n");
			printf("          | ----------------------------------------------------------------------------------------- | \n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 1.管  理  信  息                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 2.查  询  信  息                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 3.保  存  信  息                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 4.  会  员  卡                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | ----------------------------------------------------------------------------------------- |\n");
			printf("          |___________________________________________________________________________________________|\n");
			printf("请输入所需功能序号\n");
			printf("输入0以结束\n");
			return 4;
		}
		else
			printf("error");
	}
}
//总管理信息函数 
int xg() {
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   水果超市管理系统                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.增  加  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.修  改  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.删  除  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.返          回                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	int n;
	while (1) {
		printf("请输入所需功能序号");
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
			printf("          |                                   水果超市管理系统                                        |\n");
			printf("          | ----------------------------------------------------------------------------------------- | \n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 1.管  理  信  息                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 2.查  询  信  息                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 3.保  存  信  息                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | |                                 4.  会  员  卡                                      | |\n");
			printf("          |                                                                                           |\n");
			printf("          | ----------------------------------------------------------------------------------------- |\n");
			printf("          |___________________________________________________________________________________________|\n");
			printf("请输入所需功能序号\n");
			printf("输入0以结束\n");
			return 4;
		}
		else if (n == 5)
			continue;
		else
			printf("error");
	}
}
//保存信息函数 
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
	printf("保存完成");
	printf("按任意键以返回\n");
	getchar();
	getchar();
	system("CLS");
	printf("\n\n\n");
	printf("           ____________________________________________________________________________________________\n");
	printf("          |                                   水果超市管理系统                                        |\n");
	printf("          | ----------------------------------------------------------------------------------------- | \n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 1.管  理  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 2.查  询  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 3.保  存  信  息                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | |                                 4.  会  员  卡                                      | |\n");
	printf("          |                                                                                           |\n");
	printf("          | ----------------------------------------------------------------------------------------- |\n");
	printf("          |___________________________________________________________________________________________|\n");
	printf("请输入所需功能序号\n");
	printf("输入0以结束\n");

}
//主函数 
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
	printf("			          *-----------欢迎使用水果超市管理系统-------------*				");
	printf("\n");
	system("pause");
	{system("CLS");
	printf("\n");
	printf("\n");
	printf("                                *------------------水果信息录入------------------*                \n");
	int i;
	for (i = 0; i<5; i++)
	{
		char fruitname[10];
		printf("请输入水果名称：");
		if (i != 0)getchar();
		gets_s(b[i].type);
		printf("请输入水果出卖方式：（1.斤，2.箱，3.个)\n");
		scanf("%d", &b[i].selltype);
		while (b[i].selltype>3) {
			printf("输入数据有误，请重新录入");
			printf("请输入水果出卖方式：（1.斤，2.箱，3.个)\n");
			scanf("%d", &b[i].selltype);
		}
		printf("请输入单价：\n");
		b[i].per_price = changemoney();
		printf("\n");
	}
	printf("				按任意键进入系统					\n");
	getchar();
	}
	{
		system("CLS");
		printf("\n\n\n");
		printf("           ____________________________________________________________________________________________\n");
		printf("          |                                   水果超市管理系统                                        |\n");
		printf("          | ----------------------------------------------------------------------------------------- | \n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 1.管  理  信  息                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 2.查  询  信  息                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 3.保  存  信  息                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | |                                 4.  会  员  卡                                      | |\n");
		printf("          |                                                                                           |\n");
		printf("          | ----------------------------------------------------------------------------------------- |\n");
		printf("          |___________________________________________________________________________________________|\n");
		printf("请输入所需功能序号\n");
		printf("输入0以结束\n");
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
		printf("谢谢使用");
	}
}
