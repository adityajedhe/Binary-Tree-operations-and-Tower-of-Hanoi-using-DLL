//-------------------------------------------------------------------
/**
 * @file main.cpp
 * @brief The file contains the main function of the project
 * @details It contains the algorithm to solve Tower of Hanoi problem.
 * @author Aditya Jedhe
 * @date 2025-01-30
 */
//-------------------------------------------------------------------

// ---------------------------------------------- Local headers
#include "DiskStack.h"

// ---------------------------------------------- Project headers
#include "Node.h"

// ---------------------------------------------- System headers
#include <iostream>

/**
 * @brief Main function to solve the Tower of Hanoi problem
 */
int main();

/**
 * @brief Function to delete the stack and its all nodes
 * @param[in, out] iopStack Pointer to the stack to be deleted
 */
void DeleteStack(DiskStack *&iopStack);

/**
 * @brief Function to solve the Tower of Hanoi problem
 * @param[in] ipCurrentNode Pointer to the current disk node
 * @param[in] ipSourceRod Pointer to the source rod
 * @param[in] ipDestinationRod Pointer to the destination rod
 * @param[in] ipHelperRod Pointer to the helper rod
 * @note This function calls itself recursively
 */
void TowerOfHanoi(Node *ipCurrentNode, DiskStack *ipSourceRod, DiskStack *ipDestinationRod, DiskStack *ipHelperRod);

/**
 * @brief Function to move the disk from the source rod to the destination rod
 * @param[in, out] iopSourceRod Pointer to the source rod
 * @param[in, out] iopDestinationRod Pointer to the destination rod
 * @return Return true if the disk was moved successfully, false otherwise
 */
bool MoveTheDiskToDestination(DiskStack *iopSourceRod, DiskStack *iopDestinationRod);

/**
 * @brief Function to print the contents of the three rods
 */
void PrintStacks();

/**
 * @brief Global variable to count the number of transfers
 */
int nbIterations = 0;

/**
 * @brief Pointer to the DiskStack object representing stack A.
 */
DiskStack *pStackA = nullptr;

/**
 * @brief Pointer to the DiskStack object representing stack B.
 */
DiskStack *pStackB = nullptr;

/**
 * @brief Pointer to the DiskStack object representing stack C.
 */
DiskStack *pStackC = nullptr;

//-------------------------------------------------------------------
int main()
{
    /**
     * Get the number of disks from user
     */
    int nbDisks = 0;

    std::cout << "Tower of Hanoi" << std::endl;
    std::cout << "Enter number of disks: ";
    std::cin >> nbDisks;

    /**
     * Create three stacks for the three rods
     * DiskStack A is the source rod,
     * DiskStack B is the helper rod, and
     * DiskStack C is the destination rod
     */
    pStackA = new DiskStack();
    pStackB = new DiskStack();
    pStackC = new DiskStack();

    if ((nullptr == pStackA) || (nullptr == pStackB) || (nullptr == pStackC))
    {
        std::cout << "Memory allocation failed" << std::endl;

        DeleteStack(pStackA);
        DeleteStack(pStackB);
        DeleteStack(pStackC);

        return -1;
    }

    Node *pNode = nullptr;
    Node *pFirstNode = nullptr;

    /**
     *  Push the disks onto the source rod (DiskStack A)
     */
    for (int nDiskIndex = nbDisks; nDiskIndex > 0; --nDiskIndex)
    {
        pNode = new Node(nDiskIndex);

        if (nullptr == pNode)
        {
            std::cout << "Memory allocation failed" << std::endl;

            DeleteStack(pStackA);
            DeleteStack(pStackB);
            DeleteStack(pStackC);

            return -1;
        }

        if (nullptr == pFirstNode)
        {
            pFirstNode = pNode;
        }

        /**
         * Set the previous disk node to the top disk node.
         * This has to be done only once i.e. while initializing the stack.
         */
        Node *pTopDisk = pStackA->GetTopDisk();

        if (nullptr != pTopDisk)
        {
            pTopDisk->SetLeftNode(pNode);
        }

        /**
         *  Push the disk onto the source rod
         */
        pStackA->PushToStack(pNode);
    }

    PrintStacks();

    TowerOfHanoi(pFirstNode, pStackA, pStackC, pStackB);

    DeleteStack(pStackA);
    DeleteStack(pStackB);
    DeleteStack(pStackC);

    return 0;
}

//-------------------------------------------------------------------
void DeleteStack(DiskStack *&iopStack)
{
    delete iopStack;
    iopStack = nullptr;
}

//-------------------------------------------------------------------
void TowerOfHanoi(Node *ipCurrentNode, DiskStack *ipSourceRod, DiskStack *ipDestinationRod, DiskStack *ipHelperRod)
{
    if ((nullptr == ipCurrentNode) ||
        (nullptr == ipSourceRod) ||
        (nullptr == ipDestinationRod) ||
        (nullptr == ipHelperRod))
    {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    Node *pNode = ipCurrentNode->GetLeftNode();

    if (nullptr == pNode)
    {
        MoveTheDiskToDestination(ipSourceRod, ipDestinationRod);
    }
    else
    {
        TowerOfHanoi(pNode, ipSourceRod, ipHelperRod, ipDestinationRod);

        MoveTheDiskToDestination(ipSourceRod, ipDestinationRod);

        TowerOfHanoi(pNode, ipHelperRod, ipDestinationRod, ipSourceRod);
    }
}

//-------------------------------------------------------------------
bool MoveTheDiskToDestination(DiskStack *iopSourceRod, DiskStack *iopDestinationRod)
{
    bool bDiskMoved(false);

    if ((nullptr != iopSourceRod) && (nullptr != iopDestinationRod))
    {
        /**
         * Get the top disk from the source rod and the destination rod.
         */
        Node *pSourceTop = iopSourceRod->GetTopDisk();
        Node *pDestinationTop = iopDestinationRod->GetTopDisk();

        if (nullptr != pSourceTop)
        {
            bool bMoveTheDisk(false);

            /**
             * Check whether the destination rod is empty, or the top disk of the source rod is smaller than the top disk of the destination rod.
             */
            if (nullptr == pDestinationTop)
            {
                bMoveTheDisk = true;
            }
            else if (pSourceTop->GetData() < pDestinationTop->GetData())
            {
                bMoveTheDisk = true;
            }

            /**
             * If above condition is satisfied then move the disk from the source rod to the destination rod.
             */
            if (bMoveTheDisk)
            {
                iopDestinationRod->PushToStack(iopSourceRod->PopFromStack());

                PrintStacks();

                bDiskMoved = true;
            }
        }
    }

    return bDiskMoved;
}

//-------------------------------------------------------------------
void PrintStacks()
{
    /**
     * Print current iteration number
     * Print all the contents of the source rod
     * Print all the contents of the helper rod
     * Print all the contents of the destination rod
     */
    std::cout << "Iteration: " << nbIterations++ << std::endl;

    std::cout << "         [TOP]" << std::endl;

    std::cout << "Tower A: ";
    pStackA->PrintStack();

    std::cout << "Tower B: ";
    pStackB->PrintStack();

    std::cout << "Tower C: ";
    pStackC->PrintStack();

    std::cout << std::endl;
    std::cout << "-----------------------------" << std::endl;
}
