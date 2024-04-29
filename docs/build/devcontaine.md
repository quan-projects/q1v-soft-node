## .dockerignore:       

~~~.dockerignore
*

!data-node/
!data-node/q1v-node-done/
!data-node/q1v-node-done/q1v-node
~~~           

## dev-containe.dockerfile:                      

~~~dockerfile
FROM ubuntu:noble AS build

COPY boost_1_65_1_ready /home/q1v-node/boost_1_65_1_ready

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

RUN mkdir -p /home/q1v-node/q1v-node-done \
	&& chown q1v-node: /home/q1v-node/boost_1_65_1_ready \
    && chown q1v-node: /home/q1v-node/q1v-node-done

USER q1v-node

WORKDIR /home/q1v-node
	
CMD ["/bin/bash"]
~~~~~~       


## command line:       

~~~bash
$ mkdir -p data-node/q1v-node-done

$ docker build \
	-t dev-containe:0.0.1 . \
	-f dev-containe.dockerfile

$ docker run -it --rm \
  -v ./data-node/q1v-node-done:/home/q1v-node/q1v-node-done \
	dev-containe:0.0.1

q1v-node@docker:~$ git clone https://github.com/quan-projects/q1v-soft-node.git
q1v-node@docker:~$ mkdir /home/q1v-node/build && cd /home/q1v-node/build
q1v-node@docker:~$ cmake -D CMAKE_POSITION_INDEPENDENT_CODE:BOOL=true \
	-D BOOST_ROOT=/home/q1v-node/boost_1_65_1_ready \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_MAKE_PROGRAM=/usr/bin/ninja \
	-DCMAKE_C_COMPILER=/usr/bin/cc \
	-DCMAKE_CXX_COMPILER=/usr/bin/c++ \
	-G Ninja \
	-S ../q1v-soft-node -B .
q1v-node@docker:~$ ninja
q1v-node@docker:~$ cp -rf /home/q1v-node/build/q1v/src/* /home/q1v-node/q1v-node-done
q1v-node@docker:~$ cd /home/q1v-node/ && rm -rf /home/q1v-node/build && rm -rf /home/q1v-node/q1v-soft-node
q1v-node@docker:~$ exit

$ ls ./data-node/q1v-node-done
~~~         
