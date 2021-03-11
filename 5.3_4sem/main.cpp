#include <iomanip>
#include <iostream>
#include <regex>
#include <string>
#include <algorithm>



int main(int argc, char** argv)
{
	std::string data = " lots of wh++at.@email.us text text@mail.ru 1a@ya.ru lots of meaningless text lots of meaningless text norm@gmail.com lots of meaningless text  ";
	static const std::regex pattern(R"((\w+@)(\w+)(\.(?:com|ru)))");

	std::sregex_iterator begin(data.cbegin(), data.cend(), pattern);
	std::sregex_iterator end;

	std::for_each(begin, end, [](const std::smatch& m)
		{
			std::cout << m[2] << std::endl;
		});

	system("pause");

	return EXIT_SUCCESS;
}