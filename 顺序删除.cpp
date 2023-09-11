#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20  //���Ա�洢�ռ�ĳ�ʼ������
#define OK 1    
#define ERROR 0 

//typedef int Status;	//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��
int j;

typedef struct
{
	int *elem;
	int length;
} List;  //����type 
//��ʼ�� --��̬������ ʹelemָ����οռ����ַ 
int InitList(List &L)
{
	L.elem = new int[MAXSIZE];
	if(!L.elem) exit(0);
	L.length = 0;
	return OK;
}
/*ȡֵ
	�ж�ָ��λ���Ƿ���� ������ ����ERR��
	��������i������Ԫ�ظ���e��ͨ��e���ص�i��Ԫ��ȡֵ 
*/ 
int GetElem(List L,int i,int &e)
{
	if(i < 1||i>L.length) return ERROR;
	
	e = L.elem[i-1];
	return OK;
}
/*����
	�����ҳɹ����������i+1������ʧ�ܣ�����0�� 
*/
int FindElem(List &L,int i,int e) 
{
	for(i = 0;i < L.length;i++)
	{
		if(L.elem[i] == e) return i+1;
	}
	return 0;
}
/*���� 
	�ж�λ���Ƿ�Ϸ� ���Ϸ�����ERR
	�ж��Ƿ�������������ERR
	��n��i��Ԫ����������ƶ�1��λ�ã��ճ���i��λ��
	��e����iλ�� ��+1 
*/
int InsertElem(List &L,int i,int e)
{
	if(i < 1||i>(L.length+1)) return ERROR;
	if(L.length == MAXSIZE) return ERROR;
	for(j = L.length-1;j > i;j--)
	{
		L.elem[j+1] = L.elem[j];
	}
	L.elem[i-1]=e;
	L.length+=1;
	return OK;
}
/*ɾ��
	�ж�ɾ��λ���Ƿ�Ϸ� ���Ϸ�����ERR
	����i+1������n��Ԫ��������ǰ�ƶ�һ��λ��(i=nʱ�����ƶ�)
	����1 
*/
//int DelList(List &L,int min,int max)
//{
////	if(i < 1||i>(L.length+1)) return ERROR;
//	for(j = 1;j < L.length;j++)
//	{
//		if(L.elem[j]>min && L.elem[j]<max){
//			L.elem[j-1] = L.elem[j];
//		}
//	}
//	L.length-=1;
//	return OK;
//}
/*���ȣ����Ƕ���һ������j����¼����������Ԫ�صĸ�����
Ȼ�����Ǳ������Ա��е�ÿ��Ԫ�أ����Ԫ�ص�ֵ����min����С��max����������Ԫ�ء�
�������ǽ���Ԫ�ظ�ֵ��L.elem[j]������j����1��
������Ǹ������Ա�ĳ���Ϊj����Ϊ����������Ԫ�ظ�����
������Ƿ���OK��ʾɾ���ɹ���*/
int DelList(List &L, int min, int max) {
	int j = 0;
	for (int i = 0; i < L.length; i++) {
	if (L.elem[i] > min && L.elem[i] < max) {
		continue;
		}
		L.elem[j] = L.elem[i];
		j++;
	}
	L.length = j;
	return OK;
}

/*��ӡ���Ա��е�����Ԫ��*/
void Print(List L){
    printf("��ǰ˳���ĳ���:%d\n", L.length);
    for(int i = 0; i < L.length; i++){
        printf("%d ",L.elem[i]);
    }
    printf("\n");
}

int main()
{
	List L;
	InitList(L);
	InsertElem(L,1,3);InsertElem(L,2,8);
	InsertElem(L,3,11);InsertElem(L,4,25);
	InsertElem(L,5,17);InsertElem(L,6,77);
	InsertElem(L,7,13);InsertElem(L,8,65);
	InsertElem(L,9,52);InsertElem(L,10,33);
	Print(L);
	DelList(L,15,35);
	Print(L);
}
