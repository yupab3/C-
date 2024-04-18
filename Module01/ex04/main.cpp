#include <iostream>
#include <fstream>

int	main(int argc, char **argv){
	if (argc != 4) return 1;
	std::ifstream infile(argv[1]);
	std::string	fname = argv[1];
	std::ofstream outfile((fname + ".replace").c_str());
	if (!outfile.is_open()){
		std::cout << "outfile open error\n";
		return 1;
	}
	if (!infile.is_open()){
		outfile.close();
		std::cout << "infile open error\n";
		return 1;
	}
	std::string	bf_str = argv[2];
	std::string af_str = argv[3];
	if (bf_str == ""){
		std::cout << "wrong input error\n";
		outfile.close();
		infile.close();
		return 1;
	}
	std::string	str;
	std::getline(infile, str, '\0');
	size_t trgt_pos = 0;
	while (str.find(bf_str) != str.npos){
		trgt_pos = str.find(bf_str);
		outfile.write(str.c_str(), trgt_pos);
		trgt_pos += bf_str.size();
		str.erase(0, trgt_pos);
		outfile.write(af_str.c_str(), af_str.size());
	}
	outfile.write(str.c_str(), str.size());
	outfile.close();
	infile.close();
	return 0;
}