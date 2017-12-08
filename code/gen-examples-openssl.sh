#!/bin/bash

export DYLD_FALLBACK_LIBRARY_PATH=~/src/openssl
export OPENSSL_BIN=~/src/openssl/apps/openssl

plaintext_short=AAAAAAAABBBBBBBBCCCCCCCCDDDDDDDDEEEEEEEEFFFFFFFFAAAAAAAABBBBBBBB
plaintext_long="AAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDDEEEEEEEEEEEEEEEEFFFFFFFFFFFFFFFFAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBB"
ekey1="0123456789ABCDEFFEDCBA9876543210"
ekey2="FEDCBA98765432100123456789ABCDEF"
iv="000102030405060708090A0B0C0D0E0F"

for mode in ecb cbc ofb cfb ctr; do

  for ekey in ${ekey1} ${ekey2}; do

    echo "SM4-${mode} ekey ${ekey}"

    if [ "${mode}" == "ecb" ]; then
      iv_opts=""
    else
      iv_opts=" -iv ${iv}"
    fi

    plaintext="${plaintext_short}"
    if [ "${mode}" == "ctr" ]; then
      plaintext="${plaintext_long}"
    fi

    echo "SM4-${mode} plaintext ${plaintext}"

    # WARNING: the HEX STRINGS outputted are wrong because they're uppercased.
    # We do this here to make it easy to copy uppercase ciphertext to the text.
    printf "%s" ${plaintext} | \
      xxd -r -p | \
      ${OPENSSL_BIN} enc -sm4-${mode} -e -nosalt -v -nopad \
      -K ${ekey} ${iv_opts} | \
      xxd | \
      tr '[:lower:]' '[:upper:]'
  done

done

