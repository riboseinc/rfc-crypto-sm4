#  Introduction {#introduction}

SM4 [@!GBT.32907-2016] [@!ISO.IEC.18033-3.AMD2] is a cryptographic standard issued by the
Organization of State Commercial Administration of China [@OSCCA] as
authorized cryptographic algorithms for the use within China. The
algorithm is applicable  published in public.

SM4 is a symmetric encryption algorithm, specifically a blockcipher,
designed for data encryption.

This document does not aim to introduce a new algorithm, but to
provide a clear and open description of the SM4 algorithm in English,
and also to serve as a stable reference for IETF documents that utilize
this algorithm.

While this document is similar to [@SM4-En] in nature, [@SM4-En]
is a textual translation of "SMS4" [@SM4] published in 2006, and this
document follows the updated text and structure of [@!GBT.32907-2016].
The sections 1 to 7 of this document are intentionally mapped to the
corresponding sections 1 to 7 of the [@!GBT.32907-2016] standard for
convenience of the reader.


## History

The "SMS4" algorithm (the former name of SM4) was invented by
Shu-Wang Lu [@LSW-Bio], first published in 2003 as part of
[@GB.15629.11-2003], then published independently in 2006 [@SM4] by OSCCA,
officially renamed to "SM4" in 2012 in [@GMT-0002-2012] published by OSCCA,
and finally standardized in 2016 as a Chinese National Standard (GB Standard)
[@!GBT.32907-2016]. SM4 is also standardized in [@!ISO.IEC.18033-3.AMD2]
by the International Organization for Standardization in 2017.

SMS4 was originally created for use in protecting wireless networks [@SM4],
and is mandated in the Chinese National Standard for Wireless LAN WAPI (Wired
Authentication and Privacy Infrastructure) [@GB.15629.11-2003]. A proposal
was made to adopt SMS4 into the IEEE 802.11i standard, but the algorithm
was eventually not included due to concerns of introducing inoperability
with existing ciphers.

The latest SM4 standard [@!GBT.32907-2016] was proposed by OSCCA,
standardized through TC 260 of the Standardization Administration of the
People's Republic of China (SAC), and was drafted by the following
individuals at the Data Assurance and Communication Security Research
Center (DAS Center) of the Chinese Academy of Sciences, the China
Commercial Cryptography Testing Center and the Beijing Academy of
Information Science & Technology (BAIST):

* Shu-Wang Lu
* Dai-Wai Li
* Kai-Yong Deng
* Chao Zhang
* Peng Luo
* Zhong Zhang
* Fang Dong
* Ying-Ying Mao
* Zhen-Hua Liu


## Applications

SM4 (and SMS4) has prevalent hardware implementations [@SM4-FPGA]
[@SM4-VLSI], due to its being the only OSCCA-approved symmetric encryption
algorithm allowed for use in China.

SM4 can be used with multiple modes (See (#sm4-modes)).


## Cryptanalysis

A number of attacks have been attempted on SM4, such as [@SM4-Analysis]
[@SM4-Linear], but there are no known feasible attacks against the
SM4 algorithm by the time of publishing this document.

There are, however, security concerns with regards to side-channel attacks
[@SideChannel] when the SM4 algorithm is implemented in a device [@SM4-Power].

For instance, [@SM4-Power] illustrated an attack by measuring the power
consumption of the device. A chosen ciphertext attack, assuming a fixed
correlation between the sub-keys and data mask, is able to recover the round
key successfully. When the SM4 algorithm is implemented in hardware, the
parameters/keys **SHOULD** be randomly generated without fixed correlation.

There have been improvements to the hardware embodiment of SM4 such as
[@SM4-VLSI] that may resist such attacks.

In order to improve security of the SM4 cryptographic process, secure white-box
implementations such as [@SM4-WhiteBox] have been proposed. Speed enhancements,
such as [@SM4-HiSpeed], have also been proposed.
