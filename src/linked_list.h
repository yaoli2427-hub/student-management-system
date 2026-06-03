#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "student.h"

/* 链表操作函数声明 */
StudentNode* create_empty_list();
StudentNode* insert_node(StudentNode *head, Student student);
StudentNode* delete_node(StudentNode *head, const char *student_id);
StudentNode* search_by_id(StudentNode *head, const char *student_id);
StudentNode* search_by_name(StudentNode *head, const char *name);
void display_all(StudentNode *head);
int get_list_length(StudentNode *head);
StudentNode* sort_list(StudentNode *head, int (*compare)(Student, Student));
void free_list(StudentNode *head);
StudentNode* filter_by_college(StudentNode *head, const char *college);
StudentNode* filter_by_major(StudentNode *head, const char *major);
StudentNode* filter_by_class(StudentNode *head, const char *class_name);
StudentNode* filter_by_gender(StudentNode *head, const char *gender);
StudentNode* filter_by_political_status(StudentNode *head, const char *status);
StudentNode* update_student(StudentNode *head, const char *student_id, Student new_data);

#endif
