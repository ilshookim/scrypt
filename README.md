# scrypt

scrypt is a program for string cryptographic AES-CBC-Padding using cryptopp between JAVA and C++.

[To build](https://github.com/ilshookim/scrypt/blob/master/Build.md).

# AES/CBC Encrypt/Decrypt

Here, you can refer to the Java source and C++ source that can decrypt the text encrypted with AES/CBC in Android in the C++ module and the text encrypted with AES/CBC in the C++ module in Android.

# AES/CBC in JAVA (Android)
~~~
public static String secretKey = "sixteen-password";
AES256Chiper.AES_Encode("plainText");
AES256Chiper.AES_Decode("chiperText");
~~~

# AES/CBC in C++
~~~
std::string plain = "plainText";
std::string key = "sixteen-password";
std::string chiper = Scrypt::encrypt(plain, key);
std::string recover = Scrypt::decrypt(chiper, key);
assert(recover == plain);
~~~

# AES/CBC in on-line

https://www.devglan.com/online-tools/aes-encryption-decryption

- The result of encryption in Java and decryption in C++ is
- The result of encryption and decryption on the online AES/CBC page should be the same.

---

# Korean

# AES/CBC 암호화/복호화
안드로이드에서 AES/CBC으로 암호화한 전문을 C++모듈에서 복호화를 하고
C++모듈에서 AES/CBC으로 암호화한 전문을 안드로이드에서 복호화가 가능한
자바 소스와 C++ 소스를 여기에서 참고할 수 있습니다.

# 자바에서 AES/CBC 사용법
~~~
public static String secretKey = "필수16자리비밀키";
AES256Chiper.AES_Encode("암호화 내용");
AES256Chiper.AES_Decode("복호화 내용");
~~~

# C++에서 AES/CBC 사용법
~~~
std::string secret = "필수16자리비밀키";
std::vector<uint8_t> key(secret.begin(), secret.end()), iv(Scrypt::defaultBlockSize());
std::string encrypted = Scrypt::encrypt("암호화 내용", key, iv);
std::string decrypted = Scrypt::decrypt("복호화 내용", key, iv);
~~~

# 온라인에서 AES/CBC 사용법
https://www.devglan.com/online-tools/aes-encryption-decryption
- 자바에서 암호화를 하고 C++에서 복호화를 한 결과는
- 온라인 AES/CBC 페이지에서 암호화하고 복호화를 한 결과가 동일해야 할 것입니다.
