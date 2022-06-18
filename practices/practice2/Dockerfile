FROM gcc:latest

COPY . /usr/src/cpp_docker

WORKDIR /usr/src/cpp_docker

RUN g++ -o Main main.cpp domestic_animal.cpp dog.cpp cat.cpp \
	boxer.cpp calico.cpp persian.cpp husky.cpp

CMD ["./Main"]
