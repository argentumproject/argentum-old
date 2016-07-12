*Copyright Bitcoin, Litecoin, DigitalCoin, Argentum Developers 2013-2016 | [Website] (ARGCurrency.Org)*

**Argentum** is the Latin name for the element silver. It is the perfect name to represent this currency and the potential it has with a dedicated development team. Argentum is **fast, unique, and secure**. We have learned from many of the past crypto-currencies and created one that can rival any. Argentum brings innovation and experimentation that **pushes the limits**.

Specifications

## General
- Scrypt & SHA256D
- AUXPOW merge mine capability
- Optimized client

## Blocks
- Block size 10mb
- Signature operations per block maximum 100k
- 1 Minute block time

The first two features are on the bitcoin hardfork wishlist. We wanted to create the **first** cryptographic currency with almost unlimited scalability. The signature operations per block were not increased as much as block size because it is unnecessary and theoretically unreachable as is.

## Difficulty
- Dark Gravity Wave Algo

## Currency Creation
- 64 million total ARG. 
> Once this limit is reached, it is increased by 1.1% annually, the rate of human population growth.

Fair launch:
We opted for a fair launch to let everyone start mining at the same time.

- Block 0-500: 0 ARG
- Block 500-1000: 1 ARG
- Block 1000-1500: 2 ARG
- Block 1500+: block reward random from 1-5. 

- Block 1825000: block reward fixed to 3.

## Security
- Mined blocks mature after 30 confirms
- Argentum is a fast currency but it does not compromise the safety of the blockchain in the process.

## Ports
Listen Port: 13580

RPC Port: 13581

## Mining

### Solo
> 1. Launch the wallet after following the setup guide above
> 2. Configure your miner to connect to your local IP (Examples: 192.168.x.x:13581, 127.0.0.x:13581) using your RPC details.
> 3. Launch your miner.
>    Example:  Example: cgminer.exe -Ã±scrypt -o LOCALIP -u RPCUSERNAME -p RPCPASSWORD


### Pool
> 1. Create an account at a pool. It is not necessary for P2pool as you will use your ARG address to receive payment.
> 2. Create a worker if you are not on a P2pool.
> 2. Launch your miner
>    Example: cgminer.exe -Ã±scrypt -o POOL.COM -u POOL.USERNAME -p POOLPASSWORD
>    Example P2pool: cgminer.exe --scrypt -o P2POOL.COM -u ARGENTUMADDRESS -p ANYTHING

## Conf Settings
If you are setting up a pool or want to solo mine in SHA add the following to the conf file
algo=sha256d

If you want to set the daemon to scrypt, set the algo= to algo=scrypt

##Nodes
Add these nodes

addnode=52.50.240.238
addnode=149.210.234.234
addnode=192.168.0.9,
addnode=148.251.19.213
addnode=104.131.142.198
addnode=82.176.15.155
addnode=144.76.71.141
addnode=82.29.4.122
addnode=98.115.147.74
addnode=87.98.185.244
addnode=52.58.50.77
addnode=178.237.35.34
addnode=104.131.142.198
addnode=162.251.173.179
addnode=24.141.165.231
addnode=162.255.117.105

##Bootstrap & Syncing

If you have trouble syncing, here is a bootstrap.
http://argcurrency.org/download/bootstrap.zip
Always backup your wallet before doing anything to the data directory. 

## Donation Addresses
Please Donate a little to the cause!
> ARG Donation Address: ATM1imaiPtFT5K8F2tsPh4RSpw7ADk9a8G

> BTC Donation Address: 1LxXw9CRunb5mJfa99aTWQMCqmbroVBUxi
