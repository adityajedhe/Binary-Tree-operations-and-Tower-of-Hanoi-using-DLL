//-------------------------------------------------------------------
/**
 * @file BinaryTree.cpp
 * @brief Implementation file for the BinaryTree class.
 * @author Aditya Jedhe
 * @date 2025-02-06
 */
//-------------------------------------------------------------------

// ---------------------------------------------- Local Headers
#include "BinaryTree.h"

// ---------------------------------------------- Project Headers
#include "Node.h"

// ---------------------------------------------- System Headers
#include <algorithm>
#include <iostream>
#include <queue>
#include <thread>

//-------------------------------------------------------------------
BinaryTree *BinaryTree::CreateBinaryTree()
{
    return new BinaryTree;
}

//-------------------------------------------------------------------
void BinaryTree::RemoveBinaryTree(BinaryTree *&ipBinaryTree)
{
    if ((nullptr == ipBinaryTree) || (ipBinaryTree->IsEmpty()))
    {
        return;
    }

    Node *pRootNode = ipBinaryTree->_pRootNode;

    ipBinaryTree->RemoveChildren(pRootNode);

    delete pRootNode;
    pRootNode = nullptr;

    delete ipBinaryTree;
    ipBinaryTree = nullptr;
}

//-------------------------------------------------------------------
bool BinaryTree::IsEmpty()
{
    return (nullptr == _pRootNode);
}

//-------------------------------------------------------------------
void BinaryTree::InsertNodeInBinaryTree(int inData)
{
    /**
     * Create a new node with the data and
     * insert it into the complete binary tree
     * if root node exists, otherwise make it as a root node
     */
    Node *pNewNode = new Node(inData);

    if (nullptr == pNewNode)
    {
        std::cout << "Memory allocation failed" << '\n';
        return;
    }
    else if (nullptr == _pRootNode)
    {
        _pRootNode = pNewNode;
    }

    bool bNodeInserted(false);

    Node *pNode = nullptr;
    Node *pLNode = nullptr;
    Node *pRNode = nullptr;

    std::queue<Node *> qNodes;

    qNodes.push(_pRootNode);

    while ((!qNodes.empty()) && (!bNodeInserted))
    {
        pNode = qNodes.front();

        qNodes.pop();

        if (nullptr != pNode)
        {
            pLNode = pNode->GetLeftNode();
            pRNode = pNode->GetRightNode();

            if (nullptr == pLNode)
            {
                pNode->SetLeftNode(pNewNode);

                bNodeInserted = true;
            }
            else
            {
                qNodes.push(pLNode);

                if (nullptr == pRNode)
                {
                    pNode->SetRightNode(pNewNode);

                    bNodeInserted = true;
                }
                else
                {
                    qNodes.push(pRNode);
                }
            }
        }
    }
}

//-------------------------------------------------------------------
void BinaryTree::InsertNodeInBinarySearchTree(int inData)
{
    /**
     * Create a new node with the data
     * and insert it into the binary search tree
     */
    Node *pNewNode = new Node(inData);

    if (nullptr == pNewNode)
    {
        return;
    }

    if (nullptr != _pRootNode)
    {
        Node *pCurrentNode = _pRootNode;
        Node *pParentNode = nullptr;

        while (nullptr != pCurrentNode)
        {
            pParentNode = pCurrentNode;

            if (inData < pCurrentNode->GetData())
            {
                pCurrentNode = pCurrentNode->GetLeftNode();
            }
            else
            {
                pCurrentNode = pCurrentNode->GetRightNode();
            }
        }

        if (inData < pParentNode->GetData())
        {
            pParentNode->SetLeftNode(pNewNode);
        }
        else
        {
            pParentNode->SetRightNode(pNewNode);
        }
    }
    else
    {
        _pRootNode = pNewNode;
    }
}

//-------------------------------------------------------------------
void BinaryTree::DeleteBinaryTreeNode(int inData)
{
    if (IsEmpty())
    {
        return;
    }

    std::cout << "Deleting data: " << inData << '\n';
}

//-------------------------------------------------------------------
bool BinaryTree::SearchInBinaryTree(int inData)
{
    bool bFound(false);

    std::deque<Node *> dqNodes;

    Node *pNode = SearchInBinaryTree(_pRootNode, inData, dqNodes);

    if (nullptr != pNode)
    {
        bFound = true;
    }

    return bFound;
}

