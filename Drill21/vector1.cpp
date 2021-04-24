#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <string>
#include <fstream>
#include <stdexcept>
#include <algorithm>


struct Item
{
	std::string fname;
	std::string lname;
	int iid;
	double val;
};

std::ostream& operator<< (std::ostream& os,const Item& item)
{
	return os << item.fname << " " << item.lname << " " << item.iid << " " << item.val << std::endl; 

};

std::istream& operator>> (std::istream& is,  Item& it)
{
	std::string f, l;
	int id;
	double v;
	is >> f >> l >> id >> v;
	if(!is) return is;
	Item itt {f, l, id, v};
	it = itt;
	return is;
};

template<typename C>
void printout(const C& c, const std::string& s = "")
{
	std::cout << s << std::endl;
	for(auto& a : c)
		std::cout << a << " ";
	std::cout << std::endl;
};

class Cmp_by_name {
    private:
    	std::string name;
	public:
    	Cmp_by_name(const std::string& nn) : name{nn} {}
    	bool operator()(const Item& x) const { return x.fname == name; }
};

struct compare_id{
	private:
		int id;
	public:
		compare_id(const int& asd) : id{asd} {}
		bool operator()(const Item& x) const {return x.iid == id;}
};


int main()
try{

	std::vector<Item> vi;
	const std::string str {"test.txt"};
	std::ifstream ifs{str};
	if(!ifs) throw std::runtime_error("Could not read from file: " + str);

	for (Item ii; ifs >> ii;)
		vi.push_back(ii);

	std::list<Item> li (vi.size());
	std::copy(vi.begin(), vi.end(), li.begin());


	std::sort (vi.begin(), vi.end(),
		[] (const Item& a,const Item& b) {return a.fname > b.fname;});
	printout(vi, "Sort by name:");

	std::sort (vi.begin(), vi.end(),
		[] (const Item& a, const Item& b) {return a.iid > b.iid;});
	printout(vi,"Sort by iid:");

	std::sort (vi.begin(), vi.end(),
		[] (const Item& a, const Item& b) {return a.val < b.val;});
	printout(vi,"Sort by value");

	Item ins {"horse", "shoe", 99, 1.34};
	vi.insert(vi.begin(), ins);
	printout(vi, "1st insert");

	Item ins2 {"Canon", "S400", 9988, 499.95};
	vi.insert(vi.begin(), ins2);
	printout(vi, "2nd insert");

	vi.erase(std::find_if(vi.begin(), vi.end(), Cmp_by_name("Canon")));
	printout(vi, "-Canon");

	vi.erase(std::find_if(vi.begin(), vi.end(), compare_id(99)));
	printout(vi, "-99");

	printout(li, "List");


	return 0;
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}