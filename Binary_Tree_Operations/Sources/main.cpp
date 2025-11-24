//-------------------------------------------------------------------
/**
 * @file main.cpp
 * @brief The file contains the main function of the project
 * @details This file lists all the operations that can be performed on a binary tree.
 * @author Aditya Jedhe
 * @date 2025-02-10
 */
//-------------------------------------------------------------------

// ---------------------------------------------- Local Headers
#include "BinaryTree.h"

// ---------------------------------------------- System Headers
#include <iostream>
#include <vector>

/**
 * @brief Main function to perform the operations that can be performed on a binary tree
 */
int main();

/**
 * @brief Creates and initialises the tree
 * @details A binary tree is constructed by inserting each node sequentially at the current level. Once all nodes at that level are filled, the insertion continues at the next level, and this process repeats.
 * @return Pointer to created BinaryTree instance
 * @note Delete the pointer returned by the method
 */
BinaryTree *RetrieveInitialisedBinaryTree();

/**
 * @brief Creates and initialises the binary search tree
 * @details A BinaryTree is constructed by inserting each Node sequentially at the current level. Once all Nodes at that level are filled, the insertion continues at the next level, and this process repeats.
 * @return Pointer to created BinaryTree instance
 * @note Delete the pointer returned by the method
 * @warning Failing to delete the pointer will result in a memory leak.
 */
BinaryTree *RetrieveInitialisedBinarySearchTree();

/**
 * @brief Displays the list of all the operations of binary tree
 * @return Option number chosen by user w.r.t. the operation
 */
int RetrieveUserOperation();

/**
 * @brief Perform the operation on binary tree base on user selected option
 * @param[in] ipBinaryTree Binary tree on which operation will be performed
 * @param[in] inOption An option selected by user
 */
void PerformOperation(BinaryTree *ipBinaryTree, int inOption);

//-------------------------------------------------------------------
int main()
{
    BinaryTree *pBinaryTree1 = RetrieveInitialisedBinaryTree();

    // int nOption = RetrieveUserOperation();
    //
    // PerformOperation(pBinaryTree, nOption);
    if (nullptr != pBinaryTree1)
    {
        pBinaryTree1->PreOrderTraversal();
        pBinaryTree1->InOrderTraversal();
        pBinaryTree1->PostOrderTraversal();
        pBinaryTree1->LevelOrderTraversal();
        pBinaryTree1->ReverseLevelOrderTraversal();
        pBinaryTree1->SpiralOrderTraversal();
        pBinaryTree1->PrintLeafNodes();
        pBinaryTree1->PrintNonLeafNodes();
        pBinaryTree1->PrintBoundaryNodes();
        pBinaryTree1->PrintAllFullNodes();
        pBinaryTree1->PrintAllHalfNodes();
        pBinaryTree1->PrintAncestors(30);
        pBinaryTree1->PrintAncestor(30);
        pBinaryTree1->PrintDecendants(6);

        BinaryTree::RemoveBinaryTree(pBinaryTree1);
    }

    BinaryTree *pBinaryTree2 = RetrieveInitialisedBinarySearchTree();

    if (nullptr != pBinaryTree2)
    {
        pBinaryTree2->PreOrderTraversal();
        pBinaryTree2->InOrderTraversal();
        pBinaryTree2->PostOrderTraversal();
        pBinaryTree2->LevelOrderTraversal();
        pBinaryTree2->ReverseLevelOrderTraversal();
        pBinaryTree2->SpiralOrderTraversal();
        pBinaryTree2->PrintLeafNodes();
        pBinaryTree2->PrintNonLeafNodes();
        pBinaryTree2->PrintBoundaryNodes();
        pBinaryTree2->PrintAllFullNodes();
        pBinaryTree2->PrintAllHalfNodes();
        pBinaryTree2->PrintAncestors(30);
        pBinaryTree2->PrintAncestor(15);
        pBinaryTree2->PrintDecendants(6);

        BinaryTree::RemoveBinaryTree(pBinaryTree2);
    }

    return 0;
}

//-------------------------------------------------------------------
BinaryTree *RetrieveInitialisedBinaryTree()
{
    BinaryTree *pBinaryTree = BinaryTree::CreateBinaryTree();

    std::vector<int> vValues = {
        1,
        2, 3,
        4, 5, 6, 7,
        8, 9, 10, 11, 12, 13, 14, 15,
        16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

    for (auto nValue : vValues)
    {
        pBinaryTree->InsertNodeInBinaryTree(nValue);
    }

    return pBinaryTree;
}

//-------------------------------------------------------------------
BinaryTree *RetrieveInitialisedBinarySearchTree()
{
    BinaryTree *pBinaryTree = BinaryTree::CreateBinaryTree();

    std::vector<int> vValues = {
        16,
        8, 24,
        4, 12, 20, 28,
        2, 6, 10, 14, 18, 22, 26, 30,
        1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31};

    for (auto nValue : vValues)
    {
        pBinaryTree->InsertNodeInBinarySearchTree(nValue);
    }

    return pBinaryTree;
}

//-------------------------------------------------------------------
int RetrieveUserOperation()
{
    std::cout
        << "List of operations:\
                  01. Insert a node in the binary tree\
                  02. Insert a node in the binary search tree\
                  03. Delete a node from the binary tree[Not yet impl'd]\
                  04. Search for a node in the binary tree\
                  05. Search for a node in the binary search tree[Not yet impl'd]\
                  06. Traverse the binary tree: Pre-order\
                  07. Traverse the binary tree: In-order\
                  08. Traverse the binary tree: Post-order\
                  09. Traverse the binary tree: Level-order\
                  10. Traverse the binary tree: Reverse-Level-order\
                  11. Traverse the binary tree: Spiral-order\
                  12. Print all the leaf nodes in the binary tree\
                  13. Print all the non-leaf nodes in the binary tree\
                  14. Print all the border nodes of the binary tree\
                  15. Print all the full nodes in the binary tree\
                  16. Print all the half nodes in the binary tree\
                  17. Print all the nodes in the binary tree at k-level\
                  18. Print all the siblings of a node in the binary tree\
                  19. Print all the cousins of a node in the binary tree\
                  20. Print all the ancestors of a node in the binary tree\
                  21. Print all the descendants of a node in the binary tree\
                  22. Find the immidiate ancestor of a node in the binary tree\
                  23. Find the height of the binary tree\
                  24. Find the level of a node in the binary tree"
        << '\n';

    int nOption(0);

    std::cin >> nOption;

    return nOption;
}

//-------------------------------------------------------------------
void PerformOperation(BinaryTree *ipBinaryTree, int inOption)
{
    if ((nullptr == ipBinaryTree) || (1 > inOption) || (21 < inOption))
    {
        return;
    }

    switch (inOption)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        ipBinaryTree->PreOrderTraversal();
        break;
    case 7:
        ipBinaryTree->InOrderTraversal();
        break;
    case 8:
        ipBinaryTree->PostOrderTraversal();
        break;
    case 9:
        ipBinaryTree->LevelOrderTraversal();
        break;
    case 10:
        ipBinaryTree->ReverseLevelOrderTraversal();
        break;
    case 11:
        ipBinaryTree->PrintLeafNodes();
        break;
    case 12:
        ipBinaryTree->PrintNonLeafNodes();
        break;
    case 13:
        ipBinaryTree->PrintBoundaryNodes();
        break;
    }
}
