#
# Copyright (c) 2019, Infosys Ltd.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
include ../../Makefile.common

CC := g++
CFLAGS = -Wall -I$(GRPC_ROOT)/include -I$(GRPC_ROOT)/third_party/protobuf/src -std=c++11
LDFLAGS = -L$(GRPC_ROOT)/libs/opt -lgrpc++ -lgrpc -lgpr -L$(GRPC_ROOT)/libs/opt/protobuf -lprotobuf

SRCS := ./mmeGrpc.grpc.pb.cc \
        ./mmeGrpc.pb.cc

SRCDIR := .
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/mmeGrpcProtos/%,$(SRCS:.cc=.o))

MMEGRPC_PROTOBUF_LIB = $(LIBDIR)/libmmeGrpcProtoBuf.so

all :  mmeGrpc.pb.h $(MMEGRPC_PROTOBUF_LIB)

mmeGrpc.pb.h : mmeGrpc.proto
	$(GRPC_ROOT)/bins/opt/protobuf/protoc --cpp_out=. --grpc_out=. --plugin=protoc-gen-grpc=$(GRPC_ROOT)/bins/opt/grpc_cpp_plugin mmeGrpc.proto


$(MMEGRPC_PROTOBUF_LIB) : $(OBJECTS)
	@echo "Linking..."
	-@mkdir -p $(LIBDIR)
	$(CC) $(CFLAGS) $(OBJECTS) -shared -o $(MMEGRPC_PROTOBUF_LIB)

$(OBJECTS) : $(OBJDIR)/mmeGrpcProtos/%.o : $(SRCDIR)/%.cc
	-@mkdir -p $(OBJDIR)/mmeGrpcProtos
	$(CC) $(CFLAGS) $(INC_DIRS) -fPIC -c -o $@ $<

install:
	-@mkdir -p $(TARGET_DIR)/lib
	-@cp $(MMEGRPC_PROTOBUF_LIB) $(TARGET_DIR)/lib
clean:
	@echo "Cleaning..."
	-@rm -rf $(MMEGRPC_PROTOBUF_LIB) $(OBJDIR)/mmeGrpcProtos  *.pb.cc *.pb.h
