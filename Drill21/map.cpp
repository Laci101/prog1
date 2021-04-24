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





void Bekeres(std::map<std::string, int>& temp)
{
	std::string key;
	int val;
	while(temp.size() < 10 )
	{
		std::cin >> key >> val;
		temp.insert(std::pair<std::string, int>(key, val));
	}

}


int main()
{
	std::map<std::string, int> msi;
	std::map<std::string, int> :: iterator it = msi.begin();
	msi.insert ( std::pair<std::string, int> ("lecture",21));
	msi.insert ( std::pair<std::string, int> ("valami",218));
	msi.insert ( std::pair<std::string, int> ("igen",21));
	msi.insert ( std::pair<std::string, int> ("hello",2));
	msi.insert ( std::pair<std::string, int> ("szia",2123));

	std::cout << "Map\n";
	for(it=msi.begin(); it!=msi.end(); ++it)
		std::cout << it->first << "=>" << it->second << std::endl;

	msi.erase("igen");
	std::cout << "Igen erased\n";
	for(it=msi.begin(); it!=msi.end(); ++it)
		std::cout << it->first << "=>" << it->second << std::endl;

	std::cout << "Irj be string es integer parokat mig 10 nem lesz\n";
	Bekeres(msi);
	std::cout << "New map\n";
	for(it=msi.begin(); it!=msi.end(); ++it)
		std::cout << it->first << "=>" << it->second << std::endl;

	int total = std::accumulate(msi.begin(), msi.end(), 0,
            [](int sum, const std::pair<std::string,int>& p)
            { return sum += p.second; });

	  std::cout << "Total of integers: " << total << std::endl;

	std::map<int, std::string> mis;
	for(it=msi.begin(); it!=msi.end(); ++it)
		mis.insert(std::pair<int, std::string>(it->second, it->first));
	std::map<int, std::string> :: iterator it2 = mis.begin();
	std::cout << "mis map\n";
	for(it2=mis.begin(); it2!=mis.end(); ++it2)
		std::cout << it2->first << "=>" << it2->second << std::endl;


	return 0;
}