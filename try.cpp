#include "./containers/vector.hpp"
#include "./containers/stack.hpp"
#include <vector>
#include "./iterators/RandomAccess_Iterator.hpp"
#include "./iterators/Reverse_Iterator.hpp"

 void print_my_vector(ft::vector<int> v)
{
    
    ft::vector<int>::iterator it = v.begin();
    std::cout<< "\n-------------\n";
    std::cout<<"capacity: "<<v.capacity()<<" size: "<<v.size()<<std::endl;
    
	std::cout<<"my datas ---> ";
    while(it != v.end())
        std::cout<<*it++<<" ";
    std::cout<< "\n-------------\n";
}

int main()
{
    ft::vector<int>vec;
    vec.push_back(1);
    print_my_vector(vec);
    vec.push_back(2);
    print_my_vector(vec);
    vec.push_back(3);

    vec.push_back(4);

    vec.push_back(5);
    print_my_vector(vec);


}