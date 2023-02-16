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

	//vector
	//outofindex control edilecek

	/* 
    ft::vector<int> myV1;
    ft::random_access_iterator<int>::iterator myIt;
	
	print_vector(myV1);

	myV1.insert(myV1.begin(), 0);
	print_vector(myV1);

	myV1.insert(myV1.begin(), 2, 1);
	print_vector(myV1);

	myV1.erase(myV1.begin());
	print_vector(myV1);

	myV1.erase(myV1.begin(), myV1.end());
	print_vector(myV1);

	for (int i = 0; i < 10; i++)
		myV1.push_back(i);
	print_vector(myV1);
	
	
	for (int i = 0; i < 10; i++)
		myV1.pop_back();
	print_vector(myV1);

	myV1.resize(1);
	print_vector(myV1);

	myV1.resize(5, 42);
	print_vector(myV1);
	
	myV1.resize(2);
	print_vector(myV1);

	ft::vector<int>myV2;
	myV2.push_back(41);
	print_vector(myV2);

	myV1.swap(myV2);
	print_vector(myV1);


	myIt = myV2.begin();
	std::cout<<*myIt<<std::endl;
	myIt++;
	std::cout<<*myIt<<std::endl; */



  /*   ft::stack<std::string, ft::vector<std::string> > myStack;
	myStack.push("42");
	myStack.push("ecole");
	std::cout<<myStack.top()<<std::endl;

	ft::stack<int> myStackInt;
	myStackInt.push(42);
	myStackInt.push(41);
	std::cout<<myStackInt.top()<<std::endl;
	myStackInt.pop();
	std::cout<<myStackInt.top()<<std::endl; */
	/* ft::vector<int>::iterator myIt;
	myIt = myStackInt.begin();
	std::cout<<*myIt<<std::endl;
    myIt++;
    std::cout<<*myIt<<std::endl; */
	ft::vector<int> ar;
    ft::vector<int>::iterator ptr;

    ar.push_back(1);
    ar.push_back(2);
    ar.push_back(3);
    ar.push_back(4);
      
    std::cout << "The vector elements are : ";
    for (ptr = ar.begin(); ptr < ar.end(); ptr++)
        std::cout << *ptr << " ";



}