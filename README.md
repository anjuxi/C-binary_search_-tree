# C语言二叉搜索树实现

[![C](https://img.shields.io/badge/C-11-blue.svg)](https://en.wikipedia.org/wiki/C11_(C_standard_revision))
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

## 项目简介

本项目是一个用 C 语言实现的**二叉搜索树（Binary Search Tree, BST）**数据结构库。二叉搜索树是一种高效的数据结构，支持快速的插入、删除和查找操作，平均时间复杂度为 O(log n)。

## 功能特性

- **创建与销毁**：动态创建和销毁树结构，安全释放内存
- **插入与删除**：支持节点的插入和删除（包括叶子节点、单子节点、双子节点三种情况）
- **查找操作**：支持查找节点、判断是否包含、获取最小/最大值
- **遍历方式**：
  - 前序遍历（Pre-order）
  - 中序遍历（In-order）
  - 后序遍历（Post-order）
- **树形打印**：可视化打印树的结构
- **其他操作**：计算树高度、统计叶子节点数、清空树等

## 数据结构

```c
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
```

## API 接口

### 创建与销毁

| 函数                                   | 说明                 |
| -------------------------------------- | -------------------- |
| `Tree* treeCreate(void)`               | 创建一棵空树         |
| `void treeDestroy(Tree* t)`            | 销毁整棵树并释放内存 |
| `void treeNodeDestroy(TreeNode* node)` | 递归销毁节点         |

### 插入与删除

| 函数                                 | 说明                           |
| ------------------------------------ | ------------------------------ |
| `bool treeInsert(Tree* t, Data val)` | 插入一个值到树中（不允许重复） |
| `bool treeRemove(Tree* t, Data val)` | 从树中删除指定值               |

### 查找操作

| 函数                                    | 说明               |
| --------------------------------------- | ------------------ |
| `TreeNode* treeFind(Tree* t, Data val)` | 查找指定值的节点   |
| `bool treeContains(Tree* t, Data val)`  | 判断是否包含指定值 |
| `Data treeMin(Tree* t)`                 | 获取树中的最小值   |
| `Data treeMax(Tree* t)`                 | 获取树中的最大值   |

### 遍历操作

| 函数                          | 说明                       |
| ----------------------------- | -------------------------- |
| `void treePreOrder(Tree* t)`  | 前序遍历                   |
| `void treeInOrder(Tree* t)`   | 中序遍历（结果按升序排列） |
| `void treePostOrder(Tree* t)` | 后序遍历                   |

### 其他操作

| 函数                           | 说明                 |
| ------------------------------ | -------------------- |
| `bool treeIsEmpty(Tree* t)`    | 判断树是否为空       |
| `int treeSize(Tree* t)`        | 获取节点个数         |
| `void treeClear(Tree* t)`      | 清空树（保留树结构） |
| `int treeHeight(Tree* t)`      | 计算树的高度         |
| `int treeCountLeaves(Tree* t)` | 统计叶子节点数       |
| `void treePrint(Tree* t)`      | 以树形结构打印整棵树 |

## 编译与运行

```bash
gcc -o tree 树.cpp
./tree
```

## 使用示例

```c
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
```

## 输出示例

```bash
C:\Users\anjuxi\Desktop\C语言 树>a.exe
=== 二叉搜索树测试 ===

创建树:
空树 (size=0)
插入节点 50, 30, 70, 20, 40, 60, 80:

树结构 (size=7):
        80
    70
        60
50
        40
    30
        20

遍历测试:
前序遍历: 50 30 20 40 70 60 80
中序遍历: 20 30 40 50 60 70 80
后序遍历: 20 40 30 60 80 70 50

查找测试:
是否包含40: 是
是否包含100: 否
最小值: 20
最大值: 80

树高度: 3
叶子节点数: 4

删除叶子节点20:

树结构 (size=6):
        80
    70
        60
50
        40
    30

中序遍历: 30 40 50 60 70 80

删除有一个子节点的节点（插入25后删除30）:

树结构 (size=7):
        80
    70
        60
50
        40
    30
        25


树结构 (size=6):
        80
    70
        60
50
    40
        25

中序遍历: 25 40 50 60 70 80

删除有两个子节点的节点50:

树结构 (size=5):
        80
    70
60
    40
        25

中序遍历: 25 40 60 70 80

清空树:
空树 (size=0)
重新插入 100, 50, 150, 25, 75, 125, 175:

树结构 (size=7):
        175
    150
        125
100
        75
    50
        25

树已销毁
```

## 依赖说明

本项目仅依赖 C 语言标准库：

[![C Standard Library](https://img.shields.io/badge/C%20Standard%20Library-stdio.h-blue.svg)]()
[![C Standard Library](https://img.shields.io/badge/C%20Standard%20Library-stdlib.h-blue.svg)]()
[![C Standard Library](https://img.shields.io/badge/C%20Standard%20Library-stdbool.h-blue.svg)]()

- `stdio.h` - 标准输入输出
- `stdlib.h` - 内存分配函数（malloc/free）
- `stdbool.h` - 布尔类型支持

## 算法复杂度

| 操作 | 平均时间复杂度 | 最坏时间复杂度 | 空间复杂度 |
| ---- | -------------- | -------------- | ---------- |
| 插入 | O(log n)       | O(n)           | O(1)       |
| 删除 | O(log n)       | O(n)           | O(1)       |
| 查找 | O(log n)       | O(n)           | O(1)       |
| 遍历 | O(n)           | O(n)           | O(h)       |

> 注：h 为树的高度，n 为节点数

## 作者信息

**谙弆悕博士（Ailan Anjuxi）**

- 邮箱：[anjuxi.ME@outlook.com](mailto:anjuxi.ME@outlook.com)
- SIP电话：[sip:anjuxi@sip.linphone.org](sip:anjuxi@sip.linphone.org)

## 许可证

本项目采用 MIT 许可证 - 详情请参阅 [LICENSE](LICENSE) 文件。

---

*本项目用于学习和教学目的，欢迎交流讨论！*
