# Appendix A: Example Calculations {#appendix-a}

<!-- 附录A 运算示例 -->

## Example 1.

<!-- 本部分为 SM4 分组密码算法对一组明文进行加密的运算示例。
输入明文: 01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10
输入密钥: 01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10
轮密钥与每轮输出状态: -->

This example demonstrates encryption of a plaintext.

Plaintext:
    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

Encryption key:
    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

Status of the round key (rk) and round output (X) per round:

    rk[ 0] = F12186F9   X[ 4] = 27FAD345
    rk[ 1] = 41662B61   X[ 5] = A18B4CB2
    rk[ 2] = 5A6AB19A   X[ 6] = 11C1E22A
    rk[ 3] = 7BA92077   X[ 7] = CC13E2EE
    rk[ 4] = 367360F4   X[ 8] = F87C5BD5
    rk[ 5] = 776A0C61   X[ 9] = 33220757
    rk[ 6] = B6BB89B3   X[10] = 77F4C297
    rk[ 7] = 24763151   X[11] = 7A96F2EB
    rk[ 8] = A520307C   X[12] = 27DAC07F
    rk[ 9] = B7584DBD   X[13] = 42DD0F19
    rk[10] = C30753ED   X[14] = B8A5DA02
    rk[11] = 7EE55B57   X[15] = 907127FA
    rk[12] = 6988608C   X[16] = 8B952B83
    rk[13] = 30D895B7   X[17] = D42B7C59
    rk[14] = 44BA14AF   X[18] = 2FFC5831
    rk[15] = 104495A1   X[19] = F69E6888
    rk[16] = D120B428   X[20] = AF2432C4
    rk[17] = 73B55FA3   X[21] = ED1EC85E
    rk[18] = CC874966   X[22] = 55A3BA22
    rk[19] = 92244439   X[23] = 124B18AA
    rk[20] = E89E641F   X[24] = 6AE7725F
    rk[21] = 98CA015A   X[25] = F4CBA1F9
    rk[22] = C7159060   X[26] = 1DCDFA10
    rk[23] = 99E1FD2E   X[27] = 2FF60603
    rk[24] = B79BD80C   X[28] = EFF24FDC
    rk[25] = 1D2115B0   X[29] = 6FE46B75
    rk[26] = 0E228AEB   X[30] = 893450AD
    rk[27] = F1780C81   X[31] = 7B938F4C
    rk[28] = 428D3654   X[32] = 536E4246
    rk[29] = 62293496   X[33] = 86B3E94F
    rk[30] = 01CF72E5   X[34] = D206965E
    rk[31] = 9124A012   X[35] = 681EDF34

<!-- 输出密文: 68 1E DF 34 D2 06 96 5E 86 B3 E9 4F 53 6E 42 46 -->

Ciphertext:
    68 1E DF 34 D2 06 96 5E 86 B3 E9 4F 53 6E 42 46


## Example 2

<!-- A.2 示例 2 -->

<!-- 本部分为 SM4 分组密码算法使用固定的加密密钥，对一组明文反复加密1,000,000次的运算示例。 -->

This example demonstrates encryption of a plaintext 1,000,000 times repeatedly using a fixed encryption key.

<!-- 输入明文: 01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10 -->

Plaintext:
    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

<!-- 输入密钥: 01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10 -->

Encryption Key:
    01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

<!-- 输出密文: 59 52 98 C7 C6 FD 27 1F 04 02 F8 04 C3 3D 3F 66 -->

Ciphertext:
    59 52 98 C7 C6 FD 27 1F 04 02 F8 04 C3 3D 3F 66
