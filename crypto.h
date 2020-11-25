/*
    Scrypt is a string crypto for AES-CRC-Padding designed by ilshookim
    MIT License

    https://github.com/ilshookim/scrypt
*/

#pragma once

#include <fmt/core.h>

namespace Scrypt {

int32_t defaultKeyLength();
int32_t defaultBlockSize();
std::string encrypt(std::string& plain, std::vector<uint8_t>& key, std::vector<uint8_t>& iv);
std::string decrypt(std::string& cipher, std::vector<uint8_t>& key, std::vector<uint8_t>& iv);

} // namespace Scrypt
