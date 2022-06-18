FROM gcc:latest

COPY . /usr/src/practice3

WORKDIR /usr/src/practice3

RUN g++ -o Main main.cpp store_employee.cpp \
	store_manager.cpp store_associate.cpp

CMD ["./Main"]
