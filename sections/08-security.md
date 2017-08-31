#  Security Considerations

* Products and services that utilize cryptography are regulated by OSCCA [@OSCCA];
  they must be explicitly approved or certified by OSCCA before being allowed to
  be sold or used in China.

* SM4 [@!GBT.32907-2016] is a blockcipher certified by OSCCA [@OSCCA].
  No formal proof of security is provided. There are no known feasible
  attacks against SM4 algorithm by the time of publishing this document.
  On the other hand, there are security concerns with regards to
  side-channel attacks, when the SM4 algorithm is implemented in a
  device [@SM4-Power]. For instance, [@SM4-Power] illustrated an attack
  by measuring the power consumption of the device. A chosen ciphertext
  attack, assuming a fixed correlation between the sub-keys and data
  mask, is able to recover the round key successfully. When the SM4
  algorithm is implemented in hardware, the parameters/keys **SHOULD**
  be randomly generated without fixed correlation.

* SM4 is a blockcipher symmetric algorithm with key length of 128 bits. It is
  considered as an alternative to AES-128 [@NIST.FIPS.197].
