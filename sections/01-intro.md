#  Introduction {#introduction}

SM4 [@!GBT.32907-2016] is a cryptographic standard issued by the
Organization of State Commercial Administration of China [@OSCCA] as
authorized cryptographic algorithms for the use within China. The
algorithm is applicable  published in public.

SM4 is a symmetric encryption algorithm, specifically a blockcipher,
designed for data encryption.

This document is similar to [@SM4-En] in nature. [@SM4-En]
is a textual translation of "SMS4" [@SM4] published in 2006, while this
document follows the updated text and structure of [@!GBT.32907-2016].


## History

The "SMS4" algorithm (the former name of SM4) was invented by
Shu-Wang Lu [@LSW-Bio], and published by OSCCA in 2006 [@SM4]. It was
officially renamed to "SM4" in [@GMT-0002-2012] published by OSCCA in 2012,
and standardized as a Chinese National Standard (GB Standard) in 2016 as
[@!GBT.32907-2016].

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

SM4 (and SMS4) has prevalent hardware implementations, due to its being
the only OSCCA-approved symmetric encryption algorithm allowed for use
in China.

SM4 can be used with ECB, CBC, CFB, CTR, and OFB modes.
