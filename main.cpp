/*
    Scrypt is a string crypto for AES-CBC-Padding designed by ilshookim
    MIT License

    https://github.com/ilshookim/scrypt
*/

#include <fmt/core.h>

#include "build/config.h"
#include "crypto.h"

int main(int argc, char* argv[], char* envp[])
{
    const std::string appVersion = PROJECT_VER;
    const std::string appName = PROJECT_NAME;
    fmt::print("{}: version={}\n", appName, appVersion);

    std::string key = "20201126T000101Z";
    std::string plain = "{\"dummy\":\"my name is dummy\",\"version\":\"1.-1.99\",\"data\":{\"age\":50,\"address\":\"Seoul Seocho-Gu\",\"phone\":\"02-1234-5678\"},\"salary\":\"unknown\"}";
    fmt::print("plain={}\n", plain);
    std::string encrypted = Scrypt::encrypt(plain, key);
    fmt::print("encrypted={}\n", encrypted);
    std::string decrypted = Scrypt::decrypt(encrypted, key);
    fmt::print("decrypted={}\n", decrypted);

    return 0;
}
