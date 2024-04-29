
## .dockerignore:       

~~~.dockerignore
*

!boost_1_65_1/
!boost_1_65_1/**
~~~

## boost_1_65_1.dockerfile:

~~~dockerfile
FROM ubuntu:noble AS build

COPY boost_1_65_1 /home/q1v-node/boost_1_65_1

RUN userdel -r ubuntu

RUN groupadd -g 1000 q1v-node \
  && useradd --create-home --no-log-init -u 1000 -g 1000 q1v-node

RUN ln -fs /usr/share/zoneinfo/America/Belem /etc/localtime

RUN apt-get update && apt-get install -y --no-install-recommends iputils-ping \
	&& DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
		libssl-dev openssl \
		build-essential uuid-dev gdb \
		gcc-9 g++-9 clang \
		gcc-9-multilib g++-9-multilib \
		xutils-dev \
		patch \
		git nano \
		cmake libtool automake autoconf ninja-build \
		curl libcurl4-gnutls-dev wget \
		tree \
		python3 python3-pip python3-dev \
		libpulse-dev dos2unix rsync

RUN apt-get autoremove && apt-get clean \
	&& rm -rf /var/lib/apt/lists/* \
	&& update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 9 --slave /usr/bin/g++ g++ /usr/bin/g++-9 --slave /usr/bin/gcov gcov /usr/bin/gcov-9

RUN mkdir -p /home/q1v-node/boost_1_65_1_ready \
	&& chown q1v-node: /home/q1v-node/boost_1_65_1_ready \
    && chown q1v-node: /home/q1v-node/boost_1_65_1

USER q1v-node

WORKDIR /home/q1v-node
	
CMD ["/bin/bash"]
~~~      


## command line:       

~~~bash
$ mkdir -p boost_1_65_1_ready

$ wget https://boostorg.jfrog.io/artifactory/main/release/1.65.1/source/boost_1_65_1.tar.gz

$ tar -xzvf boost_1_65_1.tar.gz && rm boost_1_65_1.tar.gz

$ docker build \
	-t q1v-boost_1_65_1:0.0.1 . \
	-f boost_1_65_1.dockerfile

$ docker run -it --rm \
    -v ./boost_1_65_1_ready:/home/q1v-node/boost_1_65_1_ready \
	q1v-boost_1_65_1:0.0.1

q1v-node@docker:~$ cd boost_1_65_1
q1v-node@docker:~$ ./bootstrap.sh --prefix=/home/q1v-node/boost_1_65_1_ready --with-python=python3
q1v-node@docker:~$ ./b2 install
q1v-node@docker:~$ cd /home/q1v-node
q1v-node@docker:~$ rm -rf /home/q1v-node/boost_1_65_1
q1v-node@docker:~$ exit

$ ls boost_1_65_1_ready
~~~