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

    int32_t appExited = 0;
    std::string appExcepted = "none";
    try
    {
        std::string secret = "20201126T000101Z";
        std::string plane = "{\"dummy\":\"my name is dummy\",\"version\":\"1.-1.99\",\"data\":{\"age\":50,\"address\":\"Seoul Seocho-Gu\",\"phone\":\"02-1234-5678\"},\"salary\":\"unknown\"}";
        std::vector<uint8_t> key(secret.begin(), secret.end()), iv(Scrypt::defaultBlockSize());
        assert(key.size() == Scrypt::defaultKeyLength());
        std::string encrypted = Scrypt::encrypt(plane, key, iv);
        std::string hexfilled; for (uint8_t each : encrypted) hexfilled += fmt::format("{:02X}", each); 
        std::string decrypted = Scrypt::decrypt(encrypted, key, iv);
        fmt::print("encrypted={}\n", hexfilled);
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
