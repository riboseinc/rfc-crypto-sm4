# Round Function $$F$$

<!-- 6 轮函数 𝐅 -->

## Round Parameter Structure

<!-- 6.1 轮函数结构 -->

<!-- 设输入为 𝑋 ,𝑋 ,𝑋 ,𝑋 ∈ 𝑍43 A，轮密钥为𝑟𝑘 ∈ 𝑍43，则轮函数𝐹为: 02343 3
𝐹 𝑋0, 𝑋2, 𝑋3, 𝑋4, 𝑟𝑘 = 𝑋0⨁𝑇 𝑋2⨁𝑋3⨁𝑋4⨁𝑟𝑘 . -->


<!-- This algorithm uses a nonlinear substitution structure, encrypting 32 bits at a time. This
is called a one-round exchange. To illustrate, consider a one-round-substitution: -->

Given the 128-bit input below, where each $$X_i$ is a 32-bit word:

$$
(X_0, X_1, X_2, X_3)
$$

<!-- $$
(X_0, X_1, X_2, X_3) element-of (Z_2^32)^4
$$ -->

And the round key $$rk$$ is a 32-bit word:

<!-- $$
rk element-of Z_2^32
$$
-->

The round function $$F$$ is defined as:

$$
F(X_0, X_1, X_2, X_3, rk) = X_0 xor T(X_1 xor X_2 xor X_3 xor rk)
$$


## Mixer Substitution $$T$$

<!-- 6.2 合成置换 𝐓 -->
<!-- 2.1 Mixer-substitution T -->

<!-- Transformation T
𝑇: 𝑍43 → 𝑍43是一个可逆变换，由非线性变换𝜏和线性变换𝐿复合而成，即𝑇 ⋅ = 𝐿 𝜏 ⋅ 。 33 -->

$$T$$ is a reversible substitution function that outputs 32 bits from an input of 32 bits.

<!-- $$
T: Z_2^32 -> Z_2^32
$$
 -->

It consists of a non-linear transform $$tau$$ and linear transform $$L$$.

$$
T(.) = L(tau(.))
$$

### Non-linear Transformation tau

<!-- (1) 非线性变换 𝜏 -->
<!-- 𝜏由4个并行的S盒构成。
设输入为𝐴= 𝑎,𝑎,𝑎,𝑎 ∈ 𝑍K A，输出为𝐵= 𝑏,𝑏,𝑏,𝑏 ∈ 𝑍K A，则 0234 3 0234 3
𝑏0,𝑏2,𝑏3,𝑏4 = 𝜏 𝐴 = 𝑆𝑏𝑜𝑥 𝑎0 ,𝑆𝑏𝑜𝑥 𝑎2 ,𝑆𝑏𝑜𝑥 𝑎3 ,𝑆𝑏𝑜𝑥 𝑎4
其中，Sbox 数据如下: -->

$$tau$$ is composed of four parallel S-boxes.

Given a 32-bit input of $$A$$, where each $$a_i$$ is a 8-bit string:

$$
A = (a_0, a_1, a_2, a_3)
$$

<!-- $$
A = (a_0, a_1, a_2, a_3) element-of (Z_2^8)^4
$$
 -->

The output is a 32-bit $$B$$, where each $$b_i$$ is a 8-bit string:

$$
B = (b_0, b_1, b_2, b_3)
$$

<!-- $$
B = (b_0, b_1, b_2, b_3) element-of (Z_2^8)^4
$$ -->

$$B$$ is calculated as follows:

$$
(b_0, b_1, b_2, b_3) = tau(A)
$$

$$
tau(A) = (Sbox(a_0), Sbox(a_1), Sbox(a_2), Sbox(a_3))
$$

The lookup table of Sbox is shown below:

