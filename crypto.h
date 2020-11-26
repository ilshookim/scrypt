/*
    Scrypt is a string crypto for AES-CRC-Padding designed by ilshookim
    MIT License

    https://github.com/ilshookim/scrypt
*/

#pragma once

#include <fmt/core.h>

namespace Scrypt {

// * AES/CBC 암호화/복호화
//   안드로이드와 C++ 간에 호환성을 맞춤
//
// * 자바에서 AES/CBC 사용법
//   public static String secretKey = "비밀키";
//   AES256Chiper.AES_Encode("암호화 내용");
//   AES256Chiper.AES_Decode("복호화 내용");
//
// * C++에서 AES/CBC 사용법
//   std::string secret = "비밀키";
//   std::vector<uint8_t> key(secret.begin(), secret.end()), iv(Scrypt::defaultBlockSize());
//   std::string encrypted = Scrypt::encrypt("암호화 내용", key, iv);
//   std::string decrypted = Scrypt::decrypt("복호화 내용", key, iv);
//
int32_t defaultKeyLength();
int32_t defaultBlockSize();
std::string encrypt(std::string& plain, std::vector<uint8_t>& key, std::vector<uint8_t>& iv);
std::string decrypt(std::string& cipher, std::vector<uint8_t>& key, std::vector<uint8_t>& iv);

} // namespace Scrypt
