#include "F.h"

struct lb1 {//������
	int val;
	struct lb1* next;
};
struct lb2 {//˫������
	int val;
	struct lb2* prev;
	struct lb2* next;
};


//����������뺯������Ϊ����Ҫ������ѡ��������ͷ�巨
struct lb1* lb1_add(struct lb1* head,int num) {//cur1��ʾ���һ���ڵ�ĵ�ַ��cur0Ϊcur1ǰһ����cur1һ����ΪNULL
	
	struct lb1* head_new = lb1_c(num);
	head_new->val = num;

	if (head == NULL) {
		head_new->next = NULL;
	}
	else {
		head_new->next = head;
	}

	return head_new;
}

//���Ǵ���һ����������ڵ�ĺ���
struct lb1* lb1_c(int num) {
	struct lb1* jd = (struct lb1*)malloc(sizeof(struct lb1));
	jd->next = NULL;
	jd->val = num;

	return jd;
}

//���������ӡ����
void lb1_print(struct lb1*head) {
	struct lb1* cur = head;
	while (cur != NULL) {
		printf("%d  ", cur->val);
		cur = cur->next;
	}
	printf("û�и�����o\n");
}

//ɾ������
void lb1_remove(struct lb1** head, int num) 
{
	struct lb1* cur = *head;
	if ((*head)->val == num) 
	{
		*head = (*head)->next;
		free(cur);
	}
	else 
	{
		struct lb1* cur0 = cur;
		cur = cur->next;
		while (cur != NULL) 
		{
			if (cur->val == num) 
			{
				cur0->next = cur->next;
				free(cur);
				break;
			}
			else
			{
				cur0 = cur;
				cur = cur->next;
			}
		}
	}
}

//������뺯��������������뵽��count��Ԫ��֮ǰ(1Ϊ��ͷ)��count������������ͼӵ����һ��
void lb1_insert(struct lb1**head,int num,int count) {
	struct lb1* cur = *head;
	struct lb1* insert = lb1_c(num);
	int i = 1;
	if (count > 0){//ֻ֧���������
		if (1 == count){//�Ե�һ���������
			*head = insert;
			insert->next = cur;
			return;
		}
		while (cur != NULL){
			i++;
			if (count == i){//�������
				insert->next = cur->next;
				cur->next = insert;
				break;
			}
			cur = cur->next;
			if(cur->next == NULL){//�����������嵽���һ��
				cur->next = insert;
				break;
			}
		}
	}
	else {printf("�ݲ�֧����������");}//��������
}

//����ż����������
void lb1_odd_even(struct lb1* head) {
	struct lb1* cur = head;
	while (cur->next != NULL){
		if (cur->val % 2 != cur->next->val%2){
			int temp = cur->val;
			cur->val = cur->next->val;
			cur->next->val = temp;
			cur = cur->next;
		}
		cur = cur->next;
	}
}

//Ѱ���е�
struct lb1* lb1_mid(struct lb1*head) {
	struct lb1* cur = head;
	struct lb1* cur0 = head;

	while (cur->next != NULL && cur!= NULL) {
		cur = cur->next->next;
		cur0 = cur0->next;
	}

	return cur0;
}

//���ƣ���ô����Ϊ�˷����ж�
struct lb1* lb1_copy(struct lb1* head)
{
	struct lb1* cur = head;
	struct lb1* cur_new = lb1_c(head->val);
	struct lb1* head_new = cur_new;
	cur = cur->next;
	while (cur != NULL) 
	{
		cur_new->next = lb1_c(cur->val);
		cur_new = cur_new->next;
		cur = cur->next;
	}
	return head_new;
}

//�ж��ǲ��ǳɻ�
bool lb1_pd(struct lb1* head) 
{
	struct lb1*head2 = lb1_copy(head);
	struct lb1* cur = head2;
	struct lb1* cur0 = NULL;
	while (cur != NULL) {
		if (cur->val == 1010721) { return 1; }//ͨ�������Ž��в鿴
		cur0 = cur;
		cur = cur->next;
		cur0->val = 1010721;//��ŵĲ�Ψһ�Կ���ͨ���ṹ�嶨���Ǽ���һ���µ�int�������ж��ǲ��ǻ�״
	}
	return 0;
}

//��ת
struct lb1* lb1_copy2(struct lb1* head)
{
	struct lb1* cur = head;
	struct lb1* head_new = NULL;
	while (cur != NULL)
	{
		head_new = lb1_add(head_new,cur->val);
		cur = cur->next;
	}
	return head_new;
}





//˫��������뺯����ͷ�巨
struct lb2* lb2_add(struct lb2*head,int num) {

	struct lb2* head_new = lb2_c(num);
	head_new->val = num;

	if (head == NULL) {
		head_new->next = NULL;
		head_new->prev = NULL;
	}
	else {
		head_new->next = head;
		head->prev = head_new;
	}

	return head_new;
}

//���Ǵ���һ��˫������ڵ�ĺ���
struct lb2* lb2_c(int num) {
	struct lb2* jd = (struct lb2*)malloc(sizeof(struct lb2));
	jd->val = num;
	jd->prev = NULL;
	jd->next = NULL;

	return jd;
}

//˫�������ӡ����
void lb2_print(struct lb2* head) {
	struct lb2* cur = head;
	while (cur != NULL)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("ʲô��û����Ŷ\n");

	return;
}

//ɾ������
void lb2_remove(struct lb2** head, int num)
{
	struct lb2* cur = *head;
	if ((*head)->val == num)//�Ե�һ������
	{
		*head = (*head)->next;
		free(cur);
	}
	else
	{
		while (cur != NULL && (cur = cur->next))
		{
			if (cur->val == num)
			{
				struct lb2*cur0 = cur->prev;
				cur = cur->next;
				free(cur0->next);
				cur0->next = cur;
				if (cur != NULL) { cur->prev = cur0; }
				break;
			}
		}
	}
}

void lb2_insert(struct lb2** head, int num, int count) {
	struct lb2* cur = *head;
	struct lb2* insert = lb2_c(num);
	int i = 1;
	if (count > 0) {//ֻ֧���������
		if (1 == count) {//�Ե�һ���������
			*head = insert;
			insert->next = cur;
			cur->prev = insert;
			return;
		}
		while (cur != NULL) {
			i++;
			if (count == i) {//�������
				insert->next = cur->next;
				cur->next = insert;
				insert->prev = cur;
				insert->next->prev = insert;
				return;
			}
			cur = cur->next;
			if (cur->next == NULL) {//�����������嵽���һ��
				cur->next = insert;
				insert->prev = cur;
				break;
			}
		}
	}
	else { printf("�ݲ�֧����������"); }//��������
}
