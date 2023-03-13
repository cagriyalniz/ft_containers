#include "./containers/map.hpp"
#include <map>
#include "./iterators/Map_Iterator.hpp"
#include "./iterators/Rev_Map_Iterator.hpp"


void map_print(std::map<char, int> m)
{
    std::map<char, int>::iterator it = m.begin();
    while (it != m.end())
    {
        std::cout << it->first << "|" << it->second << std::endl;
        it++;
    }
    std::cout << std::endl;
}

void my_print(ft::map<char, int> m)
{
    ft::map<char, int>::iterator it = m.begin();
    while (it != m.end())
    {
        std::cout << it->first << "|" << it->second << std::endl;
        it++;
    }
    std::cout << std::endl;
}

void mapBegin()
{

    std::cout << "begin test start" << std::endl;

    {
        std::map<char, int>orjmap;
        ft::map<char, int> mymap;

        orjmap['d'] = 100;
        orjmap['a'] = 200;
        orjmap['c'] = 300;
        orjmap['f'] = 400;
        orjmap['v'] = 500;

        mymap['d'] = 100;
        mymap['a'] = 200;
        mymap['c'] = 300;
        mymap['f'] = 400;
        mymap['v'] = 500;

        std::map<char, int>::iterator oit = orjmap.begin();
        ft::map<char, int>::iterator mit = mymap.begin();

        if (oit->first != mit->first || oit->second != mit->second)
        {
            std::cout << "map<char, int> FALSE"<<std::endl;
            std::cout<<"my map: "<< mit->first <<mit->second<<"orj map: "<<oit->first<<oit->second<<std::endl;
        }
        else
            std::cout<<"map<char, int> OK"<<std::endl;
    }

    {
        std::map<int, int>orjmap;
        ft::map<int, int> mymap;

        orjmap[2] = 100;
        orjmap[6] = 200;
        orjmap[3] = 300;

        mymap[2] = 100;
        mymap[6] = 200;
        mymap[3] = 300;


        std::map<int, int>::iterator oit = orjmap.begin();
        ft::map<int, int>::iterator mit = mymap.begin();

        if (oit->first != mit->first || oit->second != mit->second)
        {
            std::cout << "map<int, int> FALSE"<<std::endl;
            std::cout<<"my map: "<< mit->first <<mit->second<<"orj map: "<<oit->first<<oit->second<<std::endl;
        }
        else
            std::cout<<"map<int, int> OK"<<std::endl;
    }

        

    std::cout << "begin test end" << std::endl;
}

void mapEnd()
{

    std::cout << "end test start" << std::endl;
    {
        std::map<char, int>orjmap;
        ft::map<char, int> mymap;

        orjmap['d'] = 100;
        orjmap['a'] = 200;
        orjmap['c'] = 300;
        orjmap['f'] = 400;
        orjmap['v'] = 500;

        mymap['d'] = 100;
        mymap['a'] = 200;
        mymap['c'] = 300;
        mymap['f'] = 400;
        mymap['v'] = 500;

        std::map<char, int>::iterator oit = orjmap.end();
        ft::map<char, int>::iterator mit = mymap.end();
        oit--;
        mit--;

        if (oit->first != mit->first || oit->second != mit->second)
        {
            std::cout << "map<char, int> FALSE"<<std::endl;
            std::cout<<"my map: "<< mit->first <<mit->second<<"orj map: "<<oit->first<<oit->second<<std::endl;
        }
        else
            std::cout<<"map<char, int> OK"<<std::endl;
    }

    {
        std::map<int, int>orjmap;
        ft::map<int, int> mymap;

        orjmap[2] = 100;
        orjmap[6] = 200;
        orjmap[3] = 300;

        mymap[2] = 100;
        mymap[6] = 200;
        mymap[3] = 300;


        std::map<int, int>::iterator oit = orjmap.end();
        ft::map<int, int>::iterator mit = mymap.end();

        oit--;
        mit--;

        if (oit->first != mit->first || oit->second != mit->second)
        {
            std::cout << "map<int, int> FALSE"<<std::endl;
            std::cout<<"my map: "<< mit->first <<mit->second<<"orj map: "<<oit->first<<oit->second<<std::endl;
        }
        else
            std::cout<<"map<int, int> OK"<<std::endl;
    }
    std::cout << "end test end" << std::endl;
}

