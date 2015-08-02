//===============================================================================
// @ Player.h
// ------------------------------------------------------------------------------
// Main player
//
// Copyright (C) 2008 by Elsevier, Inc. All rights reserved.
//
//
//
//===============================================================================

#ifndef __PlayerDefs__
#define __PlayerDefs__

//-------------------------------------------------------------------------------
//-- Dependencies ---------------------------------------------------------------
//-------------------------------------------------------------------------------

#include <IvVector3.h>
#include <IvHermite.h>

//-------------------------------------------------------------------------------
//-- Classes --------------------------------------------------------------------
//-------------------------------------------------------------------------------

class Player
{
public:
    Player();
    ~Player();

    void Update( float dt );
    void Render();

private:
    IvVector3   mTranslate;
    
    float       mTime;
    IvHermite   mCurve;
    bool        mRun;

    unsigned int mMode;
    IvVector3*  mSamplePositions;   // sample positions
    float*      mSampleTimes;       // arrival times
    IvVector3   mIn, mOut;          // in, out tangents
};

#endif
