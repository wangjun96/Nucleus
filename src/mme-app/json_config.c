/*
 * Copyright 2019-present Open Networking Foundation
 * Copyright (c) 2003-2018, Great Software Laboratory Pvt. Ltd.
 * Copyright (c) 2017 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

extern "C"
{
#include "json_data.h"
}

#include "mme_app.h"
#include "err_codes.h"
#include "log.h"

/**
 * @brief Initialize json parser
 * @param None
 * @return void
 */
void
init_parser(char *path)
{
	load_json(path);
}

/**
 * @brief parser mme-app input json file
 * @param None
 * @return int as SUCCESS or FAIL
 */
int
parse_mme_conf(mme_config *config)
{
	log_msg(LOG_INFO, "Parsing config %s \n", __FUNCTION__);
	/*mme own information*/
	config->mme_name = get_string_scalar((char *)("mme.name"));
	if(NULL == config->mme_name) return E_PARSING_FAILED;

	config->mme_ip_addr = get_ip_scalar((char *)("mme.ip_addr"));
	if(E_PARSING_FAILED == config->mme_ip_addr) return E_PARSING_FAILED;

	config->logging = get_string_scalar((char *)("mme.logging"));
	if(NULL == config->logging) 
    { 
	  log_msg(LOG_INFO, "Missing logging config");
      config->logging = (char *)calloc(1, strlen("debug")+1);
      strncpy(config->logging, "debug", strlen("debug")+1);
    }

	config->mcc_dig1 = get_int_scalar((char *)("mme.mcc.dig1"));
	if(E_PARSING_FAILED == config->mcc_dig1) return E_PARSING_FAILED;
	config->mcc_dig2 = get_int_scalar((char *)("mme.mcc.dig2"));
	if(E_PARSING_FAILED == config->mcc_dig1) return E_PARSING_FAILED;
	config->mcc_dig3 = get_int_scalar((char *)("mme.mcc.dig3"));
	if(E_PARSING_FAILED == config->mcc_dig1) return E_PARSING_FAILED;
	config->mcc_dig1 = get_int_scalar((char *)("mme.mnc.dig1"));
	if(E_PARSING_FAILED == config->mcc_dig1) return E_PARSING_FAILED;
	config->mnc_dig2 = get_int_scalar((char *)("mme.mnc.dig2"));
	if(E_PARSING_FAILED == config->mcc_dig1) return E_PARSING_FAILED;
	config->mnc_dig3 = get_int_scalar((char *)("mme.mnc.dig3"));
	if(E_PARSING_FAILED == config->mcc_dig1) return E_PARSING_FAILED;

	config->mme_group_id = get_int_scalar((char *)("mme.group_id"));
	if(-1 == config->mme_group_id) return -1;

	config->mme_code = get_int_scalar((char *)("mme.code"));
	if(-1 == config->mme_code) return -1;

	return SUCCESS;
}
