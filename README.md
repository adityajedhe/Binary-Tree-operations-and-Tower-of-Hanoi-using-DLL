## GitHub Project Description

### 1. **Advanced Binary Tree Implementation using Doubly Linked Lists**

This project demonstrates a novel and comprehensive implementation of **Binary Tree operations** where the underlying node structure is represented by a **Doubly Linked List**. This non-standard approach provides enhanced flexibility, particularly for traversal and node manipulation, by leveraging the bidirectional links (parent, left-child, and right-child pointers) inherent in a doubly linked structure.

#### ✨ **Core Features & Operations**

The implementation provides a complete set of operations essential for a robust binary tree library:

| Category | Operations Implemented |
| :--- | :--- |
| **Structure & Modification** | Creation, Node Insertion, Node Deletion, Node Searching. |
| **Traversal Methods** | **Pre-order, In-order, Post-order,** and **Level-order** traversal. |
| **Structural Analysis** | Calculation of Tree **Height**, Total **Node Count**, and **Level** of any given node. |
| **Node Categorization** | Counting of **Leaf, Non-Leaf, Full, Half** nodes, and identifying **Boundary Nodes**. |
| **Relationship Analysis** | Finding and counting **Ancestors, Descendants, Siblings,** and **Cousins** for a specific node. |

#### 🛠️ **Implementation Details**

* **Language:** C++
* **Data Structure:** Custom-built Node leveraging a **Doubly Linked List** paradigm.
* **Performance:** All operations are developed with a strong focus on **time and space complexity analysis**, ensuring optimized and efficient performance, particularly for the search and traversal algorithms.

***

### 2. **Tower of Hanoi Solver using Doubly Linked Lists for Disk Management**

This project provides an efficient and elegant solution to the classic **Tower of Hanoi** problem. The unique aspect of this implementation is the strategic use of a **Doubly Linked List** to model and manage the stack of disks on each tower.

#### 🎯 **Objective & Solution**

The solution iteratively transfers all disks from the source peg to the destination peg, adhering strictly to the constraints of the puzzle (only one disk moved at a time, and a larger disk can never be placed on a smaller disk).

#### 💡 **Technical Advantage**

The adoption of a Doubly Linked List for disk management offers several key advantages:
* **Efficient Stack Operations:** It facilitates **$O(1)$** insertion (push) and deletion (pop) operations, which are crucial for simulating the movement of the top disk.
* **Clear State Representation:** The list structure provides a clear, ordered, and easily manipulable representation of the disks on each tower throughout the recursive process.

#### 🛠️ **Implementation Details**

* **Language:** C++
* **Data Structure:** **Doubly Linked List** used to represent the stack of disks on each of the three towers.
* **Optimization:** The solution is designed to achieve the theoretical minimum number of moves, $2^n - 1$ (where $n$ is the number of disks), ensuring **optimal time complexity**.
