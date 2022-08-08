FROM alpine:latest

RUN apk update && apk add gcc g++

RUN  mkdir /practice13

COPY . /practice13

WORKDIR /practice13

RUN g++ -o Main main.cpp

CMD ["./Main"]