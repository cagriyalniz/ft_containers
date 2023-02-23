#include "./containers/vector.hpp"
#include "./containers/stack.hpp"
#include <vector>
#include "./iterators/RandomAccess_Iterator.hpp"
#include "./iterators/Reverse_Iterator.hpp"

 void print_my_vector(ft::vector<int> v)
{
    
    ft::vector<int>::iterator it = v.begin();
    std::cout<< "\n---my vector-----\n";
    std::cout<<"capacity: "<<v.capacity()<<" size: "<<v.size()<<std::endl;
    std::cout<< ".....................\n";
	std::cout<<"datas ---> ";
    while(it != v.end())
        std::cout<<*it++<<" ";
    std::cout<< "\n.....................\n";
}

void print_orj_vector(std::vector<int> v)
{

    std::vector<int>::iterator it = v.begin();
    std::cout<< "\n----original vector---------\n";
    std::cout<<"capacity: "<<v.capacity()<<" size: "<<v.size()<<std::endl;
    std::cout<< ".....................\n";
	std::cout<<"datas ---> ";
    while(it != v.end())
        std::cout<<*it++<<" ";
    std::cout<< "\n.....................\n";
}

void testBegin()
{
    std::cout<< "***iterator begin() const_iterator begin()***\n" <<std::endl;
	ft::vector<int> myVecBegin;
	ft::vector<int>::iterator myItBegin;
	ft::vector<int>::const_iterator myConstItBegin;

	std::vector<int> orjVecBegin;
	std::vector<int>::iterator orjItBegin;
	std::vector<int>::const_iterator constOrjItBegin;

	myVecBegin.push_back(1);
	myItBegin = myVecBegin.begin();
	myConstItBegin = myVecBegin.begin();
	std::cout <<"my vector: "<< *myItBegin<< " " << *myConstItBegin << std::endl;

	orjVecBegin.push_back(1);
	orjItBegin = orjVecBegin.begin();
	constOrjItBegin = orjVecBegin.begin();
	std::cout<<"orj vector: "<< *orjItBegin<< " " << *constOrjItBegin << std::endl;

	std::cout<< "-----------------end of the begin-----------------------------\n\n" <<std::endl;
}


void testEnd()
{
    std::cout<< "***iterator end() const_iterator end()***\n" <<std::endl;
	ft::vector<int> myVecEnd;
	ft::vector<int>::iterator myItEnd;
	ft::vector<int>::const_iterator myConstItEnd;

	std::vector<int> orjVecEnd;
	std::vector<int>::iterator orjItEnd;
	std::vector<int>::const_iterator constOrjItEnd;
	myVecEnd.push_back(1);
	myVecEnd.push_back(2);
	//2 1
	myItEnd = myVecEnd.end() - 1;
	myConstItEnd = myVecEnd.end() - 1;
	std::cout <<"my vector: "<< *myItEnd<< " " << *myConstItEnd << std::endl;

	orjVecEnd.push_back(1);
	orjVecEnd.push_back(2);
	//2 1
	orjItEnd = orjVecEnd.end() - 1;
	constOrjItEnd = orjVecEnd.end() - 1;
	std::cout<<"orj vector: "<< *constOrjItEnd<< " " << *constOrjItEnd << std::endl;
	/*
		Returns an iterator referring to the past-the-end element in the vector container.
		The past-the-end element is the theoretical element that would follow the last element in the vector. 
		It does not point to any element, and thus shall not be dereferenced.

		Vektör container'ındaki past-the-end öğesine başvuran bir iterator döndürür. 
		Past-the-end öğesi, vektördeki son öğeyi takip edecek olan teorik öğedir. 
		Herhangi bir öğeye işaret etmez ve bu nedenle atıf yapılmayacaktır.
	*/

	//If the container is empty, this function returns the same as vector::begin.
	ft::vector<int> myVecEmptyEnd;
	std::vector<int> orjVecEmptyEnd;
	std::cout<<"empty vector test: \n";
/* 	if (myVecEmptyEnd.begin() == myVecEmptyEnd.end())
		std::cout<<"True \n"; */
	if (orjVecEmptyEnd.begin() == orjVecEmptyEnd.end())
		std::cout<<"True \n";

	std::cout<< "----------------end of the end------------------------------\n\n" <<std::endl;
}

