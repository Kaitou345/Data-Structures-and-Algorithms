#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node<T>* next = nullptr;
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node()
    {
        this->next = nullptr;
    }
};

/// Template takes the type of the data in the list
template <typename T>
class LinkedList
{
public:
    LinkedList(T data)
    {    
        m_head = new Node<T>(data);
        m_current = m_head;
    }
    LinkedList() {}
    void Append(T data)
    {
        if(!m_head)
        {
            m_head = new Node<T>(data);
            m_current = m_head;
        }
        else
        {
            m_current->next = new Node<T>(data);
            m_current = m_current->next;
        }
    
    }
    ~LinkedList()
    {
        Node<T>* cur = m_head;

        while(cur)
        {
            Node<T>* cur2 = cur->next;
            delete cur;
            cur = cur2;
        }
    }
    void Prepend(T data)
    {
        
        Node<T>* temp = new Node<T>(data);
        temp->next = m_head;
        m_head = temp;

    }
    int Search(T target)
    {
        Node<T>* cur = m_head;

        int i = 0;  
        while(cur)
        {
            if(target == cur->data)
            {
                return i;
            }
            cur = cur->next;
            i++;
        }

        return -1;
    }
    void InsertAt(int index, T data)
    {
        Node<T>* cur = m_head;

        int i = 0;
        while(i < index - 1)
        {
            cur = cur->next;
            i++;
        }

        Node<T>* prev = cur;
        cur = cur->next;

        Node<T>* new_node = new Node<T>(data);
        prev->next = new_node;
        new_node->next = cur;
    }
    void Remove(T target)
    {
        if(m_head->data == target)
        {
            Node<T>* head = m_head;
            m_head = m_head->next;
            delete head;
            return;
        }

        Node<T>* cur = m_head->next;
        Node<T>* prev;
        Node<T>* next;

        while(cur)
        { 
            next = cur->next->next;
            if(cur->data == target)
            {
                delete cur;
                prev->next = next;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
        
    }
    void Print()
    {
        Node<T>* cur = m_head;

        int i = 1;
        while(cur)
        {
            std::cout << "Node " << i++ << ": " << cur->data << std::endl;
            cur = cur->next;
        }
    }

private:
    Node<T>* m_head = nullptr;
    Node<T>* m_current = nullptr;
};

