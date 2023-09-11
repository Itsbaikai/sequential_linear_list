#include <stdio.h>
#include <iostream>
#define OK 1
#define ERROR 0
using namespace std;
typedef int Status;
//���嵥����Ľṹ����
typedef int ElemType;
//------������Ĵ洢�ṹ-----// 
typedef struct LNode
{
	ElemType data;	     //����������
	struct LNode *next;	//����ָ����ָ����һ��ָ�� 
 }LNode,*LinkList;      // LNode�ǽ�㣬LinkList������LinkListΪָ��ṹ��LNode��ָ������ 
 
//------������ĳ�ʼ��-----//
  //���㷨���衿//
	//1.�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ��㡣
	//2.ͷ����ָ�����ÿա�
Status InitList(LinkList &L)
{
	//����һ���յĵ�����L
	L=new LNode;      //�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���  ��L=(LinkList)malloc(sizeof(LNode))
	L->next=NULL;     //ͷ����ָ�����ÿ�
	return OK; 
} 
 
//------��巨����������-----//
  //���㷨���衿//
	//1.����һ��ֻ��ͷ���Ŀ�����
	//2.βָ��r��ʼ����ָ��ͷ��㡣 
	//3.���ݴ������������Ԫ�ظ���n,ѭ��n��ִ�����²�����
	   //����һ���½��*P�� 
	   //����Ԫ��ֵ�����½��*p��������
	   //���½��*p���뵽β���*r֮��
	   //βָ��rָ���µ�β���*p�� 
void CreateList_R(LinkList &L,int n)
{
	//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
	L=new LNode;      //��L=(LinkList)malloc(sizeof(LNode))
	L->next=NULL;    //�Ƚ���һ����ͷ���Ŀ����� 	
	LinkList r=L;             //βָ��rָ��ͷ��� 
	for(int i=0;i<n;++i)
	{
		LinkList p=new LNode;  //�����½��*p
		cin>>p->data;  //����Ԫ��ֵ�����½��*p��������
		p->next=NULL;
		r->next=p;    //���½��*p���뵽β���*r֮�� 
		r=p;          //rָ���µ�β���*p 
	 }
 }
 
//------������Ĳ���-----//
  //���㷨���衿//
  //��ֵΪe���½����뵽��ĵ�i������λ���ϣ������뵽���ai-1��ai֮�䣬������������ͼ��ʾ���������£� 
	//1.���ҽ��ai-1����ָ��pָ��ý�㡣
	//2.����һ���½��*s�� 
	//3.���½��*s����������Ϊe�� 
	//4.���½��*s��ָ����ָ����ai��
	//5.�����*p��ָ����ָ���½��*s��
Status ListInsert(LinkList &L,int i,ElemType e)
{
	//�ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½�� 
	LinkList p=L;
	int j=0;
	while(p && (j<i-1)) 
	{
		p=p->next;   //���ҵ�i-1����㣬pָ��ý�� 
		++j;
	}
	if(!p||j>i-1) return ERROR;  //i>n+1����i<1
	LinkList s=new LNode;    //�����½��*s 
	s->data=e;		//�����*s����������Ϊe 
	s->next=p->next;//�����*s��ָ����ָ����ai 
	p->next=s;		//�����*p��ָ����ָ����*s 
	return OK; 	 
 }
 
//------��ʽ�����ĺϲ�-----//
  //���㷨���衿//
	//1.ָ��pa��pb��ʼ�����ֱ�ָ��LA��LB�ĵ�һ����㡣
	//2.LC�Ľ��ȡֵΪLA��ͷ��㡣 
	//3.ָ��pc��ʼ����ָ��LC��ͷ��㡣 
	//4.��ָ��pa��pb��δ������Ӧ��βʱ�������αȽ�pa��pb��ָ���Ԫ��ֵ����LA��LB��"ժȡ"Ԫ��ֵ��С�Ľ����뵽LC�����
	//5.���ǿձ��ʣ��β��뵽pc��ָ���֮��
	//6.�ͷ�LB��ͷ��㡣
void MergeList_L(LinkList &LA,LinkList &LB,LinkList &LC)
{
	//��֪������LA��LB��Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢LA��LB�õ��µĵ�����LC,LC��Ԫ��Ҳ��ֵ�ǵݼ�����
	LinkList pa=LA->next; LinkList pb=LB->next;	//pa��pb�ĳ�ֵ�ֱ�ָ��������ĵ�һ�����
	LC=LA;	                    //��LA��ͷ�����ΪLC��ͷ���
	LinkList pc=LC;                      //pc�ĳ�ֵָ��LC��ͷ���
	while(pa&&pb) 
	{
		//LA��LB��δ�����β������"ժȡ"������ֵ��С�Ľ����뵽LC�����
		if(pa->data<=pb->data)  //"ժȡ"pa��ָ��� 
		{
			pc->next=pa;		//��pa��ָ������ӵ�pc��ָ���֮�� 
			pc=pa;				//pcָ��pa 
			pa=pa->next;		//paָ����һ����� 
		}
		else
		{
			pc->next=pb;		//��pb��ָ������ӵ�pc��ָ���֮�� 
			pc=pb;				//pcָ��pb
			pb=pb->next;		//pbָ����һ����� 
		} 
	}
		pc->next=pa?pa:pb;
		delete LB;
 } 
 

//------��ӡ��������-----//  
void PrintList(LinkList L)
{	
	printf("��ǰ������������Ԫ��Ϊ��"); 
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
 
//------������������------//
void CreateList_LA(LinkList &L) 
{
	int n;
	printf("LA�ĳ��ȣ�");
	scanf("%d",&n);
	printf("����%d������",n);
	CreateList_R(L,n);
	PrintList(L);
}
void CreateList_LB(LinkList &L) 
{
	int n;
	printf("LB�ĳ��ȣ�");
	scanf("%d",&n);
	printf("����%d������",n);
	CreateList_R(L,n);
	PrintList(L);
}
void CreateList_LC(LinkList &L) 
{
	int n;
	printf("LC�ĳ��ȣ�");
	scanf("%d",&n);
	printf("������%d������",n);
	CreateList_R(L,n);
	PrintList(L);
}
 
 
//------������ϲ�����------//
void MergeList(LinkList LA,LinkList LB,LinkList LC)
{
	MergeList_L(LA,LB,LC);
	PrintList(LC);
}
 
//------������-----//
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
