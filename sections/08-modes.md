#  Modes of Operation {#sm4-modes}

This document defines multiple modes of operation for the SM4 blockcipher
algorithm.

The CBC (Cipher Block Chaining), ECB (Electronic CodeBook), CFB (Cipher
FeedBack), OFB (Output FeedBack) and CTR (Counter) modes are defined in
[@NIST.SP.800-38A] and utilized with the SM4 algorithm in the following
sections.

## Variables And Primitives

Hereinafter we define:

SM4Encrypt(P, K)
: The SM4 algorithm that encrypts plaintext P with key K, described in (#sm4-encryption)

SM4Decrypt(C, K)
: The SM4 algorithm that decrypts ciphertext C with key K, described in (#sm4-decryption)

b
: block size in bits, defined as 128 for SM4

P_j
: block j of ciphertext bitstring P

C_j
: block j of ciphertext bitstring C

NBlocks(B, b)
: Number of blocks of size $$b$$-bits in bitstring B

IV
: Initialization vector

LSB(b, S)
: Least significant $$b$$ bits of the bitstring $$S$$

MSB(b, S)
: Most significant $$b$$ bits of the bitstring $$S$$


## Initialization Vectors

The CBC, CFB and OFB modes require an additional input to the encryption process,
called the initialization vector (IV). The identical IV is used in the input
of encryption as well as the decryption of the corresponding ciphertext.

Generation of IV values **MUST** take into account of the considerations
in (#security-considerations) recommended by [@BC-EVAL].


## SM4-ECB

In SM4-ECB, the same key is utilized to create a
fixed assignment for a plaintext block with a ciphertext block, meaning
that a given plaintext block always gets encrypted to the same ciphertext
block. As described in [@NIST.SP.800-38A], this mode should be avoided if
this property is undesirable.

This mode requires input plaintext to be a multiple of the block size,
which in this case of SM4 it is 128-bits. It also allows multiple blocks
to be computed in parallel.


### SM4-ECB Encryption

Inputs:

- P, plaintext, length **MUST** be multiple of $$b$$
- K, SM4 128-bit encryption key

Output:

- C, ciphertext, length is a multiple of $$b$$

C is defined as follows.

```
n = NBlocks(P, b)

for i = 1 to n
  C_i = SM4Encrypt(P_i, K)
end for

C = C_1 || ... || C_n
```

### SM4-ECB Decryption

Inputs:

- C, ciphertext, length **MUST** be multiple of $$b$$
- K, SM4 128-bit encryption key

Output:

- P, plaintext, length is a multiple of $$b$$

P is defined as follows.

```
n = NBlocks(C, b)

for i = 1 to n
  P_i = SM4Decrypt(C_i, K)
end for

P = P_1 || ... || P_n
```


## SM4-CBC


SM4-CBC is similar to SM4-ECB that the input plaintext **MUST** be a multiple
of the block size, which is 128-bits in SM4. SM4-CBC requires
an additional input, the IV, that is unpredictable for a particular
execution of the encryption process.

Since CBC encryption relies on a forward cipher operation that depend on results
of the previous operation, it cannot be parallelized. However, for decryption,
since ciphertext blocks are already available, CBC parallel decryption is
possible.


### SM4-CBC Encryption

Inputs:

- P, plaintext, length **MUST** be multiple of $$b$$
- K, SM4 128-bit encryption key
- IV, 128-bit, unpredictable, initialization vector

Output:

- C, ciphertext, length is a multiple of $$b$$

C is defined as follows.

```
n = NBlocks(P, b)

C_1 = SM4Encrypt(P_1 xor IV, K)

for i = 2 to n
  C_i = SM4Encrypt(P_i xor C_{i - 1}, K)
end for

C = C_1 || ... || C_n
```

### SM4-CBC Decryption

Inputs:

- C, ciphertext, length **MUST** be a multiple of $$b$$
- K, SM4 128-bit encryption key
- IV, 128-bit, unpredictable, initialization vector

Output:

- P, plaintext, length is multiple of $$b$$

P is defined as follows.

```
n = NBlocks(C, b)

P_1 = SM4Decrypt(C_1, K) xor IV

for i = 2 to n
  P_i = SM4Decrypt(C_i, K) xor C_{i - 1}
end for

P = P_1 || ... || P_n
```



## SM4-CFB

SM4-CFB relies on feedback provided by successive ciphertext segments to
generate output blocks. The plaintext given must be a multiple of the block
size.

Similar to SM4-CBC, SM4-CFB requires an IV that is unpredictable for a particular
execution of the encryption process.

SM4-CFB further allows setting a positive integer parameter $$s$$, that is less than or
equal to the block size, to specify the size of each data segment. The same
segment size must be used in encryption and decryption.

In SM4-CFB, since the input block to each forward cipher function depends
on the output of the previous block (except the first that depends on the IV),
encryption is not parallelizable. Decryption, however, can be parallelized.

### SM4-CFB Variants

<!-- SMS4-CFB，根据输出比特序列的长度，包含SMS4-CFB1、SMS4-CFB8和SMS4-CFB128三个实现。 -->

SM4-CFB takes an integer $$s$$ to determine segment size in its encryption and
decryption routines. We define the following variants of SM4-CFB for
various $$s$$:

- SM4-CFB-1, the 1-bit SM4-CFB mode, where $$s$$ is set to 1.
- SM4-CFB-8, the 8-bit SM4-CFB mode, where $$s$$ is set to 8.
- SM4-CFB-64, the 64-bit SM4-CFB mode, where $$s$$ is set to 64.
- SM4-CFB-128, the 128-bit SM4-CFB mode, where $$s$$ is set to 128.


### SM4-CFB Encryption

Inputs:

- P#, plaintext, length **MUST** be multiple of $$s$$
- K, SM4 128-bit encryption key
- IV, 128-bit, unpredictable, initialization vector
- s, an integer 1 <= $$s$$ <= $$b$$ that defines segment size

Output:

- C#, ciphertext, length is a multiple of $$s$$

C# is defined as follows.

```
n = NBlocks(P#, s)

I_1 = IV
for i = 2 to n
  I_i = LSB(b - s, I_{i - 1}) || C#_{j - 1}
end for

for i = 1 to n
  O_j = SM4Encrypt(I_i, K)
end for

for i = 1 to n
  C#_i = P#_1 xor MSB(s, O_j)
end for

C# = C#_1 || ... || C#_n
```

### SM4-CFB Decryption

Inputs:

- C#, ciphertext, length **MUST** be a multiple of $$s$$
- K, SM4 128-bit encryption key
- IV, 128-bit, unpredictable, initialization vector
- s, an integer 1 <= s <= $$b$$ that defines segment size

Output:

- P#, plaintext, length is multiple of $$s$$

P is defined as follows.

```
n = NBlocks(P#, s)

I_1 = IV
for i = 2 to n
  I_i = LSB(b - s, I_{i - 1}) || C#_{j - 1}
end for

for i = 1 to n
  O_j = SM4Encrypt(I_i, K)
end for

for i = 1 to n
  P#_i = C#_1 xor MSB(s, O_j)
end for

P# = P#_1 || ... || P#_n
```



## SM4-OFB

SM4-OFB is the application of SM4 through the Output Feedback mode.
This mode requires that the IV is a nonce, meaning that the IV **MUST**
be unique for each execution for an input key. OFB does not require the
input plaintext to be a multiple of the block size.

In OFB, the routines for encryption and decryption are identical. As
each forward cipher function (except the first) depends on previous
results, both routines cannot be parallelized. However given a known IV, output
blocks could be generated prior to the input of plaintext (encryption)
or ciphertext (decryption).


### SM4-OFB Encryption

Inputs:

- P, plaintext, composed of (n - 1) blocks of size b, with the last block P_n of size 1 <= u <= b
- K, SM4 128-bit encryption key
- IV, a nonce (a unique value for each execution per given key)

Output:

- C, ciphertext, composed of (n - 1) blocks of size b, with the last block C_n of size 1 <= u <= b

C is defined as follows.

```
n = NBlocks(P, b)

I_1 = IV
for i = 1 to (n - 1)
  O_i = SM4Encrypt(I_i)
  I_{i + 1} = O_i
end for

for i = 1 to (n - 1)
  C_i = P_i xor O_i
end for

C_n = P_n xor MSB(u, O_n)

C = C_1 || ... || C_n
```

### SM4-OFB Decryption

Inputs:

- C, ciphertext, composed of (n - 1) blocks of size b, with the last block C_n of size 1 <= u <= b
- K, SM4 128-bit encryption key
- IV, the nonce used during encryption

Output:

- P, plaintext, composed of (n - 1) blocks of size b, with the last block P_n of size 1 <= u <= b

C is defined as follows.

```
n = NBlocks(C, b)

I_1 = IV
for i = 1 to (n - 1)
  O_i = SM4Encrypt(I_i)
  I_{i + 1} = O_i
end for

for i = 1 to (n - 1)
  P_i = C_i xor O_i
end for

P_n = C_n xor MSB(u, O_n)

P = P_1 || ... || P_n
```


## SM4-CTR

<!-- SMS4-CTR，由于SMS4软实现性能较低，因此在后续的优化中会首先提供经过Intel AVX2指令集优化的CTR实现。 -->

SM4-CTR is an implementation of a stream cipher through a block cipher
primitive. It generates a "keystream" of keys that are used to
encrypt successive blocks, with the keystream created from the input key,
a nonce (the IV) and an incremental counter. The counter could be any
sequence that does not repeat within the block size.

Both SM4-CTR encryption and decryption routines could be parallelized, and
random access is also possible.

### SM4-CTR Encryption


Inputs:

- P, plaintext, composed of (n - 1) blocks of size b, with the last block P_n of size 1 <= u <= b
- K, SM4 128-bit encryption key
- IV, a nonce (a unique value for each execution per given key)
- T, a sequence of counters from T_1 to T_n

Output:

- C, ciphertext, composed of (n - 1) blocks of size b, with the last block C_n of size 1 <= u <= b

C is defined as follows.

```
n = NBlocks(P, b)

for i = 1 to n
  O_i = SM4Encrypt(T_i)
end for

for i = 1 to (n - 1)
  C_i = P_i xor O_i
end for

C_n = P_n xor MSB(u, O_n)

C = C_1 || ... || C_n
```

### SM4-CTR Encryption


Inputs:

- C, ciphertext, composed of (n - 1) blocks of size b, with the last block C_n of size 1 <= u <= b
- K, SM4 128-bit encryption key
- IV, a nonce (a unique value for each execution per given key)
- T, a sequence of counters from T_1 to T_n

Output:

- P, plaintext, composed of (n - 1) blocks of size b, with the last block P_n of size 1 <= u <= b

P is defined as follows.

```
n = NBlocks(C, b)

for i = 1 to n
  O_i = SM4Encrypt(T_i)
end for

for i = 1 to (n - 1)
  P_i = C_i xor O_i
end for

P_n = C_n xor MSB(u, O_n)

C = C_1 || ... || C_n
```

