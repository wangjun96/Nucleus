  
/*
 * Copyright 2019-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
/**************************************
 * attachWfAttCmp.cpp
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.cpp.tt>
 **************************************/

#include "smEnumTypes.h"
#include "actionTable.h"
#include "actionHandlers/actionHandlers.h"

#include "mmeStates/attachWfAttCmp.h"	
#include "mmeStates/attachWfMbResp.h"

using namespace mme;
using namespace SM;

/******************************************************************************
* Constructor
******************************************************************************/
AttachWfAttCmp::AttachWfAttCmp():State(State_e::attach_wf_att_cmp)
{
}

/******************************************************************************
* Destructor
******************************************************************************/
AttachWfAttCmp::~AttachWfAttCmp()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
AttachWfAttCmp* AttachWfAttCmp::Instance()
{
        static AttachWfAttCmp state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void AttachWfAttCmp::initialize()
{
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::process_attach_cmp_from_ue);
                actionTable.addAction(&ActionHandlers::send_mb_req_to_sgw);
                actionTable.setNextState(AttachWfMbResp::Instance());
                eventToActionsMap.insert(pair<Event_e, ActionTable>(Event_e::ATT_CMP_FROM_UE, actionTable));
        }
}