#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20  //线性表存储空间的初始分配量
#define OK 1    
#define ERROR 0 

//typedef int Status;	//Status是函数的类型，其值是函数结果状态代码，如OK等
int j;

typedef struct
{
	int *elem;
	int length;
} List;  //类型type 
//初始化 --动态发呢配 使elem指向这段空间基地址 
int InitList(List &L)
{
	L.elem = new int[MAXSIZE];
	if(!L.elem) exit(0);
	L.length = 0;
	return OK;
}
/*取值
	判断指定位置是否合理 不合理 返回ERR；
	若合理，则将i个数据元素赋给e，通过e返回第i个元素取值 
*/ 
int GetElem(List L,int i,int &e)
{
	if(i < 1||i>L.length) return ERROR;
	
	e = L.elem[i-1];
	return OK;
}
/*查找
	若查找成功，返回序号i+1；查找失败，返回0； 
*/
int FindElem(List &L,int i,int e) 
{
	for(i = 0;i < L.length;i++)
	{
		if(L.elem[i] == e) return i+1;
	}
	return 0;
}
/*插入 
	判断位置是否合法 不合法返回ERR
	判断是否已满，满返回ERR
	将n至i的元素依次向后移动1个位置，空出第i个位置
	将e插入i位置 表长+1 
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
/*删除
	判断删除位置是否合法 不合法返回ERR
	将第i+1个至第n个元素依次向前移动一个位置(i=n时无需移动)
	表长减1 
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
/*首先，我们定义一个变量j来记录符合条件的元素的个数。
然后，我们遍历线性表中的每个元素，如果元素的值大于min并且小于max，则跳过该元素。
否则，我们将该元素赋值给L.elem[j]，并将j增加1。
最后，我们更新线性表的长度为j，即为符合条件的元素个数。
最后，我们返回OK表示删除成功。*/
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

/*打印线性表中的所有元素*/
void Print(List L){
    printf("当前顺序表的长度:%d\n", L.length);
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
