FROM alpine:latest

RUN apk update && apk add gcc g++

RUN  mkdir /practice10

COPY . /practice10

WORKDIR /practice10

RUN g++ -o Main main.cpp shape.cpp circle.cpp 

CMD ["./Main"]