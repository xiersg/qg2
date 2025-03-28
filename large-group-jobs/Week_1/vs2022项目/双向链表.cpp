#include "F.h"

struct lb2 {//双向链表
	int val;
	struct lb2* prev;
	struct lb2* next;
};

int main()
{
	//来一点数据
	int nums[] = { 1,3,2,4,6,9,5,43,5,0 };
	int m = 10;
	//初始化头节点指针
	struct lb2* head = NULL;

	//创建链表
	for (int i = 0; i < m; i++) {
		head = lb2_add(head, nums[i]);
	}

	lb2_print(head);//打印查看数据

	lb2_remove(&head, 1);
	lb2_print(head);//打印查看数据

	lb2_remove(&head, 9);
	lb2_print(head);//打印查看数据

	lb2_insert(&head, 123, 4);
	lb2_print(head);

	return 0;
}
