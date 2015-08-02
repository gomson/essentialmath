//===============================================================================
// @ Obstacle.h
// ------------------------------------------------------------------------------
// Main Obstacle
//
// Copyright (C) 2008 by Elsevier, Inc. All rights reserved.
//
//
//
//===============================================================================

#ifndef __ObstacleDefs__
#define __ObstacleDefs__

//-------------------------------------------------------------------------------
//-- Dependencies ---------------------------------------------------------------
//-------------------------------------------------------------------------------

#include "SimObject.h"

//-------------------------------------------------------------------------------
//-- Classes --------------------------------------------------------------------
//-------------------------------------------------------------------------------

class Obstacle : public SimObject
{
public:
    Obstacle();
    virtual ~Obstacle();

    virtual void Update( float dt );
};

#endif
