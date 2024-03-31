#include <iostream>

using namespace std;

/*
Size of all non-static data members
Order of data members
Byte alignment or byte padding

*/

class Student {
public:
    static int var;
    char name[22];
    int MSSV;
    double CPA;
    void print_address()
    {
        char *p = &name[0];
        cout<<"Address:    "<< reinterpret_cast<int *>(p)<<endl; //<<"    "<<&MSSV<<"    "<< &CPA<< endl;
        cout<<"Address:    "<<endl;
        cout<<"Address:    "<< &MSSV<<endl;
        cout<<"Address:    "<<endl;
        cout<<"Address:    "<< &CPA<< endl;
    }
};


class B { 
        int iMem1;
        int iMem2;
};
 
class D: public B { 
        int iMem;
};


class Base { 
public: 
    virtual void SomeFunction(...); 
private: 
    int iAMem;
}; 
 
class Derived : public Base { 
    virtual void SomeOtherFunction(...); 
private: 
    int iBMem;
}; 
//==========================================================
class ABase{ 
        int iMem; 
}; 
 
class BBase : public virtual ABase { 
        int iMem; 
}; 
 
class CBase : public virtual ABase { 
        int iMem; 
}; 
 
class ABCDerived : public BBase, public CBase { 
        int iMem; 
}; 

class Test{
    char t;
};

class Test2:public Test{

};

int main()
{
    cout<<""<<endl;
    cout<<""<<endl;
    // cout<<"Size of class Base: "<<sizeof(Base)<<endl;
    cout<<"Size of class Student: "<<sizeof(Test)<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    return 0;
}

