//
// Created by sm4ll_3gg on 12.11.16.
//

#include "Tree.h"

#include <iostream>


Tree::Tree() noexcept
{
    root = nullptr;
    now = nullptr;
    number_of_nodes = 0;
}

Tree::Tree(std::string code) throw( TException )
{
    root = nullptr;
    now = nullptr;
    number_of_nodes = 0;

    for(auto it = code.begin(); it != code.end(); it++)
    {
        if(*it == '1')
        {
            push();
            number_of_nodes++;
        }
        else if(*it == '0')
        {
            if(now == root)
            {
                throw TException("Некорректно закодированно дерево!");
            }

            now = now->parent;
        }
    }
}

void Tree::push() throw( TException )
{
    try
    {
        if (root == nullptr)
        {
            root = new Node;
            root->parent = nullptr;
            root->number = 0;

            now = root;
        }
        else
        {
            Node *temp = new Node;
            temp->parent = now;
            temp->number = number_of_nodes;

            now->child.push_front(temp);
            now = now->child.front();

            temp = nullptr;
        }
    }
    catch(std::bad_alloc& ba)
    {
        throw TException("Bad alloc");
    }
}

void Tree::print() noexcept
{
    _print(root, 0);
}

Tree::Matrix Tree::create_adjacency_matrix() noexcept
{
    Tree::Matrix matrix(number_of_nodes);
    for(int i = 0; i < number_of_nodes; i++)
    {
        matrix[i]=std::vector<int>(number_of_nodes);
    }

    _create_adjacency_matrix(matrix, root);

    return matrix;
}

//
//--------------------------Private Methods----------------------------------
//

void Tree::_print(Node* node, int level) noexcept
{
    for (int i = 0; i < level*2
            ; ++i)
    {
        std::cout << " ";
    }
    std::cout << node->number << std::endl;

    for (auto it = node->child.begin(); it != node->child.end(); ++it)
    {
        _print(*it, level+1);
    }
}

void Tree::_create_adjacency_matrix(Matrix& matrix, Node* node)  noexcept
{
    if(node->parent != nullptr)
    {
        matrix[node->parent->number][node->number] = 1;
    }

    for(auto it = node->child.begin(); it != node->child.end() ; it++)
    {
        _create_adjacency_matrix(matrix, *it);
    }
}
