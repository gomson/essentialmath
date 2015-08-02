//===============================================================================
// @ Game.cpp
// ------------------------------------------------------------------------------
// Game core routines
//
// Copyright (C) 2008 by Elsevier, Inc. All rights reserved.
//
//
//
//===============================================================================

//-------------------------------------------------------------------------------
//-- Dependencies ---------------------------------------------------------------
//-------------------------------------------------------------------------------

#include <IvRendererHelp.h>
#include <IvVector4.h>

#include "Game.h"
#include "Player.h"
#include "Obstacle.h"

//-------------------------------------------------------------------------------
//-- Static Members -------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//-- Methods --------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
// @ IvGame::Create()
//-------------------------------------------------------------------------------
// Static constructor
//-------------------------------------------------------------------------------
bool
IvGame::Create()
{
    IvGame::mGame = new Game();
    return ( IvGame::mGame != 0 );

}   // End of IvGame::Create()


//-------------------------------------------------------------------------------
// @ Game::Game()
//-------------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------------
Game::Game()
{
    // init variables
    mPlayer = 0;            // main player object
    mObstacle = 0;          // obstacle to avoid

}   // End of Game::Game()


//-------------------------------------------------------------------------------
// @ Game::~Game()
//-------------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------------
Game::~Game()
{
    delete mObstacle;
    mObstacle = 0;

    delete mPlayer;
    mPlayer = 0;

}   // End of Game::~Game()


//-------------------------------------------------------------------------------
// @ Game::PostRendererInitialize()
//-------------------------------------------------------------------------------
// Set up internal subsystems
//-------------------------------------------------------------------------------
bool 
Game::PostRendererInitialize()
{
    // Set up base class 
    IvGame::PostRendererInitialize();
    
    mPlayer = new Player();
    if (!mPlayer)
        return false;

    mObstacle = new Obstacle();
    if (!mPlayer)
        return false;
    
    ::IvSetDefaultLighting();

    return true;
}   // End of Game::PostRendererInitialize()


//-------------------------------------------------------------------------------
// @ Game::Update()
//-------------------------------------------------------------------------------
// Update object information
//-------------------------------------------------------------------------------
void
Game::UpdateObjects( float dt )
{
    // update player
    mPlayer->Update( dt );
    // update obstacle
    mObstacle->Update( dt );

    mPlayer->HandleCollision( mObstacle );
    
}   // End of Game::UpdateObjects()


//-------------------------------------------------------------------------------
// @ Game::Render()
//-------------------------------------------------------------------------------
// Render stuff
//-------------------------------------------------------------------------------
void 
Game::Render()                                  // Here's Where We Do All The Drawing
{
    // Reset The View
    ::IvSetDefaultViewer( -10.0f, 2.0f, 20.0f );
    
    // draw axes
    ::IvDrawAxes();
    
    // draw the main object
    mPlayer->Render();

    // draw the obstacle
    mObstacle->Render();
}
