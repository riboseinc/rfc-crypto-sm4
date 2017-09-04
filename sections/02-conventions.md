#  Terms and Definitions

The key words "**MUST**", "**MUST NOT**", "**REQUIRED**", "**SHALL**",
"**SHALL NOT**", "**SHOULD**", "**SHOULD NOT**", "**RECOMMENDED**",
"**MAY**", and "**OPTIONAL**" in this document are to be interpreted
as described in [@!RFC2119].

The following terms and definitions apply to this document.

block length
: Bit-length of a message block.

key length
: Bit-length of a key.

key expansion algorithm
: An operation that converts a key into a round key.

rounds
: The number of iterations of the round function.

<!-- TODO: clarify this -->

round key
: Also called a subkey, it is a key used in each round of the iterative blockcipher, derived from the input key

word
: a 32-bit quantity

S-box
: The S (substitution) box function produces 8-bit output from 8-bit input, represented as $$Sbox(.)$$
