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
            std::cout << "map<char, int> \033[1;32m OK \033[0m"<<std::endl;

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
            std::cout << "map<char, int> \033[1;32m OK \033[0m"<<std::endl;

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
            std::cout << "map<char, int> \033[1;32m OK \033[0m"<<std::endl;

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
            std::cout << "FALSE"<<std::endl;
            std::cout<<"my map: "<< mit->first <<mit->second<<"orj map: "<<oit->first<<oit->second<<std::endl;
        }
        else
            std::cout << "\033[1;32m OK \033[0m"<<std::endl;

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
            std::cout << "FALSE"<<std::endl;
            std::cout<<"my map: "<< mit->first <<mit->second<<"orj map: "<<oit->first<<oit->second<<std::endl;
        }
        else
            std::cout<<"OK"<<std::endl;
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
			std::cout << "\033[1;32m OK \033[0m"<<std::endl;

		else
		{
			std::cout << "FALSE"<<std::endl;
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
			std::cout << "\033[1;32m OK \033[0m"<<std::endl;
		else
		{
			std::cout << "FALSE"<<std::endl;
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
			std::cout<<"\033[1;32m OK \033[0m"<<std::endl;
		else
		{
			std::cout << "FALSE"<<std::endl;
            std::cout<<"my map: "<< mymap.size()<<"orj map: "<<orjmap.size()<<std::endl;
		}

  		orjmap['a']=101;
  		orjmap['b']=202;
  		orjmap['c']=302;

		mymap['a']=101;
  		mymap['b']=202;
  		mymap['c']=302;

		if (orjmap.size() == mymap.size())
			std::cout<<"\033[1;32m OK \033[0m"<<std::endl;
		else
		{
			std::cout << "\033[1;31m FALSE \033[0m"<<std::endl;
            std::cout<<"my map: "<< mymap.size()<<"orj map: "<<orjmap.size()<<std::endl;
		}
	}

    std::cout << "size test end" << std::endl;

}

void mapMaxSize()
{
    std::cout << "max size test start" << std::endl;

	{
		std::map<char,int> orjmap;
		ft::map<char,int> mymap;

	if (mymap.max_size()>1000)
    {
        for (int i=0; i<1000; i++) mymap[i]=0;
            std::cout << "\033[1;32m OK \033[0m"<<std::endl;
    }
	else
	{
		std::cout << "\033[1;31m FALSE \033[0m"<<std::endl;
        std::cout<<"my map: "<< mymap.max_size()<<"orj map: "<<orjmap.max_size()<<std::endl;
	}
	}

    std::cout << "max size test end" << std::endl;

}


/**
 * @brief 
 * If k matches the key of an element in the container, the function returns a reference to its mapped value.

 * If k does not match the key of any element in the container, the function inserts a new element with that key and returns a reference to its mapped value. 
 */
void mapBoxBrackets()
{
        std::cout << "[ ] test start" << std::endl;

    {
        std::map<char,std::string> orjmap;
		ft::map<char,std::string> mymap;


        orjmap['a']="an element";
        orjmap['b']="another element";
        orjmap['c']=orjmap['b'];

        mymap['a']="an element";
        mymap['b']="another element";
        mymap['c']=mymap['b'];

        if (orjmap['a'] == mymap['a'] && orjmap['b'] == mymap['b'] && orjmap['c'] == mymap['c'] && orjmap['d'] == mymap['d'])
            std::cout << "\033[1;32m OK \033[0m"<<std::endl;
        else
		    std::cout << "\033[1;31m FALSE \033[0m"<<std::endl;
    }
        std::cout << "[ ] test end" << std::endl;

}





void mapInsert()
{

    std::cout << "insert test start" << std::endl;

    std::map<char,int> orjmap;
    ft::map<char,int> mymap;

    // first insert function version (single parameter):
    orjmap.insert ( std::pair<char,int>('a',100) );
    orjmap.insert ( std::pair<char,int>('z',200) );

    mymap.insert ( ft::pair<char,int>('a',100) );
    mymap.insert ( ft::pair<char,int>('z',200) );

    if (mymap['a'] == orjmap['a'] && mymap['z'] == orjmap['z'])
        std::cout << "\033[1;32m OK \033[0m"<<std::endl;
    else
		std::cout << "\033[1;31m FALSE \033[0m"<<std::endl;


    // second insert function version (with hint position):
    std::map<char,int>::iterator oit = orjmap.begin();
    orjmap.insert (oit, std::pair<char,int>('b',300));  
    orjmap.insert (oit, std::pair<char,int>('c',400));  

    ft::map<char,int>::iterator mit = mymap.begin();
    mymap.insert (mit, ft::pair<char,int>('b',300));  
    mymap.insert (mit, ft::pair<char,int>('c',400)); 

    if (mymap['b'] == orjmap['b'] && mymap['c'] == orjmap['c'])
            std::cout << "\033[1;32m OK \033[0m"<<std::endl;
    else
            std::cout << "\033[1;31m FALSE \033[0m"<<std::endl;
    

    // third insert function version (range insertion):
    std::map<char,int> anothermap;
    anothermap.insert(orjmap.begin(),orjmap.find('c'));

    ft::map<char,int> anothermap2;
    anothermap2.insert(mymap.begin(),mymap.find('c'));

    ft::map<char,int>::iterator mit2 = anothermap2.begin();
    std::map<char,int>::iterator oit2=anothermap.begin();
    for (; oit2!=anothermap.end(); ++oit2)
    {
        if (oit2->first == mit2->first && oit2->second == mit2->second)
            std::cout << "\033[1;32m OK \033[0m"<<std::endl;
        else
            std::cout << "\033[1;31m FALSE \033[0m"<<std::endl;
        mit2++;
    }
      
    std::cout << "insert test end" << std::endl;

}

