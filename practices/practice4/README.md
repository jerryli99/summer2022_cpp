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
cd summer2022_cpp/practices/practice4
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
Private inheritance.
Car can access protected member m_automobile_seats: 4
Car can access public function get_owner_name(): Jerry
Car can access public member m_automobile_color: Black
-----------------------------------------------
```

Delete docker image:
```
docker image rm practice4
```
