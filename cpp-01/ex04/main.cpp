#include <iostream>
#include <string>
#include <fstream>
#include <iterator>

static std::string	replaceAll(const std::string& input, const std::string& s1, const std::string& s2)
{
	if (s1 == s2)
		return input;

	std::string	dest;
	dest.reserve(input.size());

	size_t i = 0;
	while (i < input.size())
	{
		size_t	found = input.find(s1, i);
		if (found != std::string::npos)
		{
			dest.append(input, i, found - i);
			dest += s2;
			i = found + s1.size();
		}
		else
		{
			dest.append(input, i, std::string::npos);
			break ;
		}
	}
	return dest;
}


int	main(int ac, char **av)
{
	if (ac != 4)
		return std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl, 1;

	const	std::string	filename = av[1];
	const std::string	s1 = av[2];
	const std::string	s2 = av[3];

	if (s1.empty())
		return std::cerr << "Error: <s1> cannot be empty" << std::endl, 2;

	std::ifstream	in(filename.c_str(), std::ios::in);
	if (!in)
		return std::cerr << "Error: Unable to open file " << filename << std::endl, 3;

	const std::string content((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

	const std::string outname = filename + ".replace";

	std::ofstream	out(outname.c_str(), std::ios::out | std::ios::trunc);
	if (!out)
		return std::cerr << "Error: Unable to create output file " << outname << std::endl, 4;

	out << replaceAll(content, s1, s2);

	return 0;
}
