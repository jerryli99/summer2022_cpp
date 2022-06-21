First:
```
git clone https://github.com/jerryli99/summer2022_cpp.git
```
or
```
cd summer2022_cpp

git pull
```

Next:
```
cd summer2022_cpp/practices/practice6
```

Change permission:
```
chmod u+x script.sh
```

To run code, do the following: (I assume you have Docker installed)
```bash
./script.sh
```

```
--------------------Output---------------------
Teacher name:     Sean
Teaching field:   Math, Physics, Chemistry, Biology
Teaching years:   10.5

Teach online class

StemTeachers do not have in person classes

Books students are required to use: 

Book title:  Physics1
Book author: Dinesh J.
Book ISBN:   0-7454-4533-2
Book pages:  200
Book price:  $30.45

Book title:  Physics2
Book author: Kevin K.
Book ISBN:   4-9822-1234-0
Book pages:  240
Book price:  $40.99

Book title:  Math1
Book author: Nancy L.
Book ISBN:   0-1212-1111-4
Book pages:  100
Book price:  $20.45

Book title:  Math2
Book author: Edward Liu
Book ISBN:   0-9698-6743-7
Book pages:  300
Book price:  $51

{
course1:
 [
  Student name: John
  Student ID:   123456
  Student exam1 score: 80
  Student exam2 score: 99
  Student final exam score: 80,

  Student name: Luis
  Student ID:   120456
  Student exam1 score: 80
  Student exam2 score: 90
  Student final exam score: 80,

  Student name: Tao
  Student ID:   123456
  Student exam1 score: 80
  Student exam2 score: 60
  Student final exam score: 80,

  Student name: Charlotte
  Student ID:   222123
  Student exam1 score: 80
  Student exam2 score: 99
  Student final exam score: 80,

  Student name: Deneen
  Student ID:   879231
  Student exam1 score: 80
  Student exam2 score: 99
  Student final exam score: 80,

 ],
course2:
 [
  Student name: Alpine
  Student ID:   223456
  Student exam1 score: 80
  Student exam2 score: 99
  Student final exam score: 80,

  Student name: Coul
  Student ID:   523456
  Student exam1 score: 80
  Student exam2 score: 99
  Student final exam score: 80,

  Student name: Liam
  Student ID:   123455
  Student exam1 score: 80
  Student exam2 score: 99
  Student final exam score: 80,

  Student name: Olivia
  Student ID:   454543
  Student exam1 score: 80
  Student exam2 score: 0
  Student final exam score: 80,

 ],
course3:
 [
  Student name: Kevin
  Student ID:   133456
  Student exam1 score: 80
  Student exam2 score: 19
  Student final exam score: 80,

  Student name: Brandon
  Student ID:   124222
  Student exam1 score: 80
  Student exam2 score: 99
  Student final exam score: 80,

 ],
course4:
 [
  Student name: Emma
  Student ID:   125456
  Student exam1 score: 80
  Student exam2 score: 88
  Student final exam score: 80,

  Student name: Amelia
  Student ID:   111111
  Student exam1 score: 100
  Student exam2 score: 29
  Student final exam score: 100,

 ],
course5:
 [
  Student name: Maria
  Student ID:   103456
  Student exam1 score: 80
  Student exam2 score: 79
  Student final exam score: 80,

  Student name: Tay
  Student ID:   723456
  Student exam1 score: 80
  Student exam2 score: 99
  Student final exam score: 80,

 ],
course6:
 [
  Student name: Shawn
  Student ID:   923456
  Student exam1 score: 80
  Student exam2 score: 99
  Student final exam score: 80,

  Student name: Oliver
  Student ID:   788966
  Student exam1 score: 20
  Student exam2 score: 59
  Student final exam score: 20,

 ],
course7:
 [
  Student name: Sean
  Student ID:   123006
  Student exam1 score: 80
  Student exam2 score: 99
  Student final exam score: 80,

 ],
course8:
 [
  Student name: Queen
  Student ID:   123096
  Student exam1 score: 80
  Student exam2 score: 99
  Student final exam score: 80,

  Student name: Noah
  Student ID:   789222
  Student exam1 score: 80
  Student exam2 score: 99
  Student final exam score: 80,

 ],
}
-----------------------------------------------
```

Delete docker image:
```
docker image rm practice6
```
