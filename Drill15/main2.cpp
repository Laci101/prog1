
#include "../std_lib_facilities.h"




class Person{
private:
	string first_name;
	string second_name;
	int age;
public:
	Person() { };
	Person(string s1, string s2, int a):first_name(s1), second_name(s2), age(a){ if(!is_validage()) error("Invalid age");else if(!is_validname()) error("Invalid firstname/secondname");};
	bool is_validage();
	bool is_validname();
	string get_firstname() const { return first_name; };
	string get_secondname() const { return second_name; };
	int get_age() const { return age; };
};

bool Person::is_validage()
{
	if(age<0 || age>150)return false;
	return true;
};


bool Person::is_validname()
{
	if(first_name.find('*')<first_name.length() || first_name.find(';')<first_name.length() || first_name.find(':')<first_name.length() || 	first_name.find('"')<first_name.length() || first_name.find('&')<first_name.length() || first_name.find('[')<first_name.length() || first_name.find(']')<first_name.length()|| first_name.find('^')<first_name.length() || first_name.find('%')<first_name.length() || first_name.find('#')<first_name.length() || first_name.find('$')<first_name.length() || first_name.find('@')<first_name.length() || first_name.find('!')<first_name.length() || first_name.find("'")<first_name.length() || second_name.find('*')<second_name.length() || second_name.find(';')<second_name.length() || second_name.find(':')<second_name.length() || second_name.find('"')<second_name.length() || second_name.find('&')<second_name.length() || second_name.find('[')<second_name.length() || second_name.find(']')<second_name.length()|| second_name.find('^')<second_name.length() || second_name.find('%')<second_name.length() || second_name.find('#')<second_name.length() || second_name.find('$')<second_name.length() || second_name.find('@')<second_name.length() || second_name.find('!')<second_name.length() || second_name.find("'")<second_name.length())return false;
	return true;
};

ostream& operator<< (ostream& os, Person& p)
{
	return os << p.get_firstname()
	<<" "<< p.get_secondname()
	<<" "<< p.get_age();
}

istream& operator>> (istream& is, Person& p)
{
	string f, l;
	int a;
	is >> f >> l >> a;
	if (!is) return is;
	p = Person(f, l, a);
	return is;
}

int main()
{
	/*string input1;
	string input2;
	int  input3=0;*/
	
	vector<Person> vp;
	Person p;
	
	
	cout<<"Enter some names and ages. Terminate with name 'end'\n";
	
	for (Person p; cin >> p; ) 
	{
        if (p.get_firstname() == "+") break;
        vp.push_back(p);
    	}

    	for (Person p : vp)
		cout << p << '\n';

	
	
	/*vector<string> first_names;
	vector<string> second_names;
	vector<int> ages;*/
	
	
	
return 0;
}