void testRbegin()
{
    std::cout<< "***iterator rbegin() const_iterator rbegin()***\n" <<std::endl;
	ft::vector<int> myVecRBegin;
	ft::vector<int>::reverse_iterator myItRBegin;
	ft::vector<int>::const_iterator myConstItRBegin;

	std::vector<int> orjVecRBegin;
	std::vector<int>::reverse_iterator orjItRBegin;
	std::vector<int>::const_iterator constOrjItRBegin;

	myVecRBegin.push_back(1);
	myVecRBegin.push_back(2);
	myVecRBegin.push_back(3);
	myItRBegin = myVecRBegin.rbegin();
	//orijinalde de çalışmıyor
	//myConstItRBegin = myVecRBegin.rbegin();
	std::cout <<"my vector: "<< *myItRBegin<< " " /* << *myConstItRBegin */ << std::endl;

	orjVecRBegin.push_back(1);
	orjVecRBegin.push_back(2);
	orjVecRBegin.push_back(3);
	//3 2 1
	orjItRBegin = orjVecRBegin.rbegin();
	//constOrjItRBegin = orjVecRBegin.rbegin();
	std::cout<<"orj vector: "<< *orjItRBegin<< " " /* << *constOrjItRBegin */ << std::endl;

	std::cout<< "---------------end of the rbegin-------------------------------\n\n" <<std::endl;
}

void testRend()
{
    std::cout<< "***iterator rend() const_iterator rend()***\n" <<std::endl;
	ft::vector<int> myVecREnd;
	ft::vector<int>::reverse_iterator myItREnd;
	/* ft::vector<int>::const_iterator myConstItREnd; */

	std::vector<int> orjVecREnd;
	std::vector<int>::reverse_iterator orjItREnd;
	/* std::vector<int>::const_iterator constOrjItREnd; */

	myVecREnd.push_back(1);
	myVecREnd.push_back(2);
	myVecREnd.push_back(3);
	myItREnd = myVecREnd.rbegin();
	//orijinalde de çalışmıyor
	//myConstItREnd = myVecREnd.rbegin();
	std::cout <<"my vector: "<< *myItREnd<< " " /* << *myConstItREnd */ << std::endl;

	orjVecREnd.push_back(1);
	orjVecREnd.push_back(2);
	orjVecREnd.push_back(3);
	//3 2 1
	orjItREnd = orjVecREnd.rbegin();
	//constOrjItREnd = orjVecREnd.rbegin();
	std::cout<<"orj vector: "<< *orjItREnd<< " " /* << *constOrjItREnd */ << std::endl;

	std::cout<< "-------------end of the rend---------------------------------\n\n" <<std::endl;
}

void testSize()
{
    std::cout<< "***iterator size()***\n" <<std::endl;
	ft::vector<int> myVecSize;
	std::cout <<"my vector size: "<< myVecSize.size()<< std::endl;

	std::vector<int> orjVecSize;
	std::cout<<"orj vector size: "<< orjVecSize.size()<<  std::endl;


	myVecSize.push_back(1);
	myVecSize.push_back(2);
	myVecSize.push_back(3);
	myVecSize.pop_back();

	std::cout <<"my vector size: "<< myVecSize.size()<< std::endl;

	orjVecSize.push_back(1);
	orjVecSize.push_back(2);
	orjVecSize.push_back(3);
	orjVecSize.pop_back();

	std::cout<<"orj vector size: "<< orjVecSize.size()<<  std::endl;

	std::cout<< "--------------end of the size--------------------------------\n\n" <<std::endl;
}

