#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/* 创建一个学生节点 */
StudentNode* create_student_node(Student student) {
    StudentNode *node = (StudentNode *)malloc(sizeof(StudentNode));
    if (node == NULL) {
        printf("内存分配失败！\n");
        return NULL;
    }
    node->data = student;
    node->next = NULL;
    return node;
}

/* 打印单个学生信息（详细格式） */
void print_student(Student student) {
    printf("┌─────────────────────────────────────────────┐\n");
    printf("│ 学号: %-35s │\n", student.student_id);
    printf("│ 姓名: %-35s │\n", student.name);
    printf("│ 性别: %-35s │\n", student.gender);
    printf("│ 年龄: %-35d │\n", student.age);
    printf("│ 出生年月: %-31s │\n", student.birth_date);
    printf("│ 学院: %-35s │\n", student.college);
    printf("│ 专业: %-35s │\n", student.major);
    printf("│ 班级: %-35s │\n", student.class_name);
    printf("│ 地址: %-35s │\n", student.address);
    printf("│ 电话: %-35s │\n", student.phone);
    printf("│ E-mail: %-33s │\n", student.email);
    printf("│ 宿舍号: %-33s │\n", student.dorm_number);
    printf("│ 政治面貌: %-31s │\n", student.political_status);
    printf("└─────────────────────────────────────────────┘\n");
}

/* 打印学生信息表格头部 */
void print_student_table_header() {
    printf("┌──────────┬──────────┬────┬───────────┬────────────┬────────┬──────────┐\n");
    printf("│  学号    │  姓名    │年龄│  出生年月 │  学院      │  专业  │  班级    │\n");
    printf("├──────────┼──────────┼────┼───────────┼────────────┼────────┼──────────┤\n");
}

/* 打印学生信息表格行 */
void print_student_row(Student student) {
    printf("│ %-8s │ %-8s │ %2d │ %9s │ %-10s │ %-6s │ %-8s │\n",
           student.student_id, student.name, student.age,
           student.birth_date, student.college, student.major, student.class_name);
}

/* 按学号比较 */
int compare_by_id(Student s1, Student s2) {
    return strcmp(s1.student_id, s2.student_id);
}

/* 按姓名比较 */
int compare_by_name(Student s1, Student s2) {
    return strcmp(s1.name, s2.name);
}

/* 按年龄比较 */
int compare_by_age(Student s1, Student s2) {
    return s1.age - s2.age;
}
