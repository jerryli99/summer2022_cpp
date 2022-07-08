FROM alpine:latest

RUN apk update && apk add gcc g++

RUN  mkdir /practice11

COPY . /practice11

WORKDIR /practice11

RUN g++ -o Main main.cpp character_ability.cpp character.cpp game_user.cpp

CMD ["./Main"]