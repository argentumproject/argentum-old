# Argentum
*Copyright Bitcoin, Litecoin, DigitalCoin, Argentum Developers 2013-2016 | [Website] (ARGCurrency.Org)*

**Argentum** is the Latin name for the element silver. It is the perfect name to represent this currency and the potential it has with a dedicated development team. Argentum is **fast, unique, and secure**. We have learned from many of the past crypto-currencies and created one that can rival any. Argentum brings innovation and experimentation that **pushes the limits**. The website, marketplace, and exchange are under construction and will be launched soon after Argentum.

Specifications

## General
- Scrypt & SHA256D
- AUXPOW merge mine capability
- Optimized client

## Blocks
- Block size increased to 10mb
- Signature operations per block maximum increased to 100k
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
You can either solo mine or mine in a pool.

### Solo
> 1. Launch the wallet after following the setup guide above
> 2. Configure your miner to connect to your local IP (Examples: 192.168.x.x:13581, 127.0.0.x:13581) using your RPC details.
> 3. Launch your miner.
>    Example:  Example: cgminer.exe -ñscrypt -o LOCALIP -u RPCUSERNAME -p RPCPASSWORD


### Pool
> 1. Create an account at a pool. It is not necessary for P2pool as you will use your ARG address to receive payment.
> 2. Create a worker if you are not on a P2pool.
> 2. Launch your miner
>    Example: cgminer.exe -ñscrypt -o POOL.COM -u POOL.USERNAME -p POOLPASSWORD
>    Example P2pool: cgminer.exe --scrypt -o P2POOL.COM -u ARGENTUMADDRESS -p ANYTHING

## Conf Settings
if you are setting up a pool or want to solo mine in SHA add the following to the conf file
algo=sha256d

If you wnat to set the daemon to scrypt, set the algo= to algo=scrypt

## Donation Addresses
Please Donate a little to the cause!
> ARG Donation Address: ATM1imaiPtFT5K8F2tsPh4RSpw7ADk9a8G

> BTC Donation Address: 1LxXw9CRunb5mJfa99aTWQMCqmbroVBUxi
