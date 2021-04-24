//ACCUMULATE

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <string>
#include <fstream>
#include <stdexcept>
#include <map>
#include <numeric>

template<typename C>
void printout(const C& c, const std::string& s = "")
{
	std::cout << s << std::endl;
	for(auto& a : c)
		std::cout << a << std::endl;
};

struct Lesser_than {
private:
	double v;
public:
	Lesser_than(double vv) : v(vv) { };
	bool operator()(double x) const { return x < v; };
}; 


int main()
try{
	std::vector<double> vd;
	const std::string str {"double.txt"};
	std::ifstream ifs{str};
	if(!ifs) throw std::runtime_error("Could not read from file: " + str);

	for (double ii; ifs >> ii;)
		vd.push_back(ii);

	std::vector<int> vi(vd.size());
	std::copy(vd.begin(), vd.end(), vi.begin());

	printout(vd, "Double vector output");
	printout(vi, "Integer vector output");
	
	std::map<int, double> m;
	for(size_t i = 0; i < vi.size(); ++i)
		m[vi[i]] = vd[i];
	std::cout << "Pairs\n";
	std::for_each(m.begin(), m.end(), [](const std::pair<int,double>& p)
	{std::cout << p.first << "," << p.second << "\n";});

	std::cout << "Double vector sum\n" << accumulate(vd.begin(), vd.end(), 0.0) << std::endl;
	std::cout << "The 2 vectors' difference\n" << accumulate(vd.begin(), vd.end(), 0.0) - accumulate(vi.begin(), vi.end(), 0) << std::endl;

	std::reverse(vd.begin(), vd.end());
	printout(vd, "Reverse double vector");

	std::cout << "Mean value of the double vector\n" << accumulate(vd.begin(), vd.end(), 0.0)/vd.size() << std::endl;

	std::vector<double> vd2 (vd.size());
	double mean = accumulate(vd.begin(), vd.end(), 0.0)/vd.size();
	auto it = std::copy_if(vd.begin(), vd.end(), vd2.begin(), Lesser_than(mean));
	vd2.resize(std::distance(vd2.begin(), it));
	printout(vd2, "Lesser than mean value");

	std::sort (vd.begin(), vd.end(),
		[] (const auto a, const auto b) {return a < b;});
	printout(vd,"Sorted");

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