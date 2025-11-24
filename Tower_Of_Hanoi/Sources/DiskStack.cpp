//-------------------------------------------------------------------
/**
 * @file DiskStack.cpp
 * @brief Implementation file for the DiskStack class
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

//-------------------------------------------------------------------
DiskStack::~DiskStack()
{
    Node *pNode = PopFromStack();

    while (nullptr != pNode)
    {
        delete pNode;
        pNode = PopFromStack();
    }
}

//-------------------------------------------------------------------
void DiskStack::PushToStack(Node *iopNode)
{
    if (nullptr != iopNode)
    {
        iopNode->SetRightNode(_pTopDisk);
        _pTopDisk = iopNode;
    }
}

//-------------------------------------------------------------------
Node *DiskStack::PopFromStack()
{
    Node *pNode = _pTopDisk;

    if (nullptr != pNode)
    {
        _pTopDisk = pNode->GetRightNode();
        pNode->SetRightNode(nullptr);
    }

    return pNode;
}

//-------------------------------------------------------------------
void DiskStack::PrintStack() const
{
    Node *pNode = _pTopDisk;

    while (nullptr != pNode)
    {
        std::cout << "Disk " << pNode->GetData();

        pNode = pNode->GetRightNode();

        if (nullptr != pNode)
        {
            std::cout << ", ";
        }
    }

    std::cout << '\n';
}
