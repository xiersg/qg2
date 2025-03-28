#pragma once

#ifndef F_H
#define F_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct lb1* lb1_add(struct lb1* head, int num);
struct lb1* lb1_c(int num);
void lb1_print(struct lb1* head);
void lb1_remove(struct lb1** head, int num);
void lb1_insert(struct lb1** head, int num, int count);
void lb1_odd_even(struct lb1* head);
struct lb1* lb1_mid(struct lb1* head);
struct lb1* lb1_copy(struct lb1* head);
bool lb1_pd(struct lb1* head);
struct lb1* lb1_copy2(struct lb1* head);

struct lb2* lb2_add(struct lb2* head, int num);
struct lb2* lb2_c(int num);
void lb2_print(struct lb2* head);
void lb2_remove(struct lb2** head, int num);
void lb2_insert(struct lb2** head, int num, int count);



#endif