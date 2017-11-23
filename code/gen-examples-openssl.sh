export DYLD_FALLBACK_LIBRARY_PATH=~/src/openssl
export OPENSSL_BIN=~/src/openssl/apps/openssl

plaintext="AAAAAAAABBBBBBBBCCCCCCCCDDDDDDDDEEEEEEEEFFFFFFFFAAAAAAAABBBBBBBB"
ekey="0123456789ABCDEFFEDCBA9876543210"
iv="000102030405060708090A0B0C0D0E0F"

echo "SM4-ECB"
echo ${plaintext} | \
  xxd -r -p | \
  ${OPENSSL_BIN} enc -sm4-ecb -e -nosalt \
  -K ${ekey} | \
  xxd

echo "SM4-CBC"
echo ${plaintext} | \
  xxd -r -p | \
  ${OPENSSL_BIN} enc -sm4-cbc -e -nosalt \
  -K ${ekey} \
  -iv ${iv} | \
  xxd

echo "SM4-OFB"
echo ${plaintext} | \
  xxd -r -p | \
  ${OPENSSL_BIN} enc -sm4-ofb -e -nosalt \
  -K ${ekey} \
  -iv ${iv} | \
  xxd

echo "SM4-CFB"
echo ${plaintext} | \
  xxd -r -p | \
  ${OPENSSL_BIN} enc -sm4-cfb -e -nosalt \
  -K ${ekey} \
  -iv ${iv} | \
  xxd

echo "SM4-CTR"
plaintext="AAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDDEEEEEEEEEEEEEEEEFFFFFFFFFFFFFFFFAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBB"
echo ${plaintext} | \
  xxd -r -p | \
  ${OPENSSL_BIN} enc -sm4-ctr -e -nosalt \
  -K ${ekey} \
  -iv ${iv} | \
  xxd

