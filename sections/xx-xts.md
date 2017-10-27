## SM4-XTS

<!--
XTS (XEX-based tweaked-codebook mode with ciphertext stealing)

SMS4-WRAP，将SMS4用于加密密钥，其中被加密的数据为密钥，而SMS4的密钥为KEK (Key Encryption Key)。

[@RFC3602]

NIST has defined 5 modes of operation for AES and other FIPS-approved
ciphers [MODES]: CBC (Cipher Block Chaining), ECB (Electronic
CodeBook), CFB (Cipher FeedBack), OFB (Output FeedBack) and CTR
(Counter).  The CBC mode is well-defined and well-understood for
symmetric ciphers, and is currently required for all other ESP
ciphers.  This document specifies the use of the AES cipher in CBC
mode within ESP.  This mode requires an Initialization Vector (IV)
that is the same size as the block size.  Use of a randomly generated
IV prevents generation of identical ciphertext from packets which
have identical data that spans the first block of the cipher
algorithm's block size.

The IV is XOR'd with the first plaintext block before it is
encrypted.  Then for successive blocks, the previous ciphertext block
is XOR'd with the current plaintext, before it is encrypted.

More information on CBC mode can be obtained in [MODES, CRYPTO-S].
For the use of CBC mode in ESP with 64-bit ciphers, see [CBC]. -->


<!-- ## SM4-XTS

[@NIST.SP.800-38E]

[@IEEE.1619-2007] defines XTS-AES

This standard defines the XTS-AES tweakable blockcipher and its use for encryption of sector-based storage. XTS-AES is a tweakable blockcipher that acts on data units of 128 bits or more and uses the AES blockcipher as a subroutine. The key material for XTS-AES consists of a data encryption key (used by the AES blockcipher) as well as a “tweak key” that is used to incorporate the logical position of the data block into the encryption. XTS-AES is a concrete instantiation of the class of tweakable blockciphers described in reference [XEX04]. The XTS-AES addresses threats such as copy-and-paste and dictionary attacks, while allowing parallelization and pipelining in cipher implementations.


10 This standard defines specific elements of an architecture for cryptographically protecting data stored in
11 constant length blocks. Specification of such a mechanism provides an additional and improved tool for
12 implementation of secure and interoperable protection of data residing in storage.
13
14 The XTS-AES transform defined in this standard is intended for encryption of storage where the threat
15 model includes possible access to stored data by the attacker, data to be protected is presented in fixed-size
16 units (sectors, logical disk blocks, etc.), and each unit must be processed separately, independently of other
17 data units. XTS-AES is a length-preserving transform, meaning that the ciphertext length produced by
18 XTS-AES is equal to the length of the plaintext. These two properties allow the use of XTS-AES as
19 transparent encryption: an encryption/decryption module may be added to an existing system without
20 having to modify the data layout of any of the existing components.1
21


 -->
<!--

https://www.oasis-open.org/committees/download.php/55740/AES-XTS.pdf

IEEE P1619/D16 Standard for Cryptographic Protection of Data on Block-Oriented Storage Devices
IEEE Computer Society Committee
Copyright © 2007 by the Institute of Electrical and Electronics Engineers, Inc. Three Park Avenue
New York, New York 10016-5997, USA


Apr 14, 2015 - References [NIST SP800-38B] and [RFC 4493] recommend that the ... The following table defines the AES-XTS secret key object attributes in ..


3 Introduction
The XTS-AES algorithm is a mode of operation of the Advanced Encryption Standard (AES) [1]
algorithm.

