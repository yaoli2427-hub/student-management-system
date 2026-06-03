#ifndef STUDENT_H
#define STUDENT_H

#include <time.h>

/* 学生信息结构体 */
typedef struct {
    char student_id[20];        /* 学号 */
    char name[50];              /* 姓名 */
    char gender[10];            /* 性别 */
    int age;                    /* 年龄 */
    char birth_date[20];        /* 出生年月 (YYYY-MM-DD) */
    char college[50];           /* 学院 */
    char major[50];             /* 专业 */
    char class_name[20];        /* 班级 */
    char address[100];          /* 地址 */
    char phone[20];             /* 电话 */
    char email[50];             /* E-mail */
    char dorm_number[20];       /* 宿舍号 */
    char political_status[20];  /* 政治面貌 */
} Student;

/* 链表节点结构体 */
typedef struct StudentNode {
    Student data;
    struct StudentNode *next;
} StudentNode;

/* 函数声明 */
StudentNode* create_student_node(Student student);
void print_student(Student student);
void print_student_table_header();
void print_student_row(Student student);
int compare_by_id(Student s1, Student s2);
int compare_by_name(Student s1, Student s2);
int compare_by_age(Student s1, Student s2);

#endif
