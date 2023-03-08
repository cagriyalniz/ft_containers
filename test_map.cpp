#include "./containers/map.hpp"
#include <map>
#include "./iterators/AVLTree.hpp"

void map_print(std::map<int, int> m)
{
    std::map<int, int>::iterator it = m.begin();
    while(it != m.end()){
        std::cout<<it->first<<"|"<<it->second<<std::endl;
        it++;
    }
}


void mapInsertTest()
{
    std::map<int, int> m;
    m.insert({0, 11});
    m.insert({1, 12});
    m.insert({2, 13});
    map_print(m);
}