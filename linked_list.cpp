#include <iostream>

struct Node
{
    int data;
    Node* next = nullptr;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node()
    {
        this->data = 0;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    LinkedList(int data)
    {    
        m_head = new Node(data);
        m_current = m_head;
    }
    LinkedList() {}
    void Append(int data)
    {
        if(!m_head)
        {
            m_head = new Node(data);
            m_current = m_head;
        }
        else
        {
            m_current->next = new Node(data);
            m_current = m_current->next;
        }
    
    }
    ~LinkedList()
    {
        Node* cur = m_head;

        while(cur)
        {
            Node* cur2 = cur->next;
            delete cur;
            cur = cur2;
        }
    }
    void Prepend(int data)
    {
        
        Node* temp = new Node(data);
        temp->next = m_head;
        m_head = temp;

    }
    int Search(int target)
    {
        Node* cur = m_head;

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
    void InsertAt(int index, int data)
    {
        Node* cur = m_head;

        int i = 0;
        while(i < index - 1)
        {
            cur = cur->next;
            i++;
        }

        Node* prev = cur;
        cur = cur->next;

        Node* new_node = new Node(data);
        prev->next = new_node;
        new_node->next = cur;
    }
    void Remove(int target)
    {
        if(m_head->data == target)
        {
            Node* head = m_head;
            m_head = m_head->next;
            delete head;
            return;
        }

        Node* cur = m_head->next;
        Node* prev;
        Node* next;

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
        Node* cur = m_head;

        int i = 1;
        while(cur)
        {
            std::cout << "Node " << i++ << ": " << cur->data << std::endl;
            cur = cur->next;
        }
    }

private:
    Node* m_head = nullptr;
    Node* m_current = nullptr;
};

int main()
{
    LinkedList a;
    a.Append(2);
    a.Append(4);
    a.Append(5);
    a.Append(6);
    a.Append(7);
    a.Prepend(1);
    a.Prepend(0);

    a.InsertAt(3, 100);
    a.Remove(100);
    std::cout << "Search result: " << a.Search(7) << std::endl; 
    a.Print();
}
