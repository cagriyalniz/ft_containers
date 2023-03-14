#include "./containers/vector.hpp"
#include "./containers/map.hpp"
#include "./containers/stack.hpp"
#include <vector>
#include "./iterators/RandomAccess_Iterator.hpp"
#include "./iterators/Reverse_Iterator.hpp"


int main()
{
	/* std::cout<<"Vector test is starting..."<<std::endl;
//iterators
	testBegin();
	testEnd();
	testRbegin();
	testRend();

//capacity
	testSize();
	testMaxSize();
	testResize(); 
	testCapacity();
	testEmpty();
	testReserve();

//element access
	testBoxBrackets();
	testAt();
	testFront();
	testBack();

//Modifiers:
	testAssign();
 	testPushBack();
	testPopBack();
	testInsert();
	testErase();
	testSwap();
	testClear();
	testGetAllocator(); 
	std::cout<<"Vector test finished"<<std::endl; */


	std::cout<<"Map test is starting..."<<std::endl;
	mapBegin();
	mapEnd();
	mapRBegin();
	mapREnd();
	mapEmpty();
	mapSize();
	mapMaxSize();
	
	mapBoxBrackets();
	mapInsert(); 
	//mapErase();
	mapSwap();
	mapClear();
	mapKeyComp();
	mapValueComp();
	std::cout<<"Map test finished"<<std::endl;




 
}