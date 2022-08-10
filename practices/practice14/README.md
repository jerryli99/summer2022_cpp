# Notice: This is not in the main branch. This is the practice14_branch branch!

First: ```git clone https://github.com/jerryli99/summer2022_cpp.git```

or ```cd summer2022_cpp``` and then do a ```git pull```

Next:
```
git checkout practice14_branch
cd summer2022_cpp/practices/practice14
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
----------------------------Output-----------------------------
Circle(Point(1, 2), radius 7)
Triangle(Point(1, 2), Point(3, 4), Point(5, 6))
The largest radius is: 7

Delete: Circle(Point(1, 2), radius 7)
Delete: Triangle(Point(1, 2), Point(3, 4), Point(5, 6))
Delete: Circle(Point(7, 8), radius 3)
---------------------------------------------------------------
```

Delete docker image:
```
docker image rm practice14
```
