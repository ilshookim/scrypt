/*
    Scrypt is a string crypto for AES-CRC-Padding designed by ilshookim
    MIT License

    https://github.com/ilshookim/scrypt
*/

#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>

#include "crypto.h"

namespace Scrypt {

int32_t defaultKeyLength()
{
    return CryptoPP::AES::DEFAULT_KEYLENGTH;
}

int32_t defaultBlockSize()
{
    return CryptoPP::AES::BLOCKSIZE;
}

std::string encrypt(std::string& plain, std::vector<uint8_t>& key, std::vector<uint8_t>& iv)
{
	std::string encrypted;
	CryptoPP::AES::Encryption encryption(key.data(), CryptoPP::AES::DEFAULT_KEYLENGTH);
	CryptoPP::CBC_Mode_ExternalCipher::Encryption mode(encryption, iv.data());
	CryptoPP::StreamTransformationFilter encryptor(mode, new CryptoPP::StringSink(encrypted));
	encryptor.Put(reinterpret_cast<const unsigned char*>(plain.c_str()), plain.length());
	encryptor.MessageEnd();
	return encrypted;
}

std::string decrypt(std::string& cipher, std::vector<uint8_t>& key, std::vector<uint8_t>& iv)
{
	std::string decrypted;
	CryptoPP::AES::Decryption decryption(key.data(), CryptoPP::AES::DEFAULT_KEYLENGTH);
	CryptoPP::CBC_Mode_ExternalCipher::Decryption mode(decryption, iv.data());
	CryptoPP::StreamTransformationFilter decryptor(mode, new CryptoPP::StringSink(decrypted));
	decryptor.Put(reinterpret_cast<const unsigned char*>(cipher.c_str()), cipher.size());
	decryptor.MessageEnd();
	return decrypted;
}

} // namespace Scrypt
