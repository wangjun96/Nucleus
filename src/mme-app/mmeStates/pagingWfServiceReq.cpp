  
/*
 * Copyright 2019-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
/**************************************
 * pagingWfServiceReq.cpp
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.cpp.tt>
 **************************************/

#include "mmeSmDefs.h"
#include "actionTable.h"
#include "actionHandlers/actionHandlers.h"

#include "mmeStates/pagingWfServiceReq.h"	
#include "mmeStates/serviceRequestWfAuthResponse.h"

using namespace mme;
using namespace SM;

/******************************************************************************
* Constructor
******************************************************************************/
PagingWfServiceReq::PagingWfServiceReq():State(paging_wf_service_req)
{
}

/******************************************************************************
* Destructor
******************************************************************************/
PagingWfServiceReq::~PagingWfServiceReq()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
PagingWfServiceReq* PagingWfServiceReq::Instance()
{
        static PagingWfServiceReq state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void PagingWfServiceReq::initialize()
{
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::process_service_request);
                actionTable.addAction(&ActionHandlers::send_ddn_ack_to_sgw);
                actionTable.addAction(&ActionHandlers::auth_req_to_ue);
                actionTable.setNextState(ServiceRequestWfAuthResponse::Instance());
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(SERVICE_REQUEST_FROM_UE, actionTable));
        }
}
