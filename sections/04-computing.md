# Compute Structure

<!-- 3 算法结构
本算法是一个分组算法。该算法的分组长度为 128 比特，密钥长度为 128 比特。加密算 法与密钥扩展算法都采用 32 轮非线性迭代结构。解密算法与加密算法的结构相同，只是轮密 钥的使用顺序相反，解密轮密钥是加密轮密钥的逆序。 -->

The SM4 algorithm is a blockcipher, with block size of 128 bits and a key
length of 128 bits.

Both encryption and key expansion use 32 rounds of a nonlinear key schedule
per block. Each round processes one of the four 32-bit words that constitute
the block.

The structure of encryption and decryption are identical, except that the round key
schedule has its order reversed during decryption.

Using a 8-bit S-box, it only uses exclusive-or, cyclic bit shifts and S-box
lookups to execute.
