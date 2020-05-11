#include<vector>
#include <iostream>
#include <cstddef>

class StreamCipherGrain{
public:
void start_init();



private:
std::vector<std::byte> nfsr{10};
std::vector<std::byte> lfsr{10};



}