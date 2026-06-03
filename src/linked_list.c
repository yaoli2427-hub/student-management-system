#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "linked_list.h"

/* 创建空链表 */
StudentNode* create_empty_list() {
    return NULL;
}

/* 向链表中插入节点（按学号升序插入） */
StudentNode* insert_node(StudentNode *head, Student student) {
    StudentNode *new_node = create_student_node(student);
    if (new_node == NULL) return head;

    /* 如果链表为空，直接返回新节点 */
    if (head == NULL) {
        return new_node;
    }

    /* 如果新节点学号小于头节点，插入到头部 */
    if (strcmp(student.student_id, head->data.student_id) < 0) {
        new_node->next = head;
        return new_node;
    }

    /* 遍历找到插入位置 */
    StudentNode *current = head;
    while (current->next != NULL && 
           strcmp(student.student_id, current->next->data.student_id) > 0) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    return head;
}

/* 删除指定学号的节点 */
StudentNode* delete_node(StudentNode *head, const char *student_id) {
    if (head == NULL) {
        printf("链表为空，无法删除！\n");
        return head;
    }

    /* 如果删除的是头节点 */
    if (strcmp(head->data.student_id, student_id) == 0) {
        StudentNode *temp = head;
        head = head->next;
        free(temp);
        printf("学生信息已删除！\n");
        return head;
    }

    /* 遍历找到要删除的节点 */
    StudentNode *current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->data.student_id, student_id) == 0) {
            StudentNode *temp = current->next;
            current->next = temp->next;
            free(temp);
            printf("学生信息已删除！\n");
            return head;
        }
        current = current->next;
    }

    printf("未找到该学生！\n");
    return head;
}

/* 按学号查询（返回单个节点） */
StudentNode* search_by_id(StudentNode *head, const char *student_id) {
    StudentNode *current = head;
    while (current != NULL) {
        if (strcmp(current->data.student_id, student_id) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/* 按姓名查询（返回所有匹配的节点作为新链表） */
StudentNode* search_by_name(StudentNode *head, const char *name) {
    StudentNode *result_head = NULL;
    StudentNode *current = head;
    
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            StudentNode *new_node = create_student_node(current->data);
            if (result_head == NULL) {
                result_head = new_node;
            } else {
                StudentNode *temp = result_head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = new_node;
            }
        }
        current = current->next;
    }
    
    return result_head;
}

/* 显示所有学生信息 */
void display_all(StudentNode *head) {
    if (head == NULL) {
        printf("暂无学生信息！\n");
        return;
    }

    print_student_table_header();
    StudentNode *current = head;
    int count = 0;
    while (current != NULL) {
        print_student_row(current->data);
        current = current->next;
        count++;
    }
    printf("└──────────┴──────────┴────┴───────────┴────────────┴────────┴──────────┘\n");
    printf("共有 %d 名学生。\n", count);
}

/* 获取链表长度 */
int get_list_length(StudentNode *head) {
    int count = 0;
    StudentNode *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

/* 冒泡排序链表 */
StudentNode* sort_list(StudentNode *head, int (*compare)(Student, Student)) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    StudentNode *sorted = NULL;
    StudentNode *current = head;

    while (current != NULL) {
        StudentNode *next = current->next;
        
        /* 如果排序链表为空或当前元素应该插入到头部 */
        if (sorted == NULL || compare(current->data, sorted->data) < 0) {
            current->next = sorted;
            sorted = current;
        } else {
            /* 找到合适的插入位置 */
            StudentNode *pos = sorted;
            while (pos->next != NULL && compare(current->data, pos->next->data) > 0) {
                pos = pos->next;
            }
            current->next = pos->next;
            pos->next = current;
        }
        
        current = next;
    }

    return sorted;
}

/* 释放整个链表 */
void free_list(StudentNode *head) {
    StudentNode *current = head;
    while (current != NULL) {
        StudentNode *temp = current;
        current = current->next;
        free(temp);
    }
}

/* 按学院筛选 */
StudentNode* filter_by_college(StudentNode *head, const char *college) {
    StudentNode *result = NULL;
    StudentNode *current = head;
    
    while (current != NULL) {
        if (strcmp(current->data.college, college) == 0) {
            StudentNode *new_node = create_student_node(current->data);
            if (result == NULL) {
                result = new_node;
            } else {
                StudentNode *temp = result;
                while (temp->next != NULL) temp = temp->next;
                temp->next = new_node;
            }
        }
        current = current->next;
    }
    
    return result;
}

/* 按专业筛选 */
StudentNode* filter_by_major(StudentNode *head, const char *major) {
    StudentNode *result = NULL;
    StudentNode *current = head;
    
    while (current != NULL) {
        if (strcmp(current->data.major, major) == 0) {
            StudentNode *new_node = create_student_node(current->data);
            if (result == NULL) {
                result = new_node;
            } else {
                StudentNode *temp = result;
                while (temp->next != NULL) temp = temp->next;
                temp->next = new_node;
            }
        }
        current = current->next;
    }
    
    return result;
}

/* 按班级筛选 */
StudentNode* filter_by_class(StudentNode *head, const char *class_name) {
    StudentNode *result = NULL;
    StudentNode *current = head;
    
    while (current != NULL) {
        if (strcmp(current->data.class_name, class_name) == 0) {
            StudentNode *new_node = create_student_node(current->data);
            if (result == NULL) {
                result = new_node;
            } else {
                StudentNode *temp = result;
                while (temp->next != NULL) temp = temp->next;
                temp->next = new_node;
            }
        }
        current = current->next;
    }
    
    return result;
}

/* 按性别筛选 */
StudentNode* filter_by_gender(StudentNode *head, const char *gender) {
    StudentNode *result = NULL;
    StudentNode *current = head;
    
    while (current != NULL) {
        if (strcmp(current->data.gender, gender) == 0) {
            StudentNode *new_node = create_student_node(current->data);
            if (result == NULL) {
                result = new_node;
            } else {
                StudentNode *temp = result;
                while (temp->next != NULL) temp = temp->next;
                temp->next = new_node;
            }
        }
        current = current->next;
    }
    
    return result;
}

/* 按政治面貌筛选 */
StudentNode* filter_by_political_status(StudentNode *head, const char *status) {
    StudentNode *result = NULL;
    StudentNode *current = head;
    
    while (current != NULL) {
        if (strcmp(current->data.political_status, status) == 0) {
            StudentNode *new_node = create_student_node(current->data);
            if (result == NULL) {
                result = new_node;
            } else {
                StudentNode *temp = result;
                while (temp->next != NULL) temp = temp->next;
                temp->next = new_node;
            }
        }
        current = current->next;
    }
    
    return result;
}

/* 更新学生信息 */
StudentNode* update_student(StudentNode *head, const char *student_id, Student new_data) {
    StudentNode *current = head;
    while (current != NULL) {
        if (strcmp(current->data.student_id, student_id) == 0) {
            current->data = new_data;
            printf("学生信息已更新！\n");
            return head;
        }
        current = current->next;
    }
    printf("未找到该学生！\n");
    return head;
}
