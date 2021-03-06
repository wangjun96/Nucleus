  
/*
 * Copyright 2019-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
/**************************************
 * s1ReleaseStart.cpp
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.cpp.tt>
 **************************************/

#include "mmeSmDefs.h"
#include "actionTable.h"
#include "actionHandlers/actionHandlers.h"

#include "mmeStates/s1ReleaseStart.h"	
#include "mmeStates/s1ReleaseWfReleaseAccessBearerResp.h"

using namespace mme;
using namespace SM;

/******************************************************************************
* Constructor
******************************************************************************/
S1ReleaseStart::S1ReleaseStart():State(s1_release_start)
{
}

/******************************************************************************
* Destructor
******************************************************************************/
S1ReleaseStart::~S1ReleaseStart()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
S1ReleaseStart* S1ReleaseStart::Instance()
{
        static S1ReleaseStart state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void S1ReleaseStart::initialize()
{
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::send_rel_ab_req_to_sgw);
                actionTable.setNextState(S1ReleaseWfReleaseAccessBearerResp::Instance());
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(S1_REL_REQ_FROM_UE, actionTable));
        }
}