void mapErase()
{
      std::cout << "erase test start" << std::endl;

      std::map<char,int> orjmap;
      std::map<char,int>::iterator oit;

      ft::map<char,int> mymap;
      ft::map<char,int>::iterator mit;

      // insert some values:
      orjmap['a']=10;
      orjmap['b']=20;
      orjmap['c']=30;
      orjmap['d']=40;
      orjmap['e']=50;
      orjmap['f']=60;

	  mymap['a']=10;
      mymap['b']=20;
      mymap['c']=30;
      mymap['d']=40;
      mymap['e']=50;
      mymap['f']=60;

      oit=orjmap.find('b');
      orjmap.erase (oit);                   // erasing by iterator

	  mit=mymap.find('b');
      mymap.erase (mit); 

      orjmap.erase ('c');                  // erasing by key
	  mymap.erase ('c');

      oit=orjmap.find ('e');
      orjmap.erase ( oit, orjmap.end() );    // erasing by range

	  mit=mymap.find ('e');
      mymap.erase ( mit, mymap.end() );




		mit = mymap.begin();
      for (oit=orjmap.begin(); oit!=orjmap.end(); ++oit)
      {
		if (mit->first == oit->first && mit->second == oit->second)
            std::cout << "\033[1;32m OK \033[0m"<<std::endl;
		else
		    std::cout <<"\033[1;31m FALSE \033[0m my map: "<<mit->first<<mit->second<<"orj"<<oit->first<<oit->second<<std::endl;
		mit++;
      }


      std::cout << "erase test end" << std::endl;
	  
}

void mapSwap()
{
    std::cout << "swap test start" << std::endl;

	std::map<char,int> foo,bar;

  	foo['x']=100;
  	foo['y']=200;

  	bar['a']=11;
  	bar['b']=22;
  	bar['c']=33;

  	foo.swap(bar);

	ft::map<char,int> myfoo,mybar;

  	myfoo['x']=100;
  	myfoo['y']=200;

  	mybar['a']=11;
  	mybar['b']=22;
  	mybar['c']=33;

  	myfoo.swap(mybar);



	ft::map<char,int>::iterator mit= myfoo.begin();
  	for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
	{
		if (it->first != mit->first && it->second != mit->second)
  	 		std::cout <<"\033[1;31m FALSE \033[0m my map: "<<mit->first<<mit->second<<"orj"<<it->first<<it->second<<std::endl;
		else
            std::cout << "\033[1;32m OK \033[0m"<<std::endl;
		mit++;
	}

  	
	ft::map<char,int>::iterator sit= mybar.begin();
  	for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
	{
		if (it->first != sit->first && it->second != sit->second)
  	 		std::cout <<"\033[1;31m FALSE \033[0m my map: "<<sit->first<<sit->second<<"orj"<<it->first<<it->second<<std::endl;
		else
            std::cout << "\033[1;32m OK \033[0m"<<std::endl;
		sit++;
	}

    std::cout << "swap test end" << std::endl;
	
}

/**
 * @brief Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
 * 
 */

void mapClear()
{

    std::cout << "clear test start" << std::endl;

	std::map<char,int> orjmap;
	ft::map<char,int> mymap;
    
	std::map<char,int>::iterator oit;
    ft::map<char,int>::iterator mit;


	orjmap['x']=100;
  	orjmap['y']=200;
  	orjmap['z']=300;

  	mymap['x']=100;
  	mymap['y']=200;
  	mymap['z']=300;

	mymap.clear();
	orjmap.clear();
	

	if (orjmap['x'] == mymap['x'] && mymap.size() == orjmap.size())
        std::cout << "\033[1;32m OK \033[0m"<<std::endl;
	else
  	 	std::cout <<"\033[1;31m FALSE \033[0m my map: "<<mymap['x']<<mymap.size()<<" orj"<<orjmap['x']<<orjmap.size()<<std::endl;

    std::cout << "clear test end" << std::endl;

}
/**
 * @brief 
 * ilk verilen argüman ikinci argümandan küçükse true döner büyük veya eşitse false döner
 */
void mapKeyComp()
{
    std::cout << "key compare test start" << std::endl;

    std::map<int, int> stdMap;
    ft::map<int, int> myMap;
    
    // comparison function for std::map
    std::map<int, int>::key_compare stdComp = stdMap.key_comp();
    
    // comparison function for my map
    ft::map<int, int>::key_compare myComp = myMap.key_comp();
    // comparing the two comparison functions
    if (stdComp(1, 2) == myComp(1, 2))
        std::cout << "\033[1;32m OK \033[0m"<<std::endl;

    else
        std::cout << "\033[1;31m FALSE \033[0m Comparison functions are different" << std::endl;

    std::cout << "key compare test end" << std::endl;

}

void mapKeyComp()
{
/*     std::cout << "key compare test start" << std::endl;

    std::map<int, int> stdMap;
	stdMap[0] = 2;
	stdMap[1] = 12;
	stdMap[2] = 452;
	std::cout<<stdMap[0]<<std::endl;
    ft::map<int, int> myMap;
    
    std::map<int, int>::value_compare stdComp = stdMap.value_comp();
    
    ft::map<int, int>::value_compare myComp = myMap.value_comp();

    if (stdComp(1, 2) == myComp(1, 2))
        std::cout << "\033[1;32m OK \033[0m"<<std::endl;

    else
        std::cout << "\033[1;31m FALSE \033[0m Comparison functions are different" << std::endl;

    std::cout << "key compare test end" << std::endl; */

}


