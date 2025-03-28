#include "F.h"

struct lb1; struct lb1 {//链表结构体
	int val;
	struct lb1* next;
}; 

int main()
{
	int nums[] = { 1,2,3,4,5,8,6,3,6,8 };
	int m = 10;

	struct lb1* head = NULL;//初始化头节点

	for (int i = 0; i < m; i++) {
		head = lb1_add(head, nums[i]);//头插入数据
	}
	lb1_print(head);//打印查看数据

	printf("\n\n尝试删除\n");
	lb1_remove(&head, 1);
	lb1_print(head);//打印查看数据

	lb1_remove(&head, 8);
	lb1_print(head);//打印查看数据

	printf("\n\n尝试插入\n");
	lb1_insert(&head, 123, 4);
	lb1_print(head);

	printf("\n\n尝试奇数和偶数对换\n");
	lb1_odd_even(head);
	lb1_print(head);

	printf("\n\n尝试找中点\n");
	struct lb1* mid = lb1_mid(head);
	printf("中点是 %d, 地址为%p", mid->val, mid);

	printf("\n\n尝试复制\n");
	struct lb1* head2 = lb1_copy(head);
	lb1_print(head2);

	printf("\n\n判断是不是环状");
	printf("%s\n", (lb1_pd(head) ? "yes": "no"));

	printf("\n\n尝试反转\n");
	struct lb1* head3 = lb1_copy2(head);
	lb1_print(head3);



	return 0;
}