#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define SIZE 100

// Ʈ�� ����ü ����
typedef struct TreeNode {
    double data;
    struct TreeNode* left, * right;
} TreeNode;

// Ʈ�� ����
TreeNode n1 = { 2, NULL, NULL };
TreeNode n2 = { 3, NULL, NULL };
TreeNode n3 = { 4, NULL, NULL };
TreeNode n4 = { 5, NULL, NULL };
TreeNode n5 = { 6, NULL, NULL };
TreeNode n6 = { 7, NULL ,NULL };
TreeNode n7 = { 9, NULL ,NULL };

TreeNode op1 = { '*', &n3 ,&n4 };
TreeNode op2 = { '/', &n5 ,&n6 };
TreeNode op3 = { '+', &n1,&n2 };
TreeNode op4 = { '+', &op3,&op1 };
TreeNode op5 = { '-', &op4,&op2 };
TreeNode root = { '+', &op5,&n7 };

int top = -1;
TreeNode* stack[SIZE];

// ������ ����ִ��� Ȯ���ϴ� �Լ�
int is_empty() {
    if (top == -1) return 1;
    else return 0;
}

void push(TreeNode* s) {
    if (top < SIZE - 1) stack[++top] = s;
}

TreeNode* pop() {
    TreeNode* s = NULL;
    if (top >= 0) s = stack[top--];
    return s;
}

int get_node_count(TreeNode* root) {
    int n = 0;
    while (root || !is_empty()) {
        if (root) {
            push(root);
            root = root->left;
        }
        else {
            root = pop();
            n++;
            root = root->right;
        }
    }
    return n;
}

// ���� ��� Ʈ��
double evaluate(TreeNode* root) {
    double result = 0;
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->data;
    else {
        double op1 = evaluate(root->left);
        double op2 = evaluate(root->right);
        printf("%.2f %c %.2f = ", op1, (char)root->data, op2);
        switch ((char)root->data)
        {
        case '+': printf("%.2f\n", op1 + op2); 
        return op1 + op2;
        case '-': printf("%.2f\n", op1 - op2); 
        return op1 - op2;
        case '*': printf("%.2f\n", op1 * op2); 
        return op1 * op2;
        case '/': printf("%.2f\n", op1 / op2); 
        return op1 / op2;
        }

    }
}

int main(void) {
    printf("������ ���� %.2f�Դϴ�.\n", evaluate(&root));
    int count = get_node_count(&root);
    printf("\n�� ����� ���� %d�� �Դϴ�.\n", count);
    return 0;
}