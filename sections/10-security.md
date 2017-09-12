#  Security Considerations {#security-considerations}

* Products and services that utilize cryptography are regulated by OSCCA
  [@OSCCA]; they must be explicitly approved or certified by OSCCA before being
  allowed to be sold or used in China.

* SM4 is a blockcipher symmetric algorithm with key length of 128 bits. It is
  considered as an alternative to AES-128 [@NIST.FIPS.197].

* SM4 [@!GBT.32907-2016] is a blockcipher certified by OSCCA [@OSCCA].
  No formal proof of security is provided. There are no known feasible
  attacks against SM4 algorithm by the time of publishing this document, but
  there are security concerns with regards to side-channel attacks when the
  SM4 algorithm is implemented in hardware. See (#cryptanalysis) for more
  details.

* The IV does not have to be secret. The IV itself, or criteria enough to
  determine it, **MAY** be transmitted with ciphertext.

* SM4-ECB: ECB is one of the four original modes defined for DES. With its
  problem well known to "leak quite a large amount of information" [@BC-EVAL],
  it **SHOULD NOT** be used in most cases.

* SM4-CBC, SM4-CFB, SM4-OFB: CBC, CFB and OFB are IV-based modes of operation
  that were originally defined for DES.

  When using these modes of operation, the IV **SHOULD** be random to preserve
  message confidentiality [@BC-EVAL]. It is shown in the same document that
  CBC, CFB, OFB, the variants #CBC, #CFB that utilize the recommendation of
  [@NIST.SP.800-38A] to make CBC and CFB nonce-based, are SemCPA secure as
  probabilistic encryption schemes.

  Various attack scenarios have been described in [@BC-EVAL] and these modes
  **SHOULD NOT** be used unless for compatibility reasons.

* SM4-CTR: CTR is considered to be the "best" mode of operation within
  [@NIST.SP.800-38A] as it is considered SemCPA secure as a nonce-based
  encryption scheme, providing provable-security guarantees as good as
  the classic modes of operation (ECB, CBC, CFB, OFB) [@BC-EVAL].

  Users with no need of authenticity, non-malleablility and chosen-ciphertext
  (CCA) security **MAY** utilize this mode of operation [@BC-EVAL].
