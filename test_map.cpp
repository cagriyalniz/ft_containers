#include "./containers/map.hpp"
#include <map>
#include "./iterators/TreeIter.hpp"

void map_print(std::map<int, int> m)
{
    std::map<int, int>::iterator it = m.begin();
    while(it != m.end()){
        std::cout<<it->first<<"|"<<it->second<<std::endl;
        it++;
    }
    std::cout<<std::endl;
}

void map_print(ft::map<int, int> m)
{
    ft::map<int, int>::iterator it = m.begin();
    while(it != m.end()){
        std::cout<<it->first<<"|"<<it->second<<std::endl;
        it++;
    }
    std::cout<<std::endl;

}


void mapInsertTest()
{
    ft::map<int, int> myMap;
    std::map<int, int> orjMap;

    

    myMap.insert(ft::pair<int ,int>(0, 5));
    myMap.insert(ft::pair<int ,int>(1, 4));
    myMap.insert(ft::pair<int ,int>(2, 3));

    orjMap.insert(std::pair<int ,int>(0, 5));
    orjMap.insert(std::pair<int ,int>(1, 4));
    orjMap.insert(std::pair<int ,int>(2, 3));
   
    ft::map<int, int>::iterator myIt = myMap.begin();
    std::map<int, int>::iterator orjIt = orjMap.begin();

/*     std::cout<<myIt->first <<myIt->second<<std::endl;
        myIt++;
    std::cout<<myIt->first <<myIt->second<<std::endl; */


    //map_print(orjMap);
    map_print(myMap);

    while(myIt != myMap.end() && orjIt != orjMap.end())
    {

        if (myIt->first != orjIt -> first || myIt->second != orjIt -> second) 
            std::cout<<"FAIL"<<std::endl;
        else
            std::cout<<"OK"<<std::endl;
        myIt++;
        orjIt++;
    }
    
}

void mapBegin()
{
    ft::map<char, int> myMap;
    std::map<char, int> orjMap;

    myMap['a'] = 100;
     myMap['b'] = 200;
   myMap['c'] = 50;
    
    orjMap['a'] = 100;
    orjMap['b'] = 200;
    orjMap['c'] = 300;

    
    for (std::map<char,int>::iterator it=orjMap.begin(); it!=orjMap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';


}