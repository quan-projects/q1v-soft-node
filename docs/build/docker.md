
## .dockerignore:       

~~~.dockerignore
*

!data-node/
!data-node/q1v-node-done/
!data-node/q1v-node-done/q1v-node
~~~

## q1v-node.dockerfile:       

~~~dockerfile
FROM ubuntu:noble AS build

COPY data-node/q1v-node-done/q1v-node /usr/local/bin

RUN userdel -r ubuntu

RUN groupadd -g 1000 q1v-node \
  && useradd --create-home --no-log-init -u 1000 -g 1000 q1v-node

RUN mkdir /home/q1v-node/blocks \
	&& mkdir /home/q1v-node/logs \
	&& chown q1v-node: /home/q1v-node/blocks \
	&& chown q1v-node: /home/q1v-node/logs

USER q1v-node
WORKDIR /home/q1v-node

ENTRYPOINT ["/usr/local/bin/q1v-node", "--data-dir=/home/q1v-node/blocks", "--log-file", "/home/q1v-node/logs/q1v-node.log"]
~~~       


## command line:       

~~~bash
$ mkdir -p data-node/blocks

$ mkdir data-node/logs

$ mkdir data-node/q1v-node-done

$ docker run --rm \
	-v ./data-node/q1v-node-done:/home/q1v-node/q1v-node-done \
	quanproject/dev-container:noble-boost-1.65.1

$ rm data-node/q1v-node-done/q1v-node

$ docker build \
	-t q1v-soft-node:0.0.1 . \
	-f q1v-node.dockerfile

$ docker run --rm \
	quanproject/q1v-soft-node:0.0.1 \
	--help

$ docker run -d -it \
	--name q1v-node-container \
	-v ./data-node/logs:/home/q1v-node/logs \
	-v ./data-node/blocks:/home/q1v-node/blocks \
	q1v-soft-node:0.0.1

$ docker logs q1v-node-container

$ ls data-node/blocks
~~~