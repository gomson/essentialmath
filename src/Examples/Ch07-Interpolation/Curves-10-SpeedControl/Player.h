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
#include <IvBezier.h>

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

    float DistanceSinusoid( float t, float k1, float k2 );
    float DistanceParabolic( float t, float k1, float k2 );

private:
    IvVector3   mTranslate;

    float       mTime;
    IvBezier    mCurve;
    bool        mRun;
    int         mMode;
    
};

#endif
