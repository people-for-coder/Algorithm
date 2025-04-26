#include <stdio.h>
#include "AES.h"
#include "Utils.h"

/**
 * @brief 主函数，用于测试AES加密和解密功能
 * 
 * 该函数包含两个测试用例，分别对不同的明文和密钥进行AES加密和解密操作，
 * 并打印出加密前后的数据，方便验证加密和解密的正确性。
 * 
 * @return int 程序正常结束返回0
 */
int main() {

    // 测试用例1
    // 定义一个128位（16字节）的加密密钥
    const uint8_t key[16] = {0x2b, 0x7e, 0x15, 0x16, 
                             0x28, 0xae, 0xd2, 0xa6, 
                             0xab, 0xf7, 0x15, 0x88, 
                             0x09, 0xcf, 0x4f, 0x3c};
    // 定义一个128位（16字节）的明文
    const uint8_t pt[16]={  0x32, 0x43, 0xf6, 0xa8, 
                            0x88, 0x5a, 0x30, 0x8d, 
                            0x31, 0x31, 0x98, 0xa2, 
                            0xe0, 0x37, 0x07, 0x34};
    // 定义一个128位（16字节）的数组，用于存储加密后的密文
    uint8_t ct[16] = {0};
    // 定义一个128位（16字节）的数组，用于存储解密后的明文
    uint8_t plain[16] = {0};//16byte

    // 调用aesEncrypt函数对明文进行加密
    aesEncrypt(key, 16, pt, ct, 16);
    // 调用printHex函数打印原始明文
    printHex(pt, 16, "plain data:");
    // 打印预期的密文
    printf("expect cipher:\n39 25 84 1D 02 DC 09 FB DC 11 85 97 19 6A 0B 32\n");

    // 调用printHex函数打印加密后的密文
    printHex(ct, 16, "after encryption:");

    // 调用aesDecrypt函数对密文进行解密
    aesDecrypt(key, 16, ct, plain, 16);
    // 调用printHex函数打印解密后的明文
    printHex(plain, 16, "after decryption:");

    // 测试用例2
    // 定义另一个128位（16字节）的加密密钥
    const uint8_t key2[]="1234567890123456";
    // 定义一个较长的明文数据
    const uint8_t *data = (uint8_t*)"abcdefghijklmnopqrstuvwxyz123456";
    // 定义一个256位（32字节）的数组，用于存储加密后的密文
    uint8_t ct2[32] = {0};
    // 定义一个256位（32字节）的数组，用于存储解密后的明文
    uint8_t plain2[32] = {0};
    // 调用aesEncrypt函数对明文进行加密
    aesEncrypt(key2, 16, data, ct2, 32);

    // 打印原始明文
    printf("\nplain text:\n%s\n", data);
    // 打印预期的密文
    printf("expect ciphertext:\nfcad715bd73b5cb0488f840f3bad7889\n");
    // 调用printHex函数打印加密后的密文
    printHex(ct2, 32, "after encryption:");

    // 调用aesDecrypt函数对密文进行解密
    aesDecrypt(key2, 16, ct2, plain2, 32);
    // 调用printHex函数打印解密后的明文
    printHex(plain2, 32, "after decryption:");

    // 打印解密后的明文文本
    printf("output plain text\n");
    for (int i = 0; i < 32; ++i) {
        printf("%c ", plain2[i]);
    }

    return 0;
}