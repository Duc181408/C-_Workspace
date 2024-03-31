#include<iostream> 

using namespace std; 

int function()
{
	int error_local;
	static int local_sta = 2;
	enum {i = 1, j = 2};
	class Account {
	public:
		static int  static_data;
		int normal_data;
		void error_method();
		void methods(){
			cout<<"local var and enum = "<< local_sta<< i<<j;
		}
	}
	Account::error_method(){
		cout<<"In error mrthod";
	}
	Account frank; // fine
}

int main() 
{	 
	Account out_of_scope;  // error
} 