void testMaxSize()
{
    std::cout<< "***iterator max_size()***\n" <<std::endl;
	
	ft::vector<int> myVecMaxSize;
	std::cout <<"my vector size: "<< myVecMaxSize.max_size()<< std::endl;

	std::vector<int> orjVecMaxSize;
	std::cout<<"orj vector size: "<< orjVecMaxSize.max_size()<<  std::endl;


	myVecMaxSize.push_back(1);
	myVecMaxSize.push_back(2);
	myVecMaxSize.push_back(3);
	myVecMaxSize.pop_back();

	std::cout <<"my vector size: "<< myVecMaxSize.max_size()<< std::endl;

	orjVecMaxSize.push_back(1);
	orjVecMaxSize.push_back(2);
	orjVecMaxSize.push_back(3);
	orjVecMaxSize.pop_back();

	std::cout<<"orj vector size: "<< orjVecMaxSize.max_size()<<  std::endl;

	std::cout<< "--------------end of the max size--------------------------------\n\n" <<std::endl;
}

void testResize()
{
    std::cout<< "***iterator resize()***\n" <<std::endl;
	
	ft::vector<int> myVecReSize;
	std::vector<int> orjVecReSize;


	myVecReSize.push_back(11);
	myVecReSize.push_back(2);
	myVecReSize.push_back(3);
	int myFirstSize = myVecReSize.size();
	myVecReSize.resize(2);//n is smaller than the current container size
	std::cout <<"my vector first size: "<<myFirstSize<< " my last size: ~> "<<myVecReSize.size()<< std::endl;


	orjVecReSize.push_back(1);
	orjVecReSize.push_back(2);
	orjVecReSize.push_back(3);
	int orjFirstSize = orjVecReSize.size();
	orjVecReSize.resize(2);//n is smaller than the current container size
	std::cout<<"orj vector first size: "<< orjFirstSize<<" orj last size: ~>"<<orjVecReSize.size()<<  std::endl;


	myVecReSize.resize(1, 3);//n is smaller than the current container size
	std::cout <<"my vector size: "<< myVecReSize.size()<< std::endl;

	orjVecReSize.resize(1, 3);//n is smaller than the current container size
	std::cout<<"orj vector size: "<< orjVecReSize.size()<<  std::endl;


	myVecReSize.resize(2);//n is bigger than the current container size
	std::cout <<"my vector size: "<< myVecReSize.size()<< std::endl;

	orjVecReSize.resize(2);//n is bigger than the current container size
	std::cout<<"orj vector size: "<< orjVecReSize.size()<<  std::endl;

	myVecReSize.resize(4, 1);//n is bigger than the current container size
	std::cout <<"my vector size: "<< myVecReSize.size()<< std::endl;

	orjVecReSize.resize(4, 1);//n is bigger than the current container size
	std::cout<<"orj vector size: "<< orjVecReSize.size()<<  std::endl;

	std::cout <<"my vector cap: "<< myVecReSize.capacity()<< std::endl;
	std::cout<<"orj vector cap: "<< orjVecReSize.capacity()<<  std::endl;

	myVecReSize.resize(14, 1);//n is bigger than the current container cap
	std::cout <<"my vector cap: "<< myVecReSize.capacity()<< std::endl;

	orjVecReSize.resize(14, 1);//n is bigger than the current container cap
	std::cout<<"orj vector cap: "<< orjVecReSize.capacity()<<  std::endl;

	print_my_vector(myVecReSize);
	print_orj_vector(orjVecReSize);

	std::cout<< "--------------end of the resize--------------------------------\n\n" <<std::endl;

}

