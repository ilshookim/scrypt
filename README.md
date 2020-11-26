# scrypt
scrypt is a program for string cryptographic AES-CRC-Padding using cryptopp

# AES/CBC 암호화/복호화
안드로이드에서 AES/CBC으로 암호화한 전문을 C++모듈에서 복호화를 하고
C++모듈에서 AES/CBC으로 암호화한 전문을 안드로이드에서 복호화가 가능한
자바 소스와 C++ 소스를 여기에서 참고할 수 있습니다.

# 자바에서 AES/CBC 사용법
~~~
public static String secretKey = "비밀키";
AES256Chiper.AES_Encode("암호화 내용");
AES256Chiper.AES_Decode("복호화 내용");
~~~

# C++에서 AES/CBC 사용법
~~~
std::string secret = "비밀키";
std::vector<uint8_t> key(secret.begin(), secret.end()), iv(Scrypt::defaultBlockSize());
std::string encrypted = Scrypt::encrypt("암호화 내용", key, iv);
std::string decrypted = Scrypt::decrypt("복호화 내용", key, iv);
~~~
