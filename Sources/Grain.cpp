#include"Grain.h"

void Cipher :: start_init(std::string key_string, std::string iv_string){
    auto Key = str_to_vec(key_string);
    auto IV = str_to_vec(iv_string);

    nfsr = Key;
    for(size_t i = 0; i < 8; i++){
        lfsr[i] = IV[i];
    }
    lfsr[8] = (std::byte) 0b11111111;
    lfsr[9] = (std::byte) 0b11111111;

    

}
   
std::vector<std::byte> str_to_vec(const std::string& input){
std::vector<std::byte> bytes;
  for (size_t i = 0; i < input.length(); i += 2) {
    std::string byteString = input.substr(i, 2);
    std::byte element = (std::byte) strtol(byteString.c_str(), NULL, 16);
    bytes.push_back(element);
  }
  return bytes;
}


std::byte Cipher::nfsr_feedback(){
    std::byte s_62 = (nfsr[7] & std::byte{0b00000010}) >> 1;
    std::byte s_51 = (nfsr[6] & std::byte{0b00010000}) >> 4;
    std::byte s_38 = (nfsr[4] & std::byte{0b00000010}) >> 1;
    std::byte s_23 = (nfsr[2] & std::byte{0b00000001});
    std::byte s_13 = (nfsr[1] & std::byte{0b00000100}) >> 2;
    std::byte s = (nfsr[0] & std::byte{0b10000000}) >> 7;

    return s_62 ^ s_51 ^ s_38 ^ s_23 ^ s_13 ^ s;
}

std::byte Cipher::lfsr_feedback(){
    
}
