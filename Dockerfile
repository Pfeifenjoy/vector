FROM gcc
RUN apt update
RUN apt -y install cmake valgrind rpm git
RUN mkdir /root/workspace
WORKDIR /root/workspace
