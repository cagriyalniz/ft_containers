#include "./containers/map.hpp"
#include <map>
#include "./iterators/TreeIter.hpp"

void map_print(std::map<char, int> m)
{
    std::map<char, int>::iterator it = m.begin();
    while(it != m.end()){
        std::cout<<it->first<<"|"<<it->second<<std::endl;
        it++;
    }
    std::cout<<std::endl;
}

void map_print(ft::map<char, int> m)
{
    ft::map<char, int>::iterator it = m.begin();
    while(it != m.end()){
        std::cout<<it->first<<"|"<<it->second<<std::endl;
        it++;
    }
    std::cout<<std::endl;

}

void mapBegin()
{

    std::cout<<"begin test start"<<std::endl;
    ft::map<char, int> myMap;
    std::map<char, int> orjMap;

    myMap['a'] = 100;
    myMap['b'] = 200;
    myMap['c'] = 300;
    
    orjMap['a'] = 100;
    orjMap['b'] = 200;
    orjMap['c'] = 300;

    std::map<char,int>::iterator oIt=orjMap.begin();
    ft::map<char,int>::iterator mIt=myMap.begin();
    
    if (oIt->first != mIt->first)
        std::cout<<"orj: "<<oIt->first<<" ||| " << mIt->first<<std::endl;
    else if (oIt->second != oIt->second)
        std::cout<<"orj second: "<<oIt->second<<" ||| " <<"my second" << mIt->second<<std::endl;
    else
        std::cout<<"OK.........."<<"orj first: "<<oIt->first<<" ||| "<<"my first: " << mIt->first<<" orj second: "<<oIt->second <<" my second: " << mIt->second<<std::endl;        

    std::cout<<"begin test end"<<std::endl;
}

void mapEnd()
{

    std::cout<<"end test start"<<std::endl;
    ft::map<char, int> myMap;
    std::map<char, int> orjMap;

    myMap['a'] = 100;
    myMap['b'] = 200;
    myMap['c'] = 300;
    myMap['d'] = 400;
    
    orjMap['a'] = 100;
    orjMap['b'] = 200;
    orjMap['c'] = 300;
    orjMap['d'] = 400;

    ft::map<char,int>::iterator mIt=myMap.end();
    std::map<char,int>::iterator oIt=orjMap.end();

    map_print(myMap);
    map_print(orjMap);
    
    mIt--;
    oIt--;
    if (oIt->first != mIt->first)
        std::cout<<"Fail......"<<"orj first: "<<oIt->first<<" ||| " <<"my first: " << mIt->first<<std::endl;
    else if (oIt->second != oIt->second)
        std::cout<<"Fail......"<<"orj second: "<<oIt->second<<" ||| " <<"my second" << mIt->second<<std::endl;
    else
        std::cout<<"OK.........."<<"orj first: "<<oIt->first<<" ||| "<<"my first: " << mIt->first<<" orj second: "<<oIt->second <<" my second: " << mIt->second<<std::endl;        
       

    std::cout<<"end test end"<<std::endl;
}

void mapRBegin()
{

    std::cout<<"rbegin test start"<<std::endl;


	std::map<char,int> orjmap;

  	orjmap['z'] = 100;
  	orjmap['y'] = 200;
  	orjmap['x'] = 300;

  	// show content:
  	std::map<char,int>::reverse_iterator rit;
  	for (rit=orjmap.rbegin(); rit!=orjmap.rend(); ++rit)
  	  std::cout << rit->first << " => " << rit->second << '\n';

	ft::map<char,int> mymap;

  	mymap['z'] = 100;
  	mymap['y'] = 200;
  	mymap['x'] = 300;

  	// show content:
  	ft::map<char,int>::reverse_iterator mit;
  	for (mit=mymap.rbegin(); mit!=mymap.rend(); ++mit)
  	  std::cout << mit->first << " => " << mit->second << '\n';

/*     ft::map<char,int> mymap;
    std::map<char,int> orjmap;

    mymap['x'] = 100;
    mymap['y'] = 200;
    mymap['z'] = 300;
    mymap['r'] = 30;
    mymap['t'] = 310;
    mymap['g'] = 3110;
    mymap['b'] = 31110;

	orjmap['x'] = 100;
    orjmap['y'] = 200;
    orjmap['z'] = 300;
    orjmap['r'] = 30;
    orjmap['t'] = 310;
    orjmap['g'] = 3110;
    orjmap['b'] = 31110;


	std::map<char,int>::reverse_iterator oit = orjmap.rbegin();
	ft::map<char,int>::reverse_iterator mit = mymap.rbegin();


	if (oit->first != mit->first)
	    std::cout<<"Fail...... orj: "<<oit->first<<" ||| my first" << mit->first<<std::endl;
    else if (oit->second!= mit->second)
        std::cout<<"Fail...... orj second: "<<oit->second<<" ||| my second"<< mit->second<<std::endl;
    else
        std::cout<<"OK........"<<std::endl; */


    std::cout<<"rbegin test end"<<std::endl;
}

void mapREnd()
{
    std::cout<<"rend test start"<<std::endl;
    
    std::map<char,int> mymap;
    ft::map<char,int> orjmap;

    mymap['x'] = 100;
    mymap['y'] = 200;
    mymap['z'] = 300;
    mymap['r'] = 30;
    mymap['t'] = 310;
    mymap['g'] = 3110;
    mymap['b'] = 31110;

	orjmap['x'] = 100;
    orjmap['y'] = 200;
    orjmap['z'] = 300;
    orjmap['r'] = 30;
    orjmap['t'] = 310;
    orjmap['g'] = 3110;
    orjmap['b'] = 31110;


	std::map<char,int>::reverse_iterator oritend = mymap.rend();
	ft::map<char,int>::reverse_iterator mritend = orjmap.rend();

	
	oritend--;
	mritend--;

	if (oritend->first != mritend->first)
	    std::cout<<"Fail...... orj: "<<oritend->first<<" ||| my first" << mritend->first<<std::endl;
    else if (oritend->second!= mritend->second)
        std::cout<<"Fail...... orj second: "<<oritend->second<<" ||| my second"<< mritend->second<<std::endl;
    else
        std::cout<<"OK........"<<std::endl;
	

	std::cout<<"rend test end"<<std::endl;


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
    //map_print(myMap);

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

