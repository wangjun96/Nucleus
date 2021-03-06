#!/bin/bash
#
# Copyright 2019-present Open Networking Foundation
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

SUDO=''
[[ $EUID -ne 0 ]] && SUDO=sudo

install_run_pkg_deps() {
	$SUDO apt-get update && $SUDO apt-get install -y \
		openssl \
		libidn11 \
		libgnutls30 \
		libsctp1 \
		netbase\
		openssh-server\
		sshpass
}

install_run_utils() {
        $SUDO apt-get update && $SUDO apt-get install -y \
        jq \
        dnsutils \
		iproute2 \
		iputils-ping \
		tcpdump
}

install_ssh_server() {
	$SUDO mkdir /var/run/sshd
	echo 'root:mypass' | chpasswd
	sed -i 's/PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config
	sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd
	echo "export VISIBLE=now" >> /etc/profile
}

cleanup_image() {
	$SUDO rm -rf /var/lib/apt/lists/*
}

install_run_deps() {
        install_run_pkg_deps
        install_ssh_server
}

(return 2>/dev/null) && echo "Sourced" && return

set -o errexit
set -o pipefail
set -o nounset

install_run_deps
echo "Dependency install completed"
