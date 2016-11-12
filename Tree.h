//
// Created by sm4ll_3gg on 12.11.16.
//

#ifndef GRAPHTHEORY_TREE_H
#define GRAPHTHEORY_TREE_H

#include <string>
#include <forward_list>
#include <vector>
#include "TException.h"

class Tree
{
    typedef std::vector< std::vector<int> > Matrix;

    struct Node
    {
        int number; // Порядковый номер
        std::forward_list<Node*> child;
        Node* parent;
    };

    int number_of_nodes;
    Node* now;
    Node* root;

    void                            _print(Node*, int) noexcept;
    void                            _create_adjacency_matrix(Matrix&, Node*) noexcept ;
public:
    Tree() noexcept ;
    Tree(std::string) throw( TException );

    void                            push() throw( TException );
    void                            print() noexcept;

    Matrix create_adjacency_matrix() noexcept ;
};


#endif //GRAPHTHEORY_TREE_H
