#include "./containers/vector.hpp"

/* void print_vector(ft::vector<int> v)
{
    ft::random_access_iterator<int>::iterator it = v.begin();
    std::cout<<"print vector";
    std::cout<< "\n-------------\n";
    std::cout<<"\ncapacity: "<<v.capacity()<<" size: "<<v.size()<<std::endl;
    
    while(it != v.end())
        std::cout<<*it++<<" ";
    std::cout<< "\n-------------\n";
} */

int main()
{
    ft::random_access_iterator<int>::iterator it2;
/*     ft::vector<int> v1;

    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    ft::random_access_iterator<int>::iterator it;
    it = v1.begin();
    std::cout<<*it<<std::endl;
    for(;it != v1.end(); it++)
        std::cout<<*it<<" ";

    v1.clear();
    std::cout<<"new iter"<<std::endl;
    it2 = v1.begin();
    for(;it2 != v1.end(); it2++)
        std::cout<<*it2<<" "; */
    
    ft::vector<int> v2;
    std::cout<<"\ncapacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl;
    v2.insert(v2.begin(), 3, 1);
    std::cout<<"\ncapacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl;
        it2 = v2.begin();
    for(;it2 != v2.end(); it2++)
        std::cout<<*it2<<" ";
    std::cout<<"\n------------------------"<<std::endl;

    v2.insert(v2.begin(), 3, 2);
    std::cout<<"\ncapacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl;
            it2 = v2.begin();
    for(;it2 != v2.end(); it2++)
        std::cout<<*it2<<" ";
    std::cout<<"\n------------------------"<<std::endl;

    v2.insert(v2.begin(), 3, 3);
    std::cout<<"\ncapacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl;
            it2 = v2.begin();
    for(;it2 != v2.end(); it2++)
        std::cout<<*it2<<" ";
    std::cout<<"\n------------------------"<<std::endl;

    v2.insert(v2.begin(), 3, 4);
    std::cout<<"\ncapacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl;
        it2 = v2.begin();
    for(;it2 != v2.end(); it2++)
        std::cout<<*it2<<" ";
    std::cout<<"\n------------------------"<<std::endl;
    
    v2.insert(v2.begin(), 3, 5);
    std::cout<<"\ncapacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl;

    it2 = v2.begin();
    for(;it2 != v2.end(); it2++)
        std::cout<<*it2<<" ";
    std::cout<<"\n------------------------"<<std::endl;

   
/*     v2.erase(v2.begin());
    std::cout<<"\ncapacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl; */
/*     v2.erase(v2.begin());
    std::cout<<"\ncapacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl;
    v2.erase(v2.begin());
    std::cout<<"\ncapacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl; */

    
   /*  v2.clear();
    std::cout<<"\ncapacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl;
 */


/*     v2.push_back(22);
    v2.push_back(32);
    v2.push_back(42);
    v2.push_back(52);
    v2.push_back(62); */
    /* v2.erase(v2.begin()); */
    ft::random_access_iterator<int>::iterator it3;

        it3 = v2.begin();
    for(;it3 != v2.end(); it3++)
        std::cout<<*it3<<" ";
    std::cout<<"\ncapacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl;
    
    //v2.erase(v2.begin(), v2.end());

    v2.resize(20);
    std::cout<<"\ncapacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl;

    v2.resize(30, 9);

    ft::random_access_iterator<int>::iterator it4;

    it4 = v2.begin();
    for(;it4 != v2.end(); it4++)
        std::cout<<*it4<<" ";
    std::cout<<"\ncapacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl;
    
    
    //v2.erase(v2.begin());
/*     v2.insert(v2.begin(), 72);
    it2 = v2.begin();
    for(;it2 != v2.end(); it2++)
        std::cout<<*it2<<" "; */

/*     std::cout<<"\ncapacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl;
    v2.insert(v2.begin(), 5);
    std::cout<<"capacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl;
        v2.insert(v2.begin(), 5);
    std::cout<<"capacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl;
        v2.insert(v2.begin(), 5);
    std::cout<<"capacity: "<<v2.capacity()<<" size: "<<v2.size()<<std::endl;

    ft::random_access_iterator<int>::iterator it3;

    it3 = v2.begin();
    
    for(;it3 != v2.end(); it3++)
        std::cout<<*it3<<" "; */
/*     ft::random_access_iterator<int>::iterator it3;
    it3 = v2.begin(); */
/*     it3++;
    it3++;
    v2.erase(v2.begin(), it3);
    it2 = v2.begin();
    for(;it2 != v2.end(); it2++)
        std::cout<<*it2<<" "; */
/*     it3 = v2.begin();
    it3++;
    v2.insert(it3, 72);
    ft::random_access_iterator<int>::iterator it4;
    it4 = v2.begin();
    for(;it4 != v2.end(); it4++)
        std::cout<<*it4<<" ";  */
    

}