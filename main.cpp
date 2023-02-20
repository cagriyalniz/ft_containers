#include "./containers/vector.hpp"
#include "./containers/stack.hpp"
#include <vector>
#include "./iterators/RandomAccess_Iterator.hpp"

/* void print_vector(ft::vector<int> v)
{
    ft::RandomAccessIterator<int>::iterator it = v.begin();
    std::cout<<"print MY vector";
    std::cout<< "\n-------------\n";
    std::cout<<"capacity: "<<v.capacity()<<" size: "<<v.size()<<std::endl;
    
	std::cout<<"datas ---> ";
    while(it != v.end())
        std::cout<<*it++<<" ";
    std::cout<< "\n-------------\n";
}

void print_vector(std::vector<int> v)
{
    std::vector<int>::iterator it = v.begin();
    std::cout<<"print REAL vector";
    std::cout<< "\n-------------\n";
    std::cout<<"capacity: "<<v.capacity()<<" size: "<<v.size()<<std::endl;
    
    while(it != v.end())
        std::cout<<*it++<<" ";
    std::cout<< "\n-------------\n";
} */

int main()
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

	std::cout<< "----------------------------------------------\n\n" <<std::endl;

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
	if (myVecEmptyEnd.begin() == myVecEmptyEnd.end())
		std::cout<<"True \n";
	if (orjVecEmptyEnd.begin() == orjVecEmptyEnd.end())
		std::cout<<"True \n";

	std::cout<< "----------------------------------------------\n\n" <<std::endl;

	/* std::cout<< "***iterator rbegin() const_iterator rbegin()***\n" <<std::endl;
	ft::vector<int> myVecRBegin;
	ft::vector<int>::reverse_iterator myItRBegin;
	//ft::vector<int>::const_iterator myConstItRBegin;

	std::vector<int> orjVecRBegin;
	std::vector<int>::reverse_iterator orjItRBegin;
	//std::vector<int>::const_iterator constOrjItRBegin;

	myVecRBegin.push_back(1);
	myVecRBegin.push_back(2);
	myVecRBegin.push_back(3);
	myItRBegin = myVecRBegin.rbegin();
	//myConstItRBegin = myVecRBegin.rbegin();
	std::cout <<"my vector: "<< *myItRBegin<< " " << *myConstItRBegin << std::endl;

	orjVecRBegin.push_back(1);
	orjVecRBegin.push_back(2);
	orjVecRBegin.push_back(3);
	//3 2 1
	orjItRBegin = orjVecRBegin.rbegin();
	//constOrjItRBegin = orjVecRBegin.rbegin();
	std::cout<<"orj vector: "<< *orjItRBegin<< " " << *constOrjItRBegin << std::endl;

	std::cout<< "----------------------------------------------\n\n" <<std::endl;*/
 
}