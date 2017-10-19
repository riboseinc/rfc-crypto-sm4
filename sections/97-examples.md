# Appendix A: Example Calculations {#appendix-a}

<!-- 附录A 运算示例 -->
## Examples From GB/T 32907-2016

###  Example 1

<!-- 本部分为 SM4 分组密码算法对一组明文进行加密的运算示例。
输入明文: 01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10
输入密钥: 01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10
轮密钥与每轮输出状态: -->

This is example 1 provided by [@GBT.32907-2016] to demonstrate encryption of a
plaintext.

Plaintext:
    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

Encryption key:
    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

Status of the round key ($$rk_i$$) and round output ($$X_i$$) per round:

    rk_0  = F12186F9   X_4  = 27FAD345
    rk_1  = 41662B61   X_5  = A18B4CB2
    rk_2  = 5A6AB19A   X_6  = 11C1E22A
    rk_3  = 7BA92077   X_7  = CC13E2EE
    rk_4  = 367360F4   X_8  = F87C5BD5
    rk_5  = 776A0C61   X_9  = 33220757
    rk_6  = B6BB89B3   X_10 = 77F4C297
    rk_7  = 24763151   X_11 = 7A96F2EB
    rk_8  = A520307C   X_12 = 27DAC07F
    rk_9  = B7584DBD   X_13 = 42DD0F19
    rk_10 = C30753ED   X_14 = B8A5DA02
    rk_11 = 7EE55B57   X_15 = 907127FA
    rk_12 = 6988608C   X_16 = 8B952B83
    rk_13 = 30D895B7   X_17 = D42B7C59
    rk_14 = 44BA14AF   X_18 = 2FFC5831
    rk_15 = 104495A1   X_19 = F69E6888
    rk_16 = D120B428   X_20 = AF2432C4
    rk_17 = 73B55FA3   X_21 = ED1EC85E
    rk_18 = CC874966   X_22 = 55A3BA22
    rk_19 = 92244439   X_23 = 124B18AA
    rk_20 = E89E641F   X_24 = 6AE7725F
    rk_21 = 98CA015A   X_25 = F4CBA1F9
    rk_22 = C7159060   X_26 = 1DCDFA10
    rk_23 = 99E1FD2E   X_27 = 2FF60603
    rk_24 = B79BD80C   X_28 = EFF24FDC
    rk_25 = 1D2115B0   X_29 = 6FE46B75
    rk_26 = 0E228AEB   X_30 = 893450AD
    rk_27 = F1780C81   X_31 = 7B938F4C
    rk_28 = 428D3654   X_32 = 536E4246
    rk_29 = 62293496   X_33 = 86B3E94F
    rk_30 = 01CF72E5   X_34 = D206965E
    rk_31 = 9124A012   X_35 = 681EDF34

<!-- 输出密文: 68 1E DF 34 D2 06 96 5E 86 B3 E9 4F 53 6E 42 46 -->

Ciphertext:
    68 1E DF 34 D2 06 96 5E 86 B3 E9 4F 53 6E 42 46


### Example 2

<!-- A.2 示例 2 -->

<!-- 本部分为 SM4 分组密码算法使用固定的加密密钥，对一组明文反复加密1,000,000次的运算示例。 -->
This example is provided by [@GBT.32907-2016] to demonstrate encryption of a
plaintext 1,000,000 times repeatedly, using a fixed encryption key.

<!-- 输入明文: 01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10 -->

Plaintext:

    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

<!-- 输入密钥: 01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10 -->

Encryption Key:

    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

<!-- 输出密文: 59 52 98 C7 C6 FD 27 1F 04 02 F8 04 C3 3D 3F 66 -->

Ciphertext:

    59 52 98 C7 C6 FD 27 1F 04 02 F8 04 C3 3D 3F 66


## Examples For Various Modes Of Operations

The following examples can be verified using open-source cryptographic
libraries including:

* the Botan cryptographic library [@BOTAN] with SM4 support, and
* the OpenSSL Cryptography and SSL/TLS Toolkit [@OPENSSL] with SM4 support


### SM4-ECB Example

Plaintext:

    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

Encryption Key:

    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

Ciphertext:

    68 1E DF 34 D2 06 96 5E 86 B3 E9 4F 53 6E 42 46


### SM4-CBC Example

Plaintext:

    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10
    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

Encryption Key:

    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

IV:

    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

Ciphertext:

    26 77 F4 6B 09 C1 22 CC 97 55 33 10 5B D4 A2 2A
    F6 12 5F 72 75 CE 55 2C 3A 2B BC F5 33 DE 8A 3B


### SM4-OFB Example

Plaintext:

    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10
    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

Encryption Key:

    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

IV:

    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

Ciphertext:

    69 3D 9A 53 5B AD 5B B1 78 6F 53 D7 25 3A 70 56
    F2 07 5D 28 B5 23 5F 58 D5 00 27 E4 17 7D 2B CE


### SM4-CFB Example

Plaintext:

    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10
    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

Encryption Key:

    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

IV:

    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

Ciphertext:

    69 3D 9A 53 5B AD 5B B1 78 6F 53 D7 25 3A 70 56
    9E D2 58 A8 5A 04 67 CC 92 AA B3 93 DD 97 89 95


### SM4-CTR Example

Plaintext:

    AA AA AA AA AA AA AA AA BB BB BB BB BB BB BB BB
    CC CC CC CC CC CC CC CC DD DD DD DD DD DD DD DD
    EE EE EE EE EE EE EE EE FF FF FF FF FF FF FF FF
    EE EE EE EE EE EE EE EE AA AA AA AA AA AA AA AA

Encryption Key:

    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

IV:

    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

Ciphertext:

    C2 B4 75 9E 78 AC 3C F4 3D 08 52 F4 E8 D5 F9 FD
    72 56 E8 A5 FC B6 5A 35 0E E0 06 30 91 2E 44 49
    2A 0B 17 E1 B8 5B 06 0D 0F BA 61 2D 8A 95 83 16
    38 B3 61 FD 5F FA CD 94 2F 08 14 85 A8 3C A3 5D
