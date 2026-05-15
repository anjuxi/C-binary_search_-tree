#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 树数据类型
typedef int Data;

// 树节点结构体
typedef struct TreeNode {
    Data data;              // 节点数据
    struct TreeNode* left;  // 左子节点
    struct TreeNode* right; // 右子节点
} TreeNode;

// 树结构体
typedef struct {
    TreeNode* root;         // 根节点
    int size;               // 节点个数
} Tree;

// ========== 函数声明 ==========

// 创建与销毁
Tree* treeCreate(void);
void treeDestroy(Tree* t);
void treeNodeDestroy(TreeNode* node);

// 插入与删除
bool treeInsert(Tree* t, Data val);
bool treeRemove(Tree* t, Data val);
TreeNode* treeRemoveNode(TreeNode* node, Data val);

// 查找
TreeNode* treeFind(Tree* t, Data val);
bool treeContains(Tree* t, Data val);
Data treeMin(Tree* t);
Data treeMax(Tree* t);
TreeNode* treeFindMin(TreeNode* node);
TreeNode* treeFindMax(TreeNode* node);

// 容量管理
bool treeIsEmpty(Tree* t);
int treeSize(Tree* t);
void treeClear(Tree* t);

// 遍历
void treeInOrder(Tree* t);
void treePreOrder(Tree* t);
void treePostOrder(Tree* t);
void treeInOrderNode(TreeNode* node);
void treePreOrderNode(TreeNode* node);
void treePostOrderNode(TreeNode* node);

// 打印
void treePrint(Tree* t);
void treePrintNode(TreeNode* node, int depth);

// 其他操作
int treeHeight(Tree* t);
int treeNodeHeight(TreeNode* node);
int treeCountLeaves(Tree* t);
int treeNodeCountLeaves(TreeNode* node);

// ========== 函数实现 ==========

// 创建树
Tree* treeCreate(void) {
    Tree* t = (Tree*)malloc(sizeof(Tree));
    if (!t) return NULL;
    
    t->root = NULL;
    t->size = 0;
    return t;
}

// 销毁树节点（递归）
void treeNodeDestroy(TreeNode* node) {
    if (!node) return;
    treeNodeDestroy(node->left);
    treeNodeDestroy(node->right);
    free(node);
}

// 销毁树
void treeDestroy(Tree* t) {
    if (!t) return;
    treeNodeDestroy(t->root);
    free(t);
}

// 插入节点
bool treeInsert(Tree* t, Data val) {
    if (!t) return false;
    
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) return false;
    
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    
    if (!t->root) {
        t->root = newNode;
        t->size++;
        return true;
    }
    
    TreeNode* current = t->root;
    TreeNode* parent = NULL;
    
    while (current) {
        parent = current;
        if (val < current->data) {
            current = current->left;
        } else if (val > current->data) {
            current = current->right;
        } else {
            // 值已存在，不插入重复值
            free(newNode);
            return false;
        }
    }
    
    if (val < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    t->size++;
    return true;
}

// 查找最小节点
TreeNode* treeFindMin(TreeNode* node) {
    if (!node) return NULL;
    while (node->left) {
        node = node->left;
    }
    return node;
}

// 查找最大节点
TreeNode* treeFindMax(TreeNode* node) {
    if (!node) return NULL;
    while (node->right) {
        node = node->right;
    }
    return node;
}

// 删除节点（递归实现）
TreeNode* treeRemoveNode(TreeNode* node, Data val) {
    if (!node) return NULL;
    
    if (val < node->data) {
        node->left = treeRemoveNode(node->left, val);
    } else if (val > node->data) {
        node->right = treeRemoveNode(node->right, val);
    } else {
        // 找到要删除的节点
        if (!node->left) {
            TreeNode* temp = node->right;
            free(node);
            return temp;
        } else if (!node->right) {
            TreeNode* temp = node->left;
            free(node);
            return temp;
        }
        
        // 有两个子节点，找到右子树的最小值
        TreeNode* temp = treeFindMin(node->right);
        node->data = temp->data;
        node->right = treeRemoveNode(node->right, temp->data);
    }
    return node;
}

// 删除节点
bool treeRemove(Tree* t, Data val) {
    if (!t || !t->root) return false;
    
    if (!treeContains(t, val)) return false;
    
    t->root = treeRemoveNode(t->root, val);
    t->size--;
    return true;
}

// 查找节点
TreeNode* treeFind(Tree* t, Data val) {
    if (!t) return NULL;
    
    TreeNode* current = t->root;
    while (current) {
        if (val < current->data) {
            current = current->left;
        } else if (val > current->data) {
            current = current->right;
        } else {
            return current;
        }
    }
    return NULL;
}

// 判断是否包含
bool treeContains(Tree* t, Data val) {
    return treeFind(t, val) != NULL;
}

// 获取最小值
Data treeMin(Tree* t) {
    if (!t || !t->root) return 0;
    TreeNode* minNode = treeFindMin(t->root);
    return minNode ? minNode->data : 0;
}

// 获取最大值
Data treeMax(Tree* t) {
    if (!t || !t->root) return 0;
    TreeNode* maxNode = treeFindMax(t->root);
    return maxNode ? maxNode->data : 0;
}

// 判断是否为空
bool treeIsEmpty(Tree* t) {
    return !t || t->size == 0;
}

// 获取节点个数
int treeSize(Tree* t) {
    return t ? t->size : 0;
}

// 清空树
void treeClear(Tree* t) {
    if (!t) return;
    treeNodeDestroy(t->root);
    t->root = NULL;
    t->size = 0;
}

// 中序遍历节点（递归）
void treeInOrderNode(TreeNode* node) {
    if (!node) return;
    treeInOrderNode(node->left);
    printf("%d ", node->data);
    treeInOrderNode(node->right);
}

// 前序遍历节点（递归）
void treePreOrderNode(TreeNode* node) {
    if (!node) return;
    printf("%d ", node->data);
    treePreOrderNode(node->left);
    treePreOrderNode(node->right);
}

// 后序遍历节点（递归）
void treePostOrderNode(TreeNode* node) {
    if (!node) return;
    treePostOrderNode(node->left);
    treePostOrderNode(node->right);
    printf("%d ", node->data);
}

// 中序遍历
void treeInOrder(Tree* t) {
    if (!t) return;
    printf("中序遍历: ");
    treeInOrderNode(t->root);
    printf("\n");
}

// 前序遍历
void treePreOrder(Tree* t) {
    if (!t) return;
    printf("前序遍历: ");
    treePreOrderNode(t->root);
    printf("\n");
}

// 后序遍历
void treePostOrder(Tree* t) {
    if (!t) return;
    printf("后序遍历: ");
    treePostOrderNode(t->root);
    printf("\n");
}

// 打印节点（树形结构）
void treePrintNode(TreeNode* node, int depth) {
    if (!node) return;
    
    treePrintNode(node->right, depth + 1);
    
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("%d\n", node->data);
    
    treePrintNode(node->left, depth + 1);
}

// 打印树
void treePrint(Tree* t) {
    if (!t) {
        printf("NULL\n");
        return;
    }
    
    if (treeIsEmpty(t)) {
        printf("空树 (size=0)\n");
        return;
    }
    
    printf("\n树结构 (size=%d):\n", t->size);
    treePrintNode(t->root, 0);
    printf("\n");
}

// 计算节点高度
int treeNodeHeight(TreeNode* node) {
    if (!node) return 0;
    
    int leftHeight = treeNodeHeight(node->left);
    int rightHeight = treeNodeHeight(node->right);
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// 计算树高度
int treeHeight(Tree* t) {
    if (!t) return 0;
    return treeNodeHeight(t->root);
}

// 计算叶子节点数（递归）
int treeNodeCountLeaves(TreeNode* node) {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return treeNodeCountLeaves(node->left) + treeNodeCountLeaves(node->right);
}

// 计算叶子节点数
int treeCountLeaves(Tree* t) {
    if (!t) return 0;
    return treeNodeCountLeaves(t->root);
}

// ========== 测试代码 ==========

int main() {
    printf("=== 二叉搜索树测试 ===\n\n");
    
    // 创建树
    Tree* t = treeCreate();
    printf("创建树:\n");
    treePrint(t);
    
    // 插入节点
    printf("插入节点 50, 30, 70, 20, 40, 60, 80:\n");
    treeInsert(t, 50);
    treeInsert(t, 30);
    treeInsert(t, 70);
    treeInsert(t, 20);
    treeInsert(t, 40);
    treeInsert(t, 60);
    treeInsert(t, 80);
    treePrint(t);
    
    // 遍历测试
    printf("遍历测试:\n");
    treePreOrder(t);
    treeInOrder(t);
    treePostOrder(t);
    printf("\n");
    
    // 查找测试
    printf("查找测试:\n");
    printf("是否包含40: %s\n", treeContains(t, 40) ? "是" : "否");
    printf("是否包含100: %s\n", treeContains(t, 100) ? "是" : "否");
    printf("最小值: %d\n", treeMin(t));
    printf("最大值: %d\n", treeMax(t));
    printf("\n");
    
    // 树高度和叶子节点
    printf("树高度: %d\n", treeHeight(t));
    printf("叶子节点数: %d\n", treeCountLeaves(t));
    printf("\n");
    
    // 删除测试（删除有0个子节点的节点）
    printf("删除叶子节点20:\n");
    treeRemove(t, 20);
    treePrint(t);
    treeInOrder(t);
    printf("\n");
    
    // 删除测试（删除有1个子节点的节点）
    printf("删除有一个子节点的节点（插入25后删除30）:\n");
    treeInsert(t, 25);
    treePrint(t);
    treeRemove(t, 30);
    treePrint(t);
    treeInOrder(t);
    printf("\n");
    
    // 删除测试（删除有2个子节点的节点）
    printf("删除有两个子节点的节点50:\n");
    treeRemove(t, 50);
    treePrint(t);
    treeInOrder(t);
    printf("\n");
    
    // 清空树
    printf("清空树:\n");
    treeClear(t);
    treePrint(t);
    
    // 重新插入
    printf("重新插入 100, 50, 150, 25, 75, 125, 175:\n");
    treeInsert(t, 100);
    treeInsert(t, 50);
    treeInsert(t, 150);
    treeInsert(t, 25);
    treeInsert(t, 75);
    treeInsert(t, 125);
    treeInsert(t, 175);
    treePrint(t);
    
    // 销毁树
    treeDestroy(t);
    printf("树已销毁\n");
    
    return 0;
}