//-------------------------------------------------------------------
void BinaryTree::PreOrderTraversal()
{
    if (IsEmpty())
    {
        return;
    }

    std::vector<Node *> vNodes;

    PreOrderTraversalOfBinaryTreeNode(_pRootNode, vNodes);

    std::cout << "Pre order traversal: ";

    for (auto pNode : vNodes)
    {
        if (nullptr != pNode)
        {
            std::cout << pNode->GetData() << " ";
        }
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
void BinaryTree::InOrderTraversal()
{
    if (IsEmpty())
    {
        return;
    }

    std::vector<Node *> vNodes;

    InOrderTraversalOfBinaryTreeNode(_pRootNode, vNodes);

    std::cout << "In order traversal: ";

    for (auto pNode : vNodes)
    {
        if (nullptr != pNode)
        {
            std::cout << pNode->GetData() << " ";
        }
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
void BinaryTree::PostOrderTraversal()
{
    if (IsEmpty())
    {
        return;
    }

    std::vector<Node *> vNodes;

    PostOrderTraversalOfBinaryTreeNode(_pRootNode, vNodes);

    std::cout << "Post order traversal: ";

    for (auto pNode : vNodes)
    {
        if (nullptr != pNode)
        {
            std::cout << pNode->GetData() << " ";
        }
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
void BinaryTree::LevelOrderTraversal()
{
    if (IsEmpty())
    {
        return;
    }

    std::vector<Node *> vNodes;

    LevelOrderTraversalOfBinaryTreeNode(_pRootNode, vNodes);

    std::cout << "Level order traversal: ";

    for (auto pNode : vNodes)
    {
        if (nullptr != pNode)
        {
            std::cout << pNode->GetData() << " ";
        }
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
void BinaryTree::ReverseLevelOrderTraversal()
{
    if (IsEmpty())
    {
        return;
    }

    std::deque<Node *> dqNodes;

    ReverseLevelOrderTraversalOfBinaryTreeNode(_pRootNode, dqNodes);

    std::cout << "Reverse-level order traversal: ";

    Node *pNode = nullptr;

    while (!dqNodes.empty())
    {
        pNode = dqNodes.front();

        dqNodes.pop_front();

        if (nullptr != pNode)
        {
            std::cout << pNode->GetData() << " ";
        }
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
void BinaryTree::SpiralOrderTraversal()
{
    if (IsEmpty())
    {
        return;
    }

    std::vector<Node *> vNodes;

    SpiralOrderTraversalOfBinaryTreeNode(_pRootNode, vNodes);

    std::cout << "Spiral-level order traversal: ";

    for (auto pNode : vNodes)
    {
        if (nullptr != pNode)
        {
            std::cout << pNode->GetData() << " ";
        }
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
void BinaryTree::PrintLeafNodes()
{
    if (IsEmpty())
    {
        return;
    }

    std::vector<Node *> vNodes;

    RetrieveLeafNodesOfBinaryTreeNode(_pRootNode, vNodes);

    std::cout << "Leaf nodes: ";

    for (auto pNode : vNodes)
    {
        if (nullptr != pNode)
        {
            std::cout << pNode->GetData() << " ";
        }
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
void BinaryTree::PrintNonLeafNodes()
{
    if (IsEmpty())
    {
        return;
    }

    std::vector<Node *> vNodes;

    RetrieveNonLeafNodesOfBinaryTreeNode(_pRootNode, vNodes);

    std::cout << "Non-leaf nodes: ";

    for (auto pNode : vNodes)
    {
        if (nullptr != pNode)
        {
            std::cout << pNode->GetData() << " ";
        }
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
void BinaryTree::PrintBoundaryNodes()
{
    if (IsEmpty())
    {
        return;
    }

    std::vector<Node *> vNodes;

    vNodes.push_back(_pRootNode);

    RetrieveLeftBoundaryNodesOfBinaryTreeNode(_pRootNode->GetLeftNode(),
                                              vNodes);

    RetrieveLeafNodesOfBinaryTreeNode(_pRootNode,
                                      vNodes);

    RetrieveRightBoundaryNodesOfBinaryTreeNode(_pRootNode->GetRightNode(),
                                               vNodes);

    std::cout << "Boundary nodes: ";

    for (auto pNode : vNodes)
    {
        if (nullptr != pNode)
        {
            std::cout << pNode->GetData() << " ";
        }
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
void BinaryTree::PrintAllFullNodes()
{
    std::vector<Node *> vNodes;

    PrintFullNodes(_pRootNode,
                   vNodes);

    std::cout << "Full nodes: ";

    for (auto pNode : vNodes)
    {
        if (nullptr != pNode)
        {
            std::cout << pNode->GetData() << " ";
        }
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
void BinaryTree::PrintAllHalfNodes()
{
    std::vector<Node *> vNodes;

    PrintHalfNodes(_pRootNode,
                   vNodes);

    std::cout << "Half nodes: ";

    for (auto pNode : vNodes)
    {
        if (nullptr != pNode)
        {
            std::cout << pNode->GetData() << " ";
        }
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
void BinaryTree::PrintAllNodesAtKDistance(int inKDistance)
{
    std::vector<Node *> vNodes;

    RetrieveAllNodesAtKDistance(_pRootNode,
                                inKDistance,
                                vNodes);

    std::cout << "All nodes at 'k' distance: ";

    for (auto pNode : vNodes)
    {
        if (nullptr != pNode)
        {
            std::cout << pNode->GetData() << " ";
        }
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
void BinaryTree::PrintSibling(int inData)
{
    Node *pNode = RetrieveSibling(_pRootNode, inData);

    if (nullptr != pNode)
    {
        std::cout << "Sibling of " << inData << ": " << pNode->GetData();
    }
    else
    {
        std::cout << "No sibling present for the given data." << '\n';
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
void BinaryTree::PrintCousins(int inData)
{
    std::vector<Node *> vNodes;

    RetrieveCousins(_pRootNode,
                    inData,
                    vNodes);

    std::cout << "Cousins of " << inData << ": ";

    for (auto pNode : vNodes)
    {
        if (nullptr != pNode)
        {
            std::cout << pNode->GetData() << " ";
        }
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
void BinaryTree::PrintAncestors(int inData)
{
    if (IsEmpty())
    {
        return;
    }

    std::deque<Node *> dqNodes;

    Node *pNode = SearchInBinaryTree(_pRootNode,
                                     inData,
                                     dqNodes);

    if (nullptr != pNode)
    {
        std::cout << "Ancestors of " << inData << ": ";

        for (auto pNode : dqNodes)
        {
            if (nullptr != pNode)
            {
                std::cout << pNode->GetData() << " ";
            }
        }
    }
    else
    {
        std::cout << "Node is not found for the given data." << '\n';
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
void BinaryTree::PrintDecendants(int inData)
{
    std::deque<Node *> dqNodes;

    Node *pNode = SearchInBinaryTree(_pRootNode,
                                     inData,
                                     dqNodes);

    std::vector<Node *> vNodes;

    PreOrderTraversalOfBinaryTreeNode(pNode,
                                      vNodes);

    std::cout << "Decendants of " << inData << ": ";

    for (auto pNode : vNodes)
    {
        if (nullptr != pNode)
        {
            std::cout << pNode->GetData() << " ";
        }
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
void BinaryTree::PrintAncestor(int inData)
{
    std::deque<Node *> dqNodes;

    if (nullptr != SearchInBinaryTree(_pRootNode, inData, dqNodes))
    {
        Node *pNode = dqNodes.back();

        if (nullptr != pNode)
        {
            std::cout << "Ancestor of " << inData << ": " << pNode->GetData();
        }
    }
    else
    {
        std::cout << "Node is not found for the given data." << '\n';
    }

    std::cout << '\n';
}

//-------------------------------------------------------------------
int BinaryTree::HeightOfBinaryTree()
{
    return HeightOfSubBinaryTree(_pRootNode);
}

//-------------------------------------------------------------------
int BinaryTree::FindLevelOfNode(int inData)
{
    int nLevel(-1);

    std::deque<Node *> dqNodes;

    if (SearchInBinaryTree(_pRootNode, inData, dqNodes))
    {
        nLevel = dqNodes.size();
    }

    return nLevel;
}

//===================================================================
// Private Methods: Implementation
//===================================================================

//-------------------------------------------------------------------
BinaryTree::BinaryTree() : _pRootNode(nullptr)
{
}

//-------------------------------------------------------------------
BinaryTree::~BinaryTree()
{
}

//-------------------------------------------------------------------
void BinaryTree::RemoveChildren(Node *ipParentNode)
{
    if (nullptr != ipParentNode)
    {
        Node *pLNode = ipParentNode->GetLeftNode();
        Node *pRNode = ipParentNode->GetRightNode();

        std::thread objThread1(&BinaryTree::RemoveChildren, this, pLNode);
        std::thread objThread2(&BinaryTree::RemoveChildren, this, pRNode);

        objThread1.join();
        objThread2.join();

        delete pLNode;
        delete pRNode;

        pLNode = nullptr;
        pRNode = nullptr;
    }
}

//-------------------------------------------------------------------
Node *BinaryTree::SearchInBinaryTree(Node *ipNode,
                                     int inData,
                                     std::deque<Node *> &iodqNodes)
{
    Node *pNode = nullptr;

    if (nullptr != ipNode)
    {
        if (ipNode->GetData() == inData)
        {
            pNode = ipNode;
        }
        else
        {
            pNode = SearchInBinaryTree(ipNode->GetLeftNode(), inData, iodqNodes);

            if (nullptr == pNode)
            {
                pNode = SearchInBinaryTree(ipNode->GetRightNode(), inData, iodqNodes);
            }

            if (nullptr != pNode)
            {
                iodqNodes.push_front(ipNode);
            }
        }
    }

    return pNode;
}

//-------------------------------------------------------------------
void BinaryTree::PreOrderTraversalOfBinaryTreeNode(Node *ipNode,
                                                   std::vector<Node *> &iovNodes)
{
    if (nullptr != ipNode)
    {
        iovNodes.push_back(ipNode);

        PreOrderTraversalOfBinaryTreeNode(ipNode->GetLeftNode(), iovNodes);
        PreOrderTraversalOfBinaryTreeNode(ipNode->GetRightNode(), iovNodes);
    }
}

//-------------------------------------------------------------------
void BinaryTree::InOrderTraversalOfBinaryTreeNode(Node *ipNode,
                                                  std::vector<Node *> &iovNodes)
{
    if (nullptr != ipNode)
    {
        InOrderTraversalOfBinaryTreeNode(ipNode->GetLeftNode(), iovNodes);

        iovNodes.push_back(ipNode);

        InOrderTraversalOfBinaryTreeNode(ipNode->GetRightNode(), iovNodes);
    }
}

//-------------------------------------------------------------------
void BinaryTree::PostOrderTraversalOfBinaryTreeNode(Node *ipNode,
                                                    std::vector<Node *> &iovNodes)
{
    if (nullptr != ipNode)
    {
        PostOrderTraversalOfBinaryTreeNode(ipNode->GetLeftNode(), iovNodes);
        PostOrderTraversalOfBinaryTreeNode(ipNode->GetRightNode(), iovNodes);

        iovNodes.push_back(ipNode);
    }
}

//-------------------------------------------------------------------
void BinaryTree::LevelOrderTraversalOfBinaryTreeNode(Node *ipRootNode,
                                                     std::vector<Node *> &ovNodes)
{
    Node *pNode = nullptr;
    Node *pLNode = nullptr;
    Node *pRNode = nullptr;

    ovNodes.push_back(ipRootNode);

    for (int nIdx = 0; nIdx < (int)(ovNodes.size()); ++nIdx)
    {
        pNode = ovNodes[nIdx];

        if (nullptr != pNode)
        {
            pLNode = pNode->GetLeftNode();
            pRNode = pNode->GetRightNode();

            if (nullptr != pLNode)
            {
                ovNodes.push_back(pLNode);
            }

            if (nullptr != pRNode)
            {
                ovNodes.push_back(pRNode);
            }
        }
    }
}

//-------------------------------------------------------------------
void BinaryTree::ReverseLevelOrderTraversalOfBinaryTreeNode(Node *ipRootNode,
                                                            std::deque<Node *> &odqNodes)
{
    std::deque<Node *> dqNextLevelNodes;

    std::deque<Node *> dqCurrentLevel;

    odqNodes.push_front(ipRootNode);
    dqCurrentLevel.push_back(ipRootNode);

    Node *pNode = nullptr;
    Node *pLNode = nullptr;
    Node *pRNode = nullptr;

    while (!dqCurrentLevel.empty())
    {
        pNode = dqCurrentLevel.front();

        dqCurrentLevel.pop_front();

        if (nullptr == pNode)
        {
            continue;
        }

        pLNode = pNode->GetLeftNode();
        pRNode = pNode->GetRightNode();

        if (nullptr != pLNode)
        {
            dqNextLevelNodes.push_back(pLNode);
        }

        if (nullptr != pRNode)
        {
            dqNextLevelNodes.push_back(pRNode);
        }

        if (dqCurrentLevel.empty())
        {
            dqCurrentLevel = dqNextLevelNodes;

            while (!dqNextLevelNodes.empty())
            {
                pNode = dqNextLevelNodes.back();

                dqNextLevelNodes.pop_back();

                odqNodes.push_front(pNode);
            }
        }
    }
}

//-------------------------------------------------------------------
void BinaryTree::SpiralOrderTraversalOfBinaryTreeNode(Node *ipRootNode,
                                                      std::vector<Node *> &ovNodes)
{
    bool bTraverseDirection(true);

    std::deque<Node *> dqNodesAtNextLevel;
    std::deque<Node *> dqCurrentLevel;

    ovNodes.push_back(ipRootNode);
    dqCurrentLevel.push_back(ipRootNode);

    Node *pNode = nullptr;
    Node *pLNode = nullptr;
    Node *pRNode = nullptr;

    while (!dqCurrentLevel.empty())
    {
        pNode = dqCurrentLevel.front();

        dqCurrentLevel.pop_front();

        if (nullptr == pNode)
        {
            continue;
        }

        pLNode = pNode->GetLeftNode();
        pRNode = pNode->GetRightNode();

        if (nullptr != pLNode)
        {
            dqNodesAtNextLevel.push_back(pLNode);
        }

        if (nullptr != pRNode)
        {
            dqNodesAtNextLevel.push_back(pRNode);
        }

        if (dqCurrentLevel.empty())
        {
            dqCurrentLevel = dqNodesAtNextLevel;

            while (!dqNodesAtNextLevel.empty())
            {
                if (bTraverseDirection)
                {
                    pNode = dqNodesAtNextLevel.back();
                    dqNodesAtNextLevel.pop_back();
                }
                else
                {
                    pNode = dqNodesAtNextLevel.front();
                    dqNodesAtNextLevel.pop_front();
                }

                ovNodes.push_back(pNode);
            }

            bTraverseDirection = !bTraverseDirection;
        }
    }
}

//-------------------------------------------------------------------
void BinaryTree::RetrieveLeafNodesOfBinaryTreeNode(Node *ipNode,
                                                   std::vector<Node *> &iovNodes)
{
    if (nullptr != ipNode)
    {
        if ((nullptr == ipNode->GetLeftNode()) &&
            (nullptr == ipNode->GetRightNode()))
        {
            iovNodes.push_back(ipNode);
        }
        else
        {
            RetrieveLeafNodesOfBinaryTreeNode(ipNode->GetLeftNode(), iovNodes);
            RetrieveLeafNodesOfBinaryTreeNode(ipNode->GetRightNode(), iovNodes);
        }
    }
}

//-------------------------------------------------------------------
void BinaryTree::RetrieveNonLeafNodesOfBinaryTreeNode(Node *ipNode,
                                                      std::vector<Node *> &iovNodes)
{
    if ((nullptr != ipNode) && ((nullptr != ipNode->GetLeftNode()) ||
                                (nullptr != ipNode->GetRightNode())))
    {
        iovNodes.push_back(ipNode);

        RetrieveNonLeafNodesOfBinaryTreeNode(ipNode->GetLeftNode(), iovNodes);
        RetrieveNonLeafNodesOfBinaryTreeNode(ipNode->GetRightNode(), iovNodes);
    }
}

//-------------------------------------------------------------------
void BinaryTree::RetrieveLeftBoundaryNodesOfBinaryTreeNode(Node *ipNode,
                                                           std::vector<Node *> &iovNodes)
{
    if (nullptr != ipNode)
    {
        Node *pNode = ipNode->GetLeftNode();

        if (nullptr == pNode)
        {
            pNode = ipNode->GetRightNode();
        }

        if (nullptr != pNode)
        {
            iovNodes.push_back(ipNode);

            RetrieveLeftBoundaryNodesOfBinaryTreeNode(pNode, iovNodes);
        }
    }
}

//-------------------------------------------------------------------
void BinaryTree::RetrieveRightBoundaryNodesOfBinaryTreeNode(Node *ipNode,
                                                            std::vector<Node *> &iovNodes)
{
    if (nullptr != ipNode)
    {
        Node *pNextNode = ipNode->GetRightNode();

        if (nullptr == pNextNode)
        {
            pNextNode = ipNode->GetLeftNode();
        }

        if (nullptr != pNextNode)
        {
            iovNodes.push_back(ipNode);

            RetrieveRightBoundaryNodesOfBinaryTreeNode(pNextNode, iovNodes);
        }
    }
}

//-------------------------------------------------------------------
void BinaryTree::PrintFullNodes(Node *ipNode,
                                std::vector<Node *> &iovNodes)
{
    if (nullptr != ipNode)
    {
        Node *pLNode = ipNode->GetLeftNode();
        Node *pRNode = ipNode->GetRightNode();

        if (((nullptr == pLNode) && (nullptr == pRNode)) ||
            ((nullptr != pLNode) && (nullptr != pRNode)))
        {
            iovNodes.push_back(ipNode);
        }

        PrintFullNodes(pLNode, iovNodes);
        PrintFullNodes(pRNode, iovNodes);
    }
}

//-------------------------------------------------------------------
void BinaryTree::PrintHalfNodes(Node *ipNode,
                                std::vector<Node *> &iovNodes)
{
    if (nullptr != ipNode)
    {
        Node *pLNode = ipNode->GetLeftNode();
        Node *pRNode = ipNode->GetRightNode();

        if (((nullptr != pLNode) && (nullptr == pRNode)) ||
            ((nullptr == pLNode) && (nullptr != pRNode)))
        {
            iovNodes.push_back(ipNode);
        }

        PrintHalfNodes(pLNode, iovNodes);
        PrintHalfNodes(pRNode, iovNodes);
    }
}

//-------------------------------------------------------------------
void BinaryTree::RetrieveAllNodesAtKDistance(Node *ipNode,
                                             int inKDistance,
                                             std::vector<Node *> &iovNodes)
{
    if (nullptr != ipNode)
    {
        if (0 == inKDistance)
        {
            iovNodes.push_back(ipNode);
        }
        else
        {
            RetrieveAllNodesAtKDistance(ipNode->GetLeftNode(),
                                        inKDistance - 1,
                                        iovNodes);
            RetrieveAllNodesAtKDistance(ipNode->GetRightNode(),
                                        inKDistance - 1,
                                        iovNodes);
        }
    }
}

//-------------------------------------------------------------------
Node *BinaryTree::RetrieveSibling(Node *ipNode,
                                  int inData)
{
    Node *pNode = nullptr;

    if (nullptr != ipNode)
    {
        Node *pLNode = ipNode->GetLeftNode();
        Node *pRNode = ipNode->GetRightNode();

        if ((nullptr != pLNode) && (pLNode->GetData() == inData))
        {
            pNode = pRNode;
        }
        else if ((nullptr != pRNode) && (pRNode->GetData() == inData))
        {
            pNode = pLNode;
        }

        if (nullptr == pNode)
        {
            pNode = RetrieveSibling(pLNode, inData);

            if (nullptr == pNode)
            {
                pNode = RetrieveSibling(pRNode, inData);
            }
        }
    }

    return pNode;
}

//-------------------------------------------------------------------
void BinaryTree::RetrieveCousins(Node *ipRootNode,
                                 int inData,
                                 std::vector<Node *> &ovNodes)
{
    if (nullptr == ipRootNode)
    {
        return;
    }

    bool bFound(false);

    Node *pNode = nullptr;
    Node *pLNode = nullptr;
    Node *pRNode = nullptr;

    std::queue<Node *> qCurrLevelNodes;
    std::queue<Node *> qNextLevelNodes;

    qCurrLevelNodes.push(ipRootNode);

    while (!qCurrLevelNodes.empty())
    {
        pNode = qCurrLevelNodes.front();

        qCurrLevelNodes.pop();

        if (nullptr != pNode)
        {
            pLNode = pNode->GetLeftNode();
            pRNode = pNode->GetRightNode();

            if (((nullptr != pLNode) && (pLNode->GetData() == inData)) ||
                ((nullptr != pRNode) && (pRNode->GetData() == inData)))
            {
                bFound = true;
            }
            else
            {
                qNextLevelNodes.push(pLNode);
                qNextLevelNodes.push(pRNode);
            }
        }

        if ((qCurrLevelNodes.empty()) && (!bFound))
        {
            std::swap(qCurrLevelNodes, qNextLevelNodes);
        }
    }

    while (!qNextLevelNodes.empty())
    {
        pNode = qNextLevelNodes.front();

        qNextLevelNodes.pop();

        if (nullptr != pNode)
        {
            ovNodes.push_back(pNode);
        }
    }
}

//-------------------------------------------------------------------
int BinaryTree::HeightOfSubBinaryTree(Node *ipNode)
{
    int nHeight(-1);

    if (nullptr != ipNode)
    {
        int nLHeight = HeightOfSubBinaryTree(ipNode->GetLeftNode());
        int nRHeight = HeightOfSubBinaryTree(ipNode->GetRightNode());

        nHeight = (nLHeight > nRHeight) ? (nLHeight + 1) : (nRHeight + 1);
    }

    return nHeight;
}
