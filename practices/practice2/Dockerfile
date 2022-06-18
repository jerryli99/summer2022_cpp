FROM gcc:latest

COPY . /usr/src/practice2

WORKDIR /usr/src/practice2

RUN g++ -o Main main.cpp domestic_animal.cpp dog.cpp cat.cpp \
	boxer.cpp calico.cpp persian.cpp husky.cpp

CMD ["./Main"]
