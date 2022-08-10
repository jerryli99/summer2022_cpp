FROM alpine:latest

RUN apk update && apk add gcc g++

RUN  mkdir /practice14

COPY . /practice14

WORKDIR /practice14

RUN g++ -o Main main.cpp \
                shape_quiz18.cpp \
                point_quiz18.cpp \
                circle_quiz18.cpp \
                triangle_quiz18.cpp 

CMD ["./Main"]