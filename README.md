# Binary Search Tree in C

[![C](https://img.shields.io/badge/C-11-blue.svg)](https://en.wikipedia.org/wiki/C11_(C_standard_revision))
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

## Overview

A binary search tree (BST) library in C. Insert, delete, and lookup run in O(log n) on average.

## Features

- **Create and destroy** — allocate and free the tree safely
- **Insert and delete** — delete handles leaf nodes, nodes with one child, and nodes with two children
- **Lookup** — find a node, check membership, get the min/max
- **Traversal**:
  - Pre-order
  - In-order
  - Post-order
- **Tree printing** — visualizes the tree structure
- **Other operations** — height, leaf count, clear

## Data Structure

```c
// Tree node
typedef struct TreeNode {
    Data data;              // node data
    struct TreeNode* left;  // left child
    struct TreeNode* right; // right child
} TreeNode;

// Tree
typedef struct {
    TreeNode* root;         // root node
    int size;               // node count
} Tree;
```

## API

### Create and destroy

| Function | Description |
| -------------------------------------- | -------------------- |
| `Tree* treeCreate(void)` | Create an empty tree |
| `void treeDestroy(Tree* t)` | Destroy the tree and free memory |
| `void treeNodeDestroy(TreeNode* node)` | Recursively destroy nodes |

### Insert and delete

| Function | Description |
| ------------------------------------ | ------------------------------ |
| `bool treeInsert(Tree* t, Data val)` | Insert a value (no duplicates allowed) |
| `bool treeRemove(Tree* t, Data val)` | Remove a value |

### Lookup

| Function | Description |
| --------------------------------------- | ------------------ |
| `TreeNode* treeFind(Tree* t, Data val)` | Find the node holding a value |
| `bool treeContains(Tree* t, Data val)` | Check membership |
| `Data treeMin(Tree* t)` | Get the minimum value |
| `Data treeMax(Tree* t)` | Get the maximum value |

### Traversal

| Function | Description |
| ----------------------------- | -------------------------- |
| `void treePreOrder(Tree* t)` | Pre-order traversal |
| `void treeInOrder(Tree* t)` | In-order traversal (sorted ascending) |
| `void treePostOrder(Tree* t)` | Post-order traversal |

### Other operations

| Function | Description |
| ------------------------------ | -------------------- |
| `bool treeIsEmpty(Tree* t)` | Check whether the tree is empty |
| `int treeSize(Tree* t)` | Get the node count |
| `void treeClear(Tree* t)` | Clear the tree (keep the tree object) |
| `int treeHeight(Tree* t)` | Get the tree height |
| `int treeCountLeaves(Tree* t)` | Count leaf nodes |
| `void treePrint(Tree* t)` | Print the tree as a tree structure |

## Build and Run

```bash
gcc -o tree tree.c
./tree
```

Use your actual source filename if it differs from `tree.c`.

## Example

```c
int main() {
    printf("=== Binary Search Tree Test ===\n\n");

    // Create the tree
    Tree* t = treeCreate();
    printf("Create tree:\n");
    treePrint(t);

    // Insert nodes
    printf("Insert 50, 30, 70, 20, 40, 60, 80:\n");
    treeInsert(t, 50);
    treeInsert(t, 30);
    treeInsert(t, 70);
    treeInsert(t, 20);
    treeInsert(t, 40);
    treeInsert(t, 60);
    treeInsert(t, 80);
    treePrint(t);

    // Traversal
    printf("Traversal:\n");
    treePreOrder(t);
    treeInOrder(t);
    treePostOrder(t);
    printf("\n");

    // Lookup
    printf("Lookup:\n");
    printf("Contains 40: %s\n", treeContains(t, 40) ? "yes" : "no");
    printf("Contains 100: %s\n", treeContains(t, 100) ? "yes" : "no");
    printf("Min: %d\n", treeMin(t));
    printf("Max: %d\n", treeMax(t));
    printf("\n");

    // Height and leaf count
    printf("Height: %d\n", treeHeight(t));
    printf("Leaf count: %d\n", treeCountLeaves(t));
    printf("\n");

    // Delete a leaf
    printf("Delete leaf 20:\n");
    treeRemove(t, 20);
    treePrint(t);
    treeInOrder(t);
    printf("\n");

    // Delete a node with one child
    printf("Delete a node with one child (insert 25, then delete 30):\n");
    treeInsert(t, 25);
    treePrint(t);
    treeRemove(t, 30);
    treePrint(t);
    treeInOrder(t);
    printf("\n");

    // Delete a node with two children
    printf("Delete node 50, which has two children:\n");
    treeRemove(t, 50);
    treePrint(t);
    treeInOrder(t);
    printf("\n");

    // Clear the tree
    printf("Clear tree:\n");
    treeClear(t);
    treePrint(t);

    // Re-insert
    printf("Insert 100, 50, 150, 25, 75, 125, 175:\n");
    treeInsert(t, 100);
    treeInsert(t, 50);
    treeInsert(t, 150);
    treeInsert(t, 25);
    treeInsert(t, 75);
    treeInsert(t, 125);
    treeInsert(t, 175);
    treePrint(t);

    // Destroy
    treeDestroy(t);
    printf("Tree destroyed\n");

    return 0;
}
```

## Sample Output

```bash
C:\Users\anjuxi\Desktop\tree>a.exe
=== Binary Search Tree Test ===

Create tree:
Empty tree (size=0)
Insert 50, 30, 70, 20, 40, 60, 80:

Tree structure (size=7):
        80
    70
        60
50
        40
    30
        20

Traversal:
Pre-order: 50 30 20 40 70 60 80
In-order: 20 30 40 50 60 70 80
Post-order: 20 40 30 60 80 70 50

Lookup:
Contains 40: yes
Contains 100: no
Min: 20
Max: 80

Height: 3
Leaf count: 4

Delete leaf 20:

Tree structure (size=6):
        80
    70
        60
50
        40
    30

In-order: 30 40 50 60 70 80

Delete a node with one child (insert 25, then delete 30):

Tree structure (size=7):
        80
    70
        60
50
        40
    30
        25


Tree structure (size=6):
        80
    70
        60
50
    40
        25

In-order: 25 40 50 60 70 80

Delete node 50, which has two children:

Tree structure (size=5):
        80
    70
60
    40
        25

In-order: 25 40 60 70 80

Clear tree:
Empty tree (size=0)
Insert 100, 50, 150, 25, 75, 125, 175:

Tree structure (size=7):
        175
    150
        125
100
        75
    50
        25

Tree destroyed
```

## Dependencies

Only the C standard library:

[![C Standard Library](https://img.shields.io/badge/C%20Standard%20Library-stdio.h-blue.svg)]()
[![C Standard Library](https://img.shields.io/badge/C%20Standard%20Library-stdlib.h-blue.svg)]()
[![C Standard Library](https://img.shields.io/badge/C%20Standard%20Library-stdbool.h-blue.svg)]()

- `stdio.h` — input/output
- `stdlib.h` — memory allocation (malloc/free)
- `stdbool.h` — boolean type

## Complexity

| Operation | Average | Worst case | Space |
| ---- | -------------- | -------------- | ---------- |
| Insert | O(log n) | O(n) | O(1) |
| Delete | O(log n) | O(n) | O(1) |
| Lookup | O(log n) | O(n) | O(1) |
| Traversal | O(n) | O(n) | O(h) |

> h = tree height, n = node count

## Author

**Dr. Ailan Anjuxi (谙弆悕)**

- Email: [anjuxi.ME@outlook.com](mailto:anjuxi.ME@outlook.com)
- SIP: [sip:anjuxi@sip.linphone.org](sip:anjuxi@sip.linphone.org)

## License

MIT — see [LICENSE](LICENSE) for details.

---

*This project is for learning and teaching. Discussion is welcome.*
