#include "Tree.h"

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>


int main()
{
    std::fstream fin("/home/sm4ll_3gg/Projects/Cpp/GraphTheory/TreeCode.txt");

    if(fin.is_open())
    {
        std::string code;
        fin >> code;

        try
        {
            Tree tree(code);
            tree.print();

            std::vector< std::vector<int> > matrix = tree.create_adjacency_matrix();

            for(size_t i = 0; i < matrix.size(); ++i)
            {
                for (size_t j = 0; j < matrix[i].size(); ++j)
                {
                    std::cout << matrix[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
        catch(TException& ex)
        {
            std::cout << ex.get_error_name() << std::endl;
        }
    }
    else
    {
        std::cout << "File is not open" << std::endl;
    }
    return 0;
}