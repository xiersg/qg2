#include "F.h"

struct lb2 {//˫������
	int val;
	struct lb2* prev;
	struct lb2* next;
};

int main()
{
	//��һ������
	int nums[] = { 1,3,2,4,6,9,5,43,5,0 };
	int m = 10;
	//��ʼ��ͷ�ڵ�ָ��
	struct lb2* head = NULL;

	//��������
	for (int i = 0; i < m; i++) {
		head = lb2_add(head, nums[i]);
	}

	lb2_print(head);//��ӡ�鿴����

	lb2_remove(&head, 1);
	lb2_print(head);//��ӡ�鿴����

	lb2_remove(&head, 9);
	lb2_print(head);//��ӡ�鿴����

	lb2_insert(&head, 123, 4);
	lb2_print(head);

	return 0;
}