The Security in Storage Working Group (SISWG) of the P1619 Task Group of the
Institute of Electrical and Electronics Engineers, Inc (IEEE) developed and specified XTS-AES
in IEEE Std. 1619-2007 [2]. This Recommendation approves the XTS-AES mode as specified in
that standard, subject to one additional requirement on the lengths of the data units, which is
discussed in Section 4 below.
The XTS-AES mode was designed for the cryptographic protection of data on storage devices
that use of fixed length “data units,” as defined in Ref. [2]. Note that other approved
cryptographic algorithms continue to be approved for such devices. The XTS-AES mode was
not designed for other purposes, such as the encryption of data in transit.
The XTS-AES mode is an instantiation of Rogaway’s XEX (XOR Encrypt XOR) tweakable
blockcipher [3], supplemented with a method called “ciphertext stealing” to extend the domain
of possible input data strings. In particular, XEX can only encrypt sequences of complete
blocks, i.e., any data string that is an integer multiple of 128 bits; whereas for XTS-AES, the data
string may also consist of one or more complete blocks followed by a single, non-empty partial
block. (The acronym XTS stands for the XEX Tweakable Block Cipher with Ciphertext
Stealing).
The specification of the ciphertext stealing method in Ref.[2] includes an ordering convention for
the final complete block and partial block of the encrypted data string. A different convention, in
which the order is swapped, may be desirable in some cases. The specification in Ref.[2]
provides flexibility in the physical location of these elements, as long as interoperability is not
compromised, as discussed in Section 5.
The XTS-AES mode provides confidentiality for the protected data. Authentication is not
provided, because the P1619 Task Group designed XTS-AES to provide encryption without data
expansion, so alternative cryptographic methods that incorporate an authentication tag are
precluded. In the absence of authentication or access control, XTS-AES provides more
protection than the other approved confidentiality-only modes against unauthorized manipulation
of the encrypted data.
Annex D of Ref.[2] discusses in detail the design choices for XTS, including the resistance to
manipulation of the encrypted data, and their ramifications for the incorporation of XTS-AES
into an information system. Prospective implementers of XTS-AES should consider this
information carefully to ensure that XTS-AES is an appropriate solution for a given threat
model.



Conformance
An instance of an XTS-AES implementation is defined by the following three elements, as
specified in Ref. [2]:
1) a secret key,
2) a single, fixed length for the data units that the key protects,
3) an implementation of the XTS-AES-Enc procedure or the XTS-AES-Dec procedure, or both,
for the key and the length of the data units.
The length of the data unit for any instance of an implementation of XTS-AES shall not exceed
220 AES blocks. Note that Subclause 5.1 of Ref.[2] recommends this limit but does not require
it.
An implementation of the XTS-AES encryption mode may claim conformance with this
Recommendation if every supported instance satisfies this length requirement for a data unit, in
addition to all of the requirements in Clauses 1-6 of Ref. [2].
Key management is important for XTS-AES, as for any keyed cryptographic algorithm, but the
representation of a key backup structure in the Extensible Markup Language (XML) that is
specified in Clause 7 of Ref. [2] is outside the scope of this Recommendation.
Consistent with the 220 block limit for a data unit, an implementation of XTS-AES may further
restrict the length of the data units for any key. For example, an implementation may support


only data units that are sequences of complete blocks. In this case, the ciphertext stealing
components in the implementations of the XTS-AES-Enc and the XTS-AES-Dec procedures
would be unnecessary, and these procedures essentially would be reduced to the XTS-AESblockEnc
and the XTS-AES-blockDec procedures, as specified in Ref. [2].
Similarly, an implementation may restrict its support to either the 256-bit key size (for XTSAES-128)
or the 512-bit key size (for XTS-AES-256).
Restrictions on the supported lengths of the key or the data units may affect interoperability with
other implementations.

5 Ordering Convention for the Ciphertext Stealing Case
If the length of the data units for an instance of XTS-AES is not an integral multiple of the block
size, then the specification in Ref. [2] denotes the unencrypted form of a data unit, i.e., the
plaintext, as a sequence of complete blocks, P0, P1, ...Pm-1, followed by a single, non-empty
partial block Pm, where m is a positive integer determined by the length of the data unit.
In this case, the encrypted form of the data unit, i.e., the ciphertext, has the same structure: a
sequence of complete blocks, denoted C0, C1, ...Cm-1, followed by a single, non-empty partial
block Cm, whose length is the same as the length of Pm.
For some implementations, an alternative ordering convention, in which the positions of Cm-1 and
Cm are swapped, may be desirable for the physical storage of the bits, because that ordering
corresponds more closely with the generation of the ciphertext. In particular, Cm is the truncation
of a block that is derived from Pm-1, and Cm-1 is derived from Pm, concatenated with the discarded
bits from the truncation.
Subclause 5.1 of [2] indicates that an implementation of XTS-AES should include a mapping
between the pairs of indices that define the blocks (and possibly a single partial block) of a data
unit and their physical location in the storage device, but that the mapping itself is outside the
scope of the standard.

Thus, if every external interface to the data retrieves the data in a manner that is consistent with
the ordering specified in Ref [2], then the last block and the partial block may be stored in any
convenient locations in the storage device. In other words, if necessary, a mechanism for
swapping the last complete block and the partial block could be built into the interface. -->