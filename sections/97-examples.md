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
