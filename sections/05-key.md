# Key And Key Parameters

<!-- 5 密钥及密钥参量 -->
<!-- 加密密钥长度为 128 比特，表示为𝑀𝐾 =   𝑀𝐾0, 𝑀𝐾2, 𝑀𝐾3, 𝑀𝐾4 ，其中𝑀𝐾5   𝑖 = 0,1,2,3 为字。 -->
<!--轮密钥表示为 𝑟𝑘0, 𝑟𝑘2, ⋯ , 𝑟𝑘42 ，其中𝑟𝑘5 𝑖 = 0, ⋯ ,31 为 32 比特字。轮密钥由加密密钥 生成。
 𝐹𝐾 = 𝐹𝐾0, 𝐹𝐾2, 𝐹𝐾3, 𝐹𝐾4 为系统参数，𝐶𝐾 = 𝐶𝐾0, 𝐶𝐾2, ⋯ , 𝐶𝐾42 为固定参数，用于密钥 扩展算法，其中𝐹𝐾5 𝑖 = 0,⋯,3 、𝐶𝐾5 𝑖 = 0,⋯,31 为字。 -->

Encryption key is 128 bits long, and represented below, where each
$$MK_i, (i = 0, 1, 2, 3)$$ is 32 bits long.

$$
MK = (MK_0, MK_1, MK_2, MK_3)
$$

The round key schedule is derived from the encryption key, represented as below
where each $$rk_i (i = 0, ..., 31)$$ is 32 bits long:

$$
(rk_0, rk_1, ... , rk_31)
$$


The family key used for key expansion is represented as $$FK$$, where
each $$FK_i (i = 0, ..., 3)$$ is 32 bits long:

$$
FK = (FK_0, FK_1, FK_2, FK_3)
$$


The constant key used for key expansion is represented as $$CK$$, where
each $$CK_i (i = 0, ..., 31)$$ is 32 bits long:

$$
CK = (CK_0, CK_1, ... , CK_31)
$$


