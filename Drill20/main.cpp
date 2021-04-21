#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <string>

template<typename C>
void printout(const C& c, const std::string& s = "")
{
	std::cout << s << std::endl;
	for(auto& a : c)
		std::cout << a << " ";
	std::cout << std::endl;
};

template<typename T>
void increase(T& t, int n = 0)
{
	for(auto& a : t)
		a += n;
};

template<typename In, typename Out>
Out my_copy(In first, In last, Out res)
{
	while (first != last)
	{
		*res = *first;
		++res;
		++first;
	}
	return res;
};

void f(std::vector<int>& v, int x)
{
	std::vector<int> :: iterator p = find(v.begin(),v.end(),x);
	if (p!=v.end()) {std::cout << "We found it at: " <<  std::distance(v.begin(), p) << std::endl;}
	else{std::cout << "Not found\n"; };
}

int main()
{
	int a[10];
	for (int i = 0; i < 10; ++i)
		a[i] = i;
	printout(a, "og array:");

	std::array<int, 10> b;
	std::copy(a, a + 10, b.begin());
	increase(b, 2);
	printout(b, "copied array");

	std::vector<int> my_vector = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printout(my_vector, "og vector");

	std::vector<int> my_vector2(10);
	std::copy(my_vector.begin(), my_vector.end(), my_vector2.begin());
	increase(my_vector2, 3);
	printout(my_vector2, "copied vector");

	std::list<int> li (10);
	std::copy(a, a + 10, li.begin());
	printout(li, "og list");

	std::list<int> li2 (10);
	std::copy(li.begin(), li.end(), li2.begin());
	increase(li2, 5);
	printout(li2, "copied list");

	my_copy(b.begin(), b.end(), my_vector2.begin());
	my_copy(li2.begin(), li2.end(), b.begin());
	printout(my_vector2, "array masolasa vektorba");
	printout(b, "lista masolasa arrayba");

	std::cout << "Kereses 3" << std::endl;
	f(my_vector2, 3);
	std::cout << "Kereses 27" << std::endl;
	f(my_vector2, 27);

	return 0;
}