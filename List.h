/*
* File: list.h
* 
* Author: Caleb Davis
* 
* Date: 03-01-21
* 
* Description:
*   Basic template class implementation for a doubly linked list.
* 
*/

#ifndef LIST_H
#define LIST_H

#include <iostream>

template<typename data_type>
class list
{
public:
    list()
        : head(nullptr), curr(nullptr), tail(nullptr)
    {
    }

    list(int init_size, data_type init_data = data_type())
        : head(nullptr), curr(nullptr), tail(nullptr)
    {
        for (int i = 0; i < init_size; i++)
        {
            push_back(init_data);
        }
    }

    ~list()
    {
        clear();
    }

    bool empty()
    {
        if (head == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int size()
    {
        if (empty())
        {
            return 0;
        }
        else
        {
            int count = 0;

            curr = head;

            while (curr != nullptr)
            {
                count++;
                curr = curr->next;
            }

            return count;
        }
    }

    data_type& front()
    {
        return head->data;
    }

    data_type& back()
    {
        return tail->data;
    }

    void push_back(data_type new_data = data_type())
    {
        curr = new node;
        curr->data = new_data;
        curr->next = nullptr;

        if (empty())
        {
            head = tail = curr;
            curr->prev = nullptr;
        }
        else
        {
            tail->next = curr;
            curr->prev = tail;
            tail = curr;
        }
    }

    void push_front(data_type new_data = data_type())
    {
        curr = new node;
        curr->data = new_data;
        curr->prev = nullptr;

        if (empty())
        {
            head = tail = curr;
            curr->next = nullptr;
        }
        else
        {
            head->prev = curr;
            curr->next = head;
            head = curr;
        }
    }

    data_type pop_back()
    {
        if (empty())
        {
            std::cout << "Error: Cannot pop_back. List is empty.\n";
            return data_type();
        }
        else if (head == tail)
        {
            data_type removed_data = tail->data;
            delete tail;

            head = curr = tail = nullptr;

            return removed_data;
        }
        else
        {
            data_type removed_data = tail->data;

            curr = tail;
            tail = tail->prev;
            tail->next = nullptr;

            delete curr;

            return removed_data;
        }
    }

    data_type pop_front()
    {
        if (empty())
        {
            std::cout << "Error: Cannot pop_front. List is empty.\n";
            return data_type();
        }
        else if (head == tail)
        {
            data_type removed_data = tail->data;

            delete head;

            head = curr = tail = nullptr;

            return removed_data;
        }
        else
        {
            data_type removed_data = head->data;

            curr = head;
            head = head->next;
            head->prev = nullptr;

            delete curr;
            return removed_data;
        }
    }

    void clear()
    {
        if (empty())
        {
            return;
        }
        else
        {
            int old_size = size();

            for (int i = 0; i < old_size; i++)
            {
                pop_back();
            }
        }
    }

    void resize(int new_size, data_type new_data = data_type())
    {
        int old_size = size();

        if (new_size < 0)
        {
            std::cout << "Error: Cannot resize list. New size must be non-negative.\n";
            return;
        }
        else if (new_size == 0)
        {
            clear();
        }
        else if (new_size > 0)
        {
            if (new_size == old_size)
            {
                return;
            }
            else if (new_size > old_size)
            {
                for (int i = 0; i < new_size - old_size; i++)
                {
                    push_back(new_data);
                }
            }
            else
            {
                for (int i = 0; i < old_size - new_size; i++)
                {
                    pop_back();
                }
            }
        }
    }

    void reverse()
    {
        int list_size = size();

        list<data_type> reverse;

        for (int i = 0; i < list_size; i++)
        {
            reverse.push_back(pop_back());
        }

        for (int i = 0; i < list_size; i++)
        {
            push_back(reverse.pop_front());
        }
    }

    void print()
    {
        if (empty())
        {
            std::cout << "Error: Cannot print list. List is empty.\n";
            return;
        }
        else
        {
            curr = head;
            while (curr != nullptr)
            {
                std::cout << curr->data << " ";
                curr = curr->next;
            }
            std::cout << std::endl;
        }
    }

    void print_reverse()
    {
        if (empty())
        {
            std::cout << "Error: Cannot print list. List is empty.\n";
            return;
        }
        else
        {
            curr = tail;
            while (curr != nullptr)
            {
                std::cout << curr->data << " ";
                curr = curr->prev;
            }
            std::cout << std::endl;
        }
    }

private:
    struct node
    {
        data_type data;

        node* next;
        node* prev;
    };

    node* head;
    node* curr;
    node* tail;
};

#endif /* LIST_H */