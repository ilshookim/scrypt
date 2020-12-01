/*
    Scrypt is a string crypto for AES-CBC-Padding designed by ilshookim
    MIT License

    https://github.com/ilshookim/scrypt
*/

#pragma once

#include <fmt/core.h>

namespace Scrypt {

std::string encrypt(std::string plain, std::string key, bool base64 = true);
std::string decrypt(std::string cipher, std::string key, bool base64 = true);
std::string encrypt(std::string plain, std::string key, std::string iv, bool base64 = true);
std::string decrypt(std::string cipher, std::string key, std::string iv, bool base64 = true);

} // namespace Scrypt
