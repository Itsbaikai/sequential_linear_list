#include <stdio.h>
#include <iostream>
#define OK 1
#define ERROR 0
using namespace std;
typedef int Status;
//定义单链表的结构类型
typedef int ElemType;
//------单链表的存储结构-----// 
typedef struct LNode
{
	ElemType data;	     //结点的数据域
	struct LNode *next;	//结点的指针域，指向下一个指针 
 }LNode,*LinkList;      // LNode是结点，LinkList是链表，LinkList为指向结构体LNode的指针类型 
 
//------单链表的初始化-----//
  //【算法步骤】//
	//1.生成新结点作为头结点，用头指针L指向头结点。
	//2.头结点的指针域置空。
Status InitList(LinkList &L)
{
	//构造一个空的单链表L
	L=new LNode;      //生成新结点作为头结点，用头指针L指向头结点  或L=(LinkList)malloc(sizeof(LNode))
	L->next=NULL;     //头结点的指针域置空
	return OK; 
} 
 
//------后插法创建单链表-----//
  //【算法步骤】//
	//1.创建一个只有头结点的空链表。
	//2.尾指针r初始化，指向头结点。 
	//3.根据创建链表包括的元素个数n,循环n次执行以下操作：
	   //生成一个新结点*P； 
	   //输入元素值赋给新结点*p的数据域；
	   //将新结点*p插入到尾结点*r之后；
	   //尾指针r指向新的尾结点*p。 
void CreateList_R(LinkList &L,int n)
{
	//正位序输入n个元素的值，建立带表头结点的单链表L
	L=new LNode;      //或L=(LinkList)malloc(sizeof(LNode))
	L->next=NULL;    //先建立一个带头结点的空链表 	
	LinkList r=L;             //尾指针r指向头结点 
	for(int i=0;i<n;++i)
	{
		LinkList p=new LNode;  //生成新结点*p
		cin>>p->data;  //输入元素值赋给新结点*p的数据域
		p->next=NULL;
		r->next=p;    //将新结点*p插入到尾结点*r之后 
		r=p;          //r指向新的尾结点*p 
	 }
 }
 
//------单链表的插入-----//
  //【算法步骤】//
  //将值为e的新结点插入到表的第i个结点的位置上，即插入到结点ai-1与ai之间，具体插入过程如图所示，步骤如下： 
	//1.查找结点ai-1并由指针p指向该结点。
	//2.生成一个新结点*s。 
	//3.将新结点*s的数据域置为e。 
	//4.将新结点*s的指针域指向结点ai。
	//5.将结点*p的指针域指向新结点*s。
Status ListInsert(LinkList &L,int i,ElemType e)
{
	//在带头结点的单链表L中第i个位置插入值为e的新结点 
	LinkList p=L;
	int j=0;
	while(p && (j<i-1)) 
	{
		p=p->next;   //查找第i-1个结点，p指向该结点 
		++j;
	}
	if(!p||j>i-1) return ERROR;  //i>n+1或者i<1
	LinkList s=new LNode;    //生成新结点*s 
	s->data=e;		//将结点*s的数据域置为e 
	s->next=p->next;//将结点*s的指针域指向结点ai 
	p->next=s;		//将结点*p的指针域指向结点*s 
	return OK; 	 
 }
 
//------链式有序表的合并-----//
  //【算法步骤】//
	//1.指针pa和pb初始化，分别指向LA和LB的第一个结点。
	//2.LC的结点取值为LA的头结点。 
	//3.指针pc初始化，指向LC的头结点。 
	//4.当指针pa和pb均未到达相应表尾时，则依次比较pa和pb所指向的元素值，从LA或LB中"摘取"元素值较小的结点插入到LC的最后。
	//5.将非空表的剩余段插入到pc所指结点之后。
	//6.释放LB的头结点。
void MergeList_L(LinkList &LA,LinkList &LB,LinkList &LC)
{
	//已知单链表LA和LB的元素按值非递减排列
	//归并LA和LB得到新的单链表LC,LC的元素也按值非递减排列
	LinkList pa=LA->next; LinkList pb=LB->next;	//pa和pb的初值分别指向两个表的第一个结点
	LC=LA;	                    //用LA的头结点作为LC的头结点
	LinkList pc=LC;                      //pc的初值指向LC的头结点
	while(pa&&pb) 
	{
		//LA和LB均未到达表尾，依次"摘取"两表中值较小的结点插入到LC的最后
		if(pa->data<=pb->data)  //"摘取"pa所指结点 
		{
			pc->next=pa;		//将pa所指结点链接到pc所指结点之后 
			pc=pa;				//pc指向pa 
			pa=pa->next;		//pa指向下一个结点 
		}
		else
		{
			pc->next=pb;		//将pb所指结点链接到pc所指结点之后 
			pc=pb;				//pc指向pb
			pb=pb->next;		//pb指向下一个结点 
		} 
	}
		pc->next=pa?pa:pb;
		delete LB;
 } 
 

//------打印单链表函数-----//  
void PrintList(LinkList L)
{	
	printf("当前单链表中所有元素为："); 
	LinkList p=L->next;
	if(p==NULL) return;
	else
	{
		while(p!=NULL)
		{	
			if(p->next==NULL)
			{
				printf("%d",p->data);
			}
			else
			{
				printf("%d ",p->data);
			}
			p=p->next;
		}	
	}
	printf("\n");
} 
 
//------创建单链表函数------//
void CreateList_LA(LinkList &L) 
{
	int n;
	printf("LA的长度：");
	scanf("%d",&n);
	printf("输入%d个数：",n);
	CreateList_R(L,n);
	PrintList(L);
}
void CreateList_LB(LinkList &L) 
{
	int n;
	printf("LB的长度：");
	scanf("%d",&n);
	printf("输入%d个数：",n);
	CreateList_R(L,n);
	PrintList(L);
}
void CreateList_LC(LinkList &L) 
{
	int n;
	printf("LC的长度：");
	scanf("%d",&n);
	printf("请输入%d个数：",n);
	CreateList_R(L,n);
	PrintList(L);
}
 
 
//------单链表合并函数------//
void MergeList(LinkList LA,LinkList LB,LinkList LC)
{
	MergeList_L(LA,LB,LC);
	PrintList(LC);
}
 
//------主函数-----//
int main()
{	
	int n;
	LinkList LA,LB,LC; 
	InitList(LA);
	InitList(LB);
	InitList(LC);
	CreateList_LA(LA);
	CreateList_LB(LB);
	printf("LC");
	MergeList(LA,LB,LC);
 } 
