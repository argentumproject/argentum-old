// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2013-2014 The Argentum developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

#include <stdint.h>

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    // How many times we expect transactions after the last checkpoint to
    // be slower. This number is a compromise, as it can't be accurate for
    // every system. When reindexing from a fast disk with a slow CPU, it
    // can be up to 20, while when downloading from a slow network with a
    // fast multicore CPU, it won't be much higher than 1.
    static const double SIGCHECK_VERIFICATION_FACTOR = 5.0;

    struct CCheckpointData {
        const MapCheckpoints *mapCheckpoints;
        int64_t nTimeLastCheckpoint;
        int64_t nTransactionsLastCheckpoint;
        double fTransactionsPerDay;
    };

    bool fEnabled = true;

    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    // no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
            (        0, uint256("0x88c667bc63167685e4e4da058fffdfe8e007e5abffd6855de52ad59df7bb0bb2"))
            (        1, uint256("0xdf0a20b6609b206448778428648f42a592dea10884a3fca1ce3a4c2ce12caf2f"))
            (        2, uint256("0xa10fd82c25b5ddcbcb9077cf9a70b47502a449663655a5d9cec09c19556c6d43"))
            (    50000, uint256("0xa8b62a4dd6c8aa28e2bf68c521e01da0638214f2def124a551f1a90df8402b6d"))
            (   124415, uint256("0x6d5a842bea984df8088f910d27f81af72ccfeef2bde21e100db036a51e17d6f8"))
            (   224414, uint256("0x2df7b26aea2376760533552baa54a61044d13f2c6f44ff017e855e9593aa0216"))
            (   624415, uint256("0x4651a604984d4494d09d1bb8c9f1c951e9bb214b5c930af4d0ad0bff7c513057"))
            (   824404, uint256("0x91456228171e75954e44e44b740ba075d179c11c31fc0d403843a582316a9e21"))
            (  1024406, uint256("0xf70a1dbf9c54f114690dfc7d6ac03366034e2c7a4dcd4fb71cf25f079c46c859"))
            (  1224406, uint256("0xa55d78df58fca4aec78e658614f004c2ad5930779e512447a0d96c5bb427cbe7"))
            (  1424405, uint256("0x820d255f359325f8c1792d776bef999bc8c54ab2cfb0d9f0b5d2281b759bccb3"))
            (  1624406, uint256("0xe58f3416b69542699b3e9662ea0a36318166753080b49e06e8b0a884efcb581b"))
            (  1826401, uint256("0x37c0d97ef3e0a24753b3e0eebe93588ad21b302f66c78b1046cbadeedd52c196"))
            (  1924401, uint256("0x2267dd4753f9e8fa088cdc4d257355b0a118ccd43a2f366c68de1aa260c4ba22"))
            (  1934707, uint256("0xe4527742cb236f24b355156213775e44da0e728ea453fae712fa672b18ce5f84"))
    ;
            
	static const CCheckpointData data = {
        &mapCheckpoints,
        1471941758, // * UNIX timestamp of last checkpoint block
        2139612,   // * total number of transactions between genesis and last checkpoint
                    //   (the tx=... number in the SetBestChain debug.log lines)
        1500.0     // * estimated number of transactions per day after checkpoint
    };

    static MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
        (     0, uint256("0x"))
        ;
    static const CCheckpointData dataTestnet = {
        &mapCheckpointsTestnet,
        0,
        0,
        0
    };

    static MapCheckpoints mapCheckpointsRegtest =
        boost::assign::map_list_of
        ( 0, uint256("3d2160a3b5dc4a9d62e7e66a295f70313ac808440ef7400d6c0772171ce973a5"))
        ;
    static const CCheckpointData dataRegtest = {
        &mapCheckpointsRegtest,
        0,
        0,
        0
    };

    const CCheckpointData &Checkpoints() {
        if (Params().NetworkID() == CChainParams::TESTNET)
            return dataTestnet;
        else if (Params().NetworkID() == CChainParams::MAIN)
            return data;
        else
            return dataRegtest;
    }

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (!fEnabled)
            return true;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    // Guess how far we are in the verification process at the given block index
    double GuessVerificationProgress(CBlockIndex *pindex, bool fSigchecks) {
        if (pindex==NULL)
            return 0.0;

        int64_t nNow = time(NULL);

        double fSigcheckVerificationFactor = fSigchecks ? SIGCHECK_VERIFICATION_FACTOR : 1.0;
        double fWorkBefore = 0.0; // Amount of work done before pindex
        double fWorkAfter = 0.0;  // Amount of work left after pindex (estimated)
        // Work is defined as: 1.0 per transaction before the last checkpoint, and
        // fSigcheckVerificationFactor per transaction after.

        const CCheckpointData &data = Checkpoints();

        if (pindex->nChainTx <= data.nTransactionsLastCheckpoint) {
            double nCheapBefore = pindex->nChainTx;
            double nCheapAfter = data.nTransactionsLastCheckpoint - pindex->nChainTx;
            double nExpensiveAfter = (nNow - data.nTimeLastCheckpoint)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore;
            fWorkAfter = nCheapAfter + nExpensiveAfter*fSigcheckVerificationFactor;
        } else {
            double nCheapBefore = data.nTransactionsLastCheckpoint;
            double nExpensiveBefore = pindex->nChainTx - data.nTransactionsLastCheckpoint;
            double nExpensiveAfter = (nNow - pindex->nTime)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore + nExpensiveBefore*fSigcheckVerificationFactor;
            fWorkAfter = nExpensiveAfter*fSigcheckVerificationFactor;
        }

        return fWorkBefore / (fWorkBefore + fWorkAfter);
    }

    int GetTotalBlocksEstimate()
    {
        if (!fEnabled)
            return 0;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (!fEnabled)
            return NULL;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
