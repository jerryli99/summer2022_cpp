FROM gcc:latest

COPY . /usr/src/cpp_docker

WORKDIR /usr/src/cpp_docker

RUN g++ -o Main main.cpp

CMD ["./Main"]


