First: ```git clone https://github.com/jerryli99/summer2022_cpp.git```

or ```cd summer2022_cpp``` and then do a ```git pull```

Next:
```
cd summer2022_cpp/practices/practice10
```

Change permission:
```
chmod u+x script.sh
```

To run code, do the following: (I assume you have Docker installed)
```bash
./script.sh
```
## Update
Reduced docker build image size from ~1.27GB to ~185MB 

## Result
```
--------------------Output---------------------
ClassName: This is Circle

circle x position:  12
circle y position:  13
circle radius:      14

circle1 x position: 12
circle1 y position: 13
circle1 radius:     14

circle2 x position: 12
circle2 y position: 13
circle2 radius:     14

ClassName: This is Shape

This is Circle

This is Circle

Using the virtual keyword to override PrintClassName()

This is Shape

This is Circle

This is Circle
-----------------------------------------------
```

Delete docker image:
```
docker image rm practice10
```
