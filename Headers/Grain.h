#include<vector>
#include <iostream>
#include <cstddef>

class Cipher{
public:
void start_init(std::string, std::string);
std::vector<std::byte> str_to_vec(std::string);

std::byte nfsr_feedback();
std::byte lfsr_feedback();



private:
std::vector<std::byte> nfsr{10};
std::vector<std::byte> lfsr{10};



};