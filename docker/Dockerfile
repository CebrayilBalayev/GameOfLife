FROM ubuntu:latest


ENV XDG_RUNTIME_DIR=/tmp

COPY . /Workdir

WORKDIR /Workdir/

#COPY . .

RUN apt-get -y update
RUN apt-get -y upgrade

#ARG CACHEBUST=1
RUN apt-get install -y build-essential

# install project dependencies
# Cunit
RUN apt-get install -y libcunit1-dev
#SDL2
RUN apt-get install -y libsdl2-dev
#CMake
RUN apt-get install -y build-essential libssl-dev
RUN apt-get install -y cmake


#EXPOSE 6080
# build app for production with minification
RUN cmake --version
RUN mkdir Build && cd Build && cmake ../ && cmake --build .


#RUN ./tests
#RUN ./Game_of_Life

#CMD ["echo", "Game of Life"]
#CMD ["cd""Build"]
#CMD ["ls"]
#CMD ["./tests"]
#CMD ["./Game_of_Life"]