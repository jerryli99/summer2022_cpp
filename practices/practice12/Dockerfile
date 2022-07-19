FROM alpine:latest

RUN apk update && apk add gcc g++

RUN  mkdir /practice11

COPY . /practice12

WORKDIR /practice12

RUN g++ -o Main main.cpp photo_order.cpp customer.cpp

CMD ["./Main"]