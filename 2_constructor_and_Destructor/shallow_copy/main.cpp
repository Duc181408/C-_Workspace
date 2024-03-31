#include <iostream>

using namespace std;

class Shallow{
    private:
    int *data;
    
    public:
    Shallow(int d);
    Shallow(const Shallow &source);
    int get_data_value()
    {
        cout<<"data" << *data<<endl;
        return *data;
    }
    void set_data_value(int val)
    {
        *data = val;
    }
    ~Shallow();
};
Shallow::Shallow(int d)
{
    data= new int; //create memory in heap to allocate the data
    *data=d;
}
Shallow::~Shallow()
{
    delete data; //Free memory in heap
}
			
Shallow::Shallow(const Shallow &source): data{source.data}{};

void Display_shallow(Shallow s)
{
    cout << s.get_data_value() << endl;
} //=> call ~Shallow right here  => free heap


int main()
{
    Shallow obj1 {100};

    Display_shallow(obj1);              //(1) Do the shallow copy & call destructor after done -> Clear memory in heap
    
    Shallow obj2 {obj1};                   //(2) Call the copy constructor again and point to the same pointer of obj1
    
    obj2.set_data_value(1000);    //Also change the value of obj1 
    return 0;
}
// Return from main obj1 & 2 call the destructor, now the pointer is pointing to invalid area -> Cannot delete anymore -> System error