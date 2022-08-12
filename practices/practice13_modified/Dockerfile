FROM alpine:latest

RUN apk update && apk add gcc g++

RUN  mkdir /practice13_modified1

COPY . /practice13_modified1

WORKDIR /practice13_modified1

RUN g++ -o Main main.cpp 

CMD ["./Main"]