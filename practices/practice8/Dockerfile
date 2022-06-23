FROM gcc:latest

COPY . /usr/src/practice8

WORKDIR /usr/src/practice8

RUN g++ -o Main main.cpp person.cpp student.cpp my_friend.cpp

CMD ["./Main"]
