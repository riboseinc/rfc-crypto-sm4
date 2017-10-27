# Algorithm

<!-- 7 算法描述 -->

## Encryption {#sm4-encryption}

<!-- 7.1 加密算法 -->
<!-- 本加密算法由 32 次迭代运算和 1 次反序变换 𝑅 组成。 -->
<!-- 设明文输入为𝑋 ,𝑋 ,𝑋 ,𝑋 ∈ 𝑍43 A，密文输出为𝑌,𝑌,𝑌,𝑌 ∈ 𝑍43 A，轮密钥为
𝑟𝑘 ∈𝑍43，𝑖=0,1,⋯,31。加密算法的运算过程如下: 53
(1) 32 次迭代运算: 𝑋5TA = 𝐹 𝑋5, 𝑋5T2, 𝑋5T3, 𝑋5T4, 𝑟𝑘5 ，𝑖 = 0,1, ⋯ ,31; (2)反序变换:𝑌,𝑌,𝑌,𝑌=𝑅𝑋,𝑋,𝑋,𝑋 =𝑋,𝑋,𝑋,𝑋。
        0 2 3 4 43 44 4A 4U 4U 4A 44 43
 -->

The encryption algorithm consists of 32 rounds and 1 reverse transform $$R$$.

Given a 128-bit plaintext input, where each $$X_i$$ is 32-bit wide:

$$
(X_0, X_1, X_2, X_3)
$$

<!--$$
(X_0, X_1, X_2, X_3) element-of (Z_2^32)^4
$$ -->

The output is a 128-bit ciphertext, where each $$Y_i$$ is 32-bit wide:

$$
(Y_0, Y_1, Y_2, Y_3)
$$

<!-- $$
(Y_0, Y_1, Y_2, Y_3) element-of (Z_2^32)^4
$$ -->

Each round key is designated as $$rk_i$$, where each $$rk_i$$ is 32-bit wide
and $$i = 0, 1, 2, ..., 31$$.

<!-- $$
rk_i element-of (Z_2^32), i = 0, 1, 2, ..., 31
$$
-->

a. 32 rounds of calculation

  $$i = 0, 1, ..., 31$$

  $$
  X_{i+4} = F(X_i, X_{i+1}, X_{i+2}, X_{i+3}, rk_i)
  $$

b. reverse transformation

  $$
  (Y_0, Y_1, Y_2, Y_3) = R(X_32, X_33, X_34, X_35)
  $$

  $$
  R(X_32, X_33, X_34, X_35) = (X_35, X_34, X_33, X_32)
  $$

