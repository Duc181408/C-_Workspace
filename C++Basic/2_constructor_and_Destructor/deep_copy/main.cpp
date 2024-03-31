#include <iostream>

using namespace std;

class Deep{
private:
    int *data;
    
public:
    Deep(int d);
    Deep(const Deep &source);
    int get_data_value()
    {
        cout<<"data" << *data<<endl;
        return *data;
    }
    void set_data_value(int val)
    {
        *data = val;
    }
    ~Deep();

};

Deep::Deep(const Deep &source)
{
	data=new int;                    //Create new pointer in heap
	*data=*source.data;        //Copy value to new pointer in heap
}

Deep::Deep(int d)
{
	data= new int;     //create memory in heap to allocate the data
	*data=d;
}

Deep::~Deep()
{
	delete data;         //Free memory in heap
}

void Display_Objects(Deep s)
{

    cout << s.get_data_value() << endl;
} //=> call ~Shallow right here  => free s 

int main()
{
    Deep obj1{100};
    Display_Objects(obj1);
    Deep obj2 = Deep(obj1);
    
    return 0;
}