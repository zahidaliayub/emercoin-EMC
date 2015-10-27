// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_MINER_H
#define BITCOIN_MINER_H

#include <stdint.h>
#include <cstddef>

class CBlock;
class CBlockHeader;
class CBlockIndex;
class CReserveKey;
class CScript;
class CWallet;

struct CBlockTemplate;

namespace boost {
    class thread_group;
} // namespace boost

/** Run the miner threads */
void GenerateBitcoins(bool fGenerate, CWallet* pwallet, int nThreads);
/** Run the stake minter thread */
void MintStake(boost::thread_group& threadGroup, CWallet* pwallet);
/** Generate a new block, without valid proof-of-work */
CBlockTemplate* CreateNewBlock(const CScript& scriptPubKeyIn, CWallet *pwallet = NULL, bool fProofOfStake = false);
CBlockTemplate* CreateNewBlockWithKey(CReserveKey& reservekey, CWallet *pwallet = NULL, bool fProofOfStake = false);
/** Modify the extranonce in a block */
void IncrementExtraNonce(CBlock* pblock, CBlockIndex* pindexPrev, unsigned int& nExtraNonce);
/** Check mined block */
void UpdateTime(CBlockHeader* block, const CBlockIndex* pindexPrev);

extern double dHashesPerSec;
extern int64_t nHPSTimerStart;

#endif // BITCOIN_MINER_H