void testCapacity()
{
    std::cout<< "***iterator capacity()***\n" <<std::endl;
	
	ft::vector<int> myVecCapacity;
	std::cout <<"my vector capacity: "<< myVecCapacity.capacity()<< std::endl;

	std::vector<int> orjVecCapacity;
	std::cout<<"orj vector capacity: "<< orjVecCapacity.capacity()<<  std::endl;

    for(int i = 0; i < 100; i++)
    {
	    myVecCapacity.push_back(i);
	    orjVecCapacity.push_back(i);

    }
	std::cout <<"my vector capacity: "<< myVecCapacity.capacity()<< std::endl;
	std::cout<<"orj vector capacity: "<< orjVecCapacity.capacity()<<  std::endl;

    for (int i = 0; i < 24; i++)
    {
    	myVecCapacity.pop_back();
	    orjVecCapacity.pop_back();
    }

	std::cout <<"my vector capacity: "<< myVecCapacity.capacity()<< std::endl;
	std::cout<<"orj vector capacity: "<< orjVecCapacity.capacity()<<  std::endl;

    for (int i = 0; i < 24; i++)
    {
    	myVecCapacity.insert(myVecCapacity.begin(), i*2);
    	orjVecCapacity.insert(orjVecCapacity.begin(), i*2);
    }
    
    print_my_vector(myVecCapacity);
    print_orj_vector(orjVecCapacity);
    //!!!!!insert capacity is false


	std::cout<< "--------------end of the capacity--------------------------------\n\n" <<std::endl;
}

void testEmpty()
{
    std::cout<< "***iterator empty()***\n" <<std::endl;
	
	ft::vector<int> myVecEmpty;
	std::vector<int> orjVecEmpty;

    if (myVecEmpty.empty() == orjVecEmpty.empty())
        std::cout<<"OK"<<std::endl;
    else
        std::cout<<"FAIL"<<std::endl;

    myVecEmpty.push_back(5);
    orjVecEmpty.push_back(5);
    
    if (myVecEmpty.empty() == orjVecEmpty.empty())
        std::cout<<"OK"<<std::endl;
    else
        std::cout<<"FAIL"<<std::endl;



	std::cout<< "--------------end of the empty--------------------------------\n\n" <<std::endl;
}


void testReserve()
{
    std::cout<< "***iterator reserve()***\n" <<std::endl;
	
	ft::vector<int> myVecReserve;
	std::vector<int> orjVecReserve;

    if (myVecReserve.capacity() == myVecReserve.capacity())
        std::cout<<"OK"<<std::endl;
    else
        std::cout<<"FAIL"<<std::endl;
    
    orjVecReserve.reserve(5);
    orjVecReserve.reserve(5);
    if (myVecReserve.capacity() == myVecReserve.capacity())
        std::cout<<"OK"<<std::endl;
    else
        std::cout<<"FAIL"<<std::endl;

    orjVecReserve.reserve(15);
    orjVecReserve.reserve(15);
    if (myVecReserve.capacity() == myVecReserve.capacity())
        std::cout<<"OK"<<std::endl;
    else
        std::cout<<"FAIL"<<std::endl;

    orjVecReserve.reserve(1);
    orjVecReserve.reserve(1);
    if (myVecReserve.capacity() == myVecReserve.capacity())
        std::cout<<"OK"<<std::endl;
    else
        std::cout<<"FAIL"<<std::endl;

	std::cout<< "--------------end of the reserve--------------------------------\n\n" <<std::endl;
}

void testBoxBrackets()
{
    std::cout<< "***iterator BoxBrackets()***\n" <<std::endl;
	
	ft::vector<int> myVecBoxBrackets;
	std::vector<int> orjVecBoxBrackets;

    orjVecBoxBrackets.push_back(11);
    orjVecBoxBrackets.push_back(22);
    orjVecBoxBrackets.push_back(33);

    myVecBoxBrackets.push_back(11);
    myVecBoxBrackets.push_back(22);
    myVecBoxBrackets.push_back(33);

    const int a = orjVecBoxBrackets[0];
    const int b = myVecBoxBrackets[0];
    if (a == b)
        std::cout<<"OK"<<std::endl;
    else
    {
        std::cout<<"FAIL"<<std::endl;
    }

    for (size_t i = 0; i < myVecBoxBrackets.size(); i++)
    {
        if (myVecBoxBrackets[i] == orjVecBoxBrackets[i])
            std::cout<<"OK"<<std::endl;
        else
        {
            std::cout<<"FAIL for "<<i<<". element"<<std::endl;
        }
    }    
	std::cout<< "--------------end of the BoxBrackets--------------------------------\n\n" <<std::endl;
}