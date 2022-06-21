FROM gcc:latest

COPY . /usr/src/cpp_docker

WORKDIR /usr/src/cpp_docker

RUN g++ -o Main main.cpp book.cpp student.cpp teacher.cpp \
				stem_teacher.cpp teacher_portal.cpp

CMD ["./Main"]
