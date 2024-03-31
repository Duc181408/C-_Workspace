#include <iostream>
using namespace std;

class Source;

//friend void friendFunction(Source& t);
class anotherClass {
public:
    static void memberFunction(Source& t);
};

class Source {
private:
	int private_variable;

protected:
	int protected_variable;

public:
	Source()
	{
		private_variable = 10;
		protected_variable = 99;
	}
	// friend class declaration
	friend class friend_class;
	// friend function
	friend void friendFunction(Source& t);
	friend void anotherClass::memberFunction(Source& t);
};

class friend_class {
public:
	void display(Source& t)
	{
		cout << "The value of Private Variable = "
			<< t.private_variable << endl;
		cout << "The value of Protected Variable = "
			<< t.protected_variable <<endl;
	}
};

// friend function definition
void friendFunction(Source& t)
{
	cout << "The value of Private Variable = "
		<< t.private_variable << endl;
	cout << "The value of Protected Variable = "
		<< t.protected_variable;
}

void anotherClass::memberFunction(Source& t)
{
	cout << "The value of Private Variable = "
		<< t.private_variable << endl;
	cout << "The value of Protected Variable = "
		<< t.protected_variable;
}

// Driver code
int main()
{
	Source g;
	// friend_class fri;
	// fri.display(g);
	// friendFunction(g);
	anotherClass::memberFunction(g);
	return 0;
}
