//-------------------------------------------------------------------
/**
 * @file Node.h
 * @brief Header file for the Node class
 * @author Aditya Jedhe
 * @date 2025-02-05
 */
//-------------------------------------------------------------------

#ifndef _NODE_H_
#define _NODE_H_

/**
 * @class Node
 * @brief Represents a node, encapsulating a data element and pointers to two nodes.
 */
class Node
{
public:
    /**
     * @brief Constructor for Node
     * @param[in] inData Data element to store in the node
     * @note By default, both the pointers to the nodes (left and right) are set to null
     */
    Node(const int inData = 0) : _nData{inData} {}

    /**
     * @brief Destructor for Node
     */
    virtual ~Node() = default;

    /**
     * @brief Retrieves the data element stored in the node
     * @return Data element stored in the node
     * @note It is a constant member function.
     */
    inline int GetData() const noexcept
    {
        return _nData;
    }

    /**
     * @brief Retrieves the left node
     * @return Pointer to the left node
     * @note It is a constant member function.
     */
    inline Node *GetLeftNode() const noexcept
    {
        return _pLeftNode;
    }

    /**
     * @brief Retrieves the right node
     * @return Pointer to the right node
     * @note It is a constant member function.
     */
    Node *GetRightNode() const noexcept
    {
        return _pRightNode;
    }

    /**
     * @brief Sets the left node
     * @param[in] ipLeftNode Pointer to the left node
     */
    inline void SetLeftNode(Node *ipLeftNode)
    {
        _pLeftNode = ipLeftNode;
    }

    /**
     * @brief Sets the right node
     * @param[in] ipRightNode Pointer to the right node
     */
    inline void SetRightNode(Node *ipRightNode)
    {
        _pRightNode = ipRightNode;
    }

private:
    /**
     * @brief Data element stored in the node
     */
    int _nData{};

    /**
     * @brief Pointer to the left node
     */
    Node *_pLeftNode = nullptr;

    /**
     * @brief Pointer to the right node
     */
    Node *_pRightNode = nullptr;
};

#endif // _NODE_H_
