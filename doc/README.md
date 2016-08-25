*Copyright Bitcoin, Litecoin, DigitalCoin, Argentum Developers 2013-2016 | [Website](http://www.argentum.io)*

**Argentum** is the Latin name for the element silver. It is the perfect name to represent this currency and the potential it has with a dedicated development team. Argentum is **fast, unique, and secure**. We have learned from many of the past crypto-currencies and created one that can rival any. Argentum brings innovation and experimentation that **pushes the limits**.

Specifications

## General
- Scrypt & SHA256D
- AUXPOW merge mine capability
- Optimized client

## Blocks
- Block size 10mb
- Signature operations per block maximum 100k
- 45 Second block time
- 3 Argentums per block

The first two features are on the bitcoin hardfork wishlist. We wanted to create the **first** cryptographic currency with almost unlimited scalability. The signature operations per block were not increased as much as block size because it is unnecessary and theoretically unreachable as is.

## Difficulty
- Block 1930000 new Multi-algorithm difficulty adjustment based on Digispeed.

## Currency Creation
- 64 million total ARG. 
> Once this limit is reached, it is increased by 1.1% annually, the rate of human population growth.

## Security
- Mined blocks mature after 30 confirms
- Argentum is a fast currency but it does not compromise the safety of the blockchain in the process.

## Ports
Listen Port: 13580

RPC Port: 13581

## Conf Settings
Use this to set the algorithm to SHA256D for mining (default is scrypt)  

algo=sha256d

##Nodes
Add these nodes

addnode=52.58.154.192
addnode=82.176.15.155
addnode=157.161.128.63
addnode=52.50.240.238
addnode=82.29.4.122
addnode=149.210.234.234
addnode=92.3.38.193
addnode=92.3.46.94
addnode=82.29.4.122
addnode=92.3.37.23
addnode=54.246.128.222
addnode=162.255.117.105
addnode=108.61.10.90
addnode=87.98.185.244
addnode=52.50.240.238
addnode=144.76.71.141
addnode=98.115.147.74
addnode=96.236.219.30
addnode=82.29.4.122
addnode=52.58.50.77
addnode=138.201.65.88

# Installing libdb5.1 onto a system with libdb4.8 already installed. (For AUXPOW and mining nodes)
From https://bitcointalk.org/index.php?topic=1432608.msg15382962#msg15382962

BITCOIN_ROOT=$(pwd)

- Pick some path to install BDB to, here we create a directory within the argentum directory  
> BDB_PREFIX="${BITCOIN_ROOT}/db5" mkdir -p $BDB_PREFIX

- Fetch the source and verify that it is not tampered with  
> wget 'http://download.oracle.com/berkeley-db/db-5.1.29.NC.tar.gz'
echo '08238e59736d1aacdd47cfb8e68684c695516c37f4fbe1b8267dde58dc3a576c  db-5.1.29.NC.tar.gz' | sha256sum -c  
tar -xzvf db-5.1.29.NC.tar.gz

- Build the library and install to our prefix  
> cd db-5.1.29.NC/build_unix/

-  Note: Do a static build so that it can be embedded into the exectuable, instead of having to find a .so at runtime
> ../dist/configure --enable-cxx --disable-shared --with-pic --prefix=$BDB_PREFIX
make install

- Configure Argentum Core to use our own-built instance of BDB  
> cd $BITCOIN_ROOT
./autogen.sh
./configure LDFLAGS="-L${BDB_PREFIX}/lib/" CPPFLAGS="-I${BDB_PREFIX}/include/"
make

## Donation Addresses
Please Donate a little to the cause!
> ARG Donation Address: ATM1imaiPtFT5K8F2tsPh4RSpw7ADk9a8G

> BTC Donation Address: 1LxXw9CRunb5mJfa99aTWQMCqmbroVBUxi
