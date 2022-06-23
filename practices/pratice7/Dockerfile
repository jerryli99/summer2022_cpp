FROM gcc:latest

COPY . /usr/src/practice7

WORKDIR /usr/src/practice7

RUN g++ -o Main main.cpp user.cpp root_user.cpp

CMD ["./Main"]
