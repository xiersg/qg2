#include "F.h"

struct lb1 {//单链表
	int val;
	struct lb1* next;
};
struct lb2 {//双向链表
	int val;
	struct lb2* prev;
	struct lb2* next;
};


//单向链表插入函数。因为不做要求，所以选择了最方便的头插法
struct lb1* lb1_add(struct lb1* head,int num) {//cur1表示最后一个节点的地址，cur0为cur1前一个。cur1一定不为NULL
	
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

//这是创建一个单向链表节点的函数
struct lb1* lb1_c(int num) {
	struct lb1* jd = (struct lb1*)malloc(sizeof(struct lb1));
	jd->next = NULL;
	jd->val = num;

	return jd;
}

//单向链表打印函数
void lb1_print(struct lb1*head) {
	struct lb1* cur = head;
	while (cur != NULL) {
		printf("%d  ", cur->val);
		cur = cur->next;
	}
	printf("没有更多了o\n");
}

//删除函数
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

//定义插入函数，可以正序插入到第count个元素之前(1为开头)，count大于最大索引就加到最后一个
void lb1_insert(struct lb1**head,int num,int count) {
	struct lb1* cur = *head;
	struct lb1* insert = lb1_c(num);
	int i = 1;
	if (count > 0){//只支持正序插入
		if (1 == count){//对第一个特殊操作
			*head = insert;
			insert->next = cur;
			return;
		}
		while (cur != NULL){
			i++;
			if (count == i){//插入操作
				insert->next = cur->next;
				cur->next = insert;
				break;
			}
			cur = cur->next;
			if(cur->next == NULL){//超出索引，插到最后一个
				cur->next = insert;
				break;
			}
		}
	}
	else {printf("暂不支持逆序索引");}//负数特判
}

//奇数偶数调换函数
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

//寻找中点
struct lb1* lb1_mid(struct lb1*head) {
	struct lb1* cur = head;
	struct lb1* cur0 = head;

	while (cur->next != NULL && cur!= NULL) {
		cur = cur->next->next;
		cur0 = cur0->next;
	}

	return cur0;
}

//复制，这么做是为了方便判断
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

//判断是不是成环
bool lb1_pd(struct lb1* head) 
{
	struct lb1*head2 = lb1_copy(head);
	struct lb1* cur = head2;
	struct lb1* cur0 = NULL;
	while (cur != NULL) {
		if (cur->val == 1010721) { return 1; }//通过特殊编号进行查看
		cur0 = cur;
		cur = cur->next;
		cur0->val = 1010721;//编号的不唯一性可以通过结构体定义是加入一个新的int来进行判断是不是环状
	}
	return 0;
}

//反转
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





//双向链表插入函数。头插法
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

//这是创建一个双向链表节点的函数
struct lb2* lb2_c(int num) {
	struct lb2* jd = (struct lb2*)malloc(sizeof(struct lb2));
	jd->val = num;
	jd->prev = NULL;
	jd->next = NULL;

	return jd;
}

//双向链表打印函数
void lb2_print(struct lb2* head) {
	struct lb2* cur = head;
	while (cur != NULL)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("什么都没有了哦\n");

	return;
}

//删除函数
void lb2_remove(struct lb2** head, int num)
{
	struct lb2* cur = *head;
	if ((*head)->val == num)//对第一个特判
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
	if (count > 0) {//只支持正序插入
		if (1 == count) {//对第一个特殊操作
			*head = insert;
			insert->next = cur;
			cur->prev = insert;
			return;
		}
		while (cur != NULL) {
			i++;
			if (count == i) {//插入操作
				insert->next = cur->next;
				cur->next = insert;
				insert->prev = cur;
				insert->next->prev = insert;
				return;
			}
			cur = cur->next;
			if (cur->next == NULL) {//超出索引，插到最后一个
				cur->next = insert;
				insert->prev = cur;
				break;
			}
		}
	}
	else { printf("暂不支持逆序索引"); }//负数特判
}
