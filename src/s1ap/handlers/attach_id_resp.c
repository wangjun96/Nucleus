/*
 * Copyright (c) 2003-2018, Great Software Laboratory Pvt. Ltd.
 * Copyright (c) 2017 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include "err_codes.h"
#include "options.h"
#include "ipc_api.h"
#include "main.h"
#include "s1ap.h"
#include "s1ap_config.h"
#include "sctp_conn.h"
#include "s1ap_structs.h"
#include "s1ap_msg_codes.h"
#include "msgType.h"


extern ipc_handle ipc_S1ap_Hndl;
extern struct time_stat g_attach_stats[];

int
s1_identity_resp_handler(struct proto_IE *s1_id_resp_ies)
{
	struct s1_incoming_msg_data_t id_resp= {0};

	/*****Message structure***
	*/
	log_msg(LOG_INFO, "Parse s1ap identity resp message:--\n");

	/*Validate all eNB info*/

	/*Add eNB info to hash*/

	/*Create Q structure for stage 1 to MME.
	  contains init UE information.*/
	id_resp.msg_type = id_response;
    for(int i = 0; i < s1_id_resp_ies->no_of_IEs; i++)
    {
        switch(s1_id_resp_ies->data[i].IE_type)
        {
            case S1AP_IE_MME_UE_ID:
                {
	                id_resp.ue_idx = s1_id_resp_ies->data[i].val.mme_ue_s1ap_id;
                }break;
            case S1AP_IE_NAS_PDU:
                {
                    if(s1_id_resp_ies->data[i].val.nas.header.message_type != NAS_IDENTITY_RESPONSE)
                    {
                        id_resp.msg_data.identityResp_Q_msg_m.status  = S1AP_IDENTITY_FAILED; 
                    }
                    else
                    {
                        id_resp.msg_data.identityResp_Q_msg_m.status = SUCCESS;
                    }

                    memcpy(&(id_resp.msg_data.identityResp_Q_msg_m.IMSI), 
                           &(s1_id_resp_ies->data[i].val.nas.elements[0].pduElement.IMSI),
                           BINARY_IMSI_LEN);
                }break;
            default:
                log_msg(LOG_WARNING,"Unhandled IE In identification Response %d \n",s1_id_resp_ies->data[i].IE_type);
        }
    }
	id_resp.destInstAddr = htonl(mmeAppInstanceNum_c);
	id_resp.srcInstAddr = htonl(s1apAppInstanceNum_c);

	//STIMER_GET_CURRENT_TP(g_attach_stats[s1_id_resp_ies->data[1].enb_ue_s1ap_id].auth_to_mme);
	send_tipc_message(ipc_S1ap_Hndl, mmeAppInstanceNum_c, (char *)&id_resp, S1_READ_MSG_BUF_SIZE);

	/*Send S1Setup response*/
	log_msg(LOG_INFO, "Id resp send to mme-app stage3.\n");

	//TODO: free IEs
	return SUCCESS;
}


