/*
 * Copyright 2019-present, Infosys Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 /******************************************************************************
 *
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/GtpV2StackCodeGen/tts/ietemplate.h.tt>
 ******************************************************************************/
#ifndef NODEIDENTIFIERIE_H_
#define NODEIDENTIFIERIE_H_

#include "manual/gtpV2Ie.h"



class NodeIdentifierIe: public GtpV2Ie {
public:
    NodeIdentifierIe();
    virtual ~NodeIdentifierIe();

    bool encodeNodeIdentifierIe(MsgBuffer &buffer,
                 NodeIdentifierIeData const &data);
    bool decodeNodeIdentifierIe(MsgBuffer &buffer,
                 NodeIdentifierIeData &data, Uint16 length);
    void displayNodeIdentifierIe_v(NodeIdentifierIeData const &data,
                 Debug &stream);
};

#endif /* NODEIDENTIFIERIE_H_ */