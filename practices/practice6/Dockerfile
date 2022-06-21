FROM gcc:latest

COPY . /usr/src/practice6

WORKDIR /usr/src/practice6

RUN g++ -o Main main.cpp book.cpp student.cpp teacher.cpp \
		stem_teacher.cpp teacher_portal.cpp

CMD ["./Main"]
