//-------------------------------------------------------------------
/**
 * @file DiskStack.h
 * @brief Header file for the DiskStack class
 * @author Aditya Jedhe
 * @date 2025-01-30
 */
//-------------------------------------------------------------------

#ifndef _DISKSTACK_H_
#define _DISKSTACK_H_

// ---------------------------------------------- Forward declaration
class Node;

/**
 * @class DiskStack
 * @brief Represents a stack of disks.
 * @details The DiskStack class is used to model the stacks of disks.
 * Each stack contains a list of disks, with the top disk being the most recently added disk.
 * @note This class manages memory for the disk nodes.
 * All the Node which are stacked on disk stack are deleted when disk stack is deleted.
 * It is the responsibility of the user to ensure that all the Node stacked remain valid
 * for the lifetime of the DiskStack instance.
 */
class DiskStack
{
public:
    /**
     * @brief Constructor for DiskStack
     */
    explicit DiskStack() = default;

    /**
     * @brief Destructor for DiskStack
     * @note Deletes all the nodes which are stacked onto the disk.
     */
    virtual ~DiskStack();

    /**
     * @brief Pushes a disk node onto the stack.
     * @param[in, out] iopNode Pointer to the disk node to be pushed onto the stack.
     */
    void PushToStack(Node *iopNode);

    /**
     * @brief Pops the top disk node from the stack.
     * @return Pointer to the disk node that was popped from the stack. Returns nullptr if the stack is empty.
     */
    Node *PopFromStack();

    /**
     * @brief Prints the contents of the stack.
     */
    void PrintStack() const;

    /**
     * @brief Returns the top disk node from the stack.
     * @return Pointer to the top disk node in the stack.
     */
    inline Node *GetTopDisk() const
    {
        return _pTopDisk;
    }

private:
    /**
     *  @brief Pointer to the top disk in the stack.
     */
    Node *_pTopDisk = nullptr;
};

#endif // _DISKSTACK_H_