void mapRBegin()
{

    std::cout << "rbegin test start" << std::endl;

    {
        std::map<char,int> orjmap;
        ft::map<char,int> mymap;

        orjmap['x'] = 100;
        orjmap['y'] = 200;
        orjmap['z'] = 300;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        // show content:
        std::map<char,int>::reverse_iterator oit;
        ft::map<char,int>::reverse_iterator mit;
        
        oit = orjmap.rbegin();
        mit = mymap.rbegin();
        
        if (oit->first != mit->first || oit->second != mit->second)
        {
            std::cout << "map<char, int> FALSE"<<std::endl;
            std::cout<<"my map: "<< mit->first <<mit->second<<"orj map: "<<oit->first<<oit->second<<std::endl;
        }
        else
            std::cout<<"map<char, int> OK"<<std::endl;
    }
    {
        std::map<int, int>orjmap;
        ft::map<int, int> mymap;

        orjmap[2] = 100;
        orjmap[6] = 200;
        orjmap[3] = 300;

        mymap[2] = 100;
        mymap[6] = 200;
        mymap[3] = 300;


        std::map<int, int>::reverse_iterator oit = orjmap.rbegin();
        ft::map<int, int>::reverse_iterator mit = mymap.rbegin();
        oit++;
        mit++;

        if (oit->first != mit->first || oit->second != mit->second)
        {
            std::cout << "map<int, int> FALSE"<<std::endl;
            std::cout<<"my map: "<< mit->first <<mit->second<<"orj map: "<<oit->first<<oit->second<<std::endl;
        }
        else
            std::cout<<"map<int, int> OK"<<std::endl;
    }

    std::cout << "rbegin test end" << std::endl;
}

void mapREnd()
{
    std::cout << "rend test start" << std::endl;
    {
        std::map<char,int> orjmap;
        ft::map<char,int> mymap;

        orjmap['x'] = 100;
        orjmap['a'] = 200;
        orjmap['y'] = 200;
        orjmap['z'] = 300;
        orjmap['b'] = 400;

        mymap['x'] = 100;
        mymap['a'] = 200;
        mymap['y'] = 200;
        mymap['z'] = 300;
        mymap['b'] = 400;

        std::map<char,int>::reverse_iterator oit = orjmap.rend();
        ft::map<char,int>::reverse_iterator mit = mymap.rend();

        oit--;
        mit--;

        if (oit->first != mit->first || oit->second != mit->second)
        {
            std::cout << "map<char, int> FALSE"<<std::endl;
            std::cout<<"my map: "<< mit->first <<mit->second<<"orj map: "<<oit->first<<oit->second<<std::endl;
        }
        else
            std::cout<<"map<char, int> OK"<<std::endl;
    }

    {
        std::map<int, int>orjmap;
        ft::map<int, int> mymap;

        orjmap[2] = 100;
        orjmap[6] = 200;
        orjmap[3] = 300;

        mymap[2] = 100;
        mymap[6] = 200;
        mymap[3] = 300;


        std::map<int, int>::reverse_iterator oit = orjmap.rbegin();
        ft::map<int, int>::reverse_iterator mit = mymap.rbegin();

        if (oit->first != mit->first || oit->second != mit->second)
        {
            std::cout << "map<int, int> FALSE"<<std::endl;
            std::cout<<"my map: "<< mit->first <<mit->second<<"orj map: "<<oit->first<<oit->second<<std::endl;
        }
        else
            std::cout<<"map<int, int> OK"<<std::endl;
    }

    std::cout << "rend test end" << std::endl;

}

void mapEmpty()
{
    std::cout << "empty test start" << std::endl;
	{
		std::map<char,int> orjmap;
        ft::map<char,int> mymap;

		if (orjmap.empty() == mymap.empty())
			std::cout<<"OK"<<std::endl;
		else
		{
			std::cout << "map<char, int> FALSE"<<std::endl;
			std::cout<<"my map: "<< mymap.empty()<<"orj map: "<<orjmap.empty()<<std::endl;
		}

        orjmap['x'] = 100;
        orjmap['a'] = 200;
        orjmap['y'] = 200;
        orjmap['z'] = 300;
        orjmap['b'] = 400;

        mymap['x'] = 100;
        mymap['a'] = 200;
        mymap['y'] = 200;
        mymap['z'] = 300;
        mymap['b'] = 400;

		if (orjmap.empty() == mymap.empty())
			std::cout<<"OK"<<std::endl;
		else
		{
			std::cout << "map<char, int> FALSE"<<std::endl;
			std::cout<<"my map: "<< mymap.empty()<<"orj map: "<<orjmap.empty()<<std::endl;
		}
	}
    std::cout << "empty test end" << std::endl;

}

void mapSize()
{
    std::cout << "size test start" << std::endl;

	{
		std::map<char,int> orjmap;
		ft::map<char,int> mymap;

		if (orjmap.size() == mymap.size())
			std::cout<<"OK"<<std::endl;
		else
		{
			std::cout << "map<char, int> FALSE"<<std::endl;
            std::cout<<"my map: "<< mymap.size()<<"orj map: "<<orjmap.size()<<std::endl;
		}

  		orjmap['a']=101;
  		orjmap['b']=202;
  		orjmap['c']=302;

		mymap['a']=101;
  		mymap['b']=202;
  		mymap['c']=302;

		if (orjmap.size() == mymap.size())
			std::cout<<"OK"<<std::endl;
		else
		{
			std::cout << "map<char, int> FALSE"<<std::endl;
            std::cout<<"my map: "<< mymap.size()<<"orj map: "<<orjmap.size()<<std::endl;
		}
	}

    std::cout << "size test end" << std::endl;

}

void mapInsertTest()
{
}
