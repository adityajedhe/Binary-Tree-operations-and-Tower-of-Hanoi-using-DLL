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
#include <memory>

/**
 * @brief Main function to solve the Tower of Hanoi problem
 */
int main();

/**
 * @brief Function to solve the Tower of Hanoi problem
 * @param[in] ipCurrentNode Pointer to the current disk node
 * @param[in] ispSourceTower Pointer to the source tower
 * @param[in] ispDestinationTower Pointer to the destination tower
 * @param[in] ispHelperTower Pointer to the helper tower
 * @note This function calls itself recursively
 */
void TowerOfHanoi(Node *ipCurrentNode, std::shared_ptr<DiskStack> ispSourceTower, std::shared_ptr<DiskStack> ispDestinationTower, std::shared_ptr<DiskStack> ispHelperTower);

/**
 * @brief Function to move the disk from the source tower to the destination tower
 * @param[in, out] iospSourceTower Pointer to the source tower
 * @param[in, out] iospDestinationTower Pointer to the destination tower
 * @return Return true if the disk was moved successfully, false otherwise
 */
bool MoveDiskToDestination(std::shared_ptr<DiskStack> iospSourceTower, std::shared_ptr<DiskStack> iospDestinationTower);

/**
 * @brief Function to print the contents of the three towers
 */
void PrintStacks();

/**
 * @brief Global variable to count the number of transfers
 */
int nbIterations = 0;

/**
 * @brief Pointers to the DiskStack objects representing 3 towers of Hanoi.
 */
std::shared_ptr<DiskStack> spStackA;
std::shared_ptr<DiskStack> spStackB;
std::shared_ptr<DiskStack> spStackC;

//-------------------------------------------------------------------
int main()
{
    /**
     * Get the number of disks from user
     */
    int nbDisks = 0;

    std::cout << "Tower of Hanoi" << '\n';
    std::cout << "Enter number of disks: ";
    std::cin >> nbDisks;

    /**
     * Create three stacks for the three towers
     * DiskStack A is the source tower,
     * DiskStack B is the helper tower, and
     * DiskStack C is the destination tower
     */
    spStackA = std::make_shared<DiskStack>();
    spStackB = std::make_shared<DiskStack>();
    spStackC = std::make_shared<DiskStack>();

    if ((!spStackA) || (!spStackB) || (!spStackC))
    {
        std::cout << "Memory allocation failed" << '\n';
        return -1;
    }

    Node *pNode = nullptr;
    Node *pFirstNode = nullptr;

    /**
     *  Push the disks onto the source tower (DiskStack A)
     */
    for (int nDiskIndex = nbDisks; nDiskIndex > 0; --nDiskIndex)
    {
        pNode = new Node(nDiskIndex);

        if (nullptr == pNode)
        {
            std::cout << "Memory allocation failed" << '\n';
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
        Node *pTopDisk = spStackA->GetTopDisk();

        if (nullptr != pTopDisk)
        {
            pTopDisk->SetLeftNode(pNode);
        }

        /**
         *  Push the disk onto the source tower
         */
        spStackA->PushToStack(pNode);
    }

    PrintStacks();

    TowerOfHanoi(pFirstNode, spStackA, spStackC, spStackB);

    return 0;
}

//-------------------------------------------------------------------
void TowerOfHanoi(Node *ipCurrentNode, std::shared_ptr<DiskStack> ispSourceTower, std::shared_ptr<DiskStack> ispDestinationTower, std::shared_ptr<DiskStack> ispHelperTower)
{
    if ((nullptr == ipCurrentNode) ||
        (!ispSourceTower) ||
        (!ispDestinationTower) ||
        (!ispHelperTower))
    {
        std::cout << "Invalid input" << '\n';
        return;
    }

    Node *pNode = ipCurrentNode->GetLeftNode();

    if (nullptr == pNode)
    {
        MoveDiskToDestination(ispSourceTower, ispDestinationTower);
    }
    else
    {
        TowerOfHanoi(pNode, ispSourceTower, ispHelperTower, ispDestinationTower);

        MoveDiskToDestination(ispSourceTower, ispDestinationTower);

        TowerOfHanoi(pNode, ispHelperTower, ispDestinationTower, ispSourceTower);
    }
}

//-------------------------------------------------------------------
bool MoveDiskToDestination(std::shared_ptr<DiskStack> iospSourceTower, std::shared_ptr<DiskStack> iospDestinationTower)
{
    if ((!iospSourceTower) || (!iospDestinationTower))
    {
        return false;
    }

    bool bDiskMoved(false);

    /// Get the top disk from the source tower and the destination tower.
    Node *pSourceTop = iospSourceTower->GetTopDisk();
    Node *pDestinationTop = iospDestinationTower->GetTopDisk();

    if (nullptr != pSourceTop)
    {
        bool bMoveTheDisk(false);

        /// Check whether the destination tower is empty, or the top disk of the source tower is smaller than the top disk of the destination tower.
        if (nullptr == pDestinationTop)
        {
            bMoveTheDisk = true;
        }
        else if (pSourceTop->GetData() < pDestinationTop->GetData())
        {
            bMoveTheDisk = true;
        }

        /// If above condition is satisfied then move the disk from the source towerer to the destination tower.
        if (bMoveTheDisk)
        {
            iospDestinationTower->PushToStack(iospSourceTower->PopFromStack());

            PrintStacks();

            bDiskMoved = true;
        }
    }

    return bDiskMoved;
}

//-------------------------------------------------------------------
void PrintStacks()
{
    /**
     * Print current iteration number
     * Print all the contents of the source tower
     * Print all the contents of the helper tower
     * Print all the contents of the destination tower
     */
    std::cout << "Iteration: " << nbIterations++ << '\n';

    std::cout << "         [TOP]" << '\n';

    std::cout << "Tower A: ";
    spStackA->PrintStack();

    std::cout << "Tower B: ";
    spStackB->PrintStack();

    std::cout << "Tower C: ";
    spStackC->PrintStack();

    std::cout << '\n';
    std::cout << "-----------------------------" << '\n';
}
