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
cd summer2022_cpp/practices/practice7
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
Get root permission number: 7

Changed the protected member (in base)
to public member (in derived). 
Output user_file_permission number: 4

Changed the user_file_permission number from 4 to -> 6
-----------------------------------------------
```

Delete docker image:
```
docker image rm practice7
```