Please refer to (#appendix-a) for sample calculations.


## Decryption {#sm4-decryption}

<!-- 7.2 解密算法 本算法的解密变换与加密变换结构相同，不同的仅是轮密钥的使用顺序。解密时，使用
轮密钥序 𝑟𝑘42, 𝑟𝑘40, ⋯ , 𝑟𝑘0 。 -->

Decryption takes an identical process as encryption, with the only difference
the order of the round key sequence.

During decryption, the round key sequence is:

$$
(rk_31, rk_30, ..., rk_0)
$$

## Key Schedule

<!-- 7.3 密钥扩展算法 -->
<!-- 本算法轮密钥由加密密钥通过密钥扩展算法生成。 -->
<!--加密密钥𝑀𝐾 = 𝑀𝐾 , 𝑀𝐾 , 𝑀𝐾 , 𝑀𝐾   ∈   𝑍43   A，轮密钥生成方法为:
 02343
𝐾0, 𝐾2, 𝐾3, 𝐾4 = 𝑀𝐾0⨁𝐹𝐾0, 𝑀𝐾2⨁𝐹𝐾2, 𝑀𝐾3⨁𝐹𝐾3, 𝑀𝐾4⨁𝐹𝐾4   ，
   𝑟𝑘5 = 𝐾5TA = 𝐾5⨁𝑇′ 𝐾5T2⨁𝐾5T3⨁𝐾5T4⨁𝐶𝐾5 ，𝑖 = 0,1,⋯,31。 其中:
(1) 𝑇′ 是将 5.2 中合成置换 𝑇 的线性变换 𝐿 替换为 𝐿′:
𝐿′ 𝐵 =𝐵⨁ 𝐵⋘13 ⨁ 𝐵⋘23;
(2) 系统参数 𝐹𝐾 的取值为:
𝐹𝐾0 = A3B1BAC6 ，𝐹𝐾2 = 56AA3350 ，𝐹𝐾3 = 677D9197 ，𝐹𝐾4 = B27022DC ; (3) 固定参数𝐶𝐾的取值方法为:
设𝑐𝑘5,_为𝐶𝐾5的第𝑗字节 𝑖 = 0,1, ⋯ ,31; 𝑗 = 0,1,2,3 ，即𝐶𝐾5 =   𝑐𝑘5,0, 𝑐𝑘5,2, 𝑐𝑘5,3, 𝑐𝑘5,4   ∈
𝑍K A，则𝑐𝑘 = 4𝑖+𝑗 ×7 𝑚𝑜𝑑256。 -->


Round keys used during encryption are derived from the encryption key.

Specifically, given the encryption key $$MK$$, where each $$MK_i$$ is 32-bit
wide:

$$
MK = (MK_0, MK_1, MK_2, MK_3)
$$

<!-- $$
MK = (MK_0, MK_1, MK_2, MK_3) element-of (Z_2^32)^4
$$ -->

Each round key $$rk_i$$ is created as follows, where $$i = 0, 1, ..., 31$$.

$$
(K_0, K_1, K_2, K_3)
        = (MK_0 xor FK_0, MK_1 xor FK_1, MK_2 xor FK_2, MK_3 xor FK_3)
$$

$$
rk_i = K_{i + 4}
$$

$$
K_{i + 4} = K_i xor T' (K_{i + 1} xor K_{i + 2} xor K_{i + 3} xor CK_i)
$$


Since the decryption key is identical to the encryption key, the round keys
used in the decryption process are derived from the decryption key through
the identical process to that of during encryption.


### Family Key $$FK$$

Family key $$FK$$ given in hexadecimal notation, is:

$$
FK_0 = A3B1BAC6
FK_1 = 56AA3350
FK_2 = 677D9197
FK_3 = B27022DC
$$

### Constant Key $$CK$$

The method to retrieve values from the constant key $$CK$$ is as follows.

Let $$ck_{i, j}$$ be the $$j$$-th byte ($$i = 0, 1, ..., 31; j = 0, 1, 2, 3$$) of $$CK_i$$.

Therefore, each $$ck_{i, j}$$ is a 8-bit string, and each $$CK_i$$ a 32-bit word.

$$
CK_i = (ck_{i, 0}, ck_{i, 1}, ck_{i, 2}, ck_{i, 3})
$$

<!-- $$
CK_i element-of (Z_2^8)^4
$$ -->

$$
ck_{i, j} = (4i + j) x 7 (mod 256)
$$


<!--固定参数𝐶𝐾5 𝑖=0,1,⋯,31具体值为:
00070E15, 1C232A31, 383F464D, 545B6269,
70777E85, 8C939AA1, A8AFB6BD, C4CBD2D9,
E0E7EEF5, FC030A11, 181F262D, 343B4249,
50575E65, 6C737A81, 888F969D, A4ABB2B9,
C0C7CED5, DCE3EAF1, F8FF060D, 141B2229,
30373E45, 4C535A61, 686F767D, 848B9299,
A0A7AEB5, BCC3CAD1, D8DFE6ED, F4FB0209,
10171E25, 2C333A41, 484F565D, 646B7279.
 -->

The values of the constant key $$CK_i$$, where $$(i = 0, 1, ..., 31)$$, in
hexadecimal, are:

```
CK_0  = 00070E15   CK_16 = C0C7CED5
CK_1  = 1C232A31   CK_17 = DCE3EAF1
CK_2  = 383F464D   CK_18 = F8FF060D
CK_3  = 545B6269   CK_19 = 141B2229
CK_4  = 70777E85   CK_20 = 30373E45
CK_5  = 8C939AA1   CK_21 = 4C535A61
CK_6  = A8AFB6BD   CK_22 = 686F767D
CK_7  = C4CBD2D9   CK_23 = 848B9299
CK_8  = E0E7EEF5   CK_24 = A0A7AEB5
CK_9  = FC030A11   CK_25 = BCC3CAD1
CK_10 = 181F262D   CK_26 = D8DFE6ED
CK_11 = 343B4249   CK_27 = F4FB0209
CK_12 = 50575E65   CK_28 = 10171E25
CK_13 = 6C737A81   CK_29 = 2C333A41
CK_14 = 888F969D   CK_30 = 484F565D
CK_15 = A4ABB2B9   CK_31 = 646B7279
```