<!-- a | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | A  | B  | C  | D  | E  | F
xxx|xxx-|xxx-|xxx-|xxx-|xxx-|xxx-|xxx-|xxx-|xxx-|xxx-|xxx-|xxx-|xxx-|xxx-|xxx-|xxx-
 0 | D6 | 90 | E9 | FE | CC | E1 | 3D | B7 | 16 | B6 | 14 | C2 | 28 | FB | 2C | 05
 1 | 2B | 67 | 9A | 76 | 2A | BE | 04 | C3 | AA | 44 | 13 | 26 | 49 | 86 | 06 | 99
 2 | 9C | 42 | 50 | F4 | 91 | EF | 98 | 7A | 33 | 54 | 0B | 43 | ED | CF | AC | 62
 3 | E4 | B3 | 1C | A9 | C9 | 08 | E8 | 95 | 80 | DF | 94 | FA | 75 | 8F | 3F | A6
 4 | 47 | 07 | A7 | FC | F3 | 73 | 17 | BA | 83 | 59 | 3C | 19 | E6 | 85 | 4F | A8
 5 | 68 | 6B | 81 | B2 | 71 | 64 | DA | 8B | F8 | EB | 0F | 4B | 70 | 56 | 9D | 35
 6 | 1E | 24 | 0E | 5E | 63 | 58 | D1 | A2 | 25 | 22 | 7C | 3B | 01 | 21 | 78 | 87
 7 | D4 | 00 | 46 | 57 | 9F | D3 | 27 | 52 | 4C | 36 | 02 | E7 | A0 | C4 | C8 | 9E
 8 | EA | BF | 8A | D2 | 40 | C7 | 38 | B5 | A3 | F7 | F2 | CE | F9 | 61 | 15 | A1
 9 | E0 | AE | 5D | A4 | 9B | 34 | 1A | 55 | AD | 93 | 32 | 30 | F5 | 8C | B1 | E3
 A | 1D | F6 | E2 | 2E | 82 | 66 | CA | 60 | C0 | 29 | 23 | AB | 0D | 53 | 4E | 6F
 B | D5 | DB | 37 | 45 | DE | FD | 8E | 2F | 03 | FF | 6A | 72 | 6D | 6C | 5B | 51
 C | 8D | 1B | AF | 92 | BB | DD | BC | 7F | 11 | D9 | 5C | 41 | 1F | 10 | 5A | D8
 D | 0A | C1 | 31 | 88 | A5 | CD | 7B | BD | 2D | 74 | D0 | 12 | B8 | E5 | B4 | B0
 E | 89 | 69 | 97 | 4A | 0C | 96 | 77 | 7E | 65 | B9 | F1 | 09 | C5 | 6E | C6 | 84
 F | 18 | F0 | 7D | EC | 3A | DC | 4D | 20 | 79 | EE | 5F | 3E | D7 | CB | 39 | 48 -->


       |  0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F
    ---|----------------------------------------------------------------
     0 | D6  90  E9  FE  CC  E1  3D  B7  16  B6  14  C2  28  FB  2C  05
     1 | 2B  67  9A  76  2A  BE  04  C3  AA  44  13  26  49  86  06  99
     2 | 9C  42  50  F4  91  EF  98  7A  33  54  0B  43  ED  CF  AC  62
     3 | E4  B3  1C  A9  C9  08  E8  95  80  DF  94  FA  75  8F  3F  A6
     4 | 47  07  A7  FC  F3  73  17  BA  83  59  3C  19  E6  85  4F  A8
     5 | 68  6B  81  B2  71  64  DA  8B  F8  EB  0F  4B  70  56  9D  35
     6 | 1E  24  0E  5E  63  58  D1  A2  25  22  7C  3B  01  21  78  87
     7 | D4  00  46  57  9F  D3  27  52  4C  36  02  E7  A0  C4  C8  9E
     8 | EA  BF  8A  D2  40  C7  38  B5  A3  F7  F2  CE  F9  61  15  A1
     9 | E0  AE  5D  A4  9B  34  1A  55  AD  93  32  30  F5  8C  B1  E3
     A | 1D  F6  E2  2E  82  66  CA  60  C0  29  23  AB  0D  53  4E  6F
     B | D5  DB  37  45  DE  FD  8E  2F  03  FF  6A  72  6D  6C  5B  51
     C | 8D  1B  AF  92  BB  DD  BC  7F  11  D9  5C  41  1F  10  5A  D8
     D | 0A  C1  31  88  A5  CD  7B  BD  2D  74  D0  12  B8  E5  B4  B0
     E | 89  69  97  4A  0C  96  77  7E  65  B9  F1  09  C5  6E  C6  84
     F | 18  F0  7D  EC  3A  DC  4D  20  79  EE  5F  3E  D7  CB  39  48

For example, input "EF" will produce an output read from the S-box table
row E and column F, giving the result $$Sbox(EF) = 84$$.


## Linear Substitution $$L$$


<!-- (2) 线性变换 𝐿
非线性变换 𝜏 的输出是线性变换 𝐿 的输入。设输入为𝐵 ∈ 𝑍43，输出为𝐶 ∈ 𝑍43，则
33 𝐶=𝐿𝐵 =𝐵⨁𝐵⋘2⨁𝐵⋘10⨁𝐵⋘18⨁𝐵⋘24.
-->

The output of non-linear transformation function $$tau$$ is used as input
to linear transformation function $$L$$.

Given $$B$$, a 32-bit input:

<!-- $$
B element-of Z_2^32
$$
-->

$$L$$ produces a 32-bit output $$C$$:

<!-- $$
C element-of Z_2^32
$$ -->

$$
C = L(B)
$$

$$
L(B) = B xor (B <<< 2) xor (B <<< 10) xor (B <<< 18) xor (B <<< 24)
$$