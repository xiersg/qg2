#include "F.h"

struct lb1; struct lb1 {//����ṹ��
	int val;
	struct lb1* next;
}; 

int main()
{
	int nums[] = { 1,2,3,4,5,8,6,3,6,8 };
	int m = 10;

	struct lb1* head = NULL;//��ʼ��ͷ�ڵ�

	for (int i = 0; i < m; i++) {
		head = lb1_add(head, nums[i]);//ͷ��������
	}
	lb1_print(head);//��ӡ�鿴����

	printf("\n\n����ɾ��\n");
	lb1_remove(&head, 1);
	lb1_print(head);//��ӡ�鿴����

	lb1_remove(&head, 8);
	lb1_print(head);//��ӡ�鿴����

	printf("\n\n���Բ���\n");
	lb1_insert(&head, 123, 4);
	lb1_print(head);

	printf("\n\n����������ż���Ի�\n");
	lb1_odd_even(head);
	lb1_print(head);

	printf("\n\n�������е�\n");
	struct lb1* mid = lb1_mid(head);
	printf("�е��� %d, ��ַΪ%p", mid->val, mid);

	printf("\n\n���Ը���\n");
	struct lb1* head2 = lb1_copy(head);
	lb1_print(head2);

	printf("\n\n�ж��ǲ��ǻ�״");
	printf("%s\n", (lb1_pd(head) ? "yes": "no"));

	printf("\n\n���Է�ת\n");
	struct lb1* head3 = lb1_copy2(head);
	lb1_print(head3);



	return 0;
}