/*
    Scrypt is a string crypto for AES-CRC-Padding designed by ilshookim
    MIT License

    https://github.com/ilshookim/scrypt
*/

#include <fmt/core.h>

#include <cryptopp/gcm.h>
#include <cryptopp/aes.h>
#include <cryptopp/osrng.h>
#include <cryptopp/pwdbased.h>
#include <cryptopp/files.h>

#include "build/config.h"

std::string encrypt(std::string& plain, CryptoPP::byte* key, CryptoPP::byte* iv)
{
	std::string encrypted;
	CryptoPP::AES::Encryption encryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
	CryptoPP::CBC_Mode_ExternalCipher::Encryption mode(encryption, iv);
	CryptoPP::StreamTransformationFilter encryptor(mode, new CryptoPP::StringSink(encrypted));
	encryptor.Put(reinterpret_cast<const unsigned char*>(plain.c_str()), plain.length());
	encryptor.MessageEnd();
	return encrypted;
}

std::string decrypt(std::string& cipher, CryptoPP::byte* key, CryptoPP::byte* iv)
{
	std::string decrypted;
	CryptoPP::AES::Decryption decryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
	CryptoPP::CBC_Mode_ExternalCipher::Decryption mode(decryption, iv);
	CryptoPP::StreamTransformationFilter decryptor(mode, new CryptoPP::StringSink(decrypted));
	decryptor.Put(reinterpret_cast<const unsigned char*>(cipher.c_str()), cipher.size());
	decryptor.MessageEnd();
	return decrypted;
}

int main(int argc, char* argv[], char* envp[])
{
    const std::string appVersion = PROJECT_VER;
    const std::string appName = PROJECT_NAME;
    fmt::print("{}: version={}\n", appName, appVersion);

    int32_t appExited = 0;
    std::string appExcepted = "none";
    try
    {
        std::string secret = "alticastpassword";
        std::string plane = "{\"dummy\":\"my name is dummy\",\"version\":\"1.-1.99\",\"data\":{\"age\":50,\"address\":\"Seoul Seocho-Gu\",\"phone\":\"02-2007-8620\"},\"salary\":\"unknown\"}";
        std::vector<uint8_t> key(secret.begin(), secret.end()), iv(CryptoPP::AES::BLOCKSIZE);

        std::string encrypted = encrypt(plane, key.data(), iv.data());
        fmt::print("encrypted={}\n", encrypted);

        std::string decrypted = decrypt(encrypted, key.data(), iv.data());
        fmt::print("decrypted={}\n", decrypted);
    }
    catch (std::exception& exc) 
    {
        appExited = -1;
        appExcepted = fmt::format("std::exception, cause={}", exc.what());
    }
    catch (...) 
    {
        appExited = -1;
        appExcepted = fmt::format("exception, cause={}", "...");
    }

    fmt::print("{}: exit={}, except={} <- version={}\n", 
        appName, appExited, appExcepted, appVersion);

    return appExited;
}
